#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/double-pointer/121
 *
 * Đề bài tóm tắt:
 * Cho con trỏ ban đầu trỏ tới n1. Nếu giá trị n1 là số chẵn,
 * dùng con trỏ cấp hai để chuyển nó sang trỏ tới n2; nếu lẻ thì giữ nguyên.
 * Cuối cùng in giá trị mà con trỏ đang trỏ tới.
 */

void reassign_based_on_value(int **pp, int *n2_ptr) {
    if(**pp%2==0)
    {
        *pp=n2_ptr;
    }
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int *p = &n1;

    reassign_based_on_value(&p, &n2);

    printf("%d", *p);
    return 0;
}
