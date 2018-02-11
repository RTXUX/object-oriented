//
// Created by rtxux on 2018/2/9.
//

#ifndef OBJECT_ORIENTED_SCHEDULER_H
#define OBJECT_ORIENTED_SCHEDULER_H

#include "World.h"

class Scheduler {
private:
    World &world;
    int stopped = 1;
    int target = 1;
public:
    Scheduler(World &world);

    int decide();

};


#endif //OBJECT_ORIENTED_SCHEDULER_H
