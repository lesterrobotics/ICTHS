/*
 *  Setup all 396 pins using 50 SR (Shift 
 *  Registers). Find a way to make life
 *  easier by making certain functions 
 *  and objects.
 *
 *  Idea 1: digitalWrite
 *  Being able to write a certain
 *  function similar to digitalWrite.
 */

class SR
{
    private:

    byte dataPin, shiftPin, latchPin;
    byte data = 0b00000000

    public:

    SR ( byte DP, byte SP, byte LP, int RDP_first, int RDP_last )
    {
        dataPin = DP;
        shiftPin = SP;
        latchPin = LP;
        
};