#include <QueueArray.h>
#include "debounce.h"

const int sensor = 2;
const int diameter = 70;
const float pi = 3.14159;
const int sampleLimit = 9;


unsigned int revolutions;
float circumference;
QueueArray<unsigned long> timestamps;
volatile boolean sensorPassed;

void handleInput() {
  debounce();
  sensorPassed = true;
}

float distance() {
  return (circumference * revolutions) / 100000;
}

float rate() {
  return 0;
}

void updateDisplay() {
  Serial.print("Bike Computer -- ");
  Serial.print("Circumference: ");
  Serial.print(circumference);
  Serial.print(", Revolutions: ");
  Serial.print(revolutions);
  Serial.print(", Distance: ");
  Serial.print(distance());
  Serial.print(", Speed: ");
  Serial.println(rate());
}

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  attachInterrupt(0, handleInput, FALLING);
  circumference = diameter * pi;
  Serial.println("Setup done");
}

void loop() {
  if (sensorPassed) {
    revolutions++;
    timestamps.push(millis());
    sensorPassed = false;
  }
  updateDisplay();
}
