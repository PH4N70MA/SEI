#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

//display
#define DISPLAY_ROWS 2
#define DISPLAY_COLS 16
#define DISPLAY_ADRESS 0x27

//Relay settings
#define RELAY_ID 1

#define RELAY_NAME "Heating System"
#define RELAY_PIN 13

//Hysterisis settings
#define HYSTERESIS 5

//DHT settings
#define DHTTYPE DHT22
#define DHTPIN 8
#define TEMPERATURE_READ_INTERVAL 2000


#define RELAY_TASK_STACK_SIZE 256
#define RELAY_TASK_PRIORITY 1

#endif // CONFIG_H