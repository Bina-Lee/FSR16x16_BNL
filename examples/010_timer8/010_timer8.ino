#include <Arduino.h>
#include <FSR16x16_BNL.h>

// Define the pins for Timer8
const int CLEAR_PIN = 9;  // Clear pin for Timer8
const int CLEAR_TYPE = FALLING; // Active edge type for clear
const int CLOCK_PIN = 10; // Clock pin for Timer8
const int CLOCK_TYPE = RISING; // Active edge type for clock
const int OUTPUT_PIN = A0; // Output pin for the multiplexer (analog pin)

// Initialize the sensor in Timer8 mode
FSR16x16_BNL sensor(TIMER8, CLEAR_PIN, CLEAR_TYPE, CLOCK_PIN, CLOCK_TYPE);

void setup() {
    Serial.begin(115200);
    Serial.println("FSR16x16_BNL Timer8 Example Starting...");

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
