#include <stdio.h>
#include <stdint.h>

unsigned char extractNibble(unsigned char reg, int pos) {
    uint8_t rs = 0;
    if (pos)
    {
        rs = (reg >> 4) & 0xF;
    }
    else
    {
        rs = reg & 0x0F;
    }
    return rs;
}

int main() {
    unsigned char reg;
    int pos;
    scanf("%hhu %d", &reg, &pos);
    printf("%d", extractNibble(reg, pos));
    return 0;
}
