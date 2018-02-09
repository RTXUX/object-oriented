//
// Created by rtxux on 2018/2/9.
//

#include "Scheduler.h"

Scheduler::Scheduler(World &world) : world(world) {}

int Scheduler::decide() {
    int pending = 0;
    auto triggeredPassengers = this->world.getTriggeredPassengers();
    int currentFloor = world.getElevator()->getCurrentFloor();
    auto insidePassengers = world.getElevator()->getInsidePassengers();
    //处理已触发请求的入厢
    for (auto iter = triggeredPassengers.begin(); iter != triggeredPassengers.end(); iter++) {
        if ((*iter).getInitialFloor() == currentFloor) {
            if ((*iter).getDestinstaion() == 10 && (lastDecision == 1 || lastDecision == 0)) {
                pending = 1;
                break;
            }
            if ((*iter).getDestinstaion() == 1 && (lastDecision == -1 || lastDecision == 0)) {
                pending = 1;
                break;
            }
        }
    }
    //需要入厢
    if (pending == 1) {
        return 0;
    }
    //刚到达边界
    if (((currentFloor == 1) || (currentFloor == 10)) && lastDecision != 0) {
        for (auto iter = insidePassengers.begin(); iter != insidePassengers.end(); iter++) {
            if ((*iter).getDestinstaion() == currentFloor) {
                lastDecision = 0;
                return 0;
            }
        }
    }
    //已在边界停留
    if (lastDecision == 0) {
        if (triggeredPassengers.size() == 0 && world.getElevator()->getInsidePassengers().size() == 0) {
            return 0;
        } else {
            if (currentFloor == 1) {
                lastDecision = 1;
                return 1;
            } else {
                lastDecision = -1;
                return -1;
            }
        }
    }


    return lastDecision;
}
