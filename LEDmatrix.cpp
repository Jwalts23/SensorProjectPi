#include"LEDmatrix.h"

void LEDmatrix::Delay_xms(uint x){
    bcm2835_delay(x);
}

void LEDmatrix::Write_Max7219_byte(uchar DATA){
    bcm2835_gpio_write(Max7219_pinCS,LOW);
    bcm2835_spi_transfer(DATA);
}

void LEDmatrix::Write_Max7219(uchar address1,uchar dat1){
    bcm2835_gpio_write(Max7219_pinCS,LOW);
    Write_Max7219_byte(address1);
    Write_Max7219_byte(dat1);
    bcm2835_gpio_write(Max7219_pinCS,HIGH);
}

void LEDmatrix::Init_MAX7219(){
    Write_Max7219(0x09,0x00);
    Write_Max7219(0x0a,0x03);
    Write_Max7219(0x0b,0x07);
    Write_Max7219(0x0c,0x01);
    Write_Max7219(0x0f,0x00);
}

void LEDmatrix::Init_BCM2835(){
    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256);
    bcm2835_gpio_fsel(Max7219_pinCS, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(disp1[0][0],HIGH);
}

void LEDmatrix::init(){
    Init_BCM2835();
    Init_MAX7219();
}

void LEDmatrix::testloop(){
    while (1){
        for (int j = 0; j < 36; j++){
            for (int i = 1; i < 9; i++){
                Write_Max7219(i, disp1[j][i - 1]);
            }
            Delay_xms(1000);
        }
    }
}