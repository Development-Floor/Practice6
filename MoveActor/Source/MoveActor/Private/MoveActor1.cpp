#include "MoveActor1.h"

AMoveActor1::AMoveActor1()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	isGo = true;
}

void AMoveActor1::BeginPlay()
{
	Super::BeginPlay();
	
	startLocation = GetActorLocation();
}

void AMoveActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector currentLocation = GetActorLocation();

	// 앞으로 가기
	if (isGo)
	{
		AddActorWorldOffset((endLocation - currentLocation).GetSafeNormal() * DeltaTime * moveSpeed);

		// 끝에 도달하면 방향 바꾸기
		if (FVector::Distance(startLocation, GetActorLocation()) >= FVector::Distance(startLocation, endLocation))
		{
			isGo = false;
		}
	}

	// 뒤로 가기
	else
	{
		AddActorWorldOffset((startLocation - currentLocation).GetSafeNormal() * DeltaTime * moveSpeed);

		// 끝에 도달하면 방향 바꾸기
		if (FVector::Distance(endLocation, GetActorLocation()) >= FVector::Distance(startLocation, endLocation))
		{
			isGo = true;
		}
	}
}

