#include <stdio.h>
#include <stdint.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/bit-spreading-interleave-bits-with-zeros/183
 *
 * Đề bài tóm tắt:
 * Trải 8 bit của val sang một số 16-bit sao cho các bit ban đầu
 * nằm tại vị trí chẵn 0, 2, ..., 14 và mọi vị trí lẻ đều bằng 0.
 */
uint16_t spread_bits(uint8_t val) {
    uint16_t temp=0;
    int j=0;
    for (int i=0;i<16;i++)
    {
        if(i%2!=0)
        {
            temp&=~(1<<i);
        }
        else
        {
            if(val&(1<<j))
            {
                temp|=(1<<i);
            }
            else
            {
                temp&=~(1<<i);
            }
            j++;
        }
    }
    return temp;
}

int main() {
    uint8_t val;
    scanf("%hhu", &val);

    uint16_t result = spread_bits(val);
    printf("%u", result);
    return 0;
}
