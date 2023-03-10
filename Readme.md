Dial-A-Dongle
Simple device used for selecting a hex value and setting PORT D to the binary equivalent 
There were some issues with analog jitter.  Filters were added to the top (1000) and bottom (50) for deadband.
Several lsb were dropped and it didn't help, various delays and simple averaging filters were attempted (didn't help).
a 3.3V LDO was not attempted but might have helped.
I am really starting to think this should be using a rotary encoder...
Rotary encoder is better, the signal does not wonder but response is much slower.  
Spinning encoder shaft to fast will cause erroneous results.
Coarse adjust using analog input was added, faster method of selection without jitter being an issue.
Device is not so simple any more.

 *  // Pinout
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
 *  //  SCL       --> A04; Tied HIGH W/ 3k3 Ohm resistor
 *  //  SDA       --> A05; Tied HIGH W/ 3k3 Ohm resistor

Old Analog version;
Using library U8g2 at version 2.33.15 in folder: D:\Github\libraries\U8g2 
Using library Wire at version 1.0 in folder: C:..\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\Wire 
Using library ResponsiveAnalogRead at version 1.2.1 in folder: D:\Github\libraries\ResponsiveAnalogRead 
Using library SPI at version 1.0 in folder: C:..\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
Sketch uses 17850 bytes (58%) of program storage space. Maximum is 30720 bytes.
Global variables use 717 bytes (35%) of dynamic memory, leaving 1331 bytes for local variables. Maximum is 2048 bytes.

Encoder Version;
Using library U8g2 at version 2.33.15 in folder: D:\Github\libraries\U8g2 
Using library Wire at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\Wire 
Using library ResponsiveAnalogRead at version 1.2.1 in folder: D:\Github\libraries\ResponsiveAnalogRead 
Using library Encoder at version 1.4.2 in folder: D:\Github\libraries\Encoder 
Using library SPI at version 1.0 in folder: C:..\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
Sketch uses 15800 bytes (51%) of program storage space. Maximum is 30720 bytes.
Global variables use 898 bytes (43%) of dynamic memory, leaving 1150 bytes for local variables. Maximum is 2048 bytes.

Coarse Adjust Version;
Using library U8g2 at version 2.33.15 in folder: D:\Github\libraries\U8g2 
Using library Wire at version 1.0 in folder: C:..\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\Wire 
Using library Encoder at version 1.4.2 in folder: D:\Github\libraries\Encoder 
Using library SPI at version 1.0 in folder: C:..\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
Sketch uses 18706 bytes (60%) of program storage space. Maximum is 30720 bytes.
Global variables use 1546 bytes (75%) of dynamic memory, leaving 502 bytes for local variables. Maximum is 2048 bytes.

/*  DAP  initial check-in     02-09-2023 
/*  DAP  added coarse adjust  03-10-2023
*/
