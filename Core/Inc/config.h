#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

// Configuration settings for the project

#define RX_DATA_SIZE 1
#define DEBOUNDE_DELAY 100

char buf[100];
uint8_t RX_DATA[RX_DATA_SIZE];

#endif // CONFIG_H