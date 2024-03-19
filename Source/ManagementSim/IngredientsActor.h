// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "IngredientsActor.generated.h"

UCLASS()
class MANAGEMENTSIM_API AIngredientsActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIngredientsActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Getter functions for Components */

	FORCEINLINE UBoxComponent* GetBoxComponent() const
	{
		return _BoxComponent;
	}

	FORCEINLINE UStaticMeshComponent* GetMeshComponent() const
	{
		return _MeshComponent;
	}

	UPROPERTY(VisibleAnywhere, Category = "Food")
		float CookTime;

	UPROPERTY(VisibleAnywhere, Category = "Food")
		bool Cooked;

	UPROPERTY(VisibleAnywhere, Category = "Food")
		bool Burned;

	UFUNCTION(BlueprintCallable, Category = "Food")
		void OnHit();

	UFUNCTION(BlueprintCallable, Category = "Food")
		void CookTimeTimer();

	FTimerHandle CookTimeTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ingredients Component", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* _BoxComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ingredients Component", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* _MeshComponent;
};
