#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor1.generated.h"

UCLASS()
class MOVEACTOR_API AMoveActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoveActor1();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor1|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MoveActor1|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor1|Properties")
	float moveSpeed;

	FVector startLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor1|Properties")
	FVector endLocation;

	bool isGo;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
