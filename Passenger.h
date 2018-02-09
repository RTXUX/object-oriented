//
// Created by rtxux on 2018/2/9.
//

#ifndef OBJECT_ORIENTED_PASSENGER_H
#define OBJECT_ORIENTED_PASSENGER_H


class Passenger {
private:
public:
    Passenger(int requestTime, int initialFloor, int destinstaion);

    static Passenger create(int requestTime, int initialFloor, int destination);

private:
    int requestTime;
    int initialFloor;
    int destinstaion;
public:
    int getRequestTime() const;

    void setRequestTime(int requestTime);

    int getInitialFloor() const;

    void setInitialFloor(int initialFloor);

    int getDestinstaion() const;

    void setDestinstaion(int destinstaion);


};


#endif //OBJECT_ORIENTED_PASSENGER_H
