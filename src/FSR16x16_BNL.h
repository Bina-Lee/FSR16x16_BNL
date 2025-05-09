#ifndef FSR16X16_BNL_H
#define FSR16X16_BNL_H

#include <Arduino.h>
enum pinSelectType {
    DIRECT,
    DE_MUX,
    TIMER4,
    TIMER8
};

enum clockType {
    RISING,
    FALLING
};

enum delayType {
    NONE,
    MICRO,
    MILLI
};

class FSR16x16_BNL {
    public:
        FSR16x16_BNL(pinSelectType rowT, 
                    int* rowPins, 
                    pinSelectType colT, 
                    int* colPins);
        FSR16x16_BNL(pinSelectType rowT, 
                    int* rowPins, 
                    pinSelectType colT, 
                    int* colPins, 
                    int outputPin);
        FSR16x16_BNL(pinSelectType rowT, 
                    int* rowPins, 
                    pinSelectType colT, 
                    int colClearPin, clockType colClearType, 
                    int colClockPin, clockType colClockType, 
                    int outputPin);
        FSR16x16_BNL(pinSelectType rowT, 
                    int rowClearPin, clockType rowClearType, 
                    int rowClockPin, clockType rowClockType, 
                    pinSelectType colT, 
                    int* colPins);
        FSR16x16_BNL(pinSelectType rowT, 
                    int rowClearPin, clockType rowClearType, 
                    int rowClockPin, clockType rowClockType, 
                    pinSelectType colT, 
                    int* colPins, 
                    int outputPin);
        FSR16x16_BNL(pinSelectType rowT, 
                    int rowClearPin, clockType rowClearType, 
                    int rowClockPin, clockType rowClockType, 
                    pinSelectType colT, 
                    int colClearPin, clockType colClearType, 
                    int colClockPin, clockType colClockType, 
                    int outputPin);
        FSR16x16_BNL(pinSelectType rowT, 
                    int clearPin, clockType clearType, 
                    int clockPin, clockType clkType);
    
        void begin();
        void read();
        int get(int row, int col);
        void print();

        void clockDelay(delayType delayT, int delayTime);

    private:
        static const int SIZE = 16;
        static const int SELECT_SIZE = 4;
        const pinSelectType _rowType;
        const pinSelectType _colType;

        const int* _rowPins;
        const int* _colPins;

        const int _rowClearPin;
        const clockType _rowClearType;
        const int _rowClockPin;
        const clockType _rowClockType;
        const int _colClearPin;
        const clockType _colClearType;
        const int _colClockPin;
        const clockType _colClockType;
        const int _clearPin;
        const clockType _clearType;
        const int _clockPin;
        const clockType _clockType;

        const int _outputPin = -1;

        int data[SIZE][SIZE];

        delayType _delayType = MILLI;
        int _delayTime = 20;

        void constructorError();

        void clockSignal(int pin, clockType clkType);

        void beginRowDirect();
        void beginRowDemux();
        void beginRowTimer4();
        void beginColDirect();
        void beginColMux();
        void beginColTimer4();
        void beginTimer8();

        void readDirect2Direct();
        void readDirect2MUX();
        void readDirect2TIMER4();
        void readDEMUX2Direct();
        void readDEMUX2MUX();
        void readDEMUX2TIMER4();
        void readTIMER42Direct();
        void readTIMER42MUX();
        void readTIMER42TIMER4();
        void readTIMER8();
};

#endif