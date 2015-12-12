#include "arduino.h"
#include "IRremote.h"
#include "LaserTagReceiver.h"

// +==
LaserTagReceiver::LaserTagReceiver(int receivePin)
    : receiver(receivePin) {

}

void LaserTagReceiver::enable() {
    receiver.enableIRIn();
}

void LaserTagReceiver::hitDetected(unsigned int data) {
    bool parity = (data & 1) == 1;
    unsigned int dataWithoutParity = data >> 1;

    if (getParity(data) != parity) {
        // Paritäts-Bit fehlerhaft
        //return;
    }

    unsigned char damageType = (dataWithoutParity & 0xf800) >> 11;
    unsigned char ffaBit     = (dataWithoutParity & 0x0100) >> 8;
    unsigned char teamID     = (dataWithoutParity & 0x00c0) >> 6;
    // Purpose of the ffa bit is to use the two team ID bits for the player
    unsigned char playerID   = (ffaBit == 1) ? (dataWithoutParity & 0x00ff) : (dataWithoutParity & 0x003f);

    Serial.println("Received data: ");
    Serial.print("  ");
    Serial.println(data, BIN);
    Serial.print("Damage Type: ");
    Serial.println(damageType, BIN);
    Serial.print("FFA Bit:     ");
    Serial.println(ffaBit, BIN);
    Serial.print("Team ID:     ");
    Serial.println(teamID, BIN);
    Serial.print("Player ID:   ");
    Serial.println(playerID, BIN);

    if (LaserTagReceiver::getParity(dataWithoutParity) != parity) {
        Serial.println("Parity incorrect.");
    } else {
        Serial.println("Parity correct.");
    }
}

bool LaserTagReceiver::getParity(unsigned int n) {
    bool parity = 0;
    while (n) {
        parity = !parity;
        n      = n & (n - 1);
    }
    return parity;
}

void LaserTagReceiver::decode() {
    if (receiver.decode(&results)) {
        Serial.println("I have been hit.");
        LaserTagReceiver::hitDetected(results.value);
        receiver.resume(); // Receive the next value
    }
}