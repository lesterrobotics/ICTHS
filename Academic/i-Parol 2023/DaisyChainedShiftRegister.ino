// Made by Lester Matthew Sollano

// Class Constructor:
// ShiftRegisterClass objectName ( dataPin, clockPin )
// dataPin - DS Pin of 74HC595
// clockPin - SHCP Pin of 74HC595

// Functions:
// write ( pin, state )
// pin - output pins of 74HC595 (1-16 only)
// state - HIGH, LOW

#define print(x) Serial.println(x)
#define latchPin 2

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
  int dataPin, clockPin, firstDataInt, secondDataInt;
  String firstDataStr = "00000000", secondDataStr = "00000000", tempStr;

  public:
  ShiftRegisterClass ( int dataPin, int clockPin )
  {
    this->dataPin = dataPin;
    this->clockPin = clockPin;
  }

  write ( int pin, int state )
  {
    if ( pin <= 8 ) {
      tempStr = firstDataStr;
      firstDataStr = "";
      for ( int i = 0; i < 8; i++ )
      {
        if ( i+1 != pin )
        {
          firstDataStr = firstDataStr + tempStr[i];
        } else
        {
          firstDataStr = firstDataStr + binIntToStr( state );
        }
      }
      firstDataInt = binStrToInt ( firstDataStr );
    } else
    {
      tempStr = secondDataStr;
      secondDataStr = "";
      for ( int i = 0; i < 8; i++ )
      {
        if ( i+9 != pin )
        {
          secondDataStr = secondDataStr + tempStr[i];
        } else
        {
          secondDataStr = secondDataStr + binIntToStr( state );
        }
      }
      secondDataInt = binStrToInt ( secondDataStr );
    }
    shiftOut ( dataPin, clockPin, LSBFIRST, secondDataInt );
    shiftOut ( dataPin, clockPin, LSBFIRST, firstDataInt );
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
