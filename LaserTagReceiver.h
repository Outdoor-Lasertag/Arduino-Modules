#ifndef ARDUINO_MODULES_LASERTAGRECEIVER_H
#define ARDUINO_MODULES_LASERTAGRECEIVER_H

class LaserTagReceiver
{
    private:
        IRrecv         receiver;
        decode_results results;

    public:
        LaserTagReceiver (int receivePin);

        void enable ();
        void decode ();
        static void hitDetected (unsigned int data);
        static bool getParity   (unsigned int n);
};

#endif //ARDUINO_MODULES_LASERTAGRECEIVER_H
