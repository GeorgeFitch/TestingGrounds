// Copyright George Fitch

#include "Public/ChooseNextWaypoint.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "TP_ThirdPerson/PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	/// Get owning guard
	auto Guard = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	if (!ensure(Guard)) { return EBTNodeResult::Failed; }
	auto PatrolPoints = Guard->GetPatrolPoints();

	/// Get current waypoint index
	auto Index = BlackboardComp->GetValueAsInt(IndexKeySelector.SelectedKeyName);

	/// Get current patrol point
	auto PatrolPoint = PatrolPoints[Index];

	// UE_LOG(LogTemp, Warning, TEXT("%s traveling to %s (%i)"), *Guard->GetName(), *PatrolPoint->GetName(), Index)

	/// Set waypoint
	BlackboardComp->SetValueAsObject(WaypointKeySelector.SelectedKeyName, PatrolPoint);

	/// Increment index
	Index = (Index + 1) % PatrolPoints.Num();

	/// Set next waypoint index
	BlackboardComp->SetValueAsInt(IndexKeySelector.SelectedKeyName, Index);

	return EBTNodeResult::Succeeded;
}
