// Data Pins
#define PIN_R1 26
#define PIN_G1 25
#define PIN_B1 27
#define PIN_R2 12
#define PIN_G2 14
#define PIN_B2 18

// Control Pins
#define PIN_CLK 4
#define PIN_LAT 16
#define PIN_OE  13

// Address Pins
#define PIN_A 19
#define PIN_B 23
#define PIN_C 17
#define PIN_D 5
#define PIN_E 2  

#define PANEL_HEIGHT 64
#define PANEL_WIDTH 128
#define NUM_SCANLINES 2

#define PRACTICAL_MAX_BRIGHTNESS 80.0
#define ROW_TIME_BUDGET_MICROSECONDS 100

unsigned int numAddressableRows = PANEL_HEIGHT/NUM_SCANLINES;
int* allWhite = new int[3*PANEL_WIDTH];

void setup() {
  // Set the pins into their respective modes
  pinMode(PIN_R1, OUTPUT); pinMode(PIN_G1, OUTPUT); pinMode(PIN_B1, OUTPUT);
  pinMode(PIN_R2, OUTPUT); pinMode(PIN_G2, OUTPUT); pinMode(PIN_B2, OUTPUT);
  pinMode(PIN_CLK, OUTPUT); pinMode(PIN_LAT, OUTPUT); pinMode(PIN_OE, OUTPUT);
  
  pinMode(PIN_A, OUTPUT); pinMode(PIN_B, OUTPUT); 
  pinMode(PIN_C, OUTPUT); pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);

  createInitialState();

  for (int i = 0; i < 3*PANEL_WIDTH; i++) {
    allWhite[i] = 1;
  }

  loadPixelsIntoRow(allWhite, allWhite);
}

void loop() {
  // Show all the white pixels at 50% brightness
  for (int y = 0; y < numAddressableRows; y++) {
    showRows(y, 50.0);
  }
}
