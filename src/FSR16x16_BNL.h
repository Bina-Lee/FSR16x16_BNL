#ifndef FSR16X16_BNL_H
#define FSR16X16_BNL_H

#include <Arduino.h>
enum pinSelectType {
    DIRECT,
    DE_MUX,
    TIMER4,
    TIMER8
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
                    int colClearPin, int colClearType, 
                    int colClockPin, int colClockType, 
                    int outputPin);
        FSR16x16_BNL(pinSelectType rowT, 
                    int rowClearPin, int rowClearType, 
                    int rowClockPin, int rowClockType, 
                    pinSelectType colT, 
                    int* colPins);
        FSR16x16_BNL(pinSelectType rowT, 
                    int rowClearPin, int rowClearType, 
                    int rowClockPin, int rowClockType, 
                    pinSelectType colT, 
                    int* colPins, 
                    int outputPin);
        FSR16x16_BNL(pinSelectType rowT, 
                    int rowClearPin, int rowClearType, 
                    int rowClockPin, int rowClockType, 
                    pinSelectType colT, 
                    int colClearPin, int colClearType, 
                    int colClockPin, int colClockType, 
                    int outputPin);
        FSR16x16_BNL(pinSelectType rowT, 
                    int clearPin, int clearType, 
                    int clockPin, int clkType);
    
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
        const int _rowClearType;
        const int _rowClockPin;
        const int _rowClockType;
        const int _colClearPin;
        const int _colClearType;
        const int _colClockPin;
        const int _colClockType;
        const int _clearPin;
        const int _clearType;
        const int _clockPin;
        const int _clockType;

        const int _outputPin = -1;

        int data[SIZE][SIZE];

        delayType _delayType = MILLI;
        int _delayTime = 20;

        void constructorError();

        void clockSignal(int pin, int clkType);

        void beginRowDirect();
        void beginRowDemux();
        void beginRowTIMER4();
        void beginColDIRECT();
        void beginColMUX();
        void beginColTIMER4();
        void beginTIMER8();

        void readDIRECT2DIRECT();
        void readDIRECT2MUX();
        void readDIRECT2TIMER4();
        void readDEMUX2DIRECT();
        void readDEMUX2MUX();
        void readDEMUX2TIMER4();
        void readTIMER42DIRECT();
        void readTIMER42MUX();
        void readTIMER42TIMER4();
        void readTIMER8();
};

#endif