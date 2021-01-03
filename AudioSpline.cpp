/*=============================================================================
	AudioSpline.cpp


	Luigi Platania
	www.luigiplatania.net
=============================================================================*/

#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SplineComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Math/Vector.h"
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
}

// Function called every frame on this Actor
void AAudioSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!PlayerController)
	{
		return;
	}
	FVector PlayerLocation = PlayerController->GetPawn()->GetActorLocation();

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

	// Updare the AudioComponent Location if the Player is moving
	if (IsPlayerMoving(PlayerLocation))
	{
		MoveVirtualSpeaker(PlayerLocation);
	}
	else 
	{
#if WITH_EDITOR
		// Debug visualisation BLACK
		DrawDebugSphere(GetWorld(), AudioComponent->GetComponentLocation(), 100.0f, 16, FColor().Black, false, UpdateInterval);
		DrawDebugSphere(GetWorld(), AudioComponent->GetComponentLocation(), Range, 32, FColor().Black, false, UpdateInterval);
#endif // #if WITH_EDITOR
	}
}

// Change the location of the AudioComponent along the SplineComponent
void AAudioSpline::MoveVirtualSpeaker(const FVector &PlayerLocation)
{
	// Return the closest point on the spline to the PlayerLocation
	FVector ClosestPoint = SplineComponent->FindLocationClosestToWorldLocation(PlayerLocation, ESplineCoordinateSpace::World);
	AudioComponent->SetWorldLocation(ClosestPoint); 

#if WITH_EDITOR
	// Debug visualisation WHITE
	DrawDebugSphere(GetWorld(), AudioComponent->GetComponentLocation(), 100.0f, 16, FColor().White, false, UpdateInterval);
	DrawDebugSphere(GetWorld(), AudioComponent->GetComponentLocation(), Range, 32, FColor().White, false, UpdateInterval);
#endif // #if WITH_EDITOR
}

// Return whether the player is moving 
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

// Return a ptr to PlayerController
APlayerController* AAudioSpline::GetFirstLocalPlayerController() const
{
	const UWorld* World = GetWorld();
	if (World)
	{
		if (APlayerController* PlayerController = World->GetFirstPlayerController())
		{
			return PlayerController;
		}
	}
	return nullptr;
}

