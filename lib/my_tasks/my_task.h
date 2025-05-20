#ifndef TASK_H
#define TASK_H

#include <Arduino.h>
#include "config.h"
#include "own_stdio.h"

enum systemState
{
    RUN,
    STOP,
};

void setUp(void);
void buttonPressTask(void);

#endif 