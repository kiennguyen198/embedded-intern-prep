#include <stdio.h>
#include <stdint.h>

void convert_to_big_endian(uint32_t value, uint8_t arr[4]) {
    arr[0] = (value >> 24) & 0xFFU;
    arr[1] = (value >> 16) & 0xFFU;
    arr[2] = (value >> 8) & 0xFFU;
    arr[3] = value & 0xFFU;
}

int main() {
    uint32_t value;
    uint8_t arr[4];
    scanf("%u", &value);
    convert_to_big_endian(value, arr);
    for (int i = 0; i < 4; i++) {
        printf("%u", (unsigned int)arr[i]);
        if (i < 3) {
            printf(" ");
        }
    }
    return 0;
}
