# Union

## Câu 1

Cho `union` sau:

```c
typedef union
{
    struct Register
    {
        unsigned int value1 : 3;
        unsigned int value2 : 2;
        unsigned int value3 : 3;
    } value;

    unsigned int raw;
} DemoRegister;

DemoRegister demo_reg;

demo_reg.value.value1 = 1;
demo_reg.value.value2 = 2;
demo_reg.value.value3 = 3;

demo_reg.raw = 0xFF;

printf("%d %d %d %d",
       demo_reg.value.value1,
       demo_reg.value.value2,
       demo_reg.value.value3,
       demo_reg.raw);
```

Chương trình in ra gì?

### Đáp án theo cách bố trí bit-field thông dụng

```text
7 3 7 255
```

`value` và `raw` dùng chung vùng nhớ. Sau khi `raw` được gán `0xFF`, 8 bit thấp đều bằng `1`:

```text
value1: 3 bit -> 111 -> 7
value2: 2 bit ->  11 -> 3
value3: 3 bit -> 111 -> 7
```

Các giá trị `1`, `2`, `3` được gán trước đó đã bị `demo_reg.raw = 0xFF` ghi đè. Thứ tự bố trí bit-field phụ thuộc compiler, vì vậy đây không phải kết quả portable tuyệt đối.

## Câu 2

Thay ba bit-field bằng ba biến `unsigned int`:

```c
typedef union
{
    struct Register
    {
        unsigned int value1;
        unsigned int value2;
        unsigned int value3;
    } value;

    unsigned int raw;
} DemoRegister;

DemoRegister demo_reg;

demo_reg.value.value1 = 1;
demo_reg.value.value2 = 2;
demo_reg.value.value3 = 3;

demo_reg.raw = 0xFF;

printf("%d %d %d %d",
       demo_reg.value.value1,
       demo_reg.value.value2,
       demo_reg.value.value3,
       demo_reg.raw);
```

Giả sử `unsigned int` rộng 32 bit và hệ thống có cách bố trí bộ nhớ thông dụng, chương trình in ra gì?

### Đáp án theo giả định trên

```text
255 2 3 255
```

Mỗi trường chiếm một `unsigned int` riêng. `raw` chỉ chồng lên 32 bit đầu của `struct`, tức vùng chứa `value1`, nên `value2` và `value3` không bị thay đổi.

## Ghi nhớ

```c
unsigned int value1 : 3;  // Bit-field rộng 3 bit
unsigned int value1;      // Một biến unsigned int thông thường
```

Các thành viên của `union` dùng chung địa chỉ bắt đầu, nhưng kích thước và cách diễn giải vùng nhớ phụ thuộc kiểu của từng thành viên.
