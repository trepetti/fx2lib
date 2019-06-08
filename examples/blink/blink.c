#include <stdint.h>
#include <fx2regs.h>
#include <delay.h>

int main(void)
{
    uint8_t i;

    PORTACFG = 0;
    OEA=0x03;
    while (1) {
        for (i = 0; i < 4; i++) {
            IOA = ~i;
            delay(500);
        }
    }
}
