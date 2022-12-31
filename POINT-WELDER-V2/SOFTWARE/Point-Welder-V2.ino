/***************************************************
    HJERNEN ("The Brain")

    Functionality:
    - Adjust value of ms (miliseconds)
    - Relay-programming
    - Button for opening the relay 
    - OLED screen showing ms value
    - Potentiometer for changing the ms value
***************************************************/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED oled width,  in pixels
#define SCREEN_HEIGHT 32  // OLED oled height, in pixels

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);  // Declare SSD1306 oled connected to I2C


/*** Global variables ***/
// Constants
const int msPIN = A0;                   // Analog INPUT value of potentiometer at pin 19 (A0)
const int impulseVoltagePIN = 12;       // Impulse switch OUTPUT at pin 15 (D12)
const int impulseReadPIN = 11;          // Impulse switch INPUT (read) at pin 14 (D11)
const int weldSignalPIN = 2;            // BS170 gate OUTPUT signal at pin 5 (D2)
const int LED_G = 8;                    // Green LED OUTPUT (D8)
const int LED_R = 9;                    // Red LED OUTPUT (D9)
const long millisInterval = 500;        // 500 ms
const int N = 31;                       // Number of values in compArray

// Variables and start-values
bool weld = false;                  // Boolean help variable with start-value
bool updateOLED_bool = false;       // Boolean help variable with updating the OLED
int msVAL = 0;                      // Default start ms-value  
unsigned long previousMillis = 0;   // Timing
int compArray[N];                   // Helper array with 30 ints


/*** Setup ***/
void setup() {
  // Array setup
  compArray[0] = 50;  // First index value is 50 (ms)
  for (unsigned int i = 1; i < N; i++) {
    compArray[i] = compArray[i-1] + 5;
  }

  // PIN setup
  pinMode(impulseReadPIN, INPUT);
  pinMode(impulseVoltagePIN, OUTPUT);      
  pinMode(weldSignalPIN, OUTPUT);           
  pinMode(msPIN, INPUT);    
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);               

  // Interrupt setup
  attachInterrupt(digitalPinToInterrupt(impulseReadPIN), triggerWeld, RISING);  // Triggers when pin goes from LOW to HIGH

  // OLED oled and startup
  // initialize OLED oled with address 0x3C for 128x32
  // Don't set pinMode when dealing with OLED (!), it uses I2C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("[ERROR] SSD1306 allocation failed"));
    while (true);
  }
  delay(2000);
  oled.clearDisplay();
  oled.display();

  // Initial setup
  digitalWrite(impulseVoltagePIN, HIGH);  // Set +5V on the pin
  digitalWrite(LED_G, HIGH);
}


/*** Main loop ***/
void loop() {
  // Welding
  if (weld) {
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);      // Built-in LED indicator
    digitalWrite(weldSignalPIN, HIGH);    // Start weld - keep close to delay() for accuracy
    delay(msVAL);                         // Weld time
    digitalWrite(weldSignalPIN, LOW);     // Stop weld
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    delay(1000);                          // Extra delay to ensure no double-interrupt on same button-push

    // Need to set weld = false here to ensure no double-interrupt-calling. This cooperates with the previous delay() to ensure only one weld each time the button is (quickly) pressed
    weld = false;                         // Set weld to false for next iteration
  }

  // Update ms-value
  msUpdate();                // Update ms value and OLED print settings
  oled.display();            // Update OLED display
}

/*** Functions ***/
// Interrupt handler
void triggerWeld() {
  weld = true;           
}

// Update ms and OLED
void msUpdate() {
  msVAL = analogRead(msPIN);                // Read analog signal 
  msVAL = map(msVAL, 0, 1023, 50, 203);     // Update msVAL and map analog input to between 50-200 ms

  compareWithArray();                       // Map value again to get steps and more stable ms value
  updateOLED();                             // Update OLED print settings
}

// Compare value and map to steps from compArray
void compareWithArray() {
  for (unsigned int i = 1; i < N; i++) {
    if (msVAL > compArray[i-1] && msVAL < compArray[i]) {
      int diffFloor = msVAL - compArray[i-1];
      int diffCeil = compArray[i] - msVAL;

      if (diffFloor > diffCeil) {
        msVAL = compArray[i];
      } else {
        msVAL = compArray[i-1];
      }
    }
  }
}

// OLED
void updateOLED() {
  oled.clearDisplay();
  oled.setTextSize(3);        
  oled.setTextColor(WHITE);      
  oled.setCursor(0, 5);
  oled.print(msVAL);
  oled.print(" ms");
}