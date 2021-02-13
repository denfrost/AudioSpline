/*=============================================================================
	AudioSpline.cpp

	Luigi Platania
	https://www.luigiplatania.net/

	Email:
	luigiplatania94@gmail.com
=============================================================================*/

#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SplineComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Math/Vector.h"
#include "Kismet/GameplayStatics.h"
#include "AudioSpline.h"

// Constructor
AAudioSpline::AAudioSpline(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Initialise the Spline Component and set it to be the Root
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	RootComponent = SplineComponent;
	SplineComponent->SetGenerateOverlapEvents(false);

	// Initialise the Audio Component and attach it to the Root
	AudioComponent = GetAudioComponent();
	AudioComponent->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void AAudioSpline::BeginPlay()
{
	Super::BeginPlay();

	// Set the Tick Interval equal to the user-defined Update Interval
	PrimaryActorTick.TickInterval = UpdateInterval;

	// Print an Error if the Audio Spline Actor does not have a Sound Cue
#if WITH_EDITOR
	if (bDebug && !AudioComponent->Sound)
	{
		UE_LOG(LogTemp, Error, TEXT("%s does not have a Sound Cue"), *GetName());
	}
#endif // #if WITH_EDITOR
}

// Function called every frame on this Actor
void AAudioSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Store the player location at the given time
	FVector PlayerLocation = GetPlayerLocation();

	// Update the main Audio Component Location if the Player is moving
	if (IsPlayerMoving(PlayerLocation))
	{
		// Move the main Audio Component to the point on the curve that is closest to the listener's position
		MoveVirtualSpeaker(PlayerLocation);
	}
	else
	{
		// Debug visualisation BLACK/RED. The Player is NOT moving
		if (bDebug)
		{
			// Debug the main Audio Componet
			Debug(AudioComponent->GetComponentLocation(), FColor::Black);
		}
	}

	// Play audio component if the player is in range, else Stop it.
	if (IsPlayerInRange(PlayerLocation))
	{
		if (!AudioComponent->IsPlaying())
		{
			// FadeIn the sound if the player is in range
			AudioComponent->FadeIn(0.5f, 1.0f, 0.0f, EAudioFaderCurve::Logarithmic);
		}
	}
	else if (AudioComponent->IsPlaying())
	{
			// FadeOut and Stop the sound if the player is NOT in range
			AudioComponent->FadeOut(0.5f, 0.0f, EAudioFaderCurve::Logarithmic);
	}
}

// Change the location of the AudioComponent along the SplineComponent and update che CurrentSourcePosition
void AAudioSpline::MoveVirtualSpeaker(const FVector &PlayerLocation)
{
	// Return the closest point on the spline to the PlayerLocation
	FVector ClosestPoint = SplineComponent->FindLocationClosestToWorldLocation(PlayerLocation, ESplineCoordinateSpace::World);
	AudioComponent->SetWorldLocation(ClosestPoint);

	// Debug visualisation WHITE/YELLO. The Player is moving.
	if (bDebug)
	{
		// Debug the main Audio Componet
		Debug(AudioComponent->GetComponentLocation(), FColor::White);
	}
}

// Return true if the player is moving. 
bool AAudioSpline::IsPlayerMoving(const FVector &PlayerLocation)  
{
	CurrentPlayerPosition = PlayerLocation;
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

// Return true if the player is in range
bool AAudioSpline::IsPlayerInRange(const FVector &PlayerLocation) const
{
	FVector AudioComponentLocation = AudioComponent->GetComponentLocation();
	float DistanceToPlayer = FVector::Dist(PlayerLocation, AudioComponentLocation);

	if (DistanceToPlayer < Range)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Draw Debug
void AAudioSpline::Debug(FVector DebugLocation, FColor Color) const
{
#if WITH_EDITOR
	// The life-time of the sphere is set to be UpdateInterval + 0.01 in order to avoid a flashing effect
	DrawDebugSphere(GetWorld(), DebugLocation, 100.0f, 16, Color, false, UpdateInterval + 0.01);
	DrawDebugSphere(GetWorld(), DebugLocation, Range, 32, Color, false, UpdateInterval + 0.01);
#endif // #if WITH_EDITOR
}

// Get Player Location 
FVector AAudioSpline::GetPlayerLocation() const
{
	APawn* LocalPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!LocalPawn)
	{
		return FVector();
	}
	return LocalPawn->GetActorLocation();
}
