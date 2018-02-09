#include <iostream>
#include "constants.h"
#include "World.h"

int main() {
    World world;
    Elevator elevator(world);
    Scheduler scheduler(world);
    world.setElevator(&elevator);
    world.setScheduler(&scheduler);
    int a, b, c;
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (c == 0) c = 10;
        world.getPendingPassengers().emplace_back(a, b, c);
    }
    printf("%d", world.run());
    return 0;
}