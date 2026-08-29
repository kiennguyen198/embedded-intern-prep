#include <stdio.h>
#include <stdint.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/set-specific-bits-in-a-32-bit-register/99
 *
 * Đề bài tóm tắt:
 * Cho một thanh ghi 32-bit, vị trí bắt đầu pos và độ dài len.
 * Set len bit liên tiếp từ vị trí pos thành 1 mà không làm thay đổi
 * các bit còn lại trong thanh ghi.
 */
uint32_t set_bits(uint32_t reg, uint8_t pos, uint8_t len) {
    for (int i=pos;i<pos+len;i++)
    {
        reg|=(1U<<i);
    }
    return reg;
}

int main() {
    uint32_t reg;
    uint8_t pos, len;
    scanf("%u %hhu %hhu", &reg, &pos, &len);
    printf("%u", set_bits(reg, pos, len));
    return 0;
}
