//
// Created by rtxux on 2018/2/9.
//

#ifndef OBJECT_ORIENTED_ELEVATOR_H
#define OBJECT_ORIENTED_ELEVATOR_H

#include <vector>
#include "World.h"
#include "Passenger.h"

using std::vector;

class Elevator {
private:
    World &world;
    int delivered = 0;
public:
    int getDelivered() const;

public:
    Elevator(World &world);

    int getCurrentFloor() const;

    const vector<Passenger> &getInsidePassengers() const;

    void moveUp();

    void moveDown();

    void unloadPassengers(int &totalWaitTime);

    void loadPassenger(Passenger &&passenger);

private:
    int currentFloor = 1;
    vector<Passenger> insidePassengers;

};


#endif //OBJECT_ORIENTED_ELEVATOR_H
