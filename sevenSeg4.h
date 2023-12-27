#include "sevenSeg.h"
#include <stdio.h>
#include <wiringShift.h>
#include <signal.h>
#include <unistd.h>



class sevenSeg4 : public sevenSeg
{
public:
    sevenSeg4(int Dig1Pin = -1, int Dig2Pin = -1, int Dig3Pin = -1, int Dig4Pin = -1, int sdi = -1, int rclk = -1, int srkclk = -1) : dig1Pin(Dig1Pin), dig2Pin(Dig2Pin), dig3Pin(Dig3Pin), dig4Pin(Dig4Pin), sevenSeg(sdi, rclk, srkclk) {};
    void init() override;
    void setPins(int Dig1Pin, int Dig2Pin, int Dig3Pin, int Dig4Pin, int sdi, int rclk, int srkclk);
    void pickDigit(int digit);
    void displayNumber(int num);
    void testLoop();
    void displayHiLo(bool low);


private:
    int dig1Pin, dig2Pin, dig3Pin, dig4Pin;
    int *pdig1Pin{&dig1Pin}, *pdig2Pin{&dig2Pin}, *pdig3Pin{&dig3Pin}, *pdig4Pin{&dig4Pin};
    std::array< int, 4> placePin = {*pdig1Pin, *pdig2Pin, *pdig3Pin, *pdig4Pin};
    std::array< unsigned char, 16> number = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
    std::array< unsigned char, 2>  Lo = {0xc7, 0xA3};
    std::array< unsigned char, 2>  Hi = {0x89, 0xcf};
};