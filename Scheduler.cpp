//
// Created by rtxux on 2018/2/9.
//

#include <cstdlib>

using namespace std;

#include "Scheduler.h"

enum {
    UP, DOWN, STOP
};

Scheduler::Scheduler(World &world) : world(world) {}

int Scheduler::decide() {
    int currentFloor = world.getElevator()->getCurrentFloor();
    auto insidePassengers = world.getElevator()->getInsidePassengers();
    auto triggeredPassengers = world.getTriggeredPassengers();
    int destNum[3]{0}, destTime[3]{0};
    int upFloor = 0, downFloor = 11, upExtra = 0, downExtra = 0, stopCount = 0;
    for (auto iter = insidePassengers.begin(); iter != insidePassengers.end(); iter++) {
        int destination = iter.base()->getDestinstaion();
        upFloor = max(upFloor, destination);
        downFloor = min(downFloor, destination);
        if (destination > currentFloor) {
            destNum[UP]++;
        } else if (destination < currentFloor) {
            destNum[DOWN]++;
        } else {
            destNum[STOP]++;
        }
    }

    for (auto iter = triggeredPassengers.begin(); iter != triggeredPassengers.end(); iter++) {
        int initialFloor = iter.base()->getInitialFloor();
        upFloor = max(upFloor, initialFloor);
        downFloor = min(downFloor, initialFloor);
        if (initialFloor > currentFloor) {
            destNum[UP]++;
        } else if (initialFloor < currentFloor) {
            destNum[DOWN]++;
        } else {
            destNum[STOP]++;
        }
    }

    for (auto iter = insidePassengers.begin(); iter != insidePassengers.end(); iter++) {
        int destination = iter.base()->getDestinstaion();
        if (destNum[UP]) {
            destTime[UP] += abs(upFloor - currentFloor) + abs(upFloor - destination);
            if (destination != upFloor) {
                destTime[UP]++;
            }
        }

        if (destNum[DOWN]) {
            destTime[DOWN] += abs(downFloor - currentFloor) + abs(downFloor - destination);
            if (destination != downFloor) {
                destTime[DOWN]++;
            }
        }

        if (destNum[STOP]) {
            if (destination != currentFloor) {
                destTime[STOP]++;
            } else {
                stopCount++;
            }
        }
    }

    for (auto iter = triggeredPassengers.begin(); iter != triggeredPassengers.end(); iter++) {
        int initialFloor = iter.base()->getInitialFloor();
        int destination = iter.base()->getDestinstaion();
        if (destNum[UP]) {
            destTime[UP] += abs(upFloor - currentFloor) + abs(upFloor - initialFloor) + abs(destination - initialFloor);
            if (destination != upFloor) {
                destTime[UP]++;
            }
        }

        if (destNum[DOWN]) {
            destTime[DOWN] +=
                    abs(downFloor - currentFloor) + abs(downFloor - initialFloor) + abs(destination - initialFloor);
            if (destination != downFloor) {
                destTime[DOWN]++;
            }
        }

        if (destNum[STOP]) {
            if (initialFloor == currentFloor) {
                stopCount++;
                if (destination == 1) {
                    upExtra = currentFloor - destination;
                } else if (destination == 10) {
                    downExtra = destination - currentFloor;
                }
            }

        }

    }
    if (!destNum[UP] && !destNum[DOWN] && !destNum[STOP]) {
        return 0;
    } else if (!destNum[UP] && !destNum[DOWN]) {
        return 0;
    } else if (!destNum[STOP] && !destNum[DOWN]) {
        return 1;
    } else if (!destNum[UP] && !destNum[STOP]) {
        return -1;
    } else if (!destNum[UP]) {
        if (destTime[STOP] * (downExtra + 1) > stopCount * ((abs(downFloor - currentFloor)) * 2 + 1)) {
            return -1;
        } else {
            return 0;
        }
    } else if (!destNum[DOWN]) {
        if (destTime[STOP] * (upExtra + 1) > stopCount * ((abs(upFloor - currentFloor)) * 2 + 1)) {
            return 1;
        } else {
            return 0;
        }
    } else if (!destNum[STOP]) {
        if (destTime[UP] < destTime[DOWN]) {
            return 1;
        } else {
            return -1;
        }
    } else {
        if (destTime[UP] < destTime[DOWN]) {
            if (destTime[STOP] * (upExtra + 1) > stopCount * ((abs(upFloor - currentFloor)) * 2 + 1)) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (destTime[STOP] * (downExtra + 1) > stopCount * ((abs(downFloor - currentFloor)) * 2 + 1)) {
                return -1;
            } else {
                return 0;
            }
        }
    }


}
