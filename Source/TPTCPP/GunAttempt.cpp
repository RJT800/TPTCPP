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
	GunBaseStaticMesh->SetupAttachment(GunFrame);

	GunBarrelStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunBarrelStaticMesh"));
	GunBarrelStaticMesh->SetupAttachment(GunFrame);
	
	GunStockStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunStockStaticMesh"));
	GunStockStaticMesh->SetupAttachment(GunFrame);
	
	GunSightStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunSightStaticMesh"));
	GunSightStaticMesh->SetupAttachment(GunFrame);


	GunBaseStaticMesh->ComponentTags.Add(FName("Base"));
	GunBarrelStaticMesh->ComponentTags.Add(FName("Barrel"));
	GunStockStaticMesh->ComponentTags.Add(FName("Stock"));
	GunSightStaticMesh->ComponentTags.Add(FName("Sight"));

}

// Called when the game starts or when spawned
void AGunAttempt::BeginPlay()
{
	int randomNumber = FMath::RandRange(0, GunBaseStaticMeshPool->MeshPoolTest.Num() - 1);
	UStaticMesh* BasePart = GunBaseStaticMeshPool->MeshPoolTest[randomNumber];

	randomNumber = FMath::RandRange(0, GunBarrelStaticMeshPool->MeshPoolTest.Num() - 1);
	UStaticMesh* BarrelPart = GunBarrelStaticMeshPool->MeshPoolTest[randomNumber];

	randomNumber = FMath::RandRange(0, GunStockStaticMeshPool->MeshPoolTest.Num() - 1);
	UStaticMesh* StockPart = GunStockStaticMeshPool->MeshPoolTest[randomNumber];

	randomNumber = FMath::RandRange(0, GunSightStaticMeshPool->MeshPoolTest.Num() - 1);
	UStaticMesh* SightPart = GunSightStaticMeshPool->MeshPoolTest[randomNumber];

	TArray<UStaticMeshComponent*> MeshComponents;
	this->GetComponents(MeshComponents);

	for (int i = 0; i < MeshComponents.Num(); i++)
	{
		UStaticMeshComponent* gunPart = MeshComponents[i];		

		if (gunPart->ComponentHasTag("Base"))
		{
			gunPart->SetStaticMesh(BasePart);
			gunPart->SetRelativeLocation(FVector(0,0,0),false, (FHitResult*)nullptr, ETeleportType::ResetPhysics);
		}
		else if (gunPart->ComponentHasTag("Barrel"))
		{
			gunPart->SetStaticMesh(BarrelPart);
			gunPart->SetRelativeLocation(FVector(150,0,0),false, (FHitResult*)nullptr, ETeleportType::ResetPhysics);
		}
		else if (gunPart->ComponentHasTag("Stock"))
		{
			gunPart->SetStaticMesh(StockPart);
			gunPart->SetRelativeLocation(FVector(-150,0,0),false, (FHitResult*)nullptr, ETeleportType::ResetPhysics);
		}
		else if (gunPart->ComponentHasTag("Sight"))
		{
			gunPart->SetStaticMesh(SightPart);
			gunPart->SetRelativeLocation(FVector(0,0,150),false, (FHitResult*)nullptr, ETeleportType::ResetPhysics);
		}
	}
	Super::BeginPlay();	
}

// Called every frame
void AGunAttempt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

