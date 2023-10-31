/*                                        *
 *  Setup all 396 pins using 50 SR (Shift *
 *  Registers). Find a way to make life   *
 *  easier by making certain functions    *
 *  and objects.                          *
 *                                        *
 *  Idea 1: digitalWrite                  *
 *  Being able to write a certain         *
 *  function similar to digitalWrite.     *
 *                                        */

#define latchPin 2

class SR_Object
{
    private:
    byte dataPin, shiftPin;
    byte data = 0b00000000;    // Each bit represents one RDP.

    public:
    byte SR_id;    // Used to identify which SR.
    byte RDP[16];    // Register Digital Pin (RDP)
    SR ( byte DP, byte SP, int RDP_first, byte ID )    // RDP_first represents the first pin within a set of 8 pins that the register will use.
    {
        SR_id = ID
        dataPin = DP;
        shiftPin = SP;
        for ( byte pin = 0; pin < 16; pin++ )
        {
            RDP[pin] = pin + RDP_first;    // Assigning pin numbers to RDP.
        }
    }

    byte is_present( int certainRDP )
    {
        for ( byte i = 0; i < 16; i++ )    // Loops through the SR's RDP to see if a certain RDP is present.
        {
            if ( certainRDP == RDP[i] )
            {
                return Sr_id;    // Returns which SR has the certain RDP.
            }
        }
        return 255;    // Otherwise it returns 255 indicating false.
    }
};

SR_Object ShiftRegisters[25] = {    SR ( 3, 4, 0 ),
                                    SR ( 5, 6, 17 ),
                                    SR ( 7, 8, 33 ),
                                    SR ( 9, 10, 49 ),
                                    SR ( 11, 12, 65 ),
                                    SR ( 13, 14, 81 ),

byte checkAll ( int RDP ) 
{
    
}

void RDW ( int RDP, byte IO )
{
    
}

void setup()
{
    RDW ( 2, HIGH );
}

void loop()
{
    
}
