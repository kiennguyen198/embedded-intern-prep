#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/reverse-an-array-using-only-pointers/118
 *
 * Đề bài tóm tắt:
 * Đảo ngược các phần tử của mảng ngay trên mảng ban đầu bằng
 * pointer arithmetic và dereference, không dùng array indexing
 * trong hàm reverse_array.
 */
void reverse_array(int *ptr, int n) {
    for(int i=0;i<n/2;i++)
    {
        int temp=*(ptr+n-1-i);
        *(ptr+n-1-i)=*(ptr+i);
        *(ptr+i)=temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverse_array(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1){
            printf(" ");
        }
    }

    return 0;
}
