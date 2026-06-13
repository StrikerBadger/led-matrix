#include <math.h>

void createInitialState() {
  // Make sure the output is off (the board is off is OE pin is high)
  digitalWrite(PIN_OE, HIGH);
  // Set latch to low
  digitalWrite(PIN_LAT, LOW);
  // Set all other pins also to low
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, LOW);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_CLK, LOW);
  digitalWrite(PIN_R1, LOW);
  digitalWrite(PIN_G1, LOW);
  digitalWrite(PIN_B1, LOW);
  digitalWrite(PIN_R2, LOW);
  digitalWrite(PIN_G2, LOW);
  digitalWrite(PIN_B2, LOW);
}

// Loads pixel array into the row(s)
// Precondition: CLK is off (LOW)
void loadPixelsIntoRow(int pixelsUpper[], int pixelsLower[]) {
  int numPixelsUpper = sizeof(pixelsUpper)/(3*sizeof(pixelsUpper[0]));
  int numPixelsLower = sizeof(pixelsLower)/(3*sizeof(pixelsLower[0]));

  // Tests to warn about unexpected panel behaviour
  if (numPixelsUpper > PANELWIDTH) {
    printf("Warning: Pixel-Array passed is bigger than the row itself. Pixel-Array: %s\n", pixelsUpper);
  }
  if (numPixelsUpper != numPixelsLower) {
    printf("Warning: Pixel-Array sizes don't match. Pixel-Arrays: %s, %s\n", pixelsUpper, pixelsLower);
  }

  for (int i = 0; i < max(numPixelsUpper, numPixelsLower); i++) {
    // Set the pixel values
    digitalWrite(PIN_R1, pixelsUpper[i*3]);
    digitalWrite(PIN_G1, pixelsUpper[i*3+1]);
    digitalWrite(PIN_B1, pixelsUpper[i*3+2]);
    digitalWrite(PIN_R2, pixelsLower[i*3]);
    digitalWrite(PIN_G2, pixelsLower[i*3+1]);
    digitalWrite(PIN_B2, pixelsLower[i*3+2]);
    // Advance by clocking
    digitalWrite(PIN_CLK, HIGH);
    digitalWrite(PIN_CLK, LOW);
  }
}
// Postcondition: Pixels are loaded, CLK is off (LOW)

