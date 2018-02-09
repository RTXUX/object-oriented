//
// Created by rtxux on 2018/2/9.
//

#include "Passenger.h"

int Passenger::getRequestTime() const {
    return requestTime;
}

void Passenger::setRequestTime(int requestTime) {
    Passenger::requestTime = requestTime;
}

int Passenger::getInitialFloor() const {
    return initialFloor;
}

void Passenger::setInitialFloor(int initialFloor) {
    Passenger::initialFloor = initialFloor;
}

int Passenger::getDestinstaion() const {
    return destinstaion;
}

void Passenger::setDestinstaion(int destinstaion) {
    Passenger::destinstaion = destinstaion;
}

Passenger::Passenger(int requestTime, int initialFloor, int destinstaion) : requestTime(requestTime),
                                                                            initialFloor(initialFloor),
                                                                            destinstaion(destinstaion) {}

Passenger Passenger::create(int requestTime, int initialFloor, int destination) {
    return Passenger(requestTime, initialFloor, destination);
}
