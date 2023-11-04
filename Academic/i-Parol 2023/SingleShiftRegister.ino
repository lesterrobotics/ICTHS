// Made by Lester Matthew Sollano

// Class Constructor:
// ShiftRegisterClass objectName ( dataPin, clockPin )
// dataPin - DS Pin of 74HC595
// clockPin - SHCP Pin of 74HC595

// Functions:
// write ( pin, state )
// pin - output pins of 74HC595 (1-8 only)
// state - HIGH, LOW

int latchPin = 2;

int binStrToInt ( String binStr )
{
  return strtol ( binStr.c_str(), NULL, 2 );
}

String binIntToStr ( int binInt )
{
  return String( binInt, BIN );
}

class ShiftRegisterClass
{
  private:
  int dataPin, clockPin, dataInt;
  String dataStr = "00000000", tempStr;

  public:
  ShiftRegisterClass ( int dataPin, int clockPin )
  {
    this->dataPin = dataPin;
    this->clockPin = clockPin;
  }

  write ( int pin, int state )
  {
    tempStr = dataStr;
    dataStr = "";
    for ( int i = 0; i < 8; i++ )
    {
      if ( i+1 != pin )
      {
        dataStr = dataStr + tempStr[i];
      } else
      {
        dataStr = dataStr + binIntToStr( state );
      }
    }
    dataInt = binStrToInt ( dataStr );
    shiftOut ( dataPin, clockPin, MSBFIRST, dataInt );
    digitalWrite ( latchPin, HIGH );
    digitalWrite ( latchPin, LOW );
  }
};

ShiftRegisterClass SR[] = {ShiftRegisterClass( 4, 3 )};

void allMode( uint8_t firstPin, uint8_t lastPin, byte IO )
{
  uint8_t amtOfPins = lastPin - firstPin + 1;
  for ( uint8_t counter = firstPin; counter <= lastPin; counter++ )
  {
    pinMode( counter, IO );
    Serial.print( "Pin " );
    Serial.print( counter );
    Serial.print( " set as " );
    if ( IO == INPUT )
    {
      Serial.println( "INPUT" );
    } else {
      Serial.println( "OUTPUT" );
    }
  }
}


void setup()
{
  Serial.begin(9600);
  allMode ( 0, 53, OUTPUT );
}

void loop()
{
  
}
