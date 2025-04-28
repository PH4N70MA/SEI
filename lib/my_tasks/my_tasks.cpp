#include "my_tasks.h"

void systemSetup()
{
    own_stdio_setup();
    printf("Sistem Started!\n");
    printf("Enter command: \n");
}

void getHelp(void)
{
  printf("Available commands:\n");
  printf("```General```\n");
  printf("sys_state: show all relay state\n");
  printf("```Red```\n");
  printf("red_on: Turn on red relay\n");
  printf("red_off: Turn off red relay\n");
  printf("red_toggle: Toggle red realay\n");
  printf("red_state: Get red relay state\n");
  printf("```Green```\n");
  printf("green_on: Turn on green realy\n");
  printf("green_off: Turn off green realy\n");
  printf("green_toggle: Toggle green realy\n");
  printf("green_state: Get green realy status\n");
  printf("```Blue```\n");
  printf("blue_on: Turn on blue relay\n");
  printf("blue_off: Turn off blue relay\n");
  printf("blue_toggle: Toggle blue relay\n");
  printf("blue_state: Get blue relay status\n");
  printf("```End```\n");
}

bool redRelayControl(const char *command)
{
    if (!strcmp(command, "red_on"))
    {
        red.control(ENABLE);
        printf("red status: %d\n", red.getState());
        return 1;
    }
    else if (!strcmp(command, "red_off"))
    {
        red.control(DISABLE);
        printf("red status: %d\n", red.getState());
        return 1;
    }
    else if (!strcmp(command, "red_toggle"))
    {
        red.control(TOGGLE);
        printf("red status: %d\n", red.getState());
        return 1;
    }
    else if (!strcmp(command, "red_state"))
    {
        printf("red status: %d\n", red.getState());
        return 1;
    }
    return 0;
}

bool greenRelayControl(const char *command)
{
    if (!strcmp(command, "green_on"))
    {
        green.control(ENABLE);
        printf("green status: %d\n", green.getState());
        return 1;
    }
    else if (!strcmp(command, "green_off"))
    {
        green.control(DISABLE);
        printf("green status: %d\n", green.getState());
        return 1;
    }
    else if (!strcmp(command, "green_toggle"))
    {
        green.control(TOGGLE);
        printf("green status: %d\n", green.getState());
        return 1;
    }
    else if (!strcmp(command, "green_state"))
    {
        printf("green status: %d\n", green.getState());
        return 1;
    }
    return 0;
}

bool blueRelayControl(const char *command)
{
    if (!strcmp(command, "blue_on"))
    {
        blue.control(ENABLE);
        printf("blue status: %d\n", blue.getState());
        return 1;
    }
    else if (!strcmp(command, "blue_off"))
    {
        blue.control(DISABLE);
        printf("blue status: %d\n", blue.getState());
        return 1;
    }
    else if (!strcmp(command, "blue_toggle"))
    {
        blue.control(TOGGLE);
        printf("blue status: %d\n", blue.getState());
        return 1;
    }
    else if (!strcmp(command, "blue_state"))
    {
        printf("blue status: %d\n", blue.getState());
        return 1;
    }
    return 0;
}   

void parsing(const char *command)
{
    static bool err1 = 0;
    static bool err2 = 0;
    static bool err3 = 0;

    err1 = redRelayControl(command);
    err2 = greenRelayControl(command);
    err3 = blueRelayControl(command);

    if (!strcmp(command, "help"))
    {
        getHelp();
    }
    else if (!strcmp(command, "sys_state"))
    {
        redRelayControl("red_state");
        greenRelayControl("green_state");
        blueRelayControl("blue_state");
    }
    else if (err1 && err2 && err3)
    {
        printf("Unknown command. Type 'help' for a list of available commands.\n");
    }
}