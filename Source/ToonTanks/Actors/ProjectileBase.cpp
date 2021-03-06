// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"
#include"Components/StaticComponents.h"
#include"GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubObject<UStaticMeshComponent>(TEXT("ProjectileMesh"));

	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubObject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	ProjectileMovement->InitialSpeed = MovementSpeed;
	ProjectileMovement->MaxSpeed = MovementSpeed;

	InitialLifeSpan = 3.0f;




}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}



