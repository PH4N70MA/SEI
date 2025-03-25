#ifndef CONFIG_H
#define CONFIG_H

#define GREEN_LED 7
#define BLUE_LED 6

#define ON_OFF_BUTTON 5
#define UP_BUTTON 4
#define DOWN_BUTTON 3

#define STACK_SIZE 128
#define PRIORITY 2

// Define the baud rate for the serial communication
#define BAUDRATE 115200

#define BUTTON_REFRESH_TIME 100

#define GREEN_LED_ON_TIME 1000
#define BLUE_LED_ON_TIME 300
#define BLUE_LED_OFF_TIME 500

#define FIRST_TASK_REC 10
#define SECOND_TASK_REC 20
#define THIRD_TASK_REC 200
#define IDLE_HOOK_REC 500


#endif