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

void buttonLedTask(void)
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

void ledIntermittentTask(void)
{
    if (!digitalRead(GREEN_LED)) 
    {
        bufferCounter = RESET;
        return;
    }

    static uint32_t nextTimeTask2 = RESET;

    if(millis() >= nextTimeTask2)
    {
      if (bufferCounter != globalCounter)
      {
        if (!digitalRead(GREEN_LED))
        {
          digitalWrite(GREEN_LED, !digitalRead(GREEN_LED));
          nextTimeTask2 = millis() + BLUE_LED_ON_TIME;
        }
        else if (digitalRead(GREEN_LED))
        {
          digitalWrite(GREEN_LED, !digitalRead(GREEN_LED));
          nextTimeTask2 = millis() + BLUE_LED_OFF_TIME;
          ++bufferCounter;
        }
      }
      else
      {
        nextTimeTask2 = millis() + BLUE_LED_PAUSE_TIME;
        bufferCounter = RESET;
      }
    }
}

void buttonVariableTaskSetup(void)
{
    static uint32_t nextTimeTask3 = 0;
    static bool buttonLastState = false;

    if(millis() >= nextTimeTask3) 
    {
        if(!digitalRead(UP_BUTTON) & !buttonLastState & (millis() - nextTimeTask3 ) >= BUTTON_REFRESH_TIME)
        {
            buttonLastState = true;
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        if(digitalRead(UP_BUTTON) & buttonLastState & (millis() - nextTimeTask3 ) >= BUTTON_REFRESH_TIME)
        {
            buttonLastState = false;
            digitalWrite(GREEN_LED, !digitalRead(GREEN_LED));
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
    }
}