#include <iostream>
#include <wiringPi.h>
#include <array>

class sevenSeg{
    public:
        
        sevenSeg(int sdi = -1, int rclk = -1, int srkclk =-1) : SDI(sdi), RCLK(rclk), SRCLK(srkclk) {};
        virtual void init();
        void setBasePinMode();
        virtual void setPins(int sdi, int rclk, int srkclk);
        void hc595_shift(unsigned char dat);
        unsigned char getHexChar(int i);
        void clearDisplay();

    private:
        int SDI, RCLK, SRCLK;
        // ALl HEX 16 chracters
        std::array< unsigned char, 16>  SegCode{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

};