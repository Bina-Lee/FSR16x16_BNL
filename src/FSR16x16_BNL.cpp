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

void FSR16x16_BNL::clockSignal(int pin, clockType clkType) {
    if (clkType == RISING) {
        delayMicroseconds(1);
        digitalWrite(pin, HIGH);
        delayMicroseconds(1);
        digitalWrite(pin, LOW);
    } else {
        delayMicroseconds(1);
        digitalWrite(pin, LOW);
        delayMicroseconds(1);
        digitalWrite(pin, HIGH);
    }
}

void FSR16x16_BNL::clockSignalMicro(int pin, clockType clkType, int delayT) {
    if (clkType == RISING) {
        delayMicroseconds(delayT);
        digitalWrite(pin, HIGH);
        delayMicroseconds(delayT);
        digitalWrite(pin, LOW);
    } else {
        delayMicroseconds(delayT);
        digitalWrite(pin, LOW);
        delayMicroseconds(delayT);
        digitalWrite(pin, HIGH);
    }
}

void FSR16x16_BNL::clockSignalMilli(int pin, clockType clkType, int delayT) {
    if (clkType == RISING) {
        delay(delayT);
        digitalWrite(pin, HIGH);
        delay(delayT);
        digitalWrite(pin, LOW);
    } else {
        delay(delayT);
        digitalWrite(pin, LOW);
        delay(delayT);
        digitalWrite(pin, HIGH);
    }
}

void FSR16x16_BNL::beginRowDirect() {
    for (int i = 0; i < SIZE; i++) {
        pinMode(_rowPins[i], INPUT);
        digitalWrite(_rowPins[i], HIGH);
    }
}

void FSR16x16_BNL::beginRowDemux() {
    for (int i = 0; i < SELECT_SIZE; i++) {
        pinMode(_rowPins[i], OUTPUT);
        digitalWrite(_rowPins[i], LOW);
    }
}

void FSR16x16_BNL::beginRowTimer4() {
    pinMode(_rowClearPin, OUTPUT);
    digitalWrite(_rowClearPin, LOW);
    pinMode(_rowClockPin, OUTPUT);
    digitalWrite(_rowClockPin, LOW);
}

void FSR16x16_BNL::beginColDirect() {
    for (int i = 0; i < SIZE; i++) {
        pinMode(_colPins[i], INPUT);
    }
}

void FSR16x16_BNL::beginColMUX() {
    for (int i = 0; i < SELECT_SIZE; i++) {
        pinMode(_colPins[i], OUTPUT);
        digitalWrite(_colPins[i], LOW);
    }
    pinMode(_outputPin, INPUT);
}

void FSR16x16_BNL::beginColTimer4() {
    pinMode(_colClearPin, OUTPUT);
    digitalWrite(_colClearPin, LOW);
    pinMode(_colClockPin, OUTPUT);
    digitalWrite(_colClockPin, LOW);

    pinMode(_outputPin, INPUT);
}

void FSR16x16_BNL::beginTimer8() {
    pinMode(_clearPin, OUTPUT);
    digitalWrite(_clearPin, LOW);
    pinMode(_clockPin, OUTPUT);
    digitalWrite(_clockPin, LOW);

    pinMode(_outputPin, INPUT);
}

void FSR16x16_BNL::begin() {
    if (_rowType == TIMER8) {
        beginTimer8();
    }
    else {
        if (_rowType == DIRECT) {
            beginRowDirect();
        } else if (_rowType == DEMUX) {
            beginRowDemux();
        } else if (_rowType == TIMER4) {
            beginRowTimer4();
        }

        if (_colType == DIRECT) {
            beginColDirect();
        } else if (_colType == MUX) {
            beginColMUX();
        } else if (_colType == TIMER4) {
            beginColTimer4();
        }
    }
}

void FSR16x16_BNL::readDirect2Direct() {
    for (int i = 0; i < SIZE; i++) {
        digitalWrite(_rowPins[i], HIGH);
        for (int j = 0; j < SIZE; j++) {
            data[i][j] = digitalRite(_colPins[j]);;
        }
        digitalWrite(_rowPins[i], LOW);
    }
}

void FSR16x16_BNL::readDirect2MUX() {
    for (int i = 0; i < SIZE; i++) {
        digitalWrite(_rowPins[i], HIGH);
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SELECT_SIZE; k++) {
                digitalWrite(_colPins[k], (j >> k) & 0x01);
            }
            data[i][j] = digitalRead(_outputPin);
        }
        digitalWrite(_rowPins[i], LOW);
    }
}

void FSR16x16_BNL::readDirect2TIMER4() {
    for (int i = 0; i < SIZE; i++) {
        digitalWrite(_rowPins[i], HIGH);
        clockSignal(_colClearPin, _colClearType);
        for (int j = 0; j < SIZE; j++) {
            clockSignal(_colClockPin, _colClockType);
            data[i][j] = digitalRead(_outputPin);
        }
        digitalWrite(_rowPins[i], LOW);
    }
}

void FSR16x16_BNL::readDEMUX2Direct() {
    clockSignal(_rowClearPin, _rowClearType);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SELECT_SIZE; j++) {
            date[i][j] = analogRead(_colPins[j]);
        }
        clockSignal(_rowClockPin, _rowClockType);
    }
}

void FSR16x16_BNL::readDEMUX2MUX() {
    clockSignal(_rowClearPin, _rowClearType);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SELECT_SIZE; j++) {
            for (int k = 0; k < SELECT_SIZE; k++) {
                digitalWrite(_colPins[k], (j >> k) & 0x01);
            }
            data[i][j] = digitalRead(_outputPin);
        }
        clockSignal(_rowClockPin, _rowClockType);
    }
}

void FSR16x16_BNL::readDEMUX2TIMER4() {
    clockSignal(_rowClearPin, _rowClearType);
    for (int i = 0; i < SIZE; i++) {
        clockSignal(_colClearPin, _colClearType);
        for (int j = 0; j < SELECT_SIZE; j++) {
            data[i][j] = digitalRead(_outputPin);
            clockSignal(_colClockPin, _colClockType);
        }
        clockSignal(_rowClockPin, _rowClockType);
    }
}








int FSR16x16_BNL::get(int row, int col) {
    return data[row][col];
}

void FSR16x16_BNL::print() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            Serial.print(data[i][j]);
            Serial.print(",");
        }
        Serial.println();
    }
}