#ifndef ARDUINO_MODULES_LASERTAGDATA_H
#define ARDUINO_MODULES_LASERTAGDATA_H

struct GameData {
    int gamemode;
    int players;
    bool isRunning;
};

struct PlayerData {
    int playerID;
    String name;

    int health;
    int energy;
    int ammo;
    int pickup;
};

#endif //ARDUINO_MODULES_LASERTAGDATA_H
