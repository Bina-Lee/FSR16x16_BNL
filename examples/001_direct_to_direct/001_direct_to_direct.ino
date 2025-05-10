#include <Arduino.h>
#include <FSR16x16_BNL.h>

// Define the row pins (Direct connection)
const int ROW_PINS[16] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37};

// Define the column pins (Analog pins for Direct connection)
const int COL_PINS[16] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};

// Initialize the sensor in Direct-to-Direct mode
FSR16x16_BNL sensor(DIRECT, ROW_PINS, DIRECT, COL_PINS);

void setup() {
    Serial.begin(115200);
    Serial.println("FSR16x16_BNL Direct-to-Direct Example Starting...");

    // Initialize sensor pins
    sensor.begin();
}

void loop() {
    // Read the full 16x16 matrix
    sensor.read();

    // Example: Get and print the center point (row 8, col 8)
    int centerValue = sensor.get(8, 8);
    Serial.print("Center point (8,8) value: ");
    Serial.println(centerValue);

    // Print the full matrix to Serial
    Serial.println("Full matrix:");
    sensor.print();

    // Wait for a second before the next reading
    delay(1000);
}
