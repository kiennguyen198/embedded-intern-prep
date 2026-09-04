#include <stdio.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/event-based-triggers-using-function-pointer-array/137
 *
 * Đề bài tóm tắt:
 * Dùng mảng con trỏ hàm để gọi hàm xử lý tương ứng với mã sự kiện 0-4.
 * Nếu mã nằm ngoài phạm vi này, in "Unhandled Event".
 */

void on_button() {
    printf("Button Pressed");
}
void on_timer() {
    printf("Timer Expired");
}
void on_uart() {
    printf("UART Received");
}
void on_power() {
    printf("Power On");
}
void on_error() {
    printf("Error Detected");
}

// Write your event dispatcher logic here
void (*handlers[5])(void)={on_button,on_timer,on_uart,on_power,on_error};
void handle_event(int event_code) {
    if (event_code >= 0 && event_code < 5)
    {
        handlers[event_code]();
    }
    else
    {
        printf("Unhandled Event");
    }
}

int main() {
    int event;
    scanf("%d", &event);
    handle_event(event);
    return 0;
}
