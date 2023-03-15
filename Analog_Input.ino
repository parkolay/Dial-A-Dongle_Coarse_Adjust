//return the analog read value as an integer 

int Update_Analog()
{
    AnalogReadValue = analogRead(SET_PIN); //read the analog input
    AnalogReadValue = map(AnalogReadValue,520,1018,0,127);// using the map function   
    return AnalogReadValue;
}//end int Update_Analog()