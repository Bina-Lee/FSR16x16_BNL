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
                    int rowClearPin, clockType rowClearType, 
                    int rowClockPin, clockType rowClockType, 
                    colType colT, 
                    int* colPins);
        FSR16x16_BNL(rowType rowT, 
                    int* rowPins, 
                    colType colT, 
                    int* colPins, 
                    int outputPin);
        FSR16x16_BNL(rowType rowT, 
                    int rowClearPin, clockType rowClearType, 
                    int rowClockPin, clockType rowClockType, 
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
                    int colClearPin, clockType colClearType, 
                    int colClockPin, clockType colClockType, 
                    int outputPin);
        FSR16x16_BNL(rowType rowT, 
                    int clearPin, clockType clearType, 
                    int clockPin, clockType clockType);
    
        void begin();
        void read();
        int get(int row, int col);
        void print();

    private:
        static const int SIZE = 16;
        const rowType _rowType;
        const colType _colType;

        const int* _rowPins = nullptr;
        const int* _colPins = nullptr;

        const int _rowClearPin;
        clockType _rowClearType = RISING;
        const int _rowClockPin;
        clockType _rowClockType = RISING;
        const int _colClearPin;
        clockType _colClearType = RISING;
        const int _colClockPin;
        clockType _colClockType = RISING;
        const int _clearPin;
        clockType _clearType = RISING;
        const int _clockPin;
        clockType _clockType = RISING;

        const int _outputPin = -1;

        int data[SIZE][SIZE];
};

#endif