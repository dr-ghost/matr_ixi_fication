// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Smorty.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UMotionControllerComponent;
class UAnimMontage;
class USoundBase;

UCLASS(Blueprintable, config=Game)
class MATRIXIFICATION_API ASmorty : public ACharacter
{
	GENERATED_BODY()

	//smorty's hands+weapon mesh
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh_;

	/*
	//Weapons (gun + knife)
	
	*/

	//camera component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FirstPersonCameraComponent;


public:
	// Sets default values for this character's properties
	ASmorty();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, Category="Damage", BlueprintReadWrite)
		float health;
	UPROPERTY(EditAnywhere, Category = "Damage", BlueprintReadWrite)
		float Max_health;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* FireAnimation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool f_weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
		bool isHolding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
		AActor * held_item;

protected:

	void OnFire();

	void MoveForward(float Val);

	void MoveRight(float Val);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void PickUp();

public:
	USkeletalMeshComponent* GetMesh() const{ return Mesh_; }
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
};
