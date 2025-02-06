// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestDataAsset.h"
#include "Containers/Map.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/AssetManager.h"
#include "Engine/DataAsset.h"


#include "GunAttempt.generated.h"

class UStaticMeshComponent;

UCLASS()
class TPTCPP_API AGunAttempt : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USceneComponent* GunFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UTestDataAsset* GunBaseStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UTestDataAsset* GunBarrelStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UTestDataAsset* GunStockStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UTestDataAsset* GunSightStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> comps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UDataAsset* Pool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> GunTemplate;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//UDataAssetMap PoolList;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TMap<FName, UTestDataAsset*> DataAssetMap;
	
	
public:	
	// Sets default values for this actor's properties
	AGunAttempt();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
