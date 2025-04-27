#include "main.h"

void setup(void) 
{
  buttonLedTaskSetup();
  ledIntermittentTaskSetup();
  buttonVariableTaskSetup();
}

void loop(void) 
{
  buttonLedTask();
  ledIntermittentTask();
  buttonVariableTask();
}