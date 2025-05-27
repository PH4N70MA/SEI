#ifndef TASK_H
#define TASK_H

#include <Arduino.h>
#include "config.h"
#include "own_stdio.h"

enum systemState
{
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    S8
};

void setUp(void);
void stateMachineTask(void);

#endif 