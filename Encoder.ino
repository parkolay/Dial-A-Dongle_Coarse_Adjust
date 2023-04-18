// 
// 

int UpdateEncoder()  
{
  long  newPosition = EncoderKnob.read(); //read encoder postion and set temp varible
  
  if (newPosition != oldPosition) 
  {
    oldPosition = newPosition;
    EncoderPosition = oldPosition;
    // Serial.print("newPosition ");
    // Serial.println(newPosition);

  //set constraints on EncoderPosition
    if (EncoderPosition <= 0)
    {
      EncoderPosition = 0;
    }
    else if (EncoderPosition >= 0x7F)
    {
      EncoderPosition = 0x7F;
    }
      // Serial.println(EncoderPosition);

  }//end if (newPosition != oldPosition) 
  return EncoderPosition;
}//end int UpdateEncoder()