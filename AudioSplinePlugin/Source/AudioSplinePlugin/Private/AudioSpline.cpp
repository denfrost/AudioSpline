/*=============================================================================
	AudioSpline.cpp

	Doc:
	https://github.com/luigiplatania94/AudioSpline

	Luigi Platania
	https://www.luigiplatania.net/

	Email:
	luigiplatania94@gmail.com
=============================================================================*/

#include "AudioSpline.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SplineComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Math/Vector.h"
#include "Kismet/GameplayStatics.h"

// Constructor
AAudioSpline::AAudioSpline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Initialise the Spline Component and set it to be the Root
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	RootComponent = SplineComponent;
	SplineComponent->SetGenerateOverlapEvents(false);

	// Initialise the Main Audio Component and attach it to the Root
	MainAudioComponent = GetAudioComponent();
	MainAudioComponent->SetupAttachment(RootComponent);

	// Initialise the Dual Audio Component and attach it to the root
	DualAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Dual Audio Component"));
	DualAudioComponent->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void AAudioSpline::BeginPlay()
{
	Super::BeginPlay();

	// Set the Tick Interval equal to the user-defined Update Interval
	PrimaryActorTick.TickInterval = UpdateInterval;

	// Set the SoundBase of the Dual Audio Component to be equal to the Main Audio Component's one
	DualAudioComponent->SetSound(MainAudioComponent->Sound);

	// Print an Error if the Audio Spline Actor does not have a Sound Cue
	if (!MainAudioComponent->Sound)
	{
		UE_LOG(LogTemp, Error, TEXT("%s does not have a Sound Cue"), *GetName());
	}
}

// Function called every frame on this Actor
void AAudioSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Store the player location at the given time
	FVector PlayerLocation = GetPlayerLocation();

	// Update the Audio Component(s) location(s) if the Player is moving
	if (IsPlayerMoving(PlayerLocation))
	{
		// Move the main Audio Component to the point on the curve that is closest to the listener's position
		MoveVirtualSpeaker(PlayerLocation);

#if WITH_EDITOR
		// Check if the user has enabled the JumpScanner on the instance of the Actor
		if (bAllowJumpScanner)
		{
			// Print to the Output Log the biggest jump detected during PIE (Play In Editor)
			JumpScanner();
		}
#endif // #if WITH_EDITOR

		// If a Jump was detected, play the Dual Audio Component
		if (bAllowDualSource && IsJumpDetected())
		{
			// Update Dual Audio Component position 
			DualAudioComponent->SetWorldLocation(TempOldSourcePosition);
			
			// Fade in Dual Audio Component and adjust the Main Audio Component's volume
			if (!DualAudioComponent->IsPlaying())
			{
				DualAudioComponent->FadeIn(0.05, AdjustedVolume, 0.0f, EAudioFaderCurve::Sin);
				MainAudioComponent->FadeIn(AdjustedVolumeDuration, AdjustedVolume, 0.0f, EAudioFaderCurve::Sin);
			}

			bDualDebug = true;
		}

#if WITH_EDITOR
		// DEBUG visualisation WHITE. The Player is moving.
		if (bDebug && MainAudioComponent->Sound)
		{
			// Debug the main Audio Component
			Debug(MainAudioComponent->GetComponentLocation(), FColor::White);
			
			// Debug the Dual Audio Component
			if (bDualDebug)
			{
				Debug(DualAudioComponent->GetComponentLocation(), FColor::White);
			}
		}
#endif // #if WITH_EDITOR

	} // End if (IsPlayerMoving(PlayerLocation))

#if WITH_EDITOR
	else
	{
		// DEBUG visualisation BLACK. The Player is NOT moving
		if (bDebug && MainAudioComponent->Sound)
		{
			// Debug the main Audio Componet
			Debug(MainAudioComponent->GetComponentLocation(), FColor::Black);

			// Debug the Dual Audio Component
			if (bDualDebug)
			{
				Debug(DualAudioComponent->GetComponentLocation(), FColor::Black);
			}
		}
	}
#endif // #if WITH_EDITOR


	/*
	*	Logic for playing and stopping the Main Audio Component and slowing down the tick 
	*/

	// Play Main audio component if the player is in range, else Stop it.
	// Furthermore, if the player is not in range, slow down the tick.
	if (IsPlayerInRange(PlayerLocation, MainAudioComponent))
	{
		if (!MainAudioComponent->IsPlaying())
		{
			// FadeIn the sound if the player is in range
			MainAudioComponent->FadeIn(0.1, 1.0f, 0.0f, EAudioFaderCurve::Logarithmic);

			// slow down the tick interval to optimise performance
			PrimaryActorTick.TickInterval = UpdateInterval;
		}
	}
	else if (MainAudioComponent->IsPlaying())
	{
			// FadeOut and Stop the sound if the player is NOT in range
			MainAudioComponent->FadeOut(0.1, 0.0f, EAudioFaderCurve::Logarithmic);

			// slow down the tick interval to optimise performance
			PrimaryActorTick.TickInterval = SlowInterval;
	}


	/*
	 *	Logic for stopping the Dual Audio Component and 
	*/
	if (bAllowDualSource && !IsPlayerInRange(PlayerLocation, DualAudioComponent))
	{
		// Fade out If the player is NOT in range
		if (DualAudioComponent->IsPlaying())
		{
			DualAudioComponent->FadeOut(0.1, 0.0f, EAudioFaderCurve::Logarithmic);

			// Main Audio component's volume goes back to normal
			MainAudioComponent->AdjustVolume(AdjustedVolumeDuration, 1.0f, EAudioFaderCurve::Logarithmic);
		}

		bDualDebug = false;
	}
}

// Change the location of the AudioComponent along the SplineComponent 
void AAudioSpline::MoveVirtualSpeaker(const FVector &PlayerLocation)
{
	// Return the closest point on the spline to the PlayerLocation
	CurrentSourcePosition = SplineComponent->FindLocationClosestToWorldLocation(PlayerLocation, ESplineCoordinateSpace::World);
	// Update the main Audio Component location with the closest point previously calculated
	MainAudioComponent->SetWorldLocation(CurrentSourcePosition);

	// Dual Source Logic - This will prevent to detect a jump once the the actor is spawned
	if (bDoOnce)
	{
		OldSourcePosition = CurrentSourcePosition;
		bDoOnce = false;
	} 
}

// Return true if the player is moving. 
bool AAudioSpline::IsPlayerMoving(const FVector &PlayerLocation)  
{
	CurrentPlayerPosition = PlayerLocation;
	// If the old and the current player position did not change, it means the player is not moving
	if (CurrentPlayerPosition == OldPlayerPosition)
	{
		OldPlayerPosition = CurrentPlayerPosition;
		return false;
	}
	else
	{
		OldPlayerPosition = CurrentPlayerPosition;
		return true;
	}
}

// Return true if the player is in range relative to the target Audio Component
bool AAudioSpline::IsPlayerInRange(const FVector &PlayerLocation, const UAudioComponent* TargetAudioComponent) const
{
	// Get the target Audio Component Location
	FVector TargetAudioComponentLocation = TargetAudioComponent->GetComponentLocation();
	// Store into a temporary variable the distance between the PlayerLocation and the Main Audio Component Location
	float DistanceToPlayer = FVector::Dist(PlayerLocation, TargetAudioComponentLocation);
	// Return true if thee distance is less than the user-defined Range 
	return DistanceToPlayer < Range;
}

// Get Player Location 
FVector AAudioSpline::GetPlayerLocation() const
{
	APawn* LocalPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	// Return an FVector initialised to zero if the pointer is not aiming towards the PlayerPawn
	if (!LocalPawn)
	{
		return FVector(EForceInit::ForceInitToZero);
	}

	return LocalPawn->GetActorLocation();
}

// Dual Source Function - Return true if a Jump is detected
bool AAudioSpline::IsJumpDetected()
{
	// Store the OldSourcePosition in a temporary variable. It will be used to update the Dual Audio Component Position.
	TempOldSourcePosition = OldSourcePosition;

	// Jump is detected when the distance between the CurrentSourcePosition and the OldSourcePosition is greater than the JumpThreshold (User-Defined)
	if (FVector::Dist(CurrentSourcePosition, OldSourcePosition) > JumpThreshold)
	{
		OldSourcePosition = CurrentSourcePosition;
		// Print to the output log if a Jump was detected
		if (bDebug)
		{
#if WITH_EDITOR
			// Print to the output log if a Jump was detected
			UE_LOG(LogTemp, Warning, TEXT("%s A Jump has been detected."), *GetName());
#endif // #if WITH_EDITOR
		}
		return true;
	} // End  if (FVector::Dist(CurrentSourcePosition, OldSourcePosition) > JumpThreshold)
	else
	{
		OldSourcePosition = CurrentSourcePosition;
		return false;
	}
}

// Dual Source Function - Print to the Output Log the biggest jump detected during PIE (Play In Editor) 
void AAudioSpline::JumpScanner()
{
	// Temporary distance between old and current source position
	float TempJump = FVector::Dist(CurrentSourcePosition, OldSourcePosition);
	// Update LargestJumpSoFar If the distance previously calculated is greater than its current value 
	if (TempJump > LargestJumpSoFar)
	{
		LargestJumpSoFar = TempJump;
	}
	// Print to the output log the biggest jump so far
	UE_LOG(LogTemp, Warning, TEXT("%s The biggest jump so far is: %f"), *GetName(), LargestJumpSoFar);
}

// Draw Debug sphere based on the Audio Component Location. WHITE means the player IS moving. Black means the player is NOT moving
void AAudioSpline::Debug(const FVector DebugLocation, FColor Color) const
{
	// The life-time of the sphere is set to be tick + 0.01 in order to avoid a flashing effect
	DrawDebugSphere(GetWorld(), DebugLocation, 100.0f, 16, Color, false, PrimaryActorTick.TickInterval + 0.01);
	DrawDebugSphere(GetWorld(), DebugLocation, Range, 32, Color, false, PrimaryActorTick.TickInterval + 0.01);
}

