#include "my_task.h"

void buttonLedTaskSetup(void)
{
    pinMode(ON_OFF_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_LED, OUTPUT);
}

void ledIntermittentTaskSetup(void)
{
    pinMode(BLUE_LED, OUTPUT);
}

void buttonVariableTaskSetup(void)
{
    pinMode(UP_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_BUTTON, INPUT_PULLUP);
}

void buttonLedTask(void *pvParameters)
{
    static uint32_t nextTimeTask1 = 0;
    static bool ledLastState = false;

    if(millis() >= nextTimeTask1) 
    {
        if(!digitalRead(ON_OFF_BUTTON) & !ledLastState & (millis() - nextTimeTask1 ) >= BUTTON_REFRESH_TIME)
        {
            ledLastState = true;
            nextTimeTask1 = millis() + BUTTON_REFRESH_TIME;
        }
        if(digitalRead(ON_OFF_BUTTON) & ledLastState & (millis() - nextTimeTask1 ) >= BUTTON_REFRESH_TIME)
        {
            ledLastState = false;
            digitalWrite(GREEN_LED, !digitalRead(GREEN_LED));
            nextTimeTask1 = millis() + BUTTON_REFRESH_TIME;
        }
    }
}

void ledIntermittentTask(void *pvParameters)
{
    if (digitalRead(GREEN_LED)) return;

    static uint32_t nextTimeTask2 = 0;
    static bool lastState = false;
    
    if(millis() >= nextTimeTask2)
    {

    }
}