#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <my_tasks.h>
#include "config.h"
#include "relay.h"

Relay red = Relay(RELAY_ID_RED, RELAY_NAME_RED, RELAY_PIN_RED);
Relay green = Relay(RELAY_ID_GREEN, RELAY_NAME_GREEN, RELAY_PIN_GREEN);
Relay blue = Relay(RELAY_ID_BLUE, RELAY_NAME_BLUE, RELAY_PIN_BLUE);

void setup();
void loop();

#endif // MAIN_H
