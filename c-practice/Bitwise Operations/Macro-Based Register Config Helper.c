#include <stdio.h>
#include <stdint.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/macro-based-register-config-helper/187
 *
 * Đề bài tóm tắt:
 * Tạo thanh ghi 16-bit từ ba trường: ENABLE ở bit 0, MODE ở bit 1-2
 * và SPEED ở bit 3-5. Các bit dự trữ 6-7 phải giữ bằng 0.
 */

#define ENABLE_FIELD(value) ((value)&1U)
#define MODE_FIELD(value) (((value)&0x03U)<<1)
#define SPEED_FIELD(value) (((value)&0x07U)<<3)

uint16_t build_register(uint8_t enable, uint8_t mode, uint8_t speed) {
    uint16_t temp=0;
    temp|=ENABLE_FIELD(enable);
    temp|=MODE_FIELD(mode);
    temp|=SPEED_FIELD(speed);
    return temp;
}

int main() {
    uint8_t enable, mode, speed;
    scanf("%hhu %hhu %hhu", &enable, &mode, &speed);

    uint16_t reg = build_register(enable, mode, speed);
    printf("%u", reg);
    return 0;
}
