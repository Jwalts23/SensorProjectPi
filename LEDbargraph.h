#include <iostream>
#include <wiringPi.h>
#include <array>

// This class is made for the use with an LED bargraph
class LEDbargraph{
    public:
        LEDbargraph(std::array<int,10> Pins) : pins(Pins) {};
        void init(void);
        void evenLedBarGraph(void);
        void oddLedBarGraph(void);
        void allLedBarGraph(void);
    private:
        std::array<int,10> pins;
};
