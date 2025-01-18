// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Containers/Map.h"
#include "TestDataAsset.generated.h"




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



	
};
