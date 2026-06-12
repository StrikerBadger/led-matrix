// #include <math.h>

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

// // Panel Dimensions
// #define PANEL_WIDTH 128
// #define PANEL_HEIGHT 64
// #define ROW_PAIRS (PANEL_HEIGHT / 2)

// #define ATOL 0.75

// // Framebuffer arrays
// bool frame_R[PANEL_HEIGHT][PANEL_WIDTH];
// bool frame_G[PANEL_HEIGHT][PANEL_WIDTH];
// bool frame_B[PANEL_HEIGHT][PANEL_WIDTH];

// // BRIGHTNESS PWM CONFIGURATION
// // Total time budget per row in microseconds
// const int TOTAL_ROW_TIME_US = 20; 
// // 15% of 100 microseconds = 15 microseconds active
// const int ON_TIME_US = TOTAL_ROW_TIME_US;  
// // The remaining 85% of the time, the display is forced off
// const int OFF_TIME_US = TOTAL_ROW_TIME_US - ON_TIME_US; 

// void setup() {
//   pinMode(PIN_R1, OUTPUT); pinMode(PIN_G1, OUTPUT); pinMode(PIN_B1, OUTPUT);
//   pinMode(PIN_R2, OUTPUT); pinMode(PIN_G2, OUTPUT); pinMode(PIN_B2, OUTPUT);
//   pinMode(PIN_CLK, OUTPUT); pinMode(PIN_LAT, OUTPUT); pinMode(PIN_OE, OUTPUT);
  
//   pinMode(PIN_A, OUTPUT); pinMode(PIN_B, OUTPUT); 
//   pinMode(PIN_C, OUTPUT); pinMode(PIN_D, OUTPUT);
//   pinMode(PIN_E, OUTPUT);

//   digitalWrite(PIN_OE, HIGH);
//   digitalWrite(PIN_LAT, LOW);
//   digitalWrite(PIN_CLK, LOW);

//   // Fill framebuffer with white (All channels 1)
//   for (int y = 0; y < PANEL_HEIGHT; y++) {
//     for (int x = 0; x < PANEL_WIDTH; x++) { 
//       frame_R[y][x] = 0;
//       frame_G[y][x] = 0;
//       frame_B[y][x] = 0;
//       if (abs(pow(-1.1, x-64) + 32 - y) <= ATOL) {
//         frame_B[y][x] = 1;
//         frame_R[y][x] = 1;
//       }
//     }
//   }
// }

// void setRowAddress(int row) {
//   digitalWrite(PIN_A, row & 0x01);
//   digitalWrite(PIN_B, (row >> 1) & 0x01);
//   digitalWrite(PIN_C, (row >> 2) & 0x01);
//   digitalWrite(PIN_D, (row >> 3) & 0x01);
//   digitalWrite(PIN_E, (row >> 4) & 0x01);
// }

// void loop() {
//   for (int row = 0; row < ROW_PAIRS; row++) {
    
//     // 1. Shift data in for the current row
//     for (int col = 0; col < PANEL_WIDTH; col++) {
//       int top_y = row;
//       int bot_y = row + ROW_PAIRS;

//       digitalWrite(PIN_R1, frame_R[top_y][col]);
//       digitalWrite(PIN_G1, frame_G[top_y][col]);
//       digitalWrite(PIN_B1, frame_B[top_y][col]);

//       digitalWrite(PIN_R2, frame_R[bot_y][col]);
//       digitalWrite(PIN_G2, frame_G[bot_y][col]);
//       digitalWrite(PIN_B2, frame_B[bot_y][col]);

//       digitalWrite(PIN_CLK, HIGH);
//       digitalWrite(PIN_CLK, LOW);
//     }

//     // 2. Prepare panel and Latch the data
//     digitalWrite(PIN_OE, HIGH);       
//     setRowAddress(row);               
    
//     digitalWrite(PIN_LAT, HIGH);      
//     digitalWrite(PIN_LAT, LOW);

//     // 3. 15% PWM Brightness Execution Phase
//     digitalWrite(PIN_OE, LOW);         // Turn LEDs ON
//     delayMicroseconds(ON_TIME_US);     // Keep on for 15% of the window (15us)
    
//     digitalWrite(PIN_OE, HIGH);        // Turn LEDs OFF
//     delayMicroseconds(OFF_TIME_US);    // Pad out the remaining 85% of the window (85us)
//   }
// }