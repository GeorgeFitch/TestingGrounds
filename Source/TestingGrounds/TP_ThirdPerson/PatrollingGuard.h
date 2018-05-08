// Copyright George Fitch

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()	
	
public:
	TArray<AActor*> GetPatrolPoints();

protected:
	UPROPERTY(EditInstanceOnly)
		TArray<AActor*> PatrolPoints;
	
};
