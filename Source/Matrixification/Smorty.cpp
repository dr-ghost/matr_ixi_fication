// Fill out your copyright notice in the Description page of Project Settings.


#include "Smorty.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASmorty::ASmorty()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//setting size of capsule component (collider)
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	//weapon 0 -> knife ; 1 -> gun;
	f_weapon = false;

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	
	//camera component
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));

	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//mesh component
	Mesh_ = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));

	Mesh_->SetOnlyOwnerSee(true);
	Mesh_->SetupAttachment(FirstPersonCameraComponent);
	Mesh_->bCastDynamicShadow = false;
	Mesh_->CastShadow = false;
	Mesh_->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	Mesh_->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));// change @paawan

	/*
	//gun mesh component
	
	//knife component
	
	*/
		
}

// Called when the game starts or when spawned
void ASmorty::BeginPlay()
{
	Super::BeginPlay();
	
	health = 100.0f;

	Mesh_->SetHiddenInGame(false, true);

	//hiding gun (incomplete)
}

// Called every frame
void ASmorty::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASmorty::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//check game key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASmorty::OnFire);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &ASmorty::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASmorty::MoveRight);

	//yaw inputs
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ASmorty::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ASmorty::LookUpAtRate);

	//toggle weapon
	PlayerInputComponent->BindAction("Toggle", IE_Pressed, this, &ASmorty::ToggleWeapon);

}

void ASmorty::OnFire()
{
}

void ASmorty::MoveForward(float Val)
{
	if (Val != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Val);
	}
}

void ASmorty::MoveRight(float Val)
{
	if (Val != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Val);
	}
}

void ASmorty::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASmorty::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ASmorty::ToggleWeapon()
{
	if (!f_weapon)
	{
		;
	}
	else
	{
		;
	}
}

