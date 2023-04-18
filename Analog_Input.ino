//return the analog read value as an integer 

int Update_Analog()
{
    AnalogReadValue = analogRead(SET_PIN); //read the analog input
    // Serial.print("RawAnalogReadValue ");  
    // Serial.println(AnalogReadValue);     
    AnalogReadValue = map(AnalogReadValue,0,1023,0,127);// using the map function 
    // Serial.print("Processed AnalogReadValue ");  
    // Serial.println(AnalogReadValue);  
    return AnalogReadValue;
}//end int Update_Analog()