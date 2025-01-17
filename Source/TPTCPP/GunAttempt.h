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
	UStaticMeshComponent* GunBaseStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* GunBarrelStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* GunStockStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* GunSightStaticMesh;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//TMap<FName, UDataAsset> GunPartPool;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//TArray<UStaticMesh*> BaseMeshPool;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//TArray<UStaticMesh*> BarrelMeshPool;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//TArray<UStaticMeshComponent*> comps;


	//LoadObject<UStaticMesh>()


	
	
	
public:	
	// Sets default values for this actor's properties
	AGunAttempt();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	//UTestDataAsset 

	//struct GunBase
	//{
	//	UStaticMeshComponent a;
	//	UStaticMeshComponent b;
	//	UStaticMeshComponent c;
	//};

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseMap")
	//TMap<FName, UStaticMeshComponent*> BaseMap;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseMap")
	//TArray<UStaticMesh*> GunPartPool;
	

	//you cant use a tarray as a value in a tmap
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseMap")
	//TMap<FName, TArray<UStaticMesh*>> GunPartPools;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;





	//void getTag()
	//{

	//}



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
