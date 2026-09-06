## Extract a 3-bit error code

Source: [EWskills Bitwise Operations-II Quiz](https://www.ewskills.com/quiz/bitwise-operations-ii/667/extract-error-code)

### Question

Thanh ghi `status` rộng 8 bit. Mã lỗi dài 3 bit nằm tại bits 4–6. Biểu thức nào lấy mã lỗi về dạng giá trị từ `0` đến `7`?

### Answer

Hai biểu thức đúng:

```c
(status >> 4) & 0x07
(status & 0x70) >> 4
```

`0x07` có ba bit thấp bằng `1`, còn `0x70` có bits 4–6 bằng `1`:

```text
0x07 = 0000 0111
0x70 = 0111 0000
```

Cách 1 dịch bits 4–6 xuống vị trí 0–2 rồi dùng `& 0x07` để bỏ các bit khác. Cách 2 dùng `& 0x70` giữ lại bits 4–6 trước, sau đó dịch phải 4 bit.

Ví dụ `status = 0b0101xxxx`, mã lỗi ở bits 4–6 là `101`:

```text
0101 xxxx
dịch phải 4
0000 0101
& 0000 0111
-----------
0000 0101 = 5
```

### Note

```c
status & 0x70
```

chỉ cô lập bits 4–6 nhưng chưa đưa chúng về vị trí 0–2, nên kết quả chưa phải mã lỗi `0–7`.

## Swap two values using XOR

Source: [EWskills Bitwise Operations-II Quiz](https://www.ewskills.com/quiz/bitwise-operations-ii/667/identify-the-pattern)

### Question

Kỹ thuật sau dùng để làm gì?

```c
a ^= b;
b ^= a;
a ^= b;
```

### Answer

Hoán đổi hai giá trị mà không dùng biến tạm.

Ví dụ 4 bit với `a = 1`, `b = 2`:

```text
Ban đầu: a = 0001, b = 0010
a ^= b → a = 0011, b = 0010
b ^= a → a = 0011, b = 0001
a ^= b → a = 0010, b = 0001

Kết quả: a = 2, b = 1
```

### Note

Trong code thực tế, nên dùng biến tạm vì dễ đọc và an toàn hơn.

## Bitwise NOT on `uint8_t`

Source: [EWskills Bitwise Operations-II Quiz](https://www.ewskills.com/quiz/bitwise-operations-ii/667/not-on-uint8)

### Question

Vì sao `~mask == 0xF0` sai khi `mask` là `uint8_t` có giá trị `0x0F`?

### Answer

Trước khi tính `~`, C tự động nâng `uint8_t` thành `int`. Trên hệ thống có `int` 32 bit:

```text
mask  = 0x0000000F
~mask = 0xFFFFFFF0, không phải 0xF0
```

Muốn chỉ giữ kết quả 8 bit:

```c
(uint8_t)~mask
```

### Note

`int` thường rộng 4 byte trên hệ thống 32 bit, nhưng ngôn ngữ C không đảm bảo `int` luôn là 4 byte.

## Set multiple bits simultaneously

Source: [EWskills Bitwise Operations-II Quiz](https://www.ewskills.com/quiz/bitwise-operations-ii/667/multi-bit-set)

### Question

Làm thế nào để set đồng thời bits 1, 3 và 5 mà vẫn giữ nguyên các bit khác của `reg`?

### Answer

Cách chuẩn là ghép các mask bằng bitwise OR:

```c
reg |= (1U << 1) | (1U << 3) | (1U << 5);
```

```text
1U << 1 = 0000 0010
1U << 3 = 0000 1000
1U << 5 = 0010 0000
OR       = 0010 1010 = 0x2A
```

Phép cộng cũng cho `0x2A` trong trường hợp này vì các mask không chồng bit:

```text
2 + 8 + 32 = 42 = 0x2A
```

Tuy nhiên, nếu mask bị trùng thì phép cộng có thể phát sinh carry và cho kết quả khác OR. Vì vậy, luôn ưu tiên `|` để ghép bitmask.

Bitwise AND giữa các mask trên cho `0` vì không có vị trí nào cùng bằng `1`.

## Bitwise AND versus logical AND

Source: [EWskills Bitwise Operations-III Quiz](https://www.ewskills.com/quiz/bitwise-operations-iii/668/bitwise-vs-logical)

### Question

Có thể thay `&&` bằng `&` khi kiểm tra đồng thời bit 0 và bit 7 không?

```c
if ((flags & 0x01U) && (flags & 0x80U))
```

### Answer

Không. `&` AND từng bit, còn `&&` kết hợp hai điều kiện đúng/sai.

Với `flags = 0x81`:

```text
flags & 0x01 = 1   → true
flags & 0x80 = 128 → true
true && true       → true

0x01 & 0x80        → 0
```

Cách viết rõ ràng:

```c
if (((flags & 0x01U) != 0U) &&
    ((flags & 0x80U) != 0U))
```

`&&` có short-circuit; `&` luôn tính cả hai vế.
