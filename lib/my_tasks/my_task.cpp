#include "my_task.h"

void setUp(void)
{
    own_stdio_setup();
    
    pinMode(GREEN_LIGHT_HORIZONTAL, OUTPUT);
    pinMode(ORANGE_LIGHT_HORIZONTAL, OUTPUT);
    pinMode(RED_LIGHT_HORIZONTAL, OUTPUT);

    pinMode(BUTTON_PIN_HORIZONTAL, INPUT_PULLUP);

    pinMode(GREEN_LIGHT_VERTICAL, OUTPUT);
    pinMode(ORANGE_LIGHT_VERTICAL, OUTPUT);
    pinMode(RED_LIGHT_VERTICAL, OUTPUT);

    pinMode(BUTTON_PIN_VERTICAL, INPUT_PULLUP);
}

void greenVerticall(void)
{
    digitalWrite(GREEN_LIGHT_VERTICAL, HIGH);
    digitalWrite(ORANGE_LIGHT_VERTICAL, LOW);
    digitalWrite(RED_LIGHT_VERTICAL, LOW);

    digitalWrite(GREEN_LIGHT_HORIZONTAL, LOW);
    digitalWrite(ORANGE_LIGHT_HORIZONTAL, LOW);
    digitalWrite(RED_LIGHT_HORIZONTAL, HIGH);
}

void greenVerticalIntermitent(void)
{
    static uint32_t nextTime = 0;

    if(millis() >= nextTime)
        {
            if(digitalRead(GREEN_LIGHT_VERTICAL))
            {
                digitalWrite(GREEN_LIGHT_VERTICAL, LOW);
                digitalWrite(RED_LIGHT_HORIZONTAL, LOW);
            }
            else
            {
                digitalWrite(GREEN_LIGHT_VERTICAL, HIGH);
                digitalWrite(RED_LIGHT_HORIZONTAL, HIGH);
            }
            nextTime = millis() + BLINKING_TIME;
        }
}

void orange(void)
{
    digitalWrite(GREEN_LIGHT_VERTICAL, LOW);
    digitalWrite(ORANGE_LIGHT_VERTICAL, HIGH);
    digitalWrite(RED_LIGHT_VERTICAL, LOW);

    digitalWrite(GREEN_LIGHT_HORIZONTAL, LOW);
    digitalWrite(ORANGE_LIGHT_HORIZONTAL, HIGH);
    digitalWrite(RED_LIGHT_HORIZONTAL, LOW);
}

void orangeIntermitent(void)
{
    static uint32_t nextTime = 0;

    if(millis() >= nextTime)
        {
            if(digitalRead(ORANGE_LIGHT_VERTICAL))
            {
                digitalWrite(ORANGE_LIGHT_VERTICAL, LOW);
                digitalWrite(ORANGE_LIGHT_HORIZONTAL, LOW);
            }
            else
            {
                digitalWrite(ORANGE_LIGHT_VERTICAL, HIGH);
                digitalWrite(ORANGE_LIGHT_HORIZONTAL, HIGH);
            }
            nextTime = millis() + BLINKING_TIME;
        }
}

void greenHorizotal(void)
{
    digitalWrite(GREEN_LIGHT_VERTICAL, LOW);
    digitalWrite(ORANGE_LIGHT_VERTICAL, LOW);
    digitalWrite(RED_LIGHT_VERTICAL, HIGH);

    digitalWrite(GREEN_LIGHT_HORIZONTAL, HIGH);
    digitalWrite(ORANGE_LIGHT_HORIZONTAL, LOW);
    digitalWrite(RED_LIGHT_HORIZONTAL, LOW);
}

void greenHorizontalIntermitent(void)
{
    static uint32_t nextTime = 0;

    if(millis() >= nextTime)
        {
            if(digitalRead(GREEN_LIGHT_HORIZONTAL))
            {
                digitalWrite(GREEN_LIGHT_HORIZONTAL, LOW);
                digitalWrite(RED_LIGHT_VERTICAL, LOW);
            }
            else
            {
                digitalWrite(GREEN_LIGHT_HORIZONTAL, HIGH);
                digitalWrite(RED_LIGHT_VERTICAL, HIGH);
            }
            nextTime = millis() + BLINKING_TIME;
        }
}

void stateMachineTask(void)
{
    static systemState state = S1;

    static uint32_t nextTime = millis() + WAIT_TIME_S1;

    static uint32_t nextTimeBtn1 = millis() + WAIT_TIME_BTN;
    static uint32_t nextTimeBtn2 = 0;

    static bool btn1Pressed = false;
    static bool btn2Pressed = false;

    switch (state)
    {
    case S1:
        greenVerticall();

        if(millis() >= nextTime)
        {
            state = S2;
            nextTime = millis() + WAIT_TIME_S2;
        }

        if(millis() >= nextTimeBtn1) 
        {
            if(!digitalRead(BUTTON_PIN_HORIZONTAL) & !btn1Pressed & ((millis() - nextTimeBtn1 ) >= BUTTON_REFRESH_TIME))
            {
                btn1Pressed = true;
                nextTimeBtn1 = millis() + BUTTON_REFRESH_TIME;
            }
            else if(digitalRead(BUTTON_PIN_HORIZONTAL) & btn1Pressed & ((millis() - nextTimeBtn1 ) >= BUTTON_REFRESH_TIME))
            {
                btn1Pressed = false;
                state = S2;
                nextTime = millis() + WAIT_TIME_S2;
            }
        }
        break;
    case S2:
        greenVerticalIntermitent();
        if(millis() >= nextTime)
        {
            state = S3;
            nextTime = millis() + WAIT_TIME_S3;
        }
    
        break;
    case S3:
        orange();
        if(millis() >= nextTime)
        {
            state = S4;
            nextTime = millis() + WAIT_TIME_S4;
        }

        break;
    case S4:
        orangeIntermitent();

        if(millis() >= nextTime)
        {
            state = S5;
            nextTime = millis() + WAIT_TIME_S5;
            nextTimeBtn2 = millis() + WAIT_TIME_BTN;
        }
        break;
    case S5:
        greenHorizotal();

        if(millis() >= nextTime)
        {
            state = S6;
            nextTime = millis() + WAIT_TIME_S6;
        }

        if(millis() >= nextTimeBtn2) 
        {
            if(!digitalRead(BUTTON_PIN_VERTICAL) & !btn2Pressed & ((millis() - nextTimeBtn2 ) >= BUTTON_REFRESH_TIME))
            {
                btn2Pressed = true;
                nextTimeBtn2 = millis() + BUTTON_REFRESH_TIME;
            }
            else if(digitalRead(BUTTON_PIN_VERTICAL) & btn2Pressed & ((millis() - nextTimeBtn2 ) >= BUTTON_REFRESH_TIME))
            {
                btn2Pressed = false;
                state = S6;
                nextTime = millis() + WAIT_TIME_S6;
            }
        }
        break;
    case S6:
        greenHorizontalIntermitent();

        if(millis() >= nextTime)
        {
            state = S7;
            nextTime = millis() + WAIT_TIME_S7;
        }
        break;
    case S7:
        orange();

        if(millis() >= nextTime)
        {
            state = S8;
            nextTime = millis() + WAIT_TIME_S8;
        }
        break;
    case S8:
        orangeIntermitent();

        if(millis() >= nextTime)
        {
            state = S1;
            nextTime = millis() + WAIT_TIME_S1;
            nextTimeBtn1 = millis() + WAIT_TIME_BTN;
        }
        break;
    }
}