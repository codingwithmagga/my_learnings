# Solutions Chapter 3

## Practice Problem 3.1

| Operand | Value | 
|--------:|---:|
| %rax  | 0x100 |
| 0x104 |  0xAB |
| $0x108 | 0x108 |
| (%rax) | 0xFF |
| 4(%rax) | 0xAB |
| 9(%rax,%rdx) | 0x11 |
| 260(%rcx,%rdx) | 0x13 |
| 0xFC(,%rcx,4) | 0xFF |
| (%rax,%rdx,4) | 0x11 |

## Practice Problem 3.2

movl  %eax, (%rsp)
movw  (%rax), %dx
movb  $0xFF, %bl
movb  (%rsp,%rdx,4), %dl
movq  (%rdx), %rax
movw  %dx, (%rax)

## Practice Problem 3.3

1. %ebx is no address register
2. l is 4 bytes, source is 8 bytes
3. memory to memory
4. %sl does not exist
5. destination can't be an immediate value
6. size mismatch 
7. byte is 1 byte, need movw

## Practice Problem 3.4

| src_t | dest_t | Instruction |
|---:|---:|---:|
| long  | long | movq (%rdi), %rax |
|   |  | movq 4rax, (%rsi) |
| char  |  int | movsbl (%rdi), %eax |
|   |   | movl %eax, (%rsi) |
| char  |  unsigned | movsbl (%rdi), %eax |
|   |   | movl %eax, (%rsi) |
| unsigned char  |  long | movzbl (%rdi), %eax |
|   |   | movq %rax, (%rsi) |
| int  |  char | movl (%rdi),%eax |
|   |   | movb %al, (%rsi)  |
| unsigned   |  unsigned char | movl (%rdi), %eax |
|   |   | movb %al, (%rsi)  |
| char  |  short | movsbw (%rdi), %ax |
|   |   | movw %ax, (%rsi)  |

## Practice Problem 3.5

```cpp
void decodel(long *xp, long *yp, long *zp) {
    long x = *xp;
    long y = *yp;
    long z = *zp;

    *yp = x;
    *zp = y;
    *xp = z;
}
```

## Practice Problem 3.6

| Instruction | Result | 
|---:|---: