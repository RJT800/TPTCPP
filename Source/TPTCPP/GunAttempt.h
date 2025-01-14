// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunAttempt.generated.h"

class UStaticMeshComponent;

UCLASS()
class TPTCPP_API AGunAttempt : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMesh*> MeshPool;




	
	
	
public:	
	// Sets default values for this actor's properties
	AGunAttempt();

	struct GunBase
	{
		UStaticMeshComponent a;
		UStaticMeshComponent b;
		UStaticMeshComponent c;
	};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;





	void getTag()
	{

	}


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BaseMap")
	TMap<FName, UStaticMeshComponent*> BaseMap;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
