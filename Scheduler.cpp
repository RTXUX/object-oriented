//
// Created by rtxux on 2018/2/9.
//
#include <cmath>
#include "Scheduler.h"

using namespace std;
Scheduler::Scheduler(World &world) : world(world) {}

int Scheduler::decide() {
    int pending = 0;
    auto triggeredPassengers = this->world.getTriggeredPassengers();
    int currentFloor = world.getElevator()->getCurrentFloor();
    auto insidePassengers = world.getElevator()->getInsidePassengers();
    for (auto iter = insidePassengers.begin(); iter != insidePassengers.end(); iter++) {
        if (iter.base()->getDestinstaion() == currentFloor) {
            return 0;
        }
    }
    if (target == currentFloor) {
        if (!stopped) {
            stopped = 1;
            return 0;
        } else {
            if (currentFloor == 1) {
                if (!insidePassengers.empty()) {
                    target = 10;
                }
                for (auto iter = triggeredPassengers.begin(); iter != triggeredPassengers.end(); iter++) {
                    target = max(target, iter.base()->getInitialFloor());
                }

            } else if (currentFloor == 10) {
                if (!insidePassengers.empty()) {
                    target = 1;
                }
                for (auto iter = triggeredPassengers.begin(); iter != triggeredPassengers.end(); iter++) {
                    target = min(target, iter.base()->getInitialFloor());
                }
            }
            /*else{
                int C1=0,C10=0;
                for (auto iter=insidePassengers.begin();iter!=insidePassengers.end();iter++)
                {
                    if (iter.base()->getDestinstaion()==10)
                    {
                        C10++;
                    }
                    else
                    {
                        C1++;
                    }
                }
                if(C10>C1)
                {
                    target=10;
                }
                else
                {
                    target=1;
                }
            }*/
        }
    }
    for (auto iter = triggeredPassengers.begin(); iter != triggeredPassengers.end(); iter++) {
        if (iter.base()->getInitialFloor() == currentFloor) {
            if (iter.base()->getDestinstaion() == 10 && target - currentFloor >= 0) {
                target = 10;
                return 0;
            }
            if (iter.base()->getDestinstaion() == 1 && target - currentFloor <= 0) {
                target = 1;
                return 0;
            }
        }
    }
    if (target > currentFloor) {
        return 1;
    }
    if (target < currentFloor) {
        return -1;
    }




}
