// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 3
// Exercise 1
// Submission code: 631050

#define CTRLPIN 2 // PIN connected to LED

void setup() // The setup function runs once when the Arduino is powered on or reset.
{
  pinMode(CTRLPIN, OUTPUT); // Configure CTRLPIN as an output.
}

void loop() // The loop function.
{
  digitalWrite(CTRLPIN, HIGH); // Set CTRLPIN to HIGH (turning the LED on).
  delay(1000); // Pause the program for 1000 milliseconds (1 second)

  digitalWrite(CTRLPIN, LOW); // Set CTRLPIN to LOW (turning the LED off).
  delay(1000); // Pause the program for 1000 milliseconds (1 second)
}

