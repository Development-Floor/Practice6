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

	// ������ ����
	if (isGo)
	{
		AddActorWorldOffset((endLocation - currentLocation).GetSafeNormal() * DeltaTime * moveSpeed);

		// ���� �����ϸ� ���� �ٲٱ�
		if (FVector::Distance(startLocation, GetActorLocation()) >= FVector::Distance(startLocation, endLocation))
		{
			isGo = false;
		}
	}

	// �ڷ� ����
	else
	{
		AddActorWorldOffset((startLocation - currentLocation).GetSafeNormal() * DeltaTime * moveSpeed);

		// ���� �����ϸ� ���� �ٲٱ�
		if (FVector::Distance(endLocation, GetActorLocation()) >= FVector::Distance(startLocation, endLocation))
		{
			isGo = true;
		}
	}
}

