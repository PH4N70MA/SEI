#include "my_tasks.h"

int motorDuty = 0;

GMotor2<DRIVER3WIRE> motor(MOTOR_PIN_1, MOTRO_PIN_2, MOTRO_PWN);

void buttonControlTaskSetup(void)
{
    pinMode(BUTTON_MINUS, INPUT_PULLUP);
    pinMode(BUTTON_PLUS, INPUT_PULLUP);
    pinMode(BUTTON_STOP, INPUT_PULLUP);
    pinMode(BUTTON_RESERVED, INPUT_PULLUP);
}

void plusLogic(void)
{
    motorDuty += 5;
    if(motorDuty > MAX_SPEED)
    {
        motorDuty = MAX_SPEED;
    }
    motor.setSpeedPerc(motorDuty);
    printf("\fSpeed: %d\n", motorDuty);
    if (motor.getSpeed() == 0)
    {
        motorDisplay();
    }
}

void minusLogic()
{
    motorDuty -= 5;
    if(motorDuty < MAX_SPEED_REVERS)
    {
        motorDuty = MAX_SPEED_REVERS;
    }
    motor.setSpeedPerc(motorDuty);
    printf("\fSpeed: %d\n", motorDuty);
    if (motor.getSpeed() == 0)
    {
        motorDisplay();
    }
}

void stopLogic(void)
{
    motorDuty = 0;
    motor.brake();
    motorDisplay();
}

void buttonTask(void)
{
    static uint32_t nextTimeTask3 = 0;
    static bool lastStatePLUS = false;
    static bool lastStateMINUS = false;
    static bool lastStateStop = false;

    if(millis() >= nextTimeTask3)
    {
        //plus handler
        if (!digitalRead(BUTTON_PLUS) & !lastStatePLUS & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStatePLUS = true;
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        else if (digitalRead(BUTTON_PLUS) & lastStatePLUS & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStatePLUS = false;
            
            plusLogic();

            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        //minus handler
        if (!digitalRead(BUTTON_MINUS) & !lastStateMINUS & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStateMINUS = true;
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        else if (digitalRead(BUTTON_MINUS) & lastStateMINUS & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStateMINUS = false;
            
            minusLogic();

            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        //stop button
        if (!digitalRead(BUTTON_STOP) & !lastStateStop & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStateStop = true;
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        else if (digitalRead(BUTTON_STOP) & lastStateStop & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStateStop = false;
            
            stopLogic();

            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
    }
}

void systemSetup()
{
    buttonControlTaskSetup();
    motor.setMinDuty(70);
    motor.brake();
    motor.setSpeed(0);

    own_stdio_setup();
    printf("Sistem Started!\n");
    printf("(+):+5\n");
    printf("(-):-5\n");
    printf("stop: 0");  
}

void motorDisplay(void)
{
    printf("(+):+5\n");
    printf("(-):-5\n");
    printf("stop: 0");
}

void parsing(const char *command)
{    
    if (!strcmp(command, "inc"))
    {
        plusLogic();
    }
    else if (!strcmp(command, "dec"))
    {
        minusLogic();
    }
    else if (!strcmp(command, "stop"))
    {
        stopLogic();
    }
    else
    {
        printf("\finc: speed +5");
        printf("\ndec: speed -5");
        printf("\nstop: speed == 0");
    }
}