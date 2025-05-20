#include "main.h"


void setup()
{
    systemSetup();
}

void loop()
{
  getTemperatureAndHumidity();
}

void serialEvent(void)
{
  char command[15] = {0};
  scanf("%15s", command);
  
  parsing(command);
}