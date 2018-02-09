//
// Created by rtxux on 2018/2/9.
//

#ifndef OBJECT_ORIENTED_WORLD_H
#define OBJECT_ORIENTED_WORLD_H

class World;

class Elevator;

class Scheduler;

#include "Elevator.h"
#include "Scheduler.h"
#include "Passenger.h"

using std::vector;

class World {
private:
    int time = 0;
    Elevator *elevator;
    Scheduler *scheduler;
    vector<Passenger> pendingPassengers;
    vector<Passenger> triggeredPassengers;
public:
    int getTime() const;

    Elevator *getElevator() const;

    Scheduler *getScheduler() const;

    World();

    void setElevator(Elevator *elevator);

    void setScheduler(Scheduler *scheduler);

    vector<Passenger> &getPendingPassengers();

    const vector<Passenger> &getTriggeredPassengers() const;

    int run();
};


#endif //OBJECT_ORIENTED_WORLD_H
