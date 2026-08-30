#include <stdio.h>
#include <stdint.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/bit-operations-using-macros/148
 *
 * Đề bài tóm tắt:
 * Cho một thanh ghi 8-bit. Dùng macro để lần lượt set bit 2 và 7,
 * clear bit 3, toggle bit 5, rồi trả về giá trị đã cập nhật.
 */

// Define bitwise macros here
#define SET_BIT(reg,pos) ((reg)|=(1U<<(pos)))   // tham số phải cho vào ()
#define CLEAR_BIT(reg,pos) ((reg)&=~(1U<<(pos)))
#define TOGGLE_BIT(reg,pos) ((reg)^=(1U<<(pos)))

uint8_t modify_register(uint8_t reg) {
    SET_BIT(reg,2);
    SET_BIT(reg,7);
    CLEAR_BIT(reg,3);
    TOGGLE_BIT(reg,5);
    return reg;
}

int main() {
    uint8_t reg;
    scanf("%hhu", &reg);
    printf("%u", modify_register(reg));
    return 0;
}
