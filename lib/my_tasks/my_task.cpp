#include "my_task.h"

void setUp(void)
{
    own_stdio_setup();
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

void stateMachineTask(void)
{
    static systemState state = STOP;

    state = state == RUN ? STOP : RUN;

    switch (state)
    {
    case RUN:
        digitalWrite(LED_PIN, HIGH);
        printf("\nSystem State: %d\n", digitalRead(LED_PIN));
        break;
    case STOP:
        digitalWrite(LED_PIN, LOW);
        printf("\nSystem State: %d\n", digitalRead(LED_PIN));
        break;
    }
}

void buttonPressTask(void)
{
    static uint32_t nextTimeTask1 = 0;
    static bool ledLastState = false;

    if(millis() >= nextTimeTask1) 
    {
        if(!digitalRead(BUTTON_PIN) & !ledLastState & ((millis() - nextTimeTask1 ) >= BUTTON_REFRESH_TIME))
        {
            ledLastState = true;
            nextTimeTask1 = millis() + BUTTON_REFRESH_TIME;
        }
        else if(digitalRead(BUTTON_PIN) & ledLastState & ((millis() - nextTimeTask1 ) >= BUTTON_REFRESH_TIME))
        {
            ledLastState = false;
            stateMachineTask();
            
            nextTimeTask1 = millis() + BUTTON_REFRESH_TIME;
        }
    }
}