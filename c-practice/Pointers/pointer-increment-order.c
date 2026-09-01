#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    int value1 = *ptr;            // giá trị con trỏ trỏ tới hiện tại
    int value2 = ++(*ptr);      // lấy giá trị con trỏ hiện arr[0] tại cộng 1, arr[0]=2
    int value3 = *(ptr++);     // ++ ở đây là hậu tố, đọc giá trị con trỏ hiện tại rồi dịch con trỏ sang vị trí arr[1]
    int value4 = (*ptr)++; // đọc arr[1] lưu vào value4 rồi đặt arr[1]=3
    int value5 = *(++ptr); // tăng trỏ lên arr[2] đọc giá trị =3
    int value6 = ++(*ptr); // đọc arr[2] tăng lên rồi lưu vào value

    printf("%d %d %d %d %d %d\n",
           value1, value2, value3, value4, value5, value6);

    return 0;
}
