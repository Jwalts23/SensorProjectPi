#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

class pot{
    public:
    pot(int ADCcs = 0, int ADCclk= 1, int ADCdio = 2):adcCS(ADCcs), adcCLK(ADCclk), adcDIO(ADCdio){};
    void setPins(int ADCcs = 0, int ADCclk= 1, int ADCdio = 2){adcCS = ADCcs; adcCLK = ADCclk; adcDIO = ADCdio;};
    void init();
    char get_ADC_Result(unsigned int channel);
    private:
    int adcCS, adcCLK, adcDIO;
};