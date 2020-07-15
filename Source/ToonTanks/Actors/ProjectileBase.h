// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,category="Components",meta=(AllowPrivateAccess="true"))
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,category="Components",meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditDefaultsOnly, category = "Damage", meta = (AllowAccess = "true"))
	UClass* PointerToDamageType;

	UPROPERTY(EditDefaultsOnly, category = "Damage", meta = (AllowAccess = "true"))
	TSubclassOf<DamageType> DamageType;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,category="Movement",meta=(AllowAccess="true"))
	float MovementSpeed = 1300.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,category="Damage",meta=(AllowAccess="true"))
	float Damage = 50.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
