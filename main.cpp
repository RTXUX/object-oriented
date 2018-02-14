#include <iostream>
#include "constants.h"
#include "World.h"

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    World world;
    Elevator elevator(world);
    Scheduler scheduler(world);
    world.setElevator(&elevator);
    world.setScheduler(&scheduler);
    int requestTime, initialFloor, destination;
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        scanf("%d %d %d", &requestTime, &initialFloor, &destination);
        if (destination == 0) destination = 10;
        world.getPendingPassengers().emplace_back(requestTime, initialFloor, destination);
    }
    printf("%d", world.run());
    return 0;
}