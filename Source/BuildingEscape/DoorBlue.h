// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "DoorBlue.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDoorBlue : public UActorComponent
{
	GENERATED_BODY()

	public:	
	// Sets default values for this component's properties
	UDoorBlue(); 

	protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActor() const;
	void FindAudioComponent();
	void FindPressurePlate();

	bool OpenDoorSound = false;
	bool CloseDoorSound = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Door)
	float OpenAngle = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Door)
	float DoorCloseDelay = .5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Door)
	float DoorOpenSpeed = .8f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Door)
	float DoorCloseSpeed = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Door)
	int32 MassToOpenDoors = 200;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Door)
	ATriggerVolume* Trigger_Blue = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Door)
	UAudioComponent* Audio_DoorBlue = nullptr;
	
	private:
	float InitialYaw;
	float CurrentYaw;

	float DoorLastOpened = 0.f;

};
