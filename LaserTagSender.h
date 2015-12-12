#ifndef ARDUINO_MODULES_LASERTAGSENDER_H
#define ARDUINO_MODULES_LASERTAGSENDER_H

#include "LaserTagData.h"

class LaserTagSender {
    private:
        IRsend sender;
        int pin;

    public:
        LaserTagSender (int pin);

        void enable    ();
        void fire(GameData game, PlayerData player);
};

#endif //ARDUINO_MODULES_LASERTAGSENDER_H
