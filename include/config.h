#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

//display
#define DISPLAY_ROWS 2
#define DISPLAY_COLS 16
#define DISPLAY_ADRESS 0x27

//Hysterisis settings
#define HYSTERESIS 5

//Setpoint settings PID
#define P_COIFFICIENT 0.1
#define I_COIFFICIENT 0.05
#define D_COIFFICIENT 0.01

//DHT settings
#define DHTTYPE DHT22
#define DHTPIN 8
#define TEMPERATURE_READ_INTERVAL 2000

//Control PWM settings
#define PWM_PIN 7


#define RELAY_TASK_STACK_SIZE 256
#define RELAY_TASK_PRIORITY 1

#endif // CONFIG_H