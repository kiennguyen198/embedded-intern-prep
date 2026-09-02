#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/scan-memory-for-three-consecutive-increasing-values/129
 *
 * Đề bài tóm tắt:
 * Dùng con trỏ để tìm ba giá trị liên tiếp tăng từng đơn vị trong vùng nhớ.
 * Trả về chỉ số bắt đầu của mẫu đầu tiên, hoặc -1 nếu không tìm thấy.
 */

int find_pattern(int *mem, int n) {
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        if((*(mem+i)+1)==*(mem+i+1))
        {
            count++;
        }
        else
        {
            if(count!=0)
            count--;
        }
        if(count==2)
        {
            return (i-1);
        }
    }
    return -1;
}

int main() {
    int n, arr[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int res = find_pattern(arr, n);
    printf("%d", res);

    return 0;
}
