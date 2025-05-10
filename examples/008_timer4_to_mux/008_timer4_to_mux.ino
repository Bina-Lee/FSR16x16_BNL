#include <Arduino.h>
#include <FSR16x16_BNL.h>

// Define the row pins for Timer4
const int ROW_CLEAR_PIN = 9;  // Clear pin for Timer4
const int ROW_CLEAR_TYPE = FALLING; // Active edge type for clear
const int ROW_CLOCK_PIN = 10; // Clock pin for Timer4
const int ROW_CLOCK_TYPE = RISING; // Active edge type for clock

// Define the column pins (DE_MUX configuration)
const int COL_PINS[4] = {2, 3, 4, 5}; // 4 pins for column multiplexer selection
const int OUTPUT_PIN = A0; // Output pin for the multiplexer (analog pin)

// Initialize the sensor in Timer4-to-DE_MUX mode
FSR16x16_BNL sensor(TIMER4, ROW_CLEAR_PIN, ROW_CLEAR_TYPE, ROW_CLOCK_PIN, ROW_CLOCK_TYPE, DE_MUX, COL_PINS, OUTPUT_PIN);

void setup() {
    Serial.begin(115200);
    Serial.println("FSR16x16_BNL Timer4-to-DE_MUX Example Starting...");

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
