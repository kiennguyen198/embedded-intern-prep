
/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/check-if-k-th-bit-is-set/90
 *
 * Đề bài tóm tắt:
 * Nhập số nguyên n và vị trí bit k (đánh số từ 0).
 * In 1 nếu bit k của n đang được set, ngược lại in 0.
 */
#include <stdio.h>

int isKthBitSet(int n, int k) {
    if(n&(1<<k))
        return 1;
    else return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", isKthBitSet(n, k));
    return 0;
}