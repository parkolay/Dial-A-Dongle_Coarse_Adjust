void UpdateDisplayAnalog(int temp)
{
//update the display with the values from the read
  u8g2.firstPage();
  do {
    //top line (in yelllow)
    u8g2.setFont(u8g2_font_ncenB12_tr);
    u8g2.setCursor(0,12);               
    u8g2.println("Dial-A-Dongle!");

    //next line of display space
    u8g2.setFont(u8g2_font_ncenB24_tr);
    u8g2.setCursor(0,45);
    u8g2.print("Hex= ");  
    u8g2.setCursor(85,45);
    u8g2.println(temp,HEX);

    //bottom line of display
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setCursor(0,64);
    u8g2.print("PVE Part = ");  
    u8g2.setCursor(85,64);
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
    u8g2.println("Dial-A-Dongle!");

    //next line of display space
    u8g2.setFont(u8g2_font_ncenB24_tr);
    u8g2.setCursor(0,45);
    u8g2.print("Hex= ");  
    u8g2.setCursor(85,45);
    u8g2.println(temp,HEX);

    //bottom line of display
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setCursor(0,64);
    u8g2.print("PVE Part = ");  
    u8g2.setCursor(85,64);
    u8g2.println(PartNumber(temp));
  } while ( u8g2.nextPage() );

}