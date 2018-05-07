// Copyright George Fitch

#include "Public/ChooseNextWaypoint.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	auto Index = BlackboardComp->GetValueAsInt(IndexKeySelector.SelectedKeyName);

	UE_LOG(LogTemp, Warning, TEXT("Index: %i"), Index)

	return EBTNodeResult::Succeeded;
}
