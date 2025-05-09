#ifndef FSR16X16_BNL_H
#define FSR16X16_BNL_H

#include <Arduino.h>

enum rowType {
    DIRECT,
    DEMUX,
    TIMER4,
    TIMER8
};

enum colType {
    DIRECT,
    MUX,
    TIMER4,
    TIMER8
};

enum clockType {
    RISING,
    FALLING
};

class FSR16x16_BNL {
    public:
        FSR16x16_BNL(rowType rowT, 
                    int* rowPins, 
                    colType colT, 
                    int* colPins);
        FSR16x16_BNL(rowType rowT, 
                    int* rowPins, 
                    colType colT, 
                    int* colPins, 
                    int outputPin);
        FSR16x16_BNL(rowType rowT, 
                    int* rowPins, 
                    colType colT, 
                    int colClearPin, clockType colClearType, 
                    int colClockPin, clockType colClockType, 
                    int outputPin);
        FSR16x16_BNL(rowType rowT, 
                    int rowClearPin, clockType rowClearType, 
                    int rowClockPin, clockType rowClockType, 
                    colType colT, 
                    int* colPins);
        FSR16x16_BNL(rowType rowT, 
                    int rowClearPin, clockType rowClearType, 
                    int rowClockPin, clockType rowClockType, 
                    colType colT, 
                    int* colPins, 
                    int outputPin);
        FSR16x16_BNL(rowType rowT, 
                    int rowClearPin, clockType rowClearType, 
                    int rowClockPin, clockType rowClockType, 
                    colType colT, 
                    int colClearPin, clockType colClearType, 
                    int colClockPin, clockType colClockType, 
                    int outputPin);
        FSR16x16_BNL(rowType rowT, 
                    int clearPin, clockType clearType, 
                    int clockPin, clockType clkType);
    
        void begin();
        void read();
        int get(int row, int col);
        void print();

    private:
        static const int SIZE = 16;
        static const int SELECT_SIZE = 4;
        const rowType _rowType;
        const colType _colType;

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

        void constructorError();

        void clockSignal(int pin, clockType clkType);
        void clockSignalMicro(int pin, clockType clkType, int delayT);
        void clockSignalMilli(int pin, clockType clkType, int delayT);
};

#endif