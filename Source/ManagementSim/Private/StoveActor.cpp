// Fill out your copyright notice in the Description page of Project Settings.


#include "StoveActor.h"

// Sets default values
AStoveActor::AStoveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(_BoxComponent);

	_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	_MeshComponent->SetupAttachment(_BoxComponent);
}

// Called when the game starts or when spawned
void AStoveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

