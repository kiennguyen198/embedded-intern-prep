/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/pack-multiple-fields-into-a-16-bit-control-register/146
 *
 * Đề bài tóm tắt:
 * Nhập 3 giá trị mode, speed và status.
 * Đóng gói chúng vào một thanh ghi 16 bit theo thứ tự:
 * - mode: bit 0–2
 * - speed: bit 3–7
 * - bit 8–9: luôn bằng 0
 * - status: bit 10–15
 * In ra giá trị của thanh ghi sau khi đóng gói.
 */

 #include <stdio.h>
#include <stdint.h>

uint16_t pack_register(uint8_t mode, uint8_t speed, uint8_t status) {
    uint16_t reg=((mode&0x07))|((speed&0x1F)<<3)|((status&0x3F)<<10);
    return reg;
    
}

int main() {
    uint8_t mode, speed, status;
    scanf("%hhu %hhu %hhu", &mode, &speed, &status);

    uint16_t reg = pack_register(mode, speed, status);
    printf("%u", reg);
    return 0;
}