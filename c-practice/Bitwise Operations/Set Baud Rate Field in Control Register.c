#include <stdio.h>
#include <stdint.h>

uint32_t set_baud_rate(uint32_t reg, uint8_t baud) {
    uint32_t shifted_baud = ((uint32_t)(baud & 0x0FU) << 8);

    reg &= ~(0x0FU << 8);
    reg |= shifted_baud;

    return reg;
}

int main() {
    uint32_t reg;
    uint8_t baud;
    scanf("%u %hhu", &reg, &baud);
    printf("%u", set_baud_rate(reg, baud));
    return 0;
}
