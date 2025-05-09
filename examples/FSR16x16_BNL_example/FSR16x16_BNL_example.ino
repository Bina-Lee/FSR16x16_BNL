#include <Arduino.h>
#include <FSR16x16_BNL.h>

// Define the pins
const int CLEAR_PIN = 5;    // Digital pin for counter clear/reset
const int CLOCK_PIN = 6;    // Digital pin for counter clock signal
const int ANALOG_PIN = A0;  // Analog pin for multiplexer output

// Initialize the sensor in TIMER8 mode (8-bit counter with clock/clear control)
FSR16x16_BNL sensor(TIMER8, CLEAR_PIN, RISING, CLOCK_PIN, RISING);

void setup() {
    Serial.begin(115200);
    Serial.println("FSR16x16_BNL Example Starting...");

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