// Copyright George Fitch

#include "Public/ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("ExecuteTask"))

	return EBTNodeResult::Succeeded;
}
