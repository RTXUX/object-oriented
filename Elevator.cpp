//
// Created by rtxux on 2018/2/9.
//
#include <algorithm>
#include "Elevator.h"

Elevator::Elevator(World &world) : world(world) {

}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}


const vector<Passenger> &Elevator::getInsidePassengers() const {
    return insidePassengers;
}

void Elevator::moveDown() {
    currentFloor--;
}

void Elevator::moveUp() {
    currentFloor++;
}

void Elevator::unloadPassengers(int &totalWaitTime) {
    for (auto iter = insidePassengers.begin(); iter != insidePassengers.end();) {
        if ((*iter).getDestinstaion() == this->getCurrentFloor()) {
            totalWaitTime += world.getTime() - (*iter).getRequestTime();
            iter = insidePassengers.erase(iter);
            delivered++;
        } else {
            iter++;
        }
    }
}

void Elevator::loadPassenger(Passenger &&passenger) {
    insidePassengers.emplace_back(passenger);

}

int Elevator::getDelivered() const {
    return delivered;
}
