void DisplaySplashScreen()
{
//update the display with the values from the read
  u8g2.firstPage();
  do {
    //top line (in yelllow)
    u8g2.setFont(u8g2_font_ncenB12_tr);
    u8g2.setCursor(0,12);               
    u8g2.println("Dial-A-Dongle!");
	u8g2.setCursor(0,40);
	u8g2.println("Dail-A-Dongle setting up...");

  } while ( u8g2.nextPage() );

}	

void UpdateDisplayAnalog(int temp)
{
//update the display with the values from the read
  u8g2.firstPage();
  do {
    //top line (in yelllow)
    u8g2.setFont(u8g2_font_ncenB12_tr);
    u8g2.setCursor(0,12);               
    // u8g2.println("Dial-A-Dongle!");
	u8g2.print("PORT-D "); //print text
	u8g2.print(PORTD,BIN); //print port output

    //next line of display space
    u8g2.setFont(u8g2_font_ncenB24_tr);
    u8g2.setCursor(0,40);				//was 45, needed to be moved up
    u8g2.print("Hex= ");  
    u8g2.setCursor(85,40);				//was 45, needed to be moved up
    u8g2.println(temp,HEX);

    //bottom line of display
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setCursor(0,60);				//was 64, but screen is blocked by case
    u8g2.print("PVE Part ");  
    u8g2.setCursor(75,60);				//was 64, but screen is blocked by case
    u8g2.println(PartNumber(temp));
  } while ( u8g2.nextPage() );

}

void UpdateDisplayEncoder(int temp)
{
//update the display with the values from the read
  u8g2.firstPage();
  do {
    //top line (in yelllow)
    u8g2.setFont(u8g2_font_ncenB12_tr);
    u8g2.setCursor(0,12);               
    // u8g2.println("Dial-A-Dongle!");
	u8g2.print("PORT-D "); //print text
	u8g2.print(PORTD,BIN); //print port output

    //next line of display space
    u8g2.setFont(u8g2_font_ncenB24_tr);
    u8g2.setCursor(0,40);				//was 45, needed to be moved up
    u8g2.print("Hex= ");  
    u8g2.setCursor(85,40);				//was 45, needed to be moved up
    u8g2.println(temp,HEX);

    //bottom line of display
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setCursor(0,60);				//was 64, but screen is blocked by case
    u8g2.print("PVE Part ");  
    u8g2.setCursor(75,60);				//was 64, but screen is blocked by case
    u8g2.println(PartNumber(temp));
  } while ( u8g2.nextPage() );

}