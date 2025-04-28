#include "interpreter.h"    

const char *commands[] = 
{
    "relay on",
    "relay off",
    "relay toggle",
    "relay set",
    "relay get",
    "relay status",
    "help"
};

const char *responses[] = 
{
    "Relay turned on",
    "Relay turned off",
    "Relay toggled",
    "Set command executed",
    "Get command executed",
    "Status command executed",
    "Help command executed"
};

const char *error_mesages[] = 
{
    "Error: Invalid command",
    "Error: Invalid parameters",
    "Error: Command not found",
    "Error: Unknown error",
    "Relay already on",
    "Relay already off",
};

const char *help_message[] = 
{
    "Available commands:\n",
    "1. relay on\n",
    "2. relay off\n",
    "3. relay toggle\n",
    "4. relay set <parameter>\n",
    "5. relay get <parameter>\n",
    "6. relay status\n",
};