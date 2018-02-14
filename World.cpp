//
// Created by rtxux on 2018/2/9.
//
#include <cstdio>
#include "World.h"
#include "constants.h"

int World::getTime() const {
    return time;
}

Elevator *World::getElevator() const {
    return elevator;
}

Scheduler *World::getScheduler() const {
    return scheduler;
}

vector<Passenger> &World::getPendingPassengers() {
    return pendingPassengers;
}

const vector<Passenger> &World::getTriggeredPassengers() const {
    return triggeredPassengers;
}

void World::setElevator(Elevator *elevator) {
    World::elevator = elevator;
}

void World::setScheduler(Scheduler *scheduler) {
    World::scheduler = scheduler;
}

World::World() {

}

int World::run() {
    int totalWaitTime = 0;
    int lastStop = 0;
    while (true) {
        //已完成所有运输
        if (elevator->getDelivered() == NUM_PASSENGERS) {
            return totalWaitTime;
        }
        //触发请求
        for (auto iter = pendingPassengers.begin(); iter != pendingPassengers.end();) {
            if ((*iter).getRequestTime() <= time) {
                triggeredPassengers.emplace_back(*iter);
                iter = pendingPassengers.erase(iter);
            } else {
                iter++;
            }
        }

        //决策并执行
        switch (scheduler->decide()) {
            //停靠时出厢并进厢
            case 0:
                if (!lastStop) {
                    printf("%d时，停靠在%d层\n", time, elevator->getCurrentFloor());
                }
                elevator->unloadPassengers(totalWaitTime);
                for (auto iter = triggeredPassengers.begin(); iter != triggeredPassengers.end();) {
                    if ((*iter).getInitialFloor() == elevator->getCurrentFloor()) {
                        elevator->loadPassenger(std::move(*iter));
                        iter = triggeredPassengers.erase(iter);
                    } else {
                        iter++;
                    }
                }
                lastStop = 1;
                break;
            case 1:
                elevator->moveUp();
                lastStop = 0;
                break;
            case -1:
                elevator->moveDown();
                lastStop = 0;
                break;
        }
        time++;
    }
}
