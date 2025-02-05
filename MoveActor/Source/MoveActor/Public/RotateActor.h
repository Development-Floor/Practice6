#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateActor.generated.h"

UCLASS()
class MOVEACTOR_API ARotateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotateActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotateActor|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "RotateActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateActor|Properties")
	FRotator RotationSpeed;

	virtual void Tick(float DeltaTime) override;
};
