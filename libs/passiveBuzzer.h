#include <wiringPi.h>
#include <stdio.h>
#include <softTone.h>
#include "musicNoteConstants.h"

class passiveBuzzer{
    public:
        passiveBuzzer(int BeepPin = -1) : beepPin(BeepPin){};
        void init();
        void playNote(int song[], int beat[], int index);
        void playSong(int song[], int beat[], int len);

        int song_1[35] = {CM3, CM5, CM6, CM3, CM2, CM3, CM5, CM6, CH1, CM6, CM5, CM1, CM3, CM2,
                          CM2, CM3, CM5, CM2, CM3, CM3, CL6, CL6, CL6, CM1, CM2, CM3, CM2, CL7,
                          CL6, CM1, CL5};
        int beat_1[35] = {1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
                          1, 1, 1, 1, 1, 1, 3};

        int song_2[30] = {CM1, CM1, CM1, CL5, CM3, CM3, CM3, CM1, CM1, CM3, CM5, CM5, CM4, CM3, CM2,
                          CM2, CM3, CM4, CM4, CM3, CM2, CM3, CM1, CM1, CM3, CM2, CL5, CL7, CM2, CM1};

        int beat_2[30] = {1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 3, 3, 2, 3};

    
    private:
        int beepPin;

};