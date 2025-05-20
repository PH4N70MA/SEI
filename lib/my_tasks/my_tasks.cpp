#include "my_tasks.h"

// DHT VARIABLES
double temperature = 0;
double humidity = 0;
double SETPOINT = 25.0;

void systemSetup()
{
    dht.begin();
    own_stdio_setup();
    printf("\fSistem Started!\n");
}

void relayHysteresisControl(float temperature, float humidity)
{
    if (temperature > (SETPOINT + HYSTERESIS))
    {
        heat.control(ENABLE);
    }
    else if (temperature < (SETPOINT - HYSTERESIS))
    {
        heat.control(DISABLE);
    }
    printf("SP:%.2f|R:%d\n", SETPOINT, heat.getState());
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
    
        printf("\fT:%.2f|H:%.2f\n", temperature, humidity);
        relayHysteresisControl(temperature, humidity);

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
        SETPOINT = value;
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