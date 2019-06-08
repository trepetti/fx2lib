#include <fx2regs.h>
#include <delay.h>

int main(void)
{
    PORTACFG = 0;
    OEA=0x03;
    while (1) {
        IOA = 0x00;
        delay(1000);
        IOA = 0x03;
        delay(1000);
        IOA = 0x01;
        delay(1000);
        IOA = 0x02;
        delay(1000);
    }
}
