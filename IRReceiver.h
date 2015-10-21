#ifndef IRRECEIVER_H
#define IRRECEIVER_H

class IRReceiver {
  public:
    IRReceiver(int pin, int IRpin_PIN);
    void read();
  private:
    int pin;
    int irPin;
    uint16_t pulses[100][2];
    uint8_t  currentpulse;
};

#endif