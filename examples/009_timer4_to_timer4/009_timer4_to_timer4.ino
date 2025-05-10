#include <Arduino.h>
#include <FSR16x16_BNL.h>

// Define the row pins for Timer4
const int ROW_CLEAR_PIN = 9;  // Clear pin for Timer4 (row)
const int ROW_CLEAR_TYPE = FALLING; // Active edge type for clear (row)
const int ROW_CLOCK_PIN = 10; // Clock pin for Timer4 (row)
const int ROW_CLOCK_TYPE = RISING; // Active edge type for clock (row)

// Define the column pins for Timer4
const int COL_CLEAR_PIN = 6;  // Clear pin for Timer4 (column)
const int COL_CLEAR_TYPE = FALLING; // Active edge type for clear (column)
const int COL_CLOCK_PIN = 7; // Clock pin for Timer4 (column)
const int COL_CLOCK_TYPE = RISING; // Active edge type for clock (column)
const int OUTPUT_PIN = A0; // Output pin for the multiplexer (analog pin)

// Initialize the sensor in Timer4-to-Timer4 mode
FSR16x16_BNL sensor(
    TIMER4, ROW_CLEAR_PIN, ROW_CLEAR_TYPE, ROW_CLOCK_PIN, ROW_CLOCK_TYPE, 
    TIMER4, COL_CLEAR_PIN, COL_CLEAR_TYPE, COL_CLOCK_PIN, COL_CLOCK_TYPE, OUTPUT_PIN
);

void setup() {
    Serial.begin(115200);
    Serial.println("FSR16x16_BNL Timer4-to-Timer4 Example Starting...");

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
