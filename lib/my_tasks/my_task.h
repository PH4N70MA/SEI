#ifndef TASK_H
#define TASK_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <stdio.h>
#include <Arduino.h>
#include <semphr.h>
#include <queue.h>

#include <config.h>

void freeRTOSInit(void);
void buttonLedTaskSetup(void);
void buttonLedTask(void *pvParameters);
void sincronizedTaskSetup(void);
void sincronizedTask(void *pvParameters);
void asyncTask(void *pvParameters);

#endif 