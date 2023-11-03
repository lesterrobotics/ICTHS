//  Code made by Lester Matthew G. Sollano - ICTHS Robotics Team Lead Programmer    


#define latchPin 2

class SR_Object
{
    private:
    byte dataPin, shiftPin;
    uint16_t data = 0b0000000000000000;    // Each bit represents one RDP.

    public:
    byte SR_id;    // Used to identify which SR.
    byte RDP[16];    // Register Digital Pin (RDP)
    SR_Object ( byte DP, byte SP, int RDP_first, byte ID )    // RDP_first represents the first pin within a set of 16 pins that the register will use.
    {
        SR_id = ID
        dataPin = DP;
        shiftPin = SP;
        for ( byte pin = 0; pin < 16; pin++ )
        {
            RDP[pin] = pin + RDP_first;    // Assigning pin numbers to RDP.
        }
    }

    byte is_present ( int certainRDP )
    {
        for ( byte i = 0; i < 16; i++ )    // Loops through the SR's RDP to see if a certain RDP is present.
        {
            if ( certainRDP == RDP[i] )
            {
                return SR_id;    // Returns which SR has the certain RDP.
            }
        }
        return 255;    // Otherwise it returns 255 indicating false.
    }
};

//Setting up SR Array
SR_Object ShiftRegisters[25] = {
                                    SR ( 3, 4, 0, 0 ), SR ( 5, 6, 17, 1 ), SR ( 7, 8, 33, 2 ), SR ( 9, 10, 49, 3 ), SR ( 11, 12, 65, 4 ),
                                    SR ( 13, 14, 81, 5 ), SR ( 15, 16, 97, 6 ), SR ( 17, 18, 113, 7 ), SR ( 19, 20, 129, 8 ), SR ( 21, 22, 145, 9 ),
                                    SR ( 23, 24, 161, 10 ), SR ( 25, 26, 177, 11 ), SR ( 27, 28, 193, 12 ), SR ( 29, 30, 209, 13 ), SR ( 31, 32, 225, 14 ),
                                    SR ( 33, 34, 241, 15 ), SR ( 35, 16, 97, 16 ), SR ( 37, 38, 113, 17 ), SR ( 39, 40, 129, 18 ), SR ( 41, 42, 145, 19 ),
                                    SR ( 43, 44, 321, 20 ), SR ( 45, 46, 97, 21 ), SR ( 47, 48, 113, 22 ), SR ( 49, 50, 129, 23 ), SR ( 51, 52, 145, 24 ),
                                    SR ( 53, 54,33 , 25 )
}

byte checkAll ( int RDP )    // Find which SR contains a specific RDP.
{
    
}

void RDW ( int RDP, byte IO )    // Register Digital Write
{
    
}

void setup()
{
    RDW ( 2, HIGH );
}

void loop()
{
    
}
