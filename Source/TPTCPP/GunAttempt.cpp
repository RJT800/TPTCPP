// Fill out your copyright notice in the Description page of Project Settings.


#include "GunAttempt.h"

// Sets default values
AGunAttempt::AGunAttempt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GunFrame = CreateDefaultSubobject<USceneComponent>(TEXT("GunFrame"));
	GunFrame->SetupAttachment(RootComponent);
	/*GunBaseStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunBaseStaticMesh"));
	GunBarrelStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunBarrelStaticMesh"));
	GunStockStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunStockStaticMesh"));
	GunSightStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunSightStaticMesh"));*/
	//Pool = CreateDefaultSubobject<UDataAsset>(TEXT("Pool"));
	//GunBaseStaticMesh->ComponentTags.Add(FName("Base"));
	//GunBarrelStaticMesh->ComponentTags.Add(FName("Barrel"));
	//GunStockStaticMesh->ComponentTags.Add(FName("Stock"));
	//GunSightStaticMesh->ComponentTags.Add(FName("Sight"));


	//AGunAttempt::GetComponents<UStaticMeshComponent>(comps);
	

}

// Called when the game starts or when spawned
void AGunAttempt::BeginPlay()
{
	int randomNumber = FMath::RandRange(0, GunBaseStaticMesh->MeshPoolTest.Num() - 1);
	UStaticMesh* BasePart = GunBaseStaticMesh->MeshPoolTest[randomNumber];

	randomNumber = FMath::RandRange(0, GunBarrelStaticMesh->MeshPoolTest.Num() - 1);
	UStaticMesh* BarrelPart = GunBarrelStaticMesh->MeshPoolTest[randomNumber];

	randomNumber = FMath::RandRange(0, GunStockStaticMesh->MeshPoolTest.Num() - 1);
	UStaticMesh* StockPart = GunStockStaticMesh->MeshPoolTest[randomNumber];

	randomNumber = FMath::RandRange(0, GunSightStaticMesh->MeshPoolTest.Num() - 1);
	UStaticMesh* SightPart = GunSightStaticMesh->MeshPoolTest[randomNumber];

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, FString::Printf(TEXT("Here")));

	
	//AActor* GunCore = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), GetActorLocation(), FRotator(), FActorSpawnParameters());
	//AActor* GunCore = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), GetLocation(), FRotator(), FActorSpawnParameters());
	//AActor* GunCore = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), GetTransform(), FActorSpawnParameters());
	//AActor* GunCore = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), GetActorTransform(), FActorSpawnParameters());
	//AActor* GunCore = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), FTransform(), FActorSpawnParameters());
	//AActor* GunCore = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), FVector(), FRotator(), FActorSpawnParameters());
	AActor* GunCore = GetWorld()->SpawnActor<AActor>(TSubclassOf<AActor>(), GetActorTransform(), FActorSpawnParameters());
	//AActor* GunCore = GetWorld()->SpawnActorAbsolute(TSubclassOf<AActor*>(), GetFTransform(), FActorSpawnParameters());

	FActorSpawnParameters ExtraArguments = FActorSpawnParameters();
	ExtraArguments.Owner = GunCore;

	//AActor* GunBarrel = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), GetActorLocation(), FRotator(), ExtraArguments);
	//AActor* GunStock = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), GetActorLocation(), FRotator(), ExtraArguments);
	//AActor* GunSight = GetWorld()->SpawnActor(TSubclassOf<AActor*>(), GetActorLocation(), FRotator(), ExtraArguments);

	AActor* GunBarrel = GetWorld()->SpawnActor<AActor>(TSubclassOf<AActor>(), GetActorTransform(), ExtraArguments);
	AActor* GunStock = GetWorld()->SpawnActor<AActor>(TSubclassOf<AActor>(), GetActorTransform(), ExtraArguments);
	AActor* GunSight = GetWorld()->SpawnActor<AActor>(TSubclassOf<AActor>(), GetActorTransform(), ExtraArguments);

	//UStaticMeshComponent* GunBasePart = GunCore->AddComponent(BasePart,false,Transform,ComponentClass)
	GunCore->AddComponentByClass(TSubclassOf<UStaticMeshComponent>(), false, GetActorTransform(), true);

	GunCore->GetComponentByClass<UStaticMeshComponent>()->SetStaticMesh(BasePart);
	GunBarrel->GetComponentByClass<UStaticMeshComponent>()->SetStaticMesh(BarrelPart);
	GunStock->GetComponentByClass<UStaticMeshComponent>()->SetStaticMesh(StockPart);
	GunSight->GetComponentByClass<UStaticMeshComponent>()->SetStaticMesh(SightPart);


	TArray<AActor*> templateChildren;
	Cast<AActor>(GunTemplate)->GetAllChildActors(templateChildren, true);

	for (int i = 0; i < templateChildren.Num(); i++)
	{
		AActor* gunPart = templateChildren[i];

		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, FString::Printf(TEXT("Here")));
		if (gunPart->ActorHasTag("Barrel"))
		{
			GunCore->SetActorLocation(gunPart->GetActorLocation());
		}
		else if (gunPart->ActorHasTag("Stock"))
		{
			GunCore->SetActorLocation(gunPart->GetActorLocation());
		}
		else if (gunPart->ActorHasTag("Sight"))
		{
			GunCore->SetActorLocation(gunPart->GetActorLocation());
		}
	}


	Super::BeginPlay();	
}

// Called every frame
void AGunAttempt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

