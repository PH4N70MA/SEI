#ifndef MY_TASKS_H
#define MY_TASKS_H

#include <Arduino.h>
#include <float.h>
#include <config.h>
#include <own_stdio.h>
#include <DHT.h>
#include "relay.h"

static Relay heat = Relay(RELAY_ID, RELAY_NAME, RELAY_PIN);
static DHT dht(DHTPIN, DHTTYPE);

void systemSetup(void);
void parsing(const char *command);
void getTemperatureAndHumidity(void);

#endif // MY_TASKS