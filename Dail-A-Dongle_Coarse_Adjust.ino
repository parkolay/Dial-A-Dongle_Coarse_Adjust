/*  Dial-A-Dongle
 *  // Pinout
 *  //  Input     --> A02;
 *  //  BIT 1     --> D00;
 *  //  BIT 2     --> D01;
 *  //  BIT 3     --> D02;
 *  //  BIT 4     --> D03;
 *  //  BIT 5     --> D04;
 *  //  BIT 6     --> D05;
 *  //  BIT 7     --> D06;
 *  //  BTN       --> D08;
 *  //  EncoderA  --> D10;
 *  //  EncoderB  --> D11;
 *  //  SCL       --> A04; Tied HIGH W/ 3k3 Ohm resistor
 *  //  SDA       --> A05; Tied HIGH W/ 3k3 Ohm resistor
 *
 * //   DAP  initial check-in  02-09-2023  
 */

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>


// This optional setting causes Encoder to use more optimized code,
// It must be defined before Encoder.h is included.
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

Encoder EncoderKnob(10, 11);

//tell the library which OLED is connected and how
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

  int RawAnalog       = 0;
  int FilteredAnalog  = 0;
  int AnalogReadValue = 0;
  int ledState = HIGH;        // the current state of the output pin
  int buttonState;            // the current reading from the input pin
  int lastButtonState = LOW;  // the previous reading from the input pin
  int InputTypeState = 0;     // toggle between course and fine adjust mode 

  const int SET_PIN   = A2;   //Analog pin for setting the dutyCycle value with a pontentiometer
  const int buttonPin = 8;    // the number of the pushbutton pin
  const int ledPin    = 13;   // the number of the LED pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
  unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

  long oldPosition  = -999;
  long EncoderPosition = 0;

void setup(void) 
{
  DDRD = B11111111; // set PORTD (digital 7~0) to outputs
  u8g2.begin();     //initialize the OLED library
  Serial.begin(115200); //setup serial even if it never gets used

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
  
}

void loop(void) 
{
  UpdateButtonInput();

    if (InputTypeState == HIGH)
    { 
      Update_Analog();
      PORTD = AnalogReadValue;  //push the analog read value to PORTD  
      UpdateDisplayAnalog();  
      EncoderPosition = AnalogReadValue;
    }// end if (InputTypeState == HIGH)

    else if (InputTypeState == LOW)
    {
      UpdateEncoder();
      PORTD = EncoderPosition;  //push the analog read value to PORTD
      UpdateDisplayEncoder();
    }//end else if (InputTypeState == LOW)

  //delay(500);//delay here to maybe let the adc settle?
}//end void loop(void) 