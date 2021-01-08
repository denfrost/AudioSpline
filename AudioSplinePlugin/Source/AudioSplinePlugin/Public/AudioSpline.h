/*=============================================================================
	AudioSpline.cpp

	Luigi Platania
	https://www.luigiplatania.net/

	Documentation:
	https://github.com/luigiplatania94/AudioSpline/blob/main/README.md
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

	/*
		Functions
	*/
	// Function called every frame on this Actor
	virtual void Tick(float DeltaTime) override;

	// Change the location of the AudioComponent
	void MoveVirtualSpeaker(const FVector &PlayerLocation);

	// Check if the player is moving 
	bool IsPlayerMoving(const FVector &PlayerLocation);

	// Check if the player is in range
	bool IsPlayerInRange(const FVector &PlayerLocation) const;

	/*
		Components
	*/
	USplineComponent* SplineComponent;
	UAudioComponent* AudioComponent;

	/*
		Variables
	*/
	// Distance between AudioComponent and Player. The sound is Stopped when the player goes beyond the Range
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Range = 1500.0f;
	// Tick interval
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float UpdateInterval = 0.15f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// These variable are used to calculate if the player is moving
	FVector CurrentPlayerPosition;
	FVector OldPlayerPosition;
};
