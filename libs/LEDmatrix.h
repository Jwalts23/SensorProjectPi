#include <bcm2835.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// need to use -lbcm2835 when compiling so it will access the lib.

#define uchar unsigned char
#define uint unsigned int
#define Max7219_pinCS  RPI_GPIO_P1_24

//This class is made for use with a LED matrix.
class LEDmatrix{

    public:
        LEDmatrix(int mosi = 12, int ceo = 10, int sclk = 14) : MOSI(mosi), CEO(ceo), SCLK(sclk){};
        void init();
        void Delay_xms(uint x);
        void Write_Max7219_byte(uchar DATA);
        void Write_Max7219(uchar address1,uchar dat1);
        void testLoop();

    private:
        void Init_MAX7219();
        void Init_BCM2835();
        int MOSI, CEO, SCLK;


        //This is a list of 0-9 and A-Z
        uchar disp1[36][8]={
        {0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//0
        {0x08,0x18,0x28,0x08,0x08,0x08,0x08,0x08},//1
        {0x7E,0x2,0x2,0x7E,0x40,0x40,0x40,0x7E},//2
        {0x3E,0x2,0x2,0x3E,0x2,0x2,0x3E,0x0},//3
        {0x8,0x18,0x28,0x48,0xFE,0x8,0x8,0x8},//4
        {0x3C,0x20,0x20,0x3C,0x4,0x4,0x3C,0x0},//5
        {0x3C,0x20,0x20,0x3C,0x24,0x24,0x3C,0x0},//6
        {0x3E,0x22,0x4,0x8,0x8,0x8,0x8,0x8},//7
        {0x0,0x3E,0x22,0x22,0x3E,0x22,0x22,0x3E},//8
        {0x3E,0x22,0x22,0x3E,0x2,0x2,0x2,0x3E},//9
        {0x8,0x14,0x22,0x3E,0x22,0x22,0x22,0x22},//A
        {0x3C,0x22,0x22,0x3E,0x22,0x22,0x3C,0x0},//B
        {0x3C,0x40,0x40,0x40,0x40,0x40,0x3C,0x0},//C
        {0x7C,0x42,0x42,0x42,0x42,0x42,0x7C,0x0},//D
        {0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x7C},//E
        {0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x40},//F
        {0x3C,0x40,0x40,0x40,0x40,0x44,0x44,0x3C},//G
        {0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x44},//H
        {0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x7C},//I
        {0x3C,0x8,0x8,0x8,0x8,0x8,0x48,0x30},//J
        {0x0,0x24,0x28,0x30,0x20,0x30,0x28,0x24},//K
        {0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7C},//L
        {0x81,0xC3,0xA5,0x99,0x81,0x81,0x81,0x81},//M
        {0x0,0x42,0x62,0x52,0x4A,0x46,0x42,0x0},//N
        {0x3C,0x42,0x42,0x42,0x42,0x42,0x42,0x3C},//O
        {0x3C,0x22,0x22,0x22,0x3C,0x20,0x20,0x20},//P
        {0x1C,0x22,0x22,0x22,0x22,0x26,0x22,0x1D},//Q
        {0x3C,0x22,0x22,0x22,0x3C,0x24,0x22,0x21},//R
        {0x0,0x1E,0x20,0x20,0x3E,0x2,0x2,0x3C},//S
        {0x0,0x3E,0x8,0x8,0x8,0x8,0x8,0x8},//T
        {0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1C},//U
        {0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18},//V
        {0x0,0x49,0x49,0x49,0x49,0x2A,0x1C,0x0},//W
        {0x0,0x41,0x22,0x14,0x8,0x14,0x22,0x41},//X
        {0x41,0x22,0x14,0x8,0x8,0x8,0x8,0x8},//Y
        {0x0,0x7F,0x2,0x4,0x8,0x10,0x20,0x7F},//Z
        };
            
};