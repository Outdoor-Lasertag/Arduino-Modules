#include "arduino.h"
#include "IRReceiver.h"

#define RESOLUTION 20
#define MAXPULSE   6500

IRReceiver::IRReceiver(int pin, int IRpin_PIN) {
  pinMode(pin, INPUT);
  this->pin = pin;
  this->irPin = IRpin_PIN;
  currentpulse = 0;
}

void IRReceiver::read() {
  uint16_t highpulse, lowpulse;
  highpulse = lowpulse = 0;
  
  while (irPin & (1 << pin)) { // Read high
    highpulse++;
    delayMicroseconds(RESOLUTION);

    if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
      currentpulse = 0;
      return;
    }
  } 
  pulses[currentpulse][0] = highpulse;
  
  while (!(irPin & _BV(pin))) { // Read low
    lowpulse++;
    delayMicroseconds(RESOLUTION);
    if ((lowpulse >= MAXPULSE) && (currentpulse != 0)) {
      currentpulse = 0;
      return;
    }
  }
  pulses[currentpulse][1] = lowpulse;
  
  currentpulse++;
}