#ifndef MASTER_H
#define MASTER_H

#include <Arduino.h>
#include "config.h"
#include < SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
struct Str {
  byte val_b;
  int val_i;
  long val_l;
  float val_f;
};


#endif // MASTER_H