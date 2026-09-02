#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/state-machine-using-function-pointers/127
 *
 * Đề bài tóm tắt:
 * Dùng mảng con trỏ hàm để chạy đúng ba trạng thái liên tiếp,
 * bắt đầu từ start và quay lại trạng thái đầu sau trạng thái cuối.
 */

void state_init()    { printf("Init"); }
void state_load()    { printf("Load"); }
void state_execute() { printf("Execute"); }
void state_exit()    { printf("Exit"); }

// Your logic here
void run_state_sequence(int start) {
    int count=0;
    void(*print[4])(void)={state_init,state_load,state_execute,state_exit};
    for(int i=count;i<count+3;i++)
    {
        int index=(i+start)%4;
        print[index]();
        printf("\n");
    }
}

int main() {
    int start;
    scanf("%d", &start);
    run_state_sequence(start);
    return 0;
}
