#ifndef MY_TASKS_H
#define MY_TASKS_H

#include <Arduino.h>
#include <config.h>
#include <own_stdio.h>
#include "GyverMotor2.h"

void systemSetup(void);
void parsing(const char *command);
void motorDisplay(void);
void buttonTask(void);

#endif // MY_TASKS