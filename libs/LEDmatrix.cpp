#include "LEDmatrix.h"

// def has potential for arrow interaction like the book

void LEDmatrix::Delay_xms(uint x){
    bcm2835_delay(x);
}

// send the data over SPI
void LEDmatrix::Write_Max7219_byte(uchar DATA){
    bcm2835_gpio_write(Max7219_pinCS,LOW);
    bcm2835_spi_transfer(DATA);
}

// Write the row of the LED matrx to the bcm2835
void LEDmatrix::Write_Max7219(uchar address1,uchar dat1){
    bcm2835_gpio_write(Max7219_pinCS,LOW);
    Write_Max7219_byte(address1);
    Write_Max7219_byte(dat1);
    bcm2835_gpio_write(Max7219_pinCS,HIGH);
}

//Initialize the display
void LEDmatrix::Init_MAX7219(){
    Write_Max7219(0x09,0x00);
    Write_Max7219(0x0a,0x03);
    Write_Max7219(0x0b,0x07);
    Write_Max7219(0x0c,0x01);
    Write_Max7219(0x0f,0x00);
}

//Set all the default vals for bcm2835
void LEDmatrix::Init_BCM2835(){
    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256);
    bcm2835_gpio_fsel(Max7219_pinCS, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(disp1[0][0],HIGH);
}

void LEDmatrix::init(){

    if (!bcm2835_init())
    {
        printf("Unable to init bcm2835.\n");
        return;
    }
    Init_BCM2835();
    Init_MAX7219();
}

//This will go through the list of letters and numbers and display them
void LEDmatrix::testLoop(){
    while (1){
        for (int j = 0; j < 36; j++){
            for (int i = 1; i < 9; i++){
                Write_Max7219(i, disp1[j][i - 1]);
            }
            Delay_xms(1000);
        }
    }
}