// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 3
// Exercise 3
// Submission code: 631050

// Define the analog input pin for the temperature sensor
#define Temp_Sensor 0  

void setup()
{
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);  
}

void loop()
{
  // Read the analog value from the temperature sensor
  int ADCV = analogRead(Temp_Sensor);
  // Convert the ADC value to voltage
  float Vout = (ADCV * 5.0) / 1023;
  // Convert voltage to millivolts (1V = 1000mV)
  float miliV = Vout * 1000;
  // Calculate temperature in Celsius using the formula: Temp (°C) = (Vout in mV - 500) / 10
  float tempC = (miliV - 500) / 10;

  Serial.print("Temperature: ");  // Print the temperature value to the Serial Monitor
  Serial.print(tempC);   // Print the temperature value without a new line
  Serial.println(" C");  // Print the unit "C" with a new line

  // Wait for 1000 millisecond) before looping again
  delay(1000);
}

