# FSR16x16_BNL
A library for arduino/MCU to read value of 16x16 FSR array sensor

This Arduino library is designed to scan a 16x16 FSR (Force Sensitive Resistor) pressure sensor matrix using **only 3 GPIO pins**.  
It implements a hardware-efficient approach using **an 8-bit binary counter and an analog multiplexer**, controlled by minimal digital clock and clear signals.

This minimizes the typical 32-pin (16 rows + 16 columns) setup to:
- **1 analog input pin** (multiplexer output)
- **2 digital pins** (clock + clear signals)

---

## 🛠️ Features
✅ Read all 256 points in the FSR matrix  
✅ Minimal GPIO usage: only 3 pins required  
✅ Clock-signal-based control (no complex communication)  
✅ Designed for small MCUs like Arduino Nano  
✅ Provides complete matrix data for serial output or external visualization

---

## 🔌 Circuit Setup

To use the minimal 3-pin mode:
- **Counter**: 8-bit binary counter IC (e.g., 74HC590)  
- **Decoder/Multiplexer**: connected to counter outputs  
- **MCU Pins**:
    - `clearPin` (digital): counter reset
    - `clockPin` (digital): counter clock pulse
    - `analogPin` (analog): reads multiplexer output

> 📖 Refer to the accompanying design paper for detailed wiring diagrams.

![Circuit diagram sample](./explain/sample_circuit_diagram.jpeg)

---

## 📦 Installation

1. Place `FSR16x16_BNL.h` and `FSR16x16_BNL.cpp` into your Arduino project directory.
2. In your Arduino sketch, include the library:
    ```cpp
    #include "FSR16x16_BNL.h"
    ```

---

## 🧪 Example Usage

```cpp
#include <Arduino.h>
#include "FSR16x16_BNL.h"

// Define pins for minimal GPIO mode
const int clearPin = 5;    // Counter clear/reset pin
const int clockPin = 6;    // Counter clock pin
const int analogPin = A0;  // Analog multiplexer output

// Initialize sensor in TIMER8 mode (single 8-bit counter)
FSR16x16_BNL sensor(TIMER8, clearPin, RISING, clockPin, RISING);

void setup() {
    Serial.begin(115200);
    sensor.begin();
}

void loop() {
    // Read the full 16x16 matrix
    sensor.read();

    // Example 1: Access individual value
    int centerValue = sensor.get(8, 8);
    Serial.print("Center (8,8): ");
    Serial.println(centerValue);

    // Example 2: Print full matrix over Serial
    Serial.println("Full matrix:");
    sensor.print();

    // Wait before next scan
    delay(1000);
}
```

---

## 🔍 Available Functions

| Function                      | Description                                        |
| ----------------------------- | -------------------------------------------------- |
| `begin()`                     | Initializes pins and setup.                         |
| `read()`                      | Scans all 256 points and stores readings.          |
| `get(row, col)`               | Returns the value at specified (row, col).         |
| `print()`                     | Prints the full 16x16 matrix to Serial.           |
| `clockDelay(type, time)`      | Configures delay between clock pulses (if needed). |

---

## 💡 Notes

- **Make sure to wire the hardware exactly as described** in the provided design document for the 3-pin setup.
- This library also supports more complex setups (DIRECT, DEMUX, TIMER4), but its main goal is to demonstrate the **minimum GPIO 3-pin configuration**.
- For visualizing the data, you can forward the serial output to Python or Processing to create real-time pressure maps.=