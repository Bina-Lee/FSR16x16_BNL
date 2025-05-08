#include "FSR16x16_BNL.h"

FSR16x16_BNL::FSR16x16_BNL(rowType rowT, 
                         int* rowPins, 
                         colType colT, 
                         int* colPins):
    _rowType(rowT),
    _rowPins(rowPins),
    _colType(colT),
    _colPins(colPins),

    _rowClearPin(-1),
    _rowClockPin(-1),
    _rowClearType(RISING),
    _rowClockType(RISING),
    _colClearPin(-1),
    _colClockPin(-1),
    _colClearType(RISING),
    _colClockType(RISING),
    _clearPin(-1),
    _clearType(RISING),
    _clockPin(-1),
    _clockType(RISING),
    _outputPin(-1) {
    if (!(_rowType == DIRECT || _rowType == DEMUX) || !(_colType == DIRECT)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(rowType rowT, 
                         int* rowPins, 
                         colType colT, 
                         int* colPins, 
                         int outputPin):
    _rowType(rowT),
    _rowPins(rowPins),
    _colType(colT),
    _colPins(colPins),
    _outputPin(outputPin),

    _rowClearPin(-1),
    _rowClockPin(-1),
    _rowClearType(RISING),
    _rowClockType(RISING),
    _colClearPin(-1),
    _colClockPin(-1),
    _colClearType(RISING),
    _colClockType(RISING),
    _clearPin(-1),
    _clearType(RISING),
    _clockPin(-1),
    _clockType(RISING) {
    if (!(_rowType == DIRECT || _rowType == DEMUX) || !(_colType == MUX)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(rowType rowT, 
                         int* rowPins, 
                         colType colT, 
                         int colClearPin, clockType colClearType, 
                         int colClockPin, clockType colClockType, 
                         int outputPin):
    _rowType(rowT),
    _rowPins(rowPins),
    _colType(colT),
    _colClearPin(colClearPin),
    _colClockPin(colClockPin),
    _colClearType(colClearType),
    _colClockType(colClockType),
    _outputPin(outputPin),

    _rowClearPin(-1),
    _rowClockPin(-1),
    _rowClearType(RISING),
    _rowClockType(RISING),
    _clearPin(-1),
    _clearType(RISING),
    _clockPin(-1),
    _clockType(RISING),
    _colPins(nullptr) {
    if (!(_rowType == DIRECT || _rowType == DEMUX) || !(_colType == TIMER4)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(rowType rowT, 
                         int rowClearPin, clockType rowClearType, 
                         int rowClockPin, clockType rowClockType, 
                         colType colT, 
                         int* colPins):
    _rowType(rowT),
    _rowClearPin(rowClearPin),
    _rowClockPin(rowClockPin),
    _rowClearType(rowClearType),
    _rowClockType(rowClockType),
    _colType(colT),
    _colPins(colPins),

    _colClearPin(-1),
    _colClockPin(-1),
    _colClearType(RISING),
    _colClockType(RISING),
    _clearPin(-1),
    _clearType(RISING),
    _clockPin(-1),
    _clockType(RISING),
    _outputPin(-1),
    _rowPins(nullptr) {
    if (!(_rowType == TIMER4) || !(_colType == DIRECT)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(rowType rowT, 
                         int rowClearPin, clockType rowClearType, 
                         int rowClockPin, clockType rowClockType, 
                         colType colT, 
                         int* colPins, 
                         int outputPin):
    _rowType(rowT),
    _rowClearPin(rowClearPin),
    _rowClockPin(rowClockPin),
    _rowClearType(rowClearType),
    _rowClockType(rowClockType),
    _colType(colT),
    _colPins(colPins),
    _outputPin(outputPin),

    _colClearPin(-1),
    _colClockPin(-1),
    _colClearType(RISING),
    _colClockType(RISING),
    _clearPin(-1),
    _clearType(RISING),
    _clockPin(-1),
    _clockType(RISING),
    _rowPins(nullptr) {
    if (!(_rowType == TIMER4) || !(_colType == MUX)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(rowType rowT, 
                         int rowClearPin, clockType rowClearType, 
                         int rowClockPin, clockType rowClockType, 
                         colType colT, 
                         int colClearPin, clockType colClearType, 
                         int colClockPin, clockType colClockType, 
                         int outputPin):
    _rowType(rowT),
    _rowClearPin(rowClearPin),
    _rowClockPin(rowClockPin),
    _rowClearType(rowClearType),
    _rowClockType(rowClockType),
    _colType(colT),
    _colClearPin(colClearPin),
    _colClockPin(colClockPin),
    _colClearType(colClearType),
    _colClockType(colClockType),
    _outputPin(outputPin),

    _clearPin(-1),
    _clearType(RISING),
    _clockPin(-1),
    _clockType(RISING),
    _rowPins(nullptr),
    _colPins(nullptr) {
    if (!(_rowType == TIMER4) || !(_colType == TIMER4)) constructorError();
}
FSR16x16_BNL::FSR16x16_BNL(rowType rowT, 
                         int clearPin, clockType clearType, 
                         int clockPin, clockType clkType):
    _rowType(rowT),
    _clearPin(clearPin),
    _clearType(clearType),
    _clockPin(clockPin),
    _clockType(clkType),

    _rowClearPin(-1),
    _rowClockPin(-1),
    _rowClearType(RISING),
    _rowClockType(RISING),
    _colClearPin(-1),
    _colClockPin(-1),
    _colClearType(RISING),
    _colClockType(RISING),
    _outputPin(-1),
    _rowPins(nullptr),
    _colPins(nullptr) {
    if (!(_rowType == TIMER8)) constructorError();
}

void FSR16x16_BNL::constructorError() {
    while (true) {
        Serial.println("FSR16x16_BNL: Constructor Error");
        delay(1000);
    }
}