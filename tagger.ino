#include "IRReceiver.h"

#define IRpin_PIN PIND
#define IRpin     2

IRReceiver receiver = IRReceiver(IRpin, IRpin_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  receiver.read();
}