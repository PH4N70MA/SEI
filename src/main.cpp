#include "main.h"

void setup(void) 
{

  pinMode(GREEN_LIGHT_VERTICAL, OUTPUT);
  pinMode(ORANGE_LIGHT_VERTICAL, OUTPUT);
  pinMode(RED_LIGHT_VERTICAL, OUTPUT);

  pinMode(GREEN_LIGHT_HORIZONTAL, OUTPUT);
  pinMode(ORANGE_LIGHT_HORIZONTAL, OUTPUT);
  pinMode(RED_LIGHT_HORIZONTAL, OUTPUT);

  digitalWrite(GREEN_LIGHT_VERTICAL, LOW);
  digitalWrite(ORANGE_LIGHT_VERTICAL, LOW);
  digitalWrite(RED_LIGHT_VERTICAL, LOW);

  digitalWrite(GREEN_LIGHT_HORIZONTAL, LOW);
  digitalWrite(ORANGE_LIGHT_HORIZONTAL, LOW);
  digitalWrite(RED_LIGHT_HORIZONTAL, LOW);
}

void loop(void) 
{
  digitalWrite(GREEN_LIGHT_VERTICAL, HIGH);
  delay(500);
  digitalWrite(GREEN_LIGHT_VERTICAL, LOW);

  digitalWrite(ORANGE_LIGHT_VERTICAL, HIGH);
  delay(500);
  digitalWrite(ORANGE_LIGHT_VERTICAL, LOW);

  digitalWrite(RED_LIGHT_VERTICAL, HIGH);
  delay(500);
  digitalWrite(RED_LIGHT_VERTICAL, LOW);

  digitalWrite(GREEN_LIGHT_HORIZONTAL, HIGH);
  delay(500);
  digitalWrite(GREEN_LIGHT_HORIZONTAL, LOW);

  digitalWrite(ORANGE_LIGHT_HORIZONTAL, HIGH);
  delay(500);
  digitalWrite(ORANGE_LIGHT_HORIZONTAL, LOW);

  digitalWrite(RED_LIGHT_HORIZONTAL, HIGH);
  delay(500);
  digitalWrite(RED_LIGHT_HORIZONTAL, LOW);
  // buttonPressTask();
}