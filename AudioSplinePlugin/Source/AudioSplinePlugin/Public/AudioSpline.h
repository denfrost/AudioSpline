/*=============================================================================
	AudioSpline.h

	Doc:
	https://github.com/luigiplatania94/AudioSpline

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

	// Distance between the AudioComponent and Player. The sound is Stopped when the player goes beyond the Range
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Range{ 15000.0f };

	// User-defined Tick interval
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float UpdateInterval{ 0.15f };

	// Draw debug spheres around the audio sources
	UPROPERTY(EditAnywhere)
	bool bDebug{ false };

	// The DualSource spawns a new Audio Source if the closest location on the spline jumps above a threshold.
	// Do not update this bool during PIE(Play In Editor)
	UPROPERTY(Category = "Dual Source Mode", EditAnywhere, BlueprintReadOnly)
	bool bAllowDualSource{ false };

	// Play the Dual Audio Component If the jump is greater than JumpThreshold
	UPROPERTY(Category = "Dual Source Mode", EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bAllowDualSource"))
	float JumpThreshold{ 1000.0f };

	// Volume of BOTH Audio Components when the Dual Source is spawned  
	UPROPERTY(Category = "Dual Source Mode", EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bAllowDualSource"))
	float AdjustedVolume{ 0.75f };

	// How quick the Main Audio Component is going to fade/adjust its volume when Dual Audio Component spawns OR get killed
	UPROPERTY(Category = "Dual Source Mode", EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bAllowDualSource"))
	float AdjustedVolumeDuration{ 0.5f };

	// Print to the Output Log the biggest jump detected during PIE (Play In Editor)
	UPROPERTY(Category = "Dual Source Mode", EditAnywhere, meta = (EditCondition = "bAllowDualSource"))
	bool bAllowJumpScanner{ false };


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

	// Check if the player is in range relative to the target Audio Component. 
	bool IsPlayerInRange(const FVector &PlayerLocation, const UAudioComponent* TargetAudioComponent) const;

	// Dual Source Function - Check if a Jump was detected
	bool IsJumpDetected();

	// Dual Source Function - Print to the Output Log the biggest jump detected during PIE (Play In Editor) 
	void JumpScanner();

	// Draw Debug sphere based on the Audio Component Location. WHITE means the player IS moving. Black means the player is NOT moving
	void Debug(const FVector DebugLocation, FColor Color) const;

	// Get Player Location 
	FVector GetPlayerLocation() const;

	/*
	COMPONENTS
	*/
	// Spline Component
	USplineComponent* SplineComponent;
	// Main audio source
	UAudioComponent* MainAudioComponent;
	// Dual Audio Source
	UAudioComponent* DualAudioComponent;

	/*
	VARIABLES
	*/
	// These variable are used to calculate if the player is moving
	FVector CurrentPlayerPosition;
	FVector OldPlayerPosition;

	/* 
	 * Dual Source variables
	 */
	// It prevents to detect a jump once the the actor is spawned
	bool bDoOnce{ true };

	// Debug Dual Audio Component Location
	bool bDualDebug{ false };

	// These variables are used to calculate if there was a jump 
	FVector CurrentSourcePosition;
	FVector OldSourcePosition;
	// This variable is used to update the Dual Audio Component Position
	FVector TempOldSourcePosition;

	// This variable is used for the Jump Scanner
	float LargestJumpSoFar{ 0.0f };
};
