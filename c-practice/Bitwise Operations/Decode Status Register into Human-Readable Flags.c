#include <stdio.h>
#include <stdint.h>

/*
 * Nguồn: EWskills
 * Link: https://www.ewskills.com/task/decode-status-register-into-human-readable-flags/149
 *
 * Đề bài tóm tắt:
 * Cho một thanh ghi trạng thái 8-bit, trong đó mỗi bit tương ứng
 * với một trạng thái. In tên của các trạng thái đang được bật
 * theo thứ tự bit từ 0 đến 7, mỗi trạng thái trên một dòng.
 */
const char *stateName[]={"Power On","Error","Tx Ready","Rx Ready","Overheat","Undervoltage","Timeout","Reserved"};

void decode_status(uint8_t status_reg) {
    for(int i=0;i<8;i++)
    {
        if(status_reg & (1U<<i))
        {
            printf("%s\n",stateName[i]);
        }
    }
}

int main() {
    uint8_t reg;
    scanf("%hhu", &reg);
    decode_status(reg);
    return 0;
}
