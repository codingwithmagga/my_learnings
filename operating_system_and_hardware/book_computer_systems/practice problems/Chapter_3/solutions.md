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
|---:|---:|
|leaq 6(%rax), %rdx | 6+x |
|leaq (%rax,%rcx), %rdx | x+y |
|leaq (%rax,%rcx,4), %rdx | x+4y |
|leaq 7(%rax,%rax,8), %rdx | 7+9x |
|leaq 0xA(,%rcx,4), %rdx | 10+4y |
|leaq 9(%rax,%rcx,2), %rdx | 9+2y+x |

## Practice Problem 3.7

```c
long scale2(long x, long y, long z) { 
    long t = 5x+2y+8z;
    return t;
}
```

## Practice Problem 3.8

| Instruction | Destination | Value | 
|---:|---:|---:|
| addq %rcx,(%rax)| 0x100 | 0x100 |
| subq %rdx, 8(%rax)| 0x108 | 0xA8 |
| imulq $16,(%rax,%rdx,8)| 0x118 | 0x110 |
| incq 16(%rax)| 0x110 | 0x14 |
| decq %rcx | %rcx | 0x0 |
| subq %rdx,%rax| %rax | 0xFD |

## Practice Problem 3.9

```asm
shift_left4_rightn: 
movq    %rdi, %rax
salq    $4, %rax
movl    %esi, %ecx
sarq    %cl, %rax
```

## Practice Problem 3.10

```c
long arith2(long x, long y, long z) 
{ 
    long t1 = x | y;
    long t2 = t1 >> 3;
    long t3 = -t2
    long t4 = z - t3;
    return t4; 
}
```

## Practice Problem 3.11

A. Setting the register %rdx to zero.
B. movq $0, %rdx
C. xorg requires 3 bytes and movq requires 7

## Practice Problem 3.12

```asm
uremdiv: 
    movq   %rdx, %r8 
    movq   %rdi, %rax
    movl   $0, %edx
    divq   %rsi
    movq   %rax, (%r8)
    movq   %rdx, (%rcx)
    ret
```

## Practice Problem 3.13

| Task | data_t | COMP | 
|---:|---:|---:|
| A |  int  | < |
| B |  short  | >= |
| C |  unsigned char  | <= |
| D |  long, unsigned long, pointer  | != |

## Practice Problem 3.14

| Task | data_t | TEST | 
|---:|---:|---:|
| A |  long  | >= |
| B |  short, unsigned short  | == |
| C |  unsigned char  | > |
| D |  int  | <= |

## Practice Problem 3.15

A. XXXXXX = 4003fe
B. XXXXXX = 400425
C. XXXXXX = 400543
XXXXXX = 400545
D. XXXXXX = 400560

## Practice Problem 3.16

### A

```c
void cond(long a, long p) {
    if(p == 0) {
        goto done;
    }
    if(*p >= a) {
        goto done;
    }
    *p = a;

    done:
        return;
}
```

### B

This is how the "And" operator && is modeled in assembly.
So the second part can be skipped if the first one is false.

## Practice Problem 3.17

### A

```c
long gotodiff_se(long x, long y) 
{
    long result;
    bool t = x < y;
    if(t) {
        goto x_sm_y;
    }
    ge_cnt++;
    result = x-y;
    goto done

    x_sm_y:
        lt_cnt++;
        result = y-x;
        goto done

    done: 
        return result;
}
```

### B

First version works better when there is no else.

## Practice Problem 3.18

```c
long test(long x, long y, long z)
{
    long val = x + y + z;
    if(x<-3) {
        if(y < z){
            val = x*y;
        }
        else{
            val = y*z;
        }
    } else if(x > 2) {
        val = x*z;
    }
    return val;
}
```

## Practice Problem 3.19

A. $T_MP = 2(31-16) = 30$.
B. $16+30 = 46$

## Practice Problem 3.20

A. OP = '/'
B. temp = x+7
Test x
if x>=0 temp = x
result = temp >> 3 (=x/8)

## Practice Problem 3.21

```c
long test(long x, long y)
{
    long val = 8*x;
    if(y>0) {
        if(y < z){
            val = y-x;
        }
        else{
            val = x&y;
        }
    } else if(y <= -2 ) {
        val = x + y;
    }
    return val;
}
```

## Practice Problem 3.22

A. n=12
B. n=20

## Practice Problem 3.23

A. x in %rdi at start then %rax, y in %rcx, n in %rdx

B. x is updated directly in L2 loop

C.

```asm
dw_loop:
    movq    %rdi, %rax            Copy x to %rax
    movq    %rdi, %rcx            Copy x to %rdi
    imulq   %rdi, %rcx            Calc x*x, store in %rcx (y)
    leaq    (%rdi,%rdi), %rdx     2*x nach %rdi (n)
.L2:
    leaq    1(%rcx,%rax), %rax    y+x+1 in %rax (x)
    subq    $1, %rdx              n-1
    testq   %rdx, %rdx            Check n=0
    jg      .L2                   jump if n=0
    rep; ret                      Return
```

## Practice Problem 3.24

```c
    long loop_while(long a, long b) {
        long result = 1;
        while(a<b) {
            result = result*(a+b);
            a = a + 1;
        }
        return result;
    }
```

## Practice Problem 3.25

```c
    long loop_while2(long a, long b) {
        long result = b;
        while(b>0) {
            result = result*b;
            b = b - a;
        }
        return result;
    }
```

## Practice Problem 3.26

A. jump-to-middle translation

B.

```c
    long fun_a(unsigned long x) {
        long val = 0;
        while(x!=0) {
            val = x^val;
            x >>= 1;
        }
        return val & 0x1;
    }
```

C. This code computes the parity of argument x.

## Practice Problem 3.27

```c
long fact_for_do_while(long n)
{    
    long i = 2;
    long result = 1;
    bool t = (i <= n);
    if (!t)
        goto done;
    do 
        result *= i;
        ++i;
        while(i <= n)
    done:
        return result;
}
```

```c
long fact_for_guarded_do(long n)
{ 
    long i = 2;
    long result = 1;
    bool t = (i <= n);
    if (!t)
        goto done;
    loop:
        result *= i;
        ++i;
        t = i <= n;
        if (t)
            goto loop;
    done:
        return result;
}
```

## Practice Problem 3.28

A
```c
long fun_b(unsigned long x)
{ 
    long val = 0;
    long i;

    for(i=64; i!=0; --i) {
        val = (val<<1)| (x & 0x1);
        x >>= 1;
    }

    return val;
}
```

B.: i is always bigger than zero at start.

C.: Reverse bits in x.

## Practice Problem 3.29

A.
```c
long sum=0;
long i=0;

while(i<10) {
    if(i&1) continue;
    sum += i;
    ++i;
}
```

i does not get updated. Infinite loop.

B.
```c
long sum=0;
long i=0;

while(i<10) {
    if(i&1) goto incr;
    sum += i;

incr:
    ++i;
}
```

## Practice Problem 3.30

A. Values : [-1,0,1,2,4,5,7]
B. .L5 has labels 0 and 7
.L7 has labels 2 and 4

## Practice Problem 3.31

```c
void switcher(long a, long b, long c, long *dest)
{
    long val;

    switch(a) {
    case 5:
        c = b^15;
    case 0: 
        val = 112+c;
        break;
    case 2:
    case 7:
        val = (c+b) << 2;
        break;
    case 4:
        val = a;
        break;
    default:
        val = b;
    }

    *dest = val;
}
```

## Practice Problem 3.32

| Label | PC | Instruction | %rdi | %rsi | %rax | %rsp | *%rsp | Description |
|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| M1 | 0x400560 | callq | 10 | - | - | 0x7fffffffe820 | - | Call first (10) |  
| F1 | 0x400548 | lea | 10 | - | - | 0x7fffffffe818 | 0x400565 | x+1 |  
| F2 | 0x40054c | sub | 10 | 11 | - | 0x7fffffffe818 |  0x400565 | x-1 |  
| F3 | 0x400550 | callq | 9 | 11 | - | 0x7fffffffe818 | 0x400565 | Call last(x-1,x+1) | 
| L1 | 0x400540 | mov | 9 | 11 | - | 0x7fffffffe810 | 0x400555 | u | 
| L2 | 0x400543 | imul | 9 | 11 | 9 | 0x7fffffffe810 | 0x400555 | u*v | 
| L3 | 0x400547 | retq | 9 | 11 | 99 | 0x7fffffffe810 | 0x400555 | Return | 
| F4 | 0x400555 | repz | 9 | 11 | 99 | 0x7fffffffe818 | 0x400565 | Return | 
| M2 | 0x400565 | mov | 9 | 11 | 99 | 0x7fffffffe820 | - | Resume | 

## Practice Problem 3.33

```c
size_t procprob(int a, short b,  long* u, char* v) {
    *u += a;
    *v += b;
    return sizeof(a) + sizeof(b);
}
```

## Practice Problem 3.34

A. a0-a5
B. a6-a7 or a8?
C. Calle saved registers are full

## Practice Problem 3.35

A. It stores x

```c
long rfun(unsigned long x) {
    if (x==0)
        return 0;
    unsigned long nx = x >> 2;
    long rv = rfun(nx);
    return x + rv;
}
```

## Practice Problem 3.36

| Array | Element size | Total size | Start address | Element i |
|---:|---:|---:|---:|---:|
| S | 2 | 14 | $x_s$ | $x_s + 2i$ | 
| T | 8 | 24 | $x_t$ | $x_t + 8i$ | 
| U | 8 | 48 | $x_u$ | $x_u + 8i$ | 
| V | 4 | 32 | $x_v$ | $x_v + 4i$ | 
| W | 8 | 32 | $x_w$ | $x_w + 8i$ | 

## Practice Problem 3.37

| Expression | Type | Value | Assembly Code |
|---:|---:|---:|---:|
| S+1 | short* | $x_s + 2$ | leaq 2(%rdx), %rax |
| S[3] | short | $x_s + 6$ | movw 6(%rdx), %rax |
| &S[i] | short* | $x_s + 2*i$ | leaq (%rdx, %rcx, 2), %rax |
| S[4*i+1] | short | $x_s + 8*i + 2$ | movw 2(%rdx, %rcx, 8), %rax |
| S+i-5 | short* | $x_s + 2*i - 10$ | leaq -10(%rdx, %rcx, 2), %rax |

## Practice Problem 3.38

8i-> rdx
-i-> rdx
+j -> rdx
rdx = 7i+j
5j -> rax
rax = 5j
5j -> rdi
rdi =  5j+i

P: 8*(7i+j)
Q: 8*(5j+i)

=> M=5, N=7

## Practice Problem 3.39

$&D[i][j] = x_D + L(C*i + j)$
$L=4$
C. number of columns

Aptr = x_A + 64i => C = 16
Bptr = x_B + 4k 
Bend = x_B + 4k + 16*16 

## Practice Problem 3.40

```c
void fix_set_diag_opt(fix_matrix A, int val) {
    int Abase = &A[0][0];
    long i = 0;
    long iend = N*(N+1);
    do {
        Abase[i] = val;
        i += N+1;
    } while (i!= iend)
}
```

## Practice Problem 3.41

### A

p: 0 bytes
s.x: 8 bytes
s.y: 12 bytes
next: 16 bytes

### B

24 bytes

### C

```c
void sp_init(struct prob *sp) {
    sp->s.x = sp->s.y;
    sp->p = &(sp->s.x);
    sp->next = sp;
}
```

## Practice Problem 3.42

```c
long fun(struct ELE *ptr) {
    long val = 0;

    while(ptr) {
        val += ptr->v;
        ptr = ptr->p;
    }

    return val;
}
```

Single linked list, accumulating values.

## Practice Problem 3.43

### up->t1.v

type: short

```asm
    movw 8(%rdi), %ax
    movw %ax, (%rsi)
```

### &up->t1.w

type: char*

```asm
    addq 10, %rdi
    movq %rdi, (%rsi)
```

### up->t2.a

type: int*

```asm
    movq %rdi, (%rsi)
```

### up->t2.a[up->t1.u]

type: int

```asm
    movq (%rdi), %rax          # rax = up->t1.u
    movl (%rdi,%rax,4), %eax   # eax = up->t2.a[rax]
    movl %eax, (%rsi)          # *dest = eax
```

### *up->t2.p

type: char

```asm
    movq 8(%rdi), %rax
    movb %rax, %al
    movb %al, (%rsi)
```

## Practice Problem 3.44

A. i:0, c: 4, j: 8, d:12, size: 16, alignment: 4
B. i:0, c: 4, c: 5, j: 8, size: 16, alignment: 8
C. w:0, c: 6, size: 10, alignment: 2
D. w:0, c:10, size: 40, alignment: 8
E. P3:0, P2: 18, size: 40, alignment: 8

## Practice Problem 3.45

A.

| a | b | c | d | e | f | g | h |
|---:|---:|---:|---:|---:|---:|---:|---:|
| 0 | 8 | 16 | 24 | 28 | 32 | 40 | 48 |

B: 56 bytes

C.

```c
struct {
    char *a;
    double c;
    long g;
    float e;
    int h;
    short b;
    char d;
    char f;
}
```

| a | c | g | e | h | b | d | f |
|---:|---:|---:|---:|---:|---:|---:|---:|
| 0 | 8 | 16 | 24 | 28 | 32 | 34 | 35 |

Total size: 40 bytes

## Practice Problem 3.46

### A

|stack| Comment |
|---:|---:|
|00 00 00 00 00 40 00 76| Return address |
|01 23 45 67 89 AB CD EF| %rbx |
|-| |
|-| <- %rsp | 

### B

|stack| Comment |
|---:|---:|
|00 00 00 00 00 40 00 34| Return address |
|33 32 31 30 39 38 37 36| %rbx |
|35 34 33 32 31 30 39 38| |
|37 36 35 34 33 32 31 30| <- %rsp | 

### C

00 00 00 00 00 40 00 34

### D

%rbx and return address

### E

strlen(buf) misses +1
No null check

## Practice Problem 3.47

A. 0x2000 = 2^13
B. 2^13 - 2^7 = 2^6 = 64 tests

## Practice Problem 3.48

### A

unprotecetd: buf: %rsp, v: 24(%rsp) 
protected: buf: 16%rsp, v: 8(%rsp), canary: 40(%rsp) 

### B

When buf overflows into canary, meaning bigger than 24 bytes, the system recognizes that.
Also v is not corrupted.

## Practice Problem 3.49

A. (8n + 22) && -16
                0xFFFFFFF0
    8n+8 (n odd) and 8n + 16 (n even)

B. (7+(%rsp) >> 3)*8  

C. 

|n| $s_1$ | $s_2$ | $p$ | $e_1$ | $e_2$ |
|---:|---:|---:|---:|---:|---:|
| 5 | 2065 | 2017 | 2024 | 1 | 7 |
| 6 | 2064 | 2000 | 2000 | 16 | 0 |
   
D. We can see that $s_1$ is computed in a way that preserves whatever offset $s_2$; has 
with the nearest multiple of 16. We can also see that p will be aligned on a 
multiple of 8, as is recommended for an array of 8-byte elements. 

## Practice Problem 3.50

val1 = d
val2 = i
val3 = l
val4 = f

## Practice Problem 3.51

|$T_x$| $T_y$ | Instructions | 
|---:|---:|---:|
| long | double | vccvtsi2sdq %rdi, %xmm0 |
| double | int | vcvttsd2si %xmm0, %eax |
| double | float | vunpcklpd %xmm0, %xmm0, %xmm0  |
|  | | vcvtpd2ps %xmm0, %xmm0 |
| long | float | vcvtsi2ssq %rdi, %xmm0, %xmm0 |
| float | long | vcvttss2siq %xmm0, %rax |

## Practice Problem 3.52

A: a in %xmm0, b in $rdi, c in %xmm1,d in %esi
B: a in %edi, b in %rsi, c in %rdx, d in %rcx
C: a in %rdi, b in %xmm0, c in %esi, d in %xmm1
D: a in %xmm0, b in %rdi, c in %xmm1, d in %xmm2

## Practice Problem 3.53

double functia(int p, float q, long r, double s); 
double functib(int p, long q, float r, double s); 

## Practice Problem 3.54

```c
double funct2(double w, int x, float y, long z) {
    y*= x;
    w /= z;

    return y-w; 
}
```

## Practice Problem 3.55

1077936128.0
0x40400000

$0x404 = 4+4*16*16 = 1028$
1028-1023 = 5
1.0 * 2^5 = 32

## Practice Problem 3.56

A. 
```c
#define EXPR(x) fabs(x)
``` 

B. 
```c
#define EXPR(x) 0
```

C.
```c
#define EXPR(x) -x
```

## Practice Problem 3.57

```c
double funct3(int *ap, double b, long c, float *dp) {

    if(b<*ap) {
        return 2*(*dp)+c;
    } else {
        return c*(*dp);
    }
}
```
