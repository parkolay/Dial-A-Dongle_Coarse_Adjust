void Update_Analog()
{
  //    //use the 10 bit analog input for 8 bit port to set 7 bit values 0x7F
    AnalogReadValue = analogRead(SET_PIN); //read the analog input
//   //write to line 2
//   lcd.setCursor(12,1);
//   lcd.print(AnalogRead);
  
//  // AnalogRead = AnalogRead >> 2;         //bit shift bottom two values 
//  // AnalogRead = AnalogRead - 128;        //remove top remaining bit value 
//  //similar to above but using the map function instead  
    AnalogReadValue = map(AnalogReadValue,520,1018,0,127);
}