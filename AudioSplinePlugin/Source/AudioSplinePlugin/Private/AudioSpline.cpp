/*=============================================================================
	AudioSpline.cpp

	Luigi Platania
	https://www.luigiplatania.net/

	Documentation:
	https://github.com/luigiplatania94/AudioSpline/blob/main/README.md
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
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	RootComponent = SplineComponent;
	SplineComponent->SetGenerateOverlapEvents(false);
	SplineComponent->SetCanEverAffectNavigation(false);

	AudioComponent = GetAudioComponent();
	AudioComponent->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void AAudioSpline::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.TickInterval = UpdateInterval;

#if WITH_EDITOR
	if (!AudioComponent->Sound)
	{
		// Print an Error if the Audio Spline Actor does not have a Sound Cue
		UE_LOG(LogTemp, Error, TEXT("%s does not have a Sound Cue"), *GetName());
	}
#endif // #if WITH_EDITOR
}

// Function called every frame on this Actor
void AAudioSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* LocalPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!LocalPawn)
	{
		return;
	}
	FVector PlayerLocation = LocalPawn->GetActorLocation();


	// Update the AudioComponent Location if the Player is moving
	if (IsPlayerMoving(PlayerLocation))
	{
		MoveVirtualSpeaker(PlayerLocation);
	}
	else
	{
#if WITH_EDITOR
		// Debug visualisation BLACK. The Player is NOT moving
		DrawDebugSphere(GetWorld(), AudioComponent->GetComponentLocation(), 100.0f, 16, FColor().Black, false, UpdateInterval);
		DrawDebugSphere(GetWorld(), AudioComponent->GetComponentLocation(), Range, 32, FColor().Black, false, UpdateInterval);
#endif // #if WITH_EDITOR
	}

	// Play audio component if the player is in range, else Stop it.
	if (IsPlayerInRange(PlayerLocation))
	{
		if (!AudioComponent->IsPlaying())
		{
			// FadeIn the sound if the player is in range
			AudioComponent->FadeIn(0.1f, 1.0f, 0.0f, EAudioFaderCurve::Logarithmic);
		}
	}
	else
	{
		if (AudioComponent->IsPlaying())
		{
			// FadeOut and Stop the sound if the player is NOT in range
			AudioComponent->FadeOut(0.1f, 0.0f, EAudioFaderCurve::Logarithmic);
			AudioComponent->Stop();
		}
	}
}

// Change the location of the AudioComponent along the SplineComponent
void AAudioSpline::MoveVirtualSpeaker(const FVector &PlayerLocation)
{
	// Return the closest point on the spline to the PlayerLocation
	FVector ClosestPoint = SplineComponent->FindLocationClosestToWorldLocation(PlayerLocation, ESplineCoordinateSpace::World);
	AudioComponent->SetWorldLocation(ClosestPoint);

#if WITH_EDITOR
	// Debug visualisation WHITE. The Player is moving.
	DrawDebugSphere(GetWorld(), AudioComponent->GetComponentLocation(), 100.0f, 16, FColor().White, false, UpdateInterval);
	DrawDebugSphere(GetWorld(), AudioComponent->GetComponentLocation(), Range, 32, FColor().White, false, UpdateInterval);
#endif // #if WITH_EDITOR
}

// Return whether the player is moving or not. 
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

// Return whether the player is in range
bool AAudioSpline::IsPlayerInRange(const FVector &PlayerLocation)
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