// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f; //how far a player can reach, in cm

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	
	void Grab(); ///ray-cast and grab whats in reach
	void Release(); /// Called when grab is released
	void FindPhysicsHandleComponent(); //find attached physics component
	void SetupInputComponent(); ///Setup (assumed)  input component
	const FHitResult GetFirstPhysicsBodyInReach(); //return hit for first physics body in reach	
	FVector GetReachLineEnd(); //returns current start of reach line
	FVector GetReachLineStart(); //returns current end of reach line
};