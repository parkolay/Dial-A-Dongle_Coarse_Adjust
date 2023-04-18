//Generates charater array with values that corespond to hex value

const char* PartNumber(int pn)
{
  static char* pmName[0x7f] =
  {
    "PN-10 P2200", //Hex 0x01
    "PN-11 P2201", //Hex 0x02
    "PN-12 P2203", //Hex 0x03
    "PN-13 P220A", //Hex 0x04
    "PN-14 P220B", //Hex 0x05
    "PN-15 P220E", //Hex 0x06
    "PN-16 P220F", //Hex 0x07
    "PN-17 P221A", //Hex 0x08
    "PN-18 P225C", //Hex 0x09
    "PN-19 P225E", //Hex 0x0A
    "PN-20 P229E", //Hex 0x0B
    "PN-21 P229F", //Hex 0x0C
    "PN-22 P22A1", //Hex 0x0D
    "PN-23 P22FB", //Hex 0x0E
    "PN-24 P22FE", //Hex 0x0F
    "N/A",         // No hex0x10 in the box
    "PN-25 P249D", //Hex 0x11
    "PN-33 P203A", // No hex0x12 in the box, found in PVE doc
    "PN-30 P203C", // No hex0x13 in the box, found in PVE doc
    "PN-32 P205A", //Hex 0x14 //CHECK THESE
    "PN-31 P205C", //Hex 0x15 //CHECK THESE
    "PN-35 P0046", //Hex 0x16
    "PN-36 P24FF", //Hex 0x17
    "PN-40 P215A", //Hex 0x18   // P215A ABS Wheel Speed?
    "PN-79 P006E", //Hex 0x19   //this may ALSO be set as 91
    //"PN-91",       //Hex 0x19 //cannot have two of the same hex values 
    "PN-91 P2563", // No hex0x1A in the box, found in PVE doc
    "PN-61 P20B2", // No hex0x1B in the box, found in PVE doc
    "PN-94 P24FC", //Hex 0x1C
    "PN-95 P24B1", //Hex 0x1D
    "PN-96 P24B0", //Hex 0x1E
    "PN-97 P24D1", //Hex 0x1F
    "PN-98 P24AF", //Hex 0x20
    "PN-99 P24DA", //Hex 0x21
    "PN-100 P24B4",//Hex 0x22
    "PN-101 P24AE",//Hex 0x23
    "PN-102 P24B5",//Hex 0x24
    "PN-106 P1034",//Hex 0x25
    "PN-107 P24D0",//Hex 0x26
    "PN-109 P00AF",//Hex 0x27
    "PN-110 P1148",//Hex 0x28
    "PN-111 P2AB0",//Hex 0x29
    "PN-114 P206B",//Hex 0x2A
    "PN-115 P203B",//Hex 0x2B
    "PN-116 P24B1",//Hex 0x2C
    "PN-117 P24AF",//Hex 0x2D //WHAT!!??
    "PN-118 P24AF",//Hex 0x2E //WHAT!!??
    "PN-119 P24DA",//Hex 0x2F
    "PN-120 P24B7",//Hex 0x30
    "PN-121 P24DA",//Hex 0x31
    "PN-122 P24AF",//Hex 0x32 //WAHT!!???
    "PN-123 -N/A-",//Hex 0x33
    "PN-126 P24B7",//Hex 0x34
    "PN-127 P24B7",//Hex 0x35
    "PN-131 RlgCd",// No hex0x36 in the box, found in PVE doc    
    "PN-134 P20FE",//Hex 0x37
    "PN-135 P206B",//Hex 0x38
    "PN-136 P205C",//Hex 0x39
    "PN-137 P205A",//Hex 0x3A
    "PN-138 P205B",//Hex 0x3B
    "PN-139 P2205",//Hex 0x3C
    "PN-140 P2206",//Hex 0x3D
    "PN-141 P2208",//Hex 0x3E
    "PN-142 P22A3",//Hex 0x3F
    "PN-143 P22A4",//Hex 0x40
    "PN-144 P22A6",//Hex 0x41
    "PN-146 P205B",//Hex 0x42
    "PN-148 P20B2",//Hex 0x43
  };//end of static char* pmName[0x7f] =

  if (pn > 0 && pn < 0x80) 
  {
    return pmName[pn-1];
  } 
  else
  {
    return "N/A";
  }
 
}//end of const char* PartNumber(int pn)