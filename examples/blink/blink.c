#include <fx2regs.h>
#include <delay.h>

void main(void)
{
    PORTACFG = 0;
    OEA=0xff;
    while (1) {
        IOA = 0x0;
        delay(1000);
        IOA = 0x3;
        delay(1000);
    }
}
