// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 3
// Exercise 2
// Submission code: 631050
//Pins
int const tempSensorPin = A0; // Declare pin connected to temperature sensor 
int const lightSensorPin = A1; // Declare pin connected to photoresistor
int const greenLED = 12; // Declare pin connected to green led
int const redLED = 11; // Declare pin connected to red led 
int const blueLED = 10; // Declare pin connected to blue led

//Constants
int const ANALOG_DECIMAL_CONV = 1023.0; // Constant used for analog decimal converter
float const MAX_LIGHT_VALUE =  1017.0; // Constant storing the max value of photoresistor
int const PERIODICITY = 1000; // Constant storing delay in milliseconds

//Variables
char buffer[50]; // Declare string used for defining size of print output
char tempString[10]; // Declare string for storing temperature in celsius
char lightString[10]; // Declare string for storing light decimal


void setup()
{
  pinMode(tempSensorPin, INPUT); // Configure pin to be input for temperature sensor
  pinMode(lightSensorPin, INPUT); // Configure pin to be input for light sensor
  pinMode(greenLED, OUTPUT); // Configure pin to be output green led
  pinMode(redLED, OUTPUT); // Configure pin to be output for red led
  pinMode(blueLED, OUTPUT); // Configure pin to be output for blue led
  Serial.begin(9600); // Start serial monitor
}

void loop()
{
  int tempReading  = analogRead(tempSensorPin); // read value from temperature sensor
  int lightReading = analogRead(lightSensorPin); // read value from light sensor
  float voltage = ((float)tempReading / ANALOG_DECIMAL_CONV) * 5000.0; // Convert value read from the temperature sensor into voltage
  
  float temperatureInC = (voltage - 500.0) * 0.1; // Convert the voltage to temperature in celcius
  float lightDecimal = (MAX_LIGHT_VALUE - lightReading) / (MAX_LIGHT_VALUE - 344.0); // Turn the value read from the light sensor into a decimal

  dtostrf(temperatureInC, 6, 2, tempString); // Cast the float into a string
  dtostrf(lightDecimal, 6, 2, lightString); // Cast the float into a string

  float maxTemp = 125.0, minTemp = -40.0; // Declare and initialize the range the for the temperature
  
  if (lightDecimal == 0.00) { // If no light is detected
  	minTemp = -50.0; // Assign min temperature to -50 C
    maxTemp = -11.0; // Assign max temperature to -11 C
  } else if (lightDecimal >= 0.01 && lightDecimal <= 0.20) { // If the light is within the range 0.01-0.2
  	minTemp = -12.0; // Assign min temperature to -12 C
    maxTemp = 0.0; // Assign max temperature to 0 C
  } else if (lightDecimal > 0.20 && lightDecimal <= 0.60) { // If the light is within the range 0.2-0.6
  	minTemp = 0.0; // Assign min temperature to 0 C
    maxTemp = 20.0; // Assign max temperature to 20 C
  } else if (lightDecimal > 0.60 && lightDecimal <= 1.0) { // If the light is within the range 0.6-1.0
  	minTemp = 21.0; // Assign min temperature to 21 C
    maxTemp = 125.0; // Assign max temperature to 125 C
  }
  
  if ((temperatureInC >= minTemp) && (temperatureInC <= maxTemp)) { // If temperature is within threshold
    digitalWrite(redLED, LOW); // Make red led not glow
    digitalWrite(greenLED, HIGH); // Make green led glow
    digitalWrite(blueLED, LOW); // Make blue led not glow
  } else if (temperatureInC > maxTemp) { // If temperature is greater than maximum
  	digitalWrite(redLED, HIGH); // Make red led glow
    digitalWrite(greenLED, LOW); // Make green led not glow
    digitalWrite(blueLED, LOW); // Make blue led not glow
  } else if (temperatureInC < minTemp) { // If temperature is smaller than minimum
    digitalWrite(redLED, LOW); // Make red led not glow
    digitalWrite(greenLED, LOW); // Make green led not glow
	digitalWrite(blueLED, HIGH); // Make blue led glow
  }
  
  snprintf(buffer, sizeof(buffer), "Temperature: %s degrees C, Lighlevel: %s", tempString, lightString); // Set the string of buffer to the temperature in celcius and the light as a decimal
  Serial.println(buffer); // Print out the buffer

  delay(PERIODICITY); // Delayt by 1 second
}
