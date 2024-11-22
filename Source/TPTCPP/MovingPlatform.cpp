// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Curves/CurveFloat.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(RootComponent);
	//StaticMesh->SetRelativeScale3D({ 1.0f, 1.0f, 0.1f });

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AMovingPlatform::OnTriggerOverlapBegin);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AMovingPlatform::OnTriggerOverlapEnd);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Verify Curve
	if (MovementCurve == nullptr) return;

	//Increase / Decrease Progress
	if (bIsMovingForward)
		Progress += DeltaTime;
	else
		Progress -= DeltaTime;
	Progress = FMath::Clamp(Progress, 0, 1);

	//Sample Curve
	float value = MovementCurve->GetFloatValue(Progress);

	//apply movement
	FVector newLocation = FMath::Lerp(FVector::Zero(), EndPosition, value);
	StaticMesh->SetRelativeLocation(newLocation);
	//Update Platform position
}

void AMovingPlatform::OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult&)
{
	//To Remember/Save: GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("")));
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("Forward")));
	Forward();
}

void AMovingPlatform::OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("Reverse")));
	Reverse();
}

void AMovingPlatform::Forward()
{
	bIsMovingForward = true;
}

void AMovingPlatform::Reverse()
{
	bIsMovingForward = false;
}

