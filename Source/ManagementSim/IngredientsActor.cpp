// Fill out your copyright notice in the Description page of Project Settings.


#include "IngredientsActor.h"

// Sets default values
AIngredientsActor::AIngredientsActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(_BoxComponent);

	_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	_MeshComponent->SetupAttachment(_BoxComponent);

	Cooked = false;

	Burned = false;
}


void AIngredientsActor::OnHit()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FormatAsNumber(CookTime));
	CookTime = CookTime - 1;

	if (CookTime < 10 && CookTime > 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Cooked");
		Cooked = true;
	}
	else if (CookTime < 0) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Burned");
		Burned = true;
	}
}

void AIngredientsActor::CookTimeTimer()
{
	CookTime = CookTime - 1;
}

// Called when the game starts or when spawned
void AIngredientsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIngredientsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

