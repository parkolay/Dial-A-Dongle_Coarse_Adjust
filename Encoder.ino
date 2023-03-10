void UpdateEncoder()
{
  long newPosition = EncoderKnob.read();
  
  if (newPosition != oldPosition) 
  {
    oldPosition = newPosition;
    EncoderPosition = oldPosition;
    Serial.println(newPosition);

  //set constraints on EncoderPosition
    if (EncoderPosition <= 0)
    {
      EncoderPosition = 0;
    }
    else if (EncoderPosition >= 0x7F)
    {
      EncoderPosition = 0x7F;
    }
      Serial.println(EncoderPosition);

  }//end if (newPosition != oldPosition)
  
}//end void UpdateEncoder()