#include "FSR16x16_BNL.h"

FSR16x16_BNL::FSR16x16_BNL(pinSelectType rowT, 
                         int* rowPins, 
                         pinSelectType colT, 
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
    if (!(_rowType == DIRECT || _rowType == DE_MUX) || !(_colType == DIRECT)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(pinSelectType rowT, 
                         int* rowPins, 
                         pinSelectType colT, 
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
    if (!(_rowType == DIRECT || _rowType == DE_MUX) || !(_colType == DE_MUX)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(pinSelectType rowT, 
                         int* rowPins, 
                         pinSelectType colT, 
                         int colClearPin, int colClearType, 
                         int colClockPin, int colClockType, 
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
    if (!(_rowType == DIRECT || _rowType == DE_MUX) || !(_colType == TIMER4)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(pinSelectType rowT, 
                         int rowClearPin, int rowClearType, 
                         int rowClockPin, int rowClockType, 
                         pinSelectType colT, 
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

FSR16x16_BNL::FSR16x16_BNL(pinSelectType rowT, 
                         int rowClearPin, int rowClearType, 
                         int rowClockPin, int rowClockType, 
                         pinSelectType colT, 
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
    if (!(_rowType == TIMER4) || !(_colType == DE_MUX)) constructorError();
}

FSR16x16_BNL::FSR16x16_BNL(pinSelectType rowT, 
                         int rowClearPin, int rowClearType, 
                         int rowClockPin, int rowClockType, 
                         pinSelectType colT, 
                         int colClearPin, int colClearType, 
                         int colClockPin, int colClockType, 
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

FSR16x16_BNL::FSR16x16_BNL(pinSelectType rowT, 
                         int clearPin, int clearType, 
                         int clockPin, int clkType):
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

void FSR16x16_BNL::clockSignal(int pin, int clkType) {
    if (clkType == RISING) {
        if (_delayType == NONE){
            delayMicroseconds(1);
        } else if (_delayType == MICRO) {
            delayMicroseconds(_delayTime);
        } else if (_delayType == MILLI) {
            delay(_delayTime);
        }
        digitalWrite(pin, HIGH);
        if (_delayType == NONE){
            delayMicroseconds(1);
        } else if (_delayType == MICRO) {
            delayMicroseconds(_delayTime);
        } else if (_delayType == MILLI) {
            delay(_delayTime);
        }
        digitalWrite(pin, LOW);
    } else {
        if (_delayType == NONE){
            delayMicroseconds(1);
        } else if (_delayType == MICRO) {
            delayMicroseconds(_delayTime);
        } else if (_delayType == MILLI) {
            delay(_delayTime);
        }
        digitalWrite(pin, LOW);
        if (_delayType == NONE){
            delayMicroseconds(1);
        } else if (_delayType == MICRO) {
            delayMicroseconds(_delayTime);
        } else if (_delayType == MILLI) {
            delay(_delayTime);
        }
        digitalWrite(pin, HIGH);
    }
}

void FSR16x16_BNL::beginRowDIRECT() {
    for (int i = 0; i < SIZE; i++) {
        pinMode(_rowPins[i], INPUT);
        digitalWrite(_rowPins[i], HIGH);
    }
}

void FSR16x16_BNL::beginRowDEMUX() {
    for (int i = 0; i < SELECT_SIZE; i++) {
        pinMode(_rowPins[i], OUTPUT);
        digitalWrite(_rowPins[i], LOW);
    }
}

void FSR16x16_BNL::beginRowTIMER4() {
    pinMode(_rowClearPin, OUTPUT);
    digitalWrite(_rowClearPin, LOW);
    pinMode(_rowClockPin, OUTPUT);
    digitalWrite(_rowClockPin, LOW);
}

void FSR16x16_BNL::beginColDIRECT() {
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

void FSR16x16_BNL::beginColTIMER4() {
    pinMode(_colClearPin, OUTPUT);
    digitalWrite(_colClearPin, LOW);
    pinMode(_colClockPin, OUTPUT);
    digitalWrite(_colClockPin, LOW);

    pinMode(_outputPin, INPUT);
}

void FSR16x16_BNL::beginTIMER8() {
    pinMode(_clearPin, OUTPUT);
    digitalWrite(_clearPin, LOW);
    pinMode(_clockPin, OUTPUT);
    digitalWrite(_clockPin, LOW);

    pinMode(_outputPin, INPUT);
}

void FSR16x16_BNL::begin() {
    if (_rowType == TIMER8) {
        beginTIMER8();
    }
    else {
        if (_rowType == DIRECT) {
            beginRowDIRECT();
        } else if (_rowType == DE_MUX) {
            beginRowDEMUX();
        } else if (_rowType == TIMER4) {
            beginRowTIMER4();
        }

        if (_colType == DIRECT) {
            beginColDIRECT();
        } else if (_colType == DE_MUX) {
            beginColMUX();
        } else if (_colType == TIMER4) {
            beginColTIMER4();
        }
    }
}

void FSR16x16_BNL::readDIRECT2DIRECT() {
    for (int i = 0; i < SIZE; i++) {
        digitalWrite(_rowPins[i], HIGH);
        for (int j = 0; j < SIZE; j++) {
            data[rowMap[i]][colMap[j]] = analogRead(_colPins[j]);;
        }
        digitalWrite(_rowPins[i], LOW);
    }
}

void FSR16x16_BNL::readDIRECT2MUX() {
    for (int i = 0; i < SIZE; i++) {
        digitalWrite(_rowPins[i], HIGH);
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SELECT_SIZE; k++) {
                digitalWrite(_colPins[k], (j >> k) & 0x01);
            }
            data[rowMap[i]][colMap[j]] = analogRead(_outputPin);
        }
        digitalWrite(_rowPins[i], LOW);
    }
}

void FSR16x16_BNL::readDIRECT2TIMER4() {
    for (int i = 0; i < SIZE; i++) {
        digitalWrite(_rowPins[i], HIGH);
        clockSignal(_colClearPin, _colClearType);
        for (int j = 0; j < SIZE; j++) {
            data[rowMap[i]][colMap[j]] = analogRead(_outputPin);
            clockSignal(_colClockPin, _colClockType);
        }
        digitalWrite(_rowPins[i], LOW);
    }
}

void FSR16x16_BNL::readDEMUX2DIRECT() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SELECT_SIZE; j++) {
            digitalWrite(_rowPins[j], (i >> j) & 0x01);
        }
        for (int j = 0; j < SIZE; j++) {
            data[rowMap[i]][colMap[j]] = analogRead(_colPins[j]);
        }
    }
}

void FSR16x16_BNL::readDEMUX2MUX() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SELECT_SIZE; j++) {
            digitalWrite(_rowPins[j], (i >> j) & 0x01);
        }
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SELECT_SIZE; k++) {
                digitalWrite(_colPins[k], (j >> k) & 0x01);
            }
            data[rowMap[i]][colMap[j]] = analogRead(_outputPin);
        }
    }
}

void FSR16x16_BNL::readDEMUX2TIMER4() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SELECT_SIZE; j++) {
            digitalWrite(_rowPins[j], (i >> j) & 0x01);
        }
        clockSignal(_colClearPin, _colClearType);
        for (int j = 0; j < SIZE; j++) {
            data[rowMap[i]][colMap[j]] = analogRead(_outputPin);
            clockSignal(_colClockPin, _colClockType);
        }
    }
}

void FSR16x16_BNL::readTIMER42DIRECT() {
    clockSignal(_rowClearPin, _rowClearType);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            data[rowMap[i]][colMap[j]] = analogRead(_colPins[j]);
        }
        clockSignal(_rowClockPin, _rowClockType);
    }
}

void FSR16x16_BNL::readTIMER42MUX() {
    clockSignal(_rowClearPin, _rowClearType);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SELECT_SIZE; k++) {
                digitalWrite(_colPins[k], (j >> k) & 0x01);
            }
            data[rowMap[i]][colMap[j]] = analogRead(_outputPin);
        }
        clockSignal(_rowClockPin, _rowClockType);
    }
}

void FSR16x16_BNL::readTIMER42TIMER4() {
    clockSignal(_rowClearPin, _rowClearType);
    for (int i = 0; i < SIZE; i++) {
        clockSignal(_colClearPin, _colClearType);
        for (int j = 0; j < SIZE; j++) {
            data[rowMap[i]][colMap[j]] = analogRead(_outputPin);
            clockSignal(_colClockPin, _colClockType);
        }
        clockSignal(_rowClockPin, _rowClockType);
    }
}

void FSR16x16_BNL::readTIMER8() {
    clockSignal(_clearPin, _clearType);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            data[rowMap[i]][colMap[j]] = analogRead(_outputPin);
            clockSignal(_clockPin, _clockType);
        }
    }
}

void FSR16x16_BNL::read() {
    if (_rowType == TIMER8) {
        readTIMER8();
    }
    else {
        if (_rowType == DIRECT) {
            if (_colType == DIRECT) {
                readDIRECT2DIRECT();
            } else if (_colType == DE_MUX) {
                readDIRECT2MUX();
            } else if (_colType == TIMER4) {
                readDIRECT2TIMER4();
            }
        } else if (_rowType == DE_MUX) {
            if (_colType == DIRECT) {
                readDEMUX2DIRECT();
            } else if (_colType == DE_MUX) {
                readDEMUX2MUX();
            } else if (_colType == TIMER4) {
                readDEMUX2TIMER4();
            }
        } else if (_rowType == TIMER4) {
            if (_colType == DIRECT) {
                readTIMER42DIRECT();
            } else if (_colType == DE_MUX) {
                readTIMER42MUX();
            } else if (_colType == TIMER4) {
                readTIMER42TIMER4();
            }
        }
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

void FSR16x16_BNL::clockDelay(delayType delayT, int delayTime) {
    _delayType = delayT;
    _delayTime = delayTime;
}

void FSR16x16_BNL::setRowMap(int* rowMap) {
    for (int i = 0; i < SIZE; i++) {
        _rowMap[i] = rowMap[i];
    }
}

void FSR16x16_BNL::setColMap(int* colMap) {
    for (int i = 0; i < SIZE; i++) {
        _colMap[i] = colMap[i];
    }
}

void FSR16x16_BNL::setRowMapReverse() {
    for (int i = 0; i < SIZE; i++) {
        rowMap[i] = SIZE - 1 - i;
    }
}

void FSR16x16_BNL::setColMapReverse() {
    for (int i = 0; i < SIZE; i++) {
        colMap[i] = SIZE - 1 - i;
    }
}