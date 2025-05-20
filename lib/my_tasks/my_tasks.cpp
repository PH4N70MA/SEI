#include "my_tasks.h"

// DHT VARIABLES
double temperature = 0;
double humidity = 0;
double SETPOINT = 25.0;

void systemSetup()
{
    dht.begin();
    regulator.setDirection(NORMAL);
    regulator.setLimits(0, 255);
    regulator.setpoint = SETPOINT;
    own_stdio_setup();
    printf("\fSistem Started!\n");
}

void PWMControl(float temperature)
{
    regulator.input = temperature;
    analogWrite(PWM_PIN, regulator.getResultTimer());
    printf("PID:%.2f\n", (double)regulator.getResultTimer());
}

void getTemperatureAndHumidity(void)
{
    static uint32_t nextTimeTask = 0;

    if(millis() >= nextTimeTask)
    {
        temperature = dht.readTemperature();
        humidity = dht.readHumidity();
    
        if (isnan(temperature) || isnan(humidity))
        {
            printf("\fFailed to read from DHT sensor!\n");
            return;
        }
    
        printf("\fT:%.2f|SP:%.2f\n", temperature, SETPOINT);

        PWMControl(temperature);

        nextTimeTask = millis() + TEMPERATURE_READ_INTERVAL;
    }
}

void getHelp(void)
{
  //print aveilible commands
    printf("\fAvailable commands:\n");
    printf("s <value> - Set the setpoint temperature\n");
}

bool RelayControl(const char *command)
{
    static float value;
    if (sscanf(command, "%f", &value)) 
    {
        regulator.setpoint = value;
        SETPOINT = regulator.setpoint;
        return 1;
    }
    return 0;
}

void parsing(const char *command)
{
    static bool err1 = 0;

    err1 = RelayControl(command);

    if (!strcmp(command, "help"))
    {
        getHelp();
    }
    else if (!err1)
    {
        printf("Unknown command. Type 'help' for a list of available commands.\n");
    }
}