#include "my_task.h"

void buttonLedTaskSetup(void)
{
    pinMode(ON_OFF_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_LED, OUTPUT);
}

