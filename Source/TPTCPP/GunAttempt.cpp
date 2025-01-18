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
	//GunBaseStaticMesh->SetupAttachment(RootComponent);
	GunBaseStaticMesh->ComponentTags.Add(FName("Base"));
	GunBarrelStaticMesh->ComponentTags.Add(FName("Barrel"));
	GunStockStaticMesh->ComponentTags.Add(FName("Stock"));
	GunSightStaticMesh->ComponentTags.Add(FName("Sight"));
	//comps.Add(GunBaseStaticMesh);
	//comps.Add(GunBarrelStaticMesh);
	
	AGunAttempt::GetComponents<UStaticMeshComponent>(comps);
	
	//BaseMap.Add("Base", GunBarrelStaticMesh);
	//StaticMesh->SetRelativeScale3D({ 1.0f,1.0f,1.0f });
}

// Called when the game starts or when spawned
void AGunAttempt::BeginPlay()
{

	//IdontKnowanymoreman.Add("Base", )
	//if (auto j = GetPrimaryAssetId())
	//UTestDataAsset* DATest = LoadObject()
	//get all static mesh components 
	//GetComponentByClass()
	//TArray<UStaticMeshComponent*> comps;
	//comps.
	//GetComponents(comps);
	
	//FMath::RandRange(0, 5);


	//GetComponentsByTag(UActorComponent::StaticClass(), FName("Base"));
	//GetComponentsByTag(this, FName("Base"));
	Super::BeginPlay();
	//StaticMesh->SetStaticMesh(UStaticMesh* )
	
}

// Called every frame
void AGunAttempt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

