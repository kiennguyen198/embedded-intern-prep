#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/bit-toggle/89
 *
 * Đề bài tóm tắt:
 * Nhập một số nguyên n, đảo bit tại vị trí 5 (đánh số từ 0)
 * rồi in ra giá trị sau khi thay đổi.
 *
 * Lưu ý: ví dụ 31 -> 95 trên trang nguồn bị sai.
 * Toggle bit 5 của 31 cho kết quả đúng là 63.
 */
int toggleFifthBit(int n)
{
    n ^= (1 << 5);
    return n;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d", toggleFifthBit(n));

    return 0;
}
