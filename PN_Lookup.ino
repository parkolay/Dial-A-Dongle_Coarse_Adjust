//Generates charater array with values that corespond to hex value

const char* PartNumber(int pn)
{
  static char* pmName[0x7f] =
  {
    "PN-10", //Hex 0x01
    "PN-11", //Hex 0x02
    "PN-12", //Hex 0x03
    "PN-13", //Hex 0x04
    "PN-14", //Hex 0x05
    "PN-15", //Hex 0x06
    "PN-16", //Hex 0x07
    "PN-17", //Hex 0x08
    "PN-18", //Hex 0x09
    "PN-19", //Hex 0x0A
    "PN-20", //Hex 0x0B
    "PN-21", //Hex 0x0C
    "PN-22", //Hex 0x0D
    "PN-23", //Hex 0x0E
    "PN-24", //Hex 0x0F
    "N/A",   // No hex0x10 in the box
    "PN-25", //Hex 0x11
    "N/A",   // No hex0x12 in the box
    "N/A",   // No hex0x13 in the box
    "PN-31", //Hex 0x14
    "PN-32", //Hex 0x15
    "PN-35", //Hex 0x16
    "PN-36", //Hex 0x17
    "PN-61", //Hex 0x18
    "79-91", //Hex 0x19
    //"PN-91",//Hex 0x19
    "N/A",   // No hex0x1A in the box
    "N/A",   // No hex0x1B in the box
    "PN-94", //Hex 0x1C
    "PN-95", //Hex 0x1D
    "PN-96", //Hex 0x1E
    "PN-97", //Hex 0x1F
    "PN-98", //Hex 0x20
    "PN-99", //Hex 0x21
    "PN-100",//Hex 0x22
    "PN-101",//Hex 0x23
    "PN-102",//Hex 0x24
    "PN-106",//Hex 0x25
    "PN-107",//Hex 0x26
    "PN-109",//Hex 0x27
    "PN-110",//Hex 0x28
    "PN-111",//Hex 0x29
    "PN-114",//Hex 0x2A
    "PN-115",//Hex 0x2B
    "PN-116",//Hex 0x2C
    "PN-117",//Hex 0x2D
    "PN-118",//Hex 0x2E
    "PN-119",//Hex 0x2F
    "PN-120",//Hex 0x30
    "PN-121",//Hex 0x31
    "PN-122",//Hex 0x32
    "PN-123",//Hex 0x33
    "PN-126",//Hex 0x34
    "PN-127",//Hex 0x35
    "N/A",   // No hex0x36 in the box    
    "PN-134",//Hex 0x37
    "PN-135",//Hex 0x38
    "PN-136",//Hex 0x39
    "PN-137",//Hex 0x3A
    "PN-138",//Hex 0x3B
    "PN-139",//Hex 0x3C
    "PN-140",//Hex 0x3D
    "PN-141",//Hex 0x3E
    "PN-142",//Hex 0x3F
    "PN-143",//Hex 0x40
    "PN-144",//Hex 0x41
    "PN-146",//Hex 0x42
    "PN-148",//Hex 0x43    
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