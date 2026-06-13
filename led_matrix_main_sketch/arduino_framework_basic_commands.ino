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