#include <stdio.h>
#include <stdint.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/keep-only-the-highest-set-bit/111
 *
 * Đề bài tóm tắt:
 * Cho một thanh ghi 16-bit. Chỉ giữ lại bit 1 cao nhất
 * và clear tất cả các bit còn lại. Nếu reg bằng 0 thì trả về 0.
 */
uint16_t highest_set_bit(uint16_t reg) {
    uint16_t temp=(1U<<15);
    int rs=-1;
    for (int i=0;i<16;i++)
    {
        if (reg&(temp>>i))
        {
            rs=i;
            break;
        }
    }
    if(rs==-1)
        return 0;
    return (temp>>rs);
}

int main() {
    uint16_t reg;
    scanf("%hu", &reg);
    uint16_t result = highest_set_bit(reg);
    printf("%hu", result);
    return 0;
}
