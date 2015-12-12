#include "arduino.h"
#include "IRremote.h"
#include "LaserTagSender.h"

LaserTagSender::LaserTagSender(int pin): sender() {
    this->pin = pin;
}

void LaserTagSender::fire(GameData game, PlayerData player) {

    unsigned int raw[100] =
            {
                    2400,  600, 600, 600, 1200, 600, 600, 600, 600, 600, 600, 600,
                    600, 600, 600, 600, 600, 600, 600, 600, 1200, 600, 600, 600,
                    1200, 600, 1200, 600, 600, 600, 1200, 600, 1200, 600, 600,
            };
    // 80B6

    sender.sendRaw(raw, 100, 38);
    Serial.println("Fired.");
    //sender.sendSony(0x80B6, 16);
}

void LaserTagSender::enable() {
    pinMode      (pin, INPUT);
    digitalWrite (pin, HIGH);
}