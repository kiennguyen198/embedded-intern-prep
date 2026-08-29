#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/set-or-clear-a-specific-bit-in-a-register/87
 *
 * Đề bài tóm tắt:
 * Nhập giá trị của một thanh ghi 8-bit (0-255), vị trí bit (0-7)
 * và chế độ thao tác. Mode 1 dùng để set bit, mode 0 dùng để clear bit.
 * In ra giá trị thanh ghi sau khi thay đổi.
 */
unsigned char modifyBit(unsigned char reg, int pos, int mode)
{
    if (mode == 1)
    {
        reg |= (1U << pos);
    }
    else
    {
        reg &= ~(1U << pos);
    }

    return reg;
}

int main(void)
{
    unsigned char reg;
    int pos, mode;

    scanf("%hhu %d %d", &reg, &pos, &mode);
    printf("%d", modifyBit(reg, pos, mode));

    return 0;
}
