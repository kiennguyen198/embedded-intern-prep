# Struct

## Câu 1

Đoạn code sau in ra gì?

```c
typedef struct
{
    short a;
    long b;
    char c;
} tem;

typedef struct
{
    short a;
    char c;
    long b;
} tem2;

int main()
{
    tem a;
    tem2 b;

    printf("%d %d", sizeof(a), sizeof(b));
    return 0;
}
```

### Đáp án theo giả định của đề

```text
12 8
```

Giả sử `short` rộng 2 byte, `long` rộng 4 byte và `long` cần được căn chỉnh theo mốc 4 byte:

```text
tem:
short(2) + padding(2) + long(4) + char(1) + padding(3) = 12

tem2:
short(2) + char(1) + padding(1) + long(4) = 8
```

Thứ tự thành viên ảnh hưởng lượng padding và kích thước của `struct`. Kết quả thực tế phụ thuộc ABI, kích thước kiểu dữ liệu và quy tắc alignment của hệ thống.

`sizeof` trả về `size_t`, nên cách in portable hơn là:

```c
printf("%zu %zu", sizeof(a), sizeof(b));
```
