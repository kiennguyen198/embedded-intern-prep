## Uninitialized pointer

Source: [EWskills Pointer-i Quiz](https://www.ewskills.com/quiz/pointer-i/671/uninitialized-pointer)

### Question

Điều gì xảy ra khi dereference một con trỏ chưa khởi tạo?

```c
int *config_ptr;
*config_ptr = 0x0F;
```

### Answer

Đây là undefined behavior.

`config_ptr` chưa được khởi tạo nên chứa một địa chỉ không xác định. Việc ghi dữ liệu qua `*config_ptr` có thể làm hỏng dữ liệu, gây crash hoặc hard fault.

Con trỏ phải trỏ đến một vùng nhớ hợp lệ trước khi được dereference.

## Walking an `int` array using `char *`

Source: [EWskills Pointer-i Quiz](https://www.ewskills.com/quiz/pointer-i/671/wrong-type-walk)

### Question

Đoạn code sau in ra giá trị nào trên hệ thống 32-bit có `int` rộng 4 byte?

```c
int data[3] = {0x11223344, 0x55667788, 0xAABBCCDD};
char *p = (char *)data;
p += 4;
printf("0x%X", *(int *)p);
```

### Answer

Kết quả là `0x55667788`.

Con trỏ `char *` tăng mỗi lần 1 byte. Vì vậy, `p += 4` di chuyển 4 byte, đúng bằng kích thước một `int`, nên `p` trỏ tới `data[1]`. Ép lại thành `int *` và dereference sẽ đọc giá trị `0x55667788`.

## `const` pointer semantics

Source: [EWskills Pointer-ii Quiz](https://www.ewskills.com/quiz/pointer-ii/672/const-pointer-semantics)

### Question

Con trỏ nào ngăn việc sửa giá trị của thanh ghi?

```c
const int *p1 = (const int *)0x40020000;
int *const p2 = (int *const)0x40020000;
```

### Answer

`p1` ngăn sửa dữ liệu thông qua con trỏ vì nó trỏ tới một `const int`. Vẫn có thể thay đổi địa chỉ mà `p1` đang giữ.

`p2` là con trỏ có địa chỉ cố định, nhưng dữ liệu mà nó trỏ tới vẫn có thể được sửa.

### Note

```text
const trước * → khóa dữ liệu
const sau  * → khóa con trỏ
```

## Redirect a pointer using a double pointer

Source: [EWskills Pointer-ii Quiz](https://www.ewskills.com/quiz/pointer-ii/672/double-pointer-redirect)

### Question

Đoạn code sau in ra giá trị nào?

```c
void redirect(int **pp, int *new_target) {
    *pp = new_target;
}

int a = 10, b = 20;
int *p = &a;
redirect(&p, &b);
printf("%d", *p);
```

### Answer

Kết quả là `20`.

Ban đầu `p` trỏ tới `a`. Hàm nhận `&p`, nên `pp` giữ địa chỉ của chính con trỏ `p`. Dòng `*pp = new_target` tương đương với `p = &b`, làm `p` chuyển sang trỏ tới `b`.

```text
Trước hàm: p → a → 10
Sau hàm:   p → b → 20
```

### Note

```text
p    → con trỏ
*p   → dữ liệu mà p trỏ tới
&p   → địa chỉ của chính p
pp   → địa chỉ của p
*pp  → chính là p
**pp → dữ liệu mà p trỏ tới
```

Muốn lưu địa chỉ của con trỏ p thì dùng int **pp, rồi truyền &p.

## Returning a pointer to a local variable

Source: [EWskills Pointer-iii Quiz](https://www.ewskills.com/quiz/pointer-iii/673/function-returns-a-pointer)

### Question

Điều gì xảy ra khi một hàm trả về địa chỉ của biến local?

```c
int *get_config() {
    int timeout = 500;
    return &timeout;
}

int *cfg = get_config();
printf("%d", *cfg);
```

### Answer

Đây là undefined behavior. Khi `get_config()` kết thúc, biến local `timeout` hết lifetime và con trỏ `cfg` trở thành dangling pointer.

```text
Địa chỉ cũ vẫn còn được lưu trong cfg.
Biến timeout tại địa chỉ đó đã không còn tồn tại hợp lệ.
```

Vùng stack cũ có thể chưa bị ghi đè nên chương trình đôi khi vẫn in `500`, nhưng cũng có thể in giá trị rác hoặc crash.

### Note

Không trả về con trỏ tới biến local thông thường. Có thể dùng biến `static` hoặc để hàm gọi tạo biến rồi truyền địa chỉ của biến đó vào hàm.

## Pointer subtraction

Source: [EWskills Pointer-iii Quiz](https://www.ewskills.com/quiz/pointer-iii/673/pointer-subtraction)

### Question

Giá trị của `count` là bao nhiêu?

```c
int arr[6] = {10, 20, 30, 40, 50, 60};
int *start = &arr[1];
int *end = &arr[4];
int count = end - start;
```

### Answer

`count = 3` vì phép trừ hai con trỏ trả về khoảng cách tính theo số phần tử:

```text
&arr[4] - &arr[1] = 4 - 1 = 3
```

Nếu một `int` rộng 4 byte thì khoảng cách địa chỉ là 12 byte, tương ứng `12 / 4 = 3` phần tử.

### Note

Chỉ được trừ hai con trỏ cùng nằm trong một mảng hoặc tại vị trí ngay sau phần tử cuối của mảng đó. Trừ con trỏ thuộc hai đối tượng không liên quan là undefined behavior.

Kiểu chuẩn để lưu kết quả phép trừ con trỏ là `ptrdiff_t` trong `<stddef.h>`.

## Accessing a memory-mapped register

Source: [EWskills Pointer-iv Quiz](https://www.ewskills.com/quiz/pointer-iv/675/memory-mapped-register-access)

### Question

Khi truy cập thanh ghi phần cứng qua địa chỉ cố định, có cần dùng `volatile` không?

### Answer

Có. Thanh ghi phần cứng có thể bị thay đổi bởi phần cứng và mỗi lần đọc hoặc ghi đều có ý nghĩa. `volatile` buộc compiler thực hiện truy cập thật thay vì tự bỏ hoặc gộp chúng.

```c
volatile uint32_t *gpio_odr =
    (volatile uint32_t *)0x40020014;

*gpio_odr |= (1U << 5);
```

### Note

```text
Biến RAM thông thường      → thường không cần volatile
Thanh ghi phần cứng        → dùng volatile
Biến bị ISR/phần cứng đổi  → thường dùng volatile
```

`volatile uint32_t *reg` nghĩa là dữ liệu thanh ghi là `volatile`. `uint32_t *volatile reg` chỉ làm bản thân biến con trỏ thành `volatile`.

`volatile` không đảm bảo thao tác atomic và không tự giải quyết tranh chấp giữa main, ISR hoặc nhiều task.
