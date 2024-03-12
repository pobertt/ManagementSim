// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PanPawn.generated.h"

UCLASS()
class MANAGEMENTSIM_API APanPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APanPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE USpringArmComponent* GetSpringArmComponent() const
	{
		return _SpringArmComponent;
	}

	FORCEINLINE UCameraComponent* GetCameraComponent() const
	{
		return _CameraComponent;
	}

	FORCEINLINE UBoxComponent* GetBoxComponent() const
	{
		return _BoxComponent;
	}

	FORCEINLINE UStaticMeshComponent* GetMeshComponent() const
	{
		return _MeshComponent;
	}

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pan Component", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* _SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pan Component", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* _CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pan Component", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* _BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pan Component", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* _MeshComponent;

};
