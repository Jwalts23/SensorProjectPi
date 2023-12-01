#include <bcm2835.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

class LEDmatrix{
    #define uchar unsigned char
    #define uint unsigned int
    #define Max7219_pinCS  RPI_GPIO_P1_24

    public:
        LEDmatrix(int mosi = 12, int ceo = 10, int sclk = 14) : MOSI(mosi), CEO(ceo), SCLK(sclk){};
        void init();
    private:
        int MOSI, CEO, SCLK;
            
};