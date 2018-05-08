// Copyright George Fitch

#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const {
	return this->PatrolPoints;
}
