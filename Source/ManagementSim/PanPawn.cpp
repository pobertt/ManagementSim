// Fill out your copyright notice in the Description page of Project Settings.


#include "PanPawn.h"

// Sets default values
APanPawn::APanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(_BoxComponent);

	_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	_MeshComponent->SetupAttachment(_BoxComponent);

	//Create the camera spring arm
	_SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	_SpringArmComponent->SetupAttachment(RootComponent);
	_SpringArmComponent->SetUsingAbsoluteRotation(true);
	_SpringArmComponent->TargetArmLength = 80.0f;
	_SpringArmComponent->SetRelativeRotation(FRotator(-60.0f, 0.0f, 0.0f));
	_SpringArmComponent->bDoCollisionTest = false;

	//Create the camera
	_CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_CameraComponent->SetupAttachment(_SpringArmComponent, USpringArmComponent::SocketName);
	_CameraComponent->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void APanPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

