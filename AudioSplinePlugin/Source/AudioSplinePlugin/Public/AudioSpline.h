/*=============================================================================
	AudioSpline.h

	Luigi Platania
	https://www.luigiplatania.net/

	Email:
	luigiplatania94@gmail.com
=============================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "Sound/AmbientSound.h"
#include "AudioSpline.generated.h"

class USplineComponent;

UCLASS(Blueprintable)
class AUDIOSPLINEPLUGIN_API AAudioSpline : public AAmbientSound
{
	GENERATED_BODY()

public:
	// Constructor
	AAudioSpline(const FObjectInitializer& ObjectInitializer);

	// Function called every frame on this Actor
	virtual void Tick(float DeltaTime) override;

	// Distance between main AudioComponent and Player. The sound is Stopped when the player goes beyond the Range
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Range = 15000.0f;

	// Tick interval
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float UpdateInterval = 0.15f;

	// Debug
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bDebug = false;

	// The DualSource spawns a new Audio Source if the closest location jumps above a threshold
	UPROPERTY(Category = "Dual Source Mode", EditAnywhere, BlueprintReadOnly)
	bool bAllowDualSource = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/*
	FUNCTIONS
	*/
	// Change the location of the AudioComponent and update che CurrentSourcePosition
	void MoveVirtualSpeaker(const FVector &PlayerLocation);

	// Check if the player is moving 
	bool IsPlayerMoving(const FVector &PlayerLocation);

	// Check if the player is in range
	bool IsPlayerInRange(const FVector &PlayerLocation) const;

	// Draw Debug
	void Debug(FVector DebugLocation, FColor Color) const;

	// Get Player Location 
	FVector GetPlayerLocation() const;

	/*
	COMPONENTS
	*/
	USplineComponent* SplineComponent;

	// This is the main audio source
	UAudioComponent* AudioComponent;

	/*
	VARIABLES
	*/
	// These variable are used to calculate if the player is moving
	FVector CurrentPlayerPosition;
	FVector OldPlayerPosition;
};
