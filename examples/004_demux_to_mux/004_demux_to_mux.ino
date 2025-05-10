#include <Arduino.h>
#include <FSR16x16_BNL.h>

// Define the row pins (DE_MUX connection)
const int ROW_PINS[4] = {6, 7, 8, 9}; // 4 pins for demultiplexer selection

// Define the column pins (DE_MUX connection)
const int COL_PINS[4] = {2, 3, 4, 5}; // 4 pins for multiplexer selection
const int OUTPUT_PIN = A0; // Output pin for the multiplexer (analog pin)

// Initialize the sensor in DE_MUX-to-DE_MUX mode
FSR16x16_BNL sensor(DE_MUX, ROW_PINS, DE_MUX, COL_PINS, OUTPUT_PIN);

void setup() {
    Serial.begin(115200);
    Serial.println("FSR16x16_BNL DE_MUX-to-DE_MUX Example Starting...");

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
