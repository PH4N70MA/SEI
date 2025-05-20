#ifndef MY_TASKS_H
#define MY_TASKS_H

#include <Arduino.h>
#include <float.h>
#include <config.h>
#include <own_stdio.h>
#include <DHT.h>
#include <GyverPID.h>

static GyverPID regulator(P_COIFFICIENT, I_COIFFICIENT, D_COIFFICIENT);
static DHT dht(DHTPIN, DHTTYPE);

void systemSetup(void);
void parsing(const char *command);
void getTemperatureAndHumidity(void);

#endif // MY_TASKS