// Copyright George Fitch

#include "Public/ChooseNextWaypoint.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"

#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	/// Get owning guard
	auto GuardPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (!ensure(GuardPawn)) { return EBTNodeResult::Failed; }

	/// Get patrol route component
	auto PatrolRouteComp = GuardPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRouteComp)) { return EBTNodeResult::Failed; }

	/// Get patrol points
	auto PatrolPoints = PatrolRouteComp->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is missing patrol points."), *GuardPawn->GetName())
			return EBTNodeResult::Failed;
	}

	/// Get current waypoint index
	auto Index = BlackboardComp->GetValueAsInt(IndexKeySelector.SelectedKeyName);

	/// Get current patrol point
	auto PatrolPoint = PatrolPoints[Index];

	/// Set waypoint
	BlackboardComp->SetValueAsObject(WaypointKeySelector.SelectedKeyName, PatrolPoint);

	// UE_LOG(LogTemp, Warning, TEXT("%s traveling to %s (%i)"), *Guard->GetName(), *PatrolPoint->GetName(), Index)

	/// Increment index
	Index = (Index + 1) % PatrolPoints.Num();

	/// Set next waypoint index
	BlackboardComp->SetValueAsInt(IndexKeySelector.SelectedKeyName, Index);

	return EBTNodeResult::Succeeded;
}
