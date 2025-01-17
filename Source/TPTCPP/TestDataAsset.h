// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Containers/Map.h"
#include "TestDataAsset.generated.h"


//USTRUCT(BlueprintType)
//struct FGunBasePool : public FTableRowBase
//{
//	GENERATED_BODY()
//
//	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
//	//FText DisplayName;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
//	FText TagName;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
//	UStaticMesh* Mesh;
//
//	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
//};

/**
 * 
 */
UCLASS()
class TPTCPP_API UTestDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UStaticMesh*> MeshPoolTest;

//
//	USTRUCT(BlueprintType)
//	struct GunBasePool : public FTableRowBase
//{
//
//	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
//	//FText DisplayName;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
//	FText TagName;
//
//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
//	UStaticMesh* Mesh;
//
//	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
//};

	//UProperty(EditAnywhere)
		//TMap<FName, FGunBasePool> AssetItems;


	
};
