//

void DisplaySplashScreen()
{
//update the display with the values from the read
  u8g2.firstPage();
  do {
    //top line (in yelllow)
    u8g2.setFont(u8g2_font_ncenB12_tr);
    u8g2.setCursor(0,12);               
    //u8g2.println("Dial-A-Dongle!"); //these two lines increased the global varible by 2%
    //bottom line (in blue)
	  u8g2.setCursor(0,41);
	  //u8g2.println("Dail-A-Dongle setting up...");

  } while ( u8g2.nextPage() );

}//end of void DisplaySplashScreen()	

void UpdateDisplayAnalog(int temp)
{
//update the display with the values from the read
// Dsiplay is wrtten to in "pages" Top yellow has two pages each 8 pixels high 
// Bottom section has 6 pages of blue, making 64 rows of pixels
// There is a black hoizontal line that seperates
// top and bottom

  u8g2.firstPage();
  do {
        //top line (in yelllow)e
        u8g2.setFont(u8g2_font_ncenB12_tr);
        u8g2.setCursor(0,12);               
        // u8g2.println("Dial-A-Dongle!");
        u8g2.print("PORT "); //print text

        if (PortCtrl == LOW)
        {
          u8g2.setFont(u8g2_font_ncenB10_tr);
          u8g2.print(temp,BIN); //print port output
          //u8g2.print(" ");
          //u8g2.print(batt.level());
        }
        else 
        {
          u8g2.print("OFF ");
          // u8g2.print(((5/1024)*analogRead(A2))*2);    //((5volts/10bits)*TICs)*2)
          // u8g2.print("V");
        }

        //next line of display space
        u8g2.setFont(u8g2_font_ncenB24_tr);
        u8g2.setCursor(0,41);				//was 45, needed to be moved up
        u8g2.print("Hex= ");  
        u8g2.setCursor(85,41);				//was 45, needed to be moved up
        u8g2.println(temp,HEX);

        //bottom line of display
        u8g2.setFont(u8g2_font_ncenB10_tr);
        u8g2.setCursor(0,60);				//was 64, but screen is blocked by case
        //u8g2.print("PVE ");  
        //u8g2.setCursor(35,60);				//was 64, but screen is blocked by case
        u8g2.println(PartNumber(temp));
        
  } while ( u8g2.nextPage() );
}//end of void UpdateDisplayAnalog(int temp)

void UpdateDisplayEncoder(int temp)
{

//update the display with the values from the read
  u8g2.firstPage();
  do {
        //top line (in yelllow)
        u8g2.setFont(u8g2_font_ncenB12_tr);
        u8g2.setCursor(0,12);               
        // u8g2.println("Dial-A-Dongle!");
        u8g2.print("PORT "); //print text

        if (PortCtrl == LOW)
        {
          u8g2.setFont(u8g2_font_ncenB10_tr);
          u8g2.print(temp,BIN); //print port output
          // u8g2.print(" ");
          // u8g2.print(batt.level());
        }
        else 
        {
          u8g2.print("OFF ");
          // u8g2.print(((5/1024)*analogRead(A2))*2);    //((5volts/10bits)*TICs)*2)
          // u8g2.print("V");
        }

        //next line of display space
        u8g2.setFont(u8g2_font_ncenB24_tr);
        u8g2.setCursor(0,41);				//was 45, needed to be moved up
        u8g2.print("Hex= ");  
        u8g2.setCursor(85,41);				//was 45, needed to be moved up
        u8g2.println(temp,HEX);

        //bottom line of display
        u8g2.setFont(u8g2_font_ncenB10_tr);
        u8g2.setCursor(0,60);				//was 64, but screen is blocked by case
        //u8g2.print("PVE ");  
        //u8g2.setCursor(35,60);				//was 64, but screen is blocked by case
        u8g2.println(PartNumber(temp));
  } while ( u8g2.nextPage() );
}//end of void UpdateDisplayEncoder(int temp)