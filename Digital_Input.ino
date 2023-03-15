//

void UpdateButtonInput()
{
    // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);


  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState)
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) 
    {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) 
      {
        ledState = !ledState;
        EncoderPosition = AnalogReadValue;        
      }// end if (buttonState == HIGH)
    }// end if (reading != buttonState) 
  }// end if ((millis() - lastDebounceTime) > debounceDelay) 

  // set the LED on pin 13:
  digitalWrite(ledPin, ledState);
  Serial.println(ledState);
  InputTypeState = ledState;

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}//end void UpdateButtonInput()