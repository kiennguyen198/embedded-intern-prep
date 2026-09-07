# Enum

## Câu 1

Đoạn code sau in ra gì?

```c
enum number
{
    one = 1,
    two = 2,
    three,
    five,
    four = 4,
    six,
    seven = 7
};

int main()
{
    printf("%d %d %d", five, four, six);
    return 0;
}
```

### Đáp án

```text
4 4 5
```

Nếu một phần tử `enum` không được gán giá trị, nó nhận giá trị của phần tử đứng trước cộng `1`:

```text
one   = 1
two   = 2
three = 3
five  = 4
four  = 4
six   = 5
seven = 7
```

Các phần tử trong cùng một `enum` được phép có giá trị trùng nhau, nên `five` và `four` đều bằng `4`.
