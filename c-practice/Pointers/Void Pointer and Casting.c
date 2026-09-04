#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/void-pointer-and-casting/138
 *
 * Đề bài tóm tắt:
 * Nhận hai con trỏ void trỏ tới hai số int hoặc float.
 * Dựa vào ký tự loại dữ liệu để cộng và in kết quả phù hợp.
 */

void add_and_print(void *a, void *b, char type) {
    if(type=='i')
    {
        int *c=a,*d=b;
        printf("%d",*c+*d);
    }
    else if(type=='f')
    {
        float *c=a,*d=b;
        printf("%.1f",*c+*d);
    }
}

int main() {
    char type;
    scanf(" %c", &type);

    if (type == 'i') {
        int x, y;
        scanf("%d %d", &x, &y);
        add_and_print(&x, &y, type);
    } else if (type == 'f') {
        float x, y;
        scanf("%f %f", &x, &y);
        add_and_print(&x, &y, type);
    }

    return 0;
}
