
// // Data Pins
// #define PIN_R1 26
// #define PIN_G1 25
// #define PIN_B1 27
// #define PIN_R2 12
// #define PIN_G2 14
// #define PIN_B2 18

// // Control Pins
// #define PIN_CLK 4
// #define PIN_LAT 16
// #define PIN_OE  13

// // Address Pins
// #define PIN_A 19
// #define PIN_B 23
// #define PIN_C 17
// #define PIN_D 5
// #define PIN_E 2  

// #define NUM_ROWS 64
// #define NUM_COLS 128
// #define NUM_LOGICAL_ROWS NUM_ROWS/2

// void setup() {
//   pinMode(PIN_R1, OUTPUT); pinMode(PIN_G1, OUTPUT); pinMode(PIN_B1, OUTPUT);
//   pinMode(PIN_R2, OUTPUT); pinMode(PIN_G2, OUTPUT); pinMode(PIN_B2, OUTPUT);
//   pinMode(PIN_CLK, OUTPUT); pinMode(PIN_LAT, OUTPUT); pinMode(PIN_OE, OUTPUT);
  
//   pinMode(PIN_A, OUTPUT); pinMode(PIN_B, OUTPUT); 
//   pinMode(PIN_C, OUTPUT); pinMode(PIN_D, OUTPUT);
//   pinMode(PIN_E, OUTPUT);

//   // First Row
//   digitalWrite(PIN_A, LOW);
//   digitalWrite(PIN_B, LOW);
//   digitalWrite(PIN_C, LOW);
//   digitalWrite(PIN_D, LOW);
//   digitalWrite(PIN_E, LOW);

//   // disable outputs
//   digitalWrite(PIN_OE, HIGH);
//   digitalWrite(PIN_LAT, LOW);
  
//   // Clock is first off
//   digitalWrite(PIN_CLK, LOW);

//   // Set color to full white
//   digitalWrite(PIN_R1, HIGH);
//   digitalWrite(PIN_G1, HIGH);
//   digitalWrite(PIN_B1, HIGH);
//   digitalWrite(PIN_R2, HIGH);
//   digitalWrite(PIN_G2, HIGH);
//   digitalWrite(PIN_B2, HIGH);

//   // Pre-fill the whole row with the white pixels, keep that for the whole run
//   for (int i = 0; i < NUM_COLS; i++) {
//     digitalWrite(PIN_CLK, HIGH);
//     digitalWrite(PIN_CLK, LOW);
//   }
// }

// void loop() {
//     for (int y = 0; y < NUM_LOGICAL_ROWS; y++) {
//       // Disengage Latch
//       digitalWrite(PIN_LAT, LOW);
//       // Set the row address
//       digitalWrite(PIN_A, y & 1);
//       digitalWrite(PIN_B, y & (1 << 1));
//       digitalWrite(PIN_C, y & (1 << 2));
//       digitalWrite(PIN_D, y & (1 << 3));
//       digitalWrite(PIN_E, y & (1 << 4));
//       // Latch the row
//       digitalWrite(PIN_LAT, HIGH);
//       // Enable Output for 15 microseconds
//       digitalWrite(PIN_OE, LOW);
//       delayMicroseconds(1);
//       // And then have it turned off for 85 microseconds
//       digitalWrite(PIN_OE, HIGH);
//       delayMicroseconds(99);
//     } 
// }