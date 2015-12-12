#include "IRremote.h"
#include "LaserTagData.h"
#include "LaserTagReceiver.h"
#include "LaserTagSender.h"

// Senden ist zwangsweise Pin D3!
#define PIN_IR_RECEIVER     10
#define PIN_BUTTON          2

LaserTagReceiver receiver(PIN_IR_RECEIVER);
LaserTagSender   sender(PIN_BUTTON);

GameData game;
PlayerData player;
bool awaitingFire = false;

void fireInterrupt();

void setup()
{
    Serial.begin(9600);

    receiver.enable();
    sender.enable();

    // FALLING -> Pull Up Button
    attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), fireInterrupt, FALLING);
}

// Nach Feuern wird kein weiterer Treffer registriert!

void loop()
{
    receiver.decode();

    if (awaitingFire) {
        awaitingFire = false;

        sender.fire(game, player);
    }
}

void fireInterrupt()
{
    awaitingFire = true;
}