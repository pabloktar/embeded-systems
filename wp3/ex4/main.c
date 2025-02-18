// (C) Pavlo Ovchynnykov, Stefan Tram, Danis Music, group 19 (2025)
// Work package 3
// Exercise 4
// Submission code: 631050


// Pin macros
#define COL4 4
#define COL3 5
#define COL2 6
#define COL1 7
#define ROW4 8
#define ROW3 9
#define ROW2 10
#define ROW1 11

// Keypad keys
char KEYS[][4] = {{'1', '2', '3', 'A'},
				{'4', '5', '6', 'B'},
				{'7', '8', '9', 'C'},
 				{'*', '0', '#', 'D'}};

// Arrays for rows and columns
int rows[] = {ROW1, ROW2, ROW3, ROW4};
int cols[] = {COL1, COL2, COL3, COL4};

void setup()
{
  // Set up columns as input and rows as output
  pinMode(COL4, INPUT);
  pinMode(COL3, INPUT);
  pinMode(COL2, INPUT);
  pinMode(COL1, INPUT);
  pinMode(ROW4, OUTPUT);
  pinMode(ROW3, OUTPUT);
  pinMode(ROW2, OUTPUT);
  pinMode(ROW1, OUTPUT);

  
  // Open serial at port 9600
  Serial.begin(9600);
  
  // Set default values for output pins(rows) as high
  digitalWrite(ROW4, HIGH);
  digitalWrite(ROW3, HIGH);
  digitalWrite(ROW2, HIGH);
  digitalWrite(ROW1, HIGH);
}


// Funciton detecting which key is pressed and printing the key in the serial if any.
void detect_key();

void loop()
{
  // detect what key is pressed
  detect_key();
  
  // wait 1 sec
  delay(1000);
}




void detect_key() {
 
  // iterate over rows
  for(int i = 0; i < 4; i++){
    // set the row to LOW
	digitalWrite(rows[i], LOW);
    
    // iterate over columns
    for(int j = 0; j < 4; j++){
      // check if the key is pressed by checking the voltage on the pin
      if(digitalRead(cols[j]) == LOW){
        // print the key
      	Serial.println(KEYS[i][j]);
      }
    }
    
    // set the row back to HIGH
    digitalWrite(rows[i], HIGH);
  }
}
