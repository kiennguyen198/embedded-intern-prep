#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/function-pointer-dispatch-table/126
 *
 * Đề bài tóm tắt:
 * Tạo mảng con trỏ hàm cho bốn phép toán cộng, trừ, nhân và chia.
 * Dùng mã lệnh cmd làm chỉ số để gọi phép toán tương ứng.
 */

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int execute_command(int a, int b, int cmd) {
    int(*operation[4])(int,int)={add,sub,mul,divide};
    return operation[cmd](a,b);
}

int main() {
    int a, b, cmd;
    scanf("%d %d %d", &a, &b, &cmd);

    int result = execute_command(a, b, cmd);
    printf("%d", result);

    return 0;
}
