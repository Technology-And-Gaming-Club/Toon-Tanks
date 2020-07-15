// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include"Components/CapsuleComponent.h"
#include"Kismet/KismetMathLibrary.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APawnBase::RotateTurret(FVector LookAtTarget)
{
	//update turret rotation to face towards look at target passed from child class

	FVector StartLocation = TurretMesh->GetComponentLocation();
	FRotator TurretRotation = UKismetMathLibrary::FindLookAtRotation(StartLocation, FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z));
	//turret mesh->setworldrotation()
	TurretMesh->SetWorldRotation(TurretRotation);
}


void APawnBase:: Fire()
{
	//get projectile spawn point on rotation && rotation->spawn projectle class at rotation towards rotation
	UE_LOG(LogTemp, Warning, TEXT("FIRE!!!"));
}

void APawnBase:: HandleDestruction()
{
	//universal functionality
	//play death effects scene and camera
	//then do unique child overrides
	//pwnturret-if turret die-then destroy self
	//pwntank-if tank die-hide components and stop input.
}

