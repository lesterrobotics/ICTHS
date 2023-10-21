#define DATA_PIN 11
#define SHIFT_PIN 13
#define LATCH_PIN 12

int data = 0b11111111;

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
    Serial.begin( 9600 );
    allMode( 2, 13, OUTPUT );
    shiftOut( DATA_PIN, SHIFT_PIN, MSBFIRST, data );
    digitalWrite( LATCH_PIN, HIGH );
    digitalWrite( LATCH_PIN, LOW );
}

void loop()
{
}
