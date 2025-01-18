// Fill out your copyright notice in the Description page of Project Settings.


#include "GunAttempt.h"

// Sets default values
AGunAttempt::AGunAttempt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GunFrame = CreateDefaultSubobject<USceneComponent>(TEXT("GunFrame"));
	GunFrame->SetupAttachment(RootComponent);
	GunBaseStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunBaseStaticMesh"));
	GunBarrelStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunBarrelStaticMesh"));
	GunStockStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunStockStaticMesh"));
	GunSightStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunSightStaticMesh"));
	Pool = CreateDefaultSubobject<UDataAsset>(TEXT("Pool"));
	GunBaseStaticMesh->ComponentTags.Add(FName("Base"));
	GunBarrelStaticMesh->ComponentTags.Add(FName("Barrel"));
	GunStockStaticMesh->ComponentTags.Add(FName("Stock"));
	GunSightStaticMesh->ComponentTags.Add(FName("Sight"));

	
	AGunAttempt::GetComponents<UStaticMeshComponent>(comps);
	

}

// Called when the game starts or when spawned
void AGunAttempt::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AGunAttempt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

