#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

#define LIGHTBULB_TASK_STACK_SIZE 256
#define LIGHTBULB_TASK_PRIORITY 1
#define LIGHTBULB_TASK_RECURENCE 100
#define LIGHTBULB_TASK_NAME "LightbulbTask"

//Relay settings
#define RELAY_ID_RED 1
#define RELAY_ID_GREEN 2
#define RELAY_ID_BLUE 3

#define RELAY_NAME_RED "Red light control"
#define RELAY_NAME_GREEN "Green light control"
#define RELAY_NAME_BLUE "Blue light control"

#define RELAY_PIN_RED 13
#define RELAY_PIN_GREEN 12
#define RELAY_PIN_BLUE 11


#define RELAY_TASK_STACK_SIZE 256
#define RELAY_TASK_PRIORITY 1

//lightbulb settings
#define LIGHTBULB_ID 0u
#define LIGHTBULB_NAME "Lightbulb"
#define LIGHTBULB_PIN 3

#endif // CONFIG_H