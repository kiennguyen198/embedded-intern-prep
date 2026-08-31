#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/add-two-integers-using-void-pointers/125
 *
 * Đề bài tóm tắt:
 * Nhận hai con trỏ void, mỗi con trỏ trỏ tới một số nguyên.
 * Chuyển về con trỏ int và trả về tổng của hai số đó.
 */

int add_two_void_pointers(void *a, void *b) {
    int *temp1=a;
    int *temp2=b;
    return *temp1+*temp2;

    return 0;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", add_two_void_pointers(&a, &b));
    return 0;
}
