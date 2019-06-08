#include <stdint.h>
#include <fx2regs.h>
#include <delay.h>

#define FX2_RENUM   (1U<<1)
#define FX2_DISCON  (1U<<3)


int main(void)
{
    uint8_t i;

    // Avoid bricking the device:
    // https://www.triplespark.net/elec/periph/USB-FX2/eeprom/.
    if (USBCS & FX2_RENUM)
    {
        USBCS |= FX2_DISCON;
        SYNCDELAY2;
        USBCS &= ~FX2_RENUM;
        SYNCDELAY2;
        USBCS &= ~FX2_DISCON;
        SYNCDELAY2;
    }

    // Use Port A as GPIO.
    PORTACFG = 0;

    // Set Port A's least significant two pins to outputs.
    OEA=0x03;

    // Count to three... forever...
    while (1) {
        for (i = 0; i < 4; i++) {
            IOA = ~i;
            delay(500);
        }
    }
}
