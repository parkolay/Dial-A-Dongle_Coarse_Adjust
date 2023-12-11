/*  Dial-A-Dongle
 *  // Pinout
 *  //  Input     --> A00;  // used in prototype
 *  //  Batt mon  --> A01;
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
 *  //  Engage    --> D12;
 *  //  LED       --> D13;
 *  //  SCL       --> A04; Tied HIGH W/ 1k7 Ohm resistor
 *  //  SDA       --> A05; Tied HIGH W/ 1k7 Ohm resistor
 *
 * //   DAP  initial check-in  02-09-2023  
 */

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <Battery.h>

// This optional setting causes Encoder to use more optimized code,
// It must be defined before Encoder.h is included.
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

//assign Encoder Knob to Encoder library
Encoder EncoderKnob(10, 11);

  int RawAnalog       = 0;
  int FilteredAnalog  = 0;
  int AnalogReadValue = 0;
  int AnalogReadBattValue = 0;
  int ledState        = HIGH; // the current state of the output pin
  int buttonState;            // the current reading from the input pin
  int PortCtrl;               // chose not to give it an initialized state 
  int lastButtonState = LOW;  // the previous reading from the input pin
  int InputTypeState  = 0;    // toggle between course and fine adjust mode 

  const int BATT_MON  = A1;   //set analog 1 as batt sense pin
  const int SET_PIN   = A2;   //Analog pin for setting the value with a potentiometer
  const int buttonPin = 8;    // the number of the pushbutton pin
  const int engage    = 12;   // used to engage Port-d output, I know, engage is a funny word for enable.
  const int ledPin    = 13;   // the number of the LED pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
  unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

  long oldPosition  = -999;
  long EncoderPosition = 0;



//assign Batt to Battery library
Battery batt = Battery(3200, 4500, BATT_MON);  //6.4V is battery low


//tell the library which OLED is connected and how
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) 
{
  //DDRD = B11111111; // set PORTD (digital 7~0) to outputs
  u8g2.begin();     //initialize the OLED library
  DisplaySplashScreen();
  // Serial.begin(115200); //setup serial even if it never gets used
  // Serial.println("Dail-A-Dongle setting up...");

  // specify an activationPin & activationMode for on-demand configurations
  //batt.onDemand(3, HIGH);
  batt.begin(3500, 2.0);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(engage,INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
  
}

void loop(void) 
{
  UpdateButtonInput();

    PortCtrl = digitalRead(engage);

    if (InputTypeState == HIGH)     //has the momentary switch been pushed to change state to HIGH?
    { 
      int temp = Update_Analog();   //update_analog() has a return that will set the temp variable
      if (PortCtrl == LOW)
      {     
        DDRD = B11111111;           // set PORTD (digital 7~0) to outputs
        PORTD = temp;               //push the analog read value to PORTD       
      }//end if (engage == true)
      else 
      {
        DDRD = B00000000; //was DDRD = B00000010;
                          // set PORTD (digital 7~0) to "mostly" inputs" 
                          // this leaves the Tx pin set as an output and
                          // the possibility of pn-11 to trigger a fault
                          //this did set hex 0x02 and it was changed to all 0's

      }
        UpdateDisplayAnalog(temp);  //now we send that same temp variable to another function
        EncoderKnob.write(temp);    //we use the same temp variable one more time before we leave this area} 
    }//end if (InputTypeState == HIGH)

    else if (InputTypeState == LOW) //has the momentary switch been pushed to change state to LOW?
    {
      int temp = UpdateEncoder();
      if (PortCtrl == LOW)
      {      
        DDRD = B11111111; // set PORTD (digital 7~0) to outputs
        PORTD = temp;     //push the analog read value to PORTD
      }//end if (engage == true) 
      else 
      {
        DDRD = B00000000; // set PORTD (digital 7~0) to "mostly" inputs"       
      }

      UpdateDisplayEncoder(temp);
    }// end else if (InputTypeState == LOW) 

  //delay(500);//delay here to maybe let the adc settle?
}//end void loop(void) 