# Solutions Chapter 2

## Practice Problem 2.1

### A

|        | 1 | 2 | 3 | 4 | 5 | 6 |
|--------|---:|---:|---:|---:|---:|---:|
| Hex    | 3 | 9 | A | 7 | F | 8 |
| Binary | 0011 | 1001 | 1010 | 0111 | 1111 | 1000 |

### B

|        | 1 | 2 | 3 | 4 | 
|--------|---:|---:|---:|---:|
| Binary | 1100 | 1001 | 0111 | 1011 |
| Hex | C | 9 | 7 | B | 

### C

|        | 1 | 2 | 3 | 4 | 5 | 
|--------|---:|---:|---:|---:|---:|
| Hex    | D | 5 | E | 4 | C | 
| Binary | 1101 | 0101 | 1110 | 0100 | 1100 |

### D

|        | 1 | 2 | 3 | 4 | 5 | 6 |
|--------|---:|---:|---:|---:|---:|---:|
| Binary | 0010 | 0110 | 1110 | 0111 | 1011 | 0101 | 
| Hex    | 2 | 6 | E | 7 | B | 5 |  

## Practice Problem 2.2

|   n     | $2^n (decimal)$ | $2^n (hexadecimal)$ | 
|--------:|---:|---:|
| 9 | 512 | 0x200 | 
| 19    | 524288 | 0x80000 |  
|  14   | 16384 | 0x4000 |  
|   16  | 65536 | 0x10000|  
| 17    | 131072|0x20000 |  
|   5  | 32| 0x20 |  
|   7  | 128 | 0x80|  

## Practice Problem 2.3

|   decimal     | binary | Hexadecimal | 
|--------:|---:|---:|
| 0 | 0000 0000 | 0x00 | 
| 167   | 1010 0111  | 0xA7 |  
|  62   | 0011 1110 | 0x3E  |  
|  188  | 1011 1100 | 0xBC |  
|  55  | 0011 0111 | 0x37 |  
| 136  | 1000 1000 | 0x88  |  
|  243   | 1111 0011 | 0xF3 |  
| 82 | 0101 0010 | 0x52 |
| 172 | 1010 1100 | 0xAC |
| 231 | 1110 0111 | 0xE7|

## Practice Problem 2.4

### A 

0x503C + 0x8 = 0x5044

### B

0x503C - 0x40 = 0x4FFC

### C

0x503C + 64 = 0x507C

### D

0x50EA - 0x503C = 0xAE

## Practice Problem 2.5

### A

Little endian: 21 
Big endian: 87

### B

Little endian: 21 43  
Big endian: 87 65 

### C

Little endian: 21 43 65 
Big endian: 87 65 43

## Practice Problem 2.6

### A

Hex: 0x00359141  
Bin: 0000 0000 0011 0101 1001 0001 0100 0001

Hex: 0x4A564504  
Bin: 0100 1010 0101 0110 0100 0101 0000 0100

### B
00000000001101011001000101000001  
&ensp;&ensp;01001010010101100100010100000100  
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;**************************

21 bits in total are equal

### C
First part (only first significant bit of integer, multiple high order bits float) and the last zeros of float.

## Practice Problem 2.7

61 62 63 64 65 66

## Practice Problem 2.8

|   Operation     | Result |
|--------:|---:|
| $a$ | [01101001]  |
| $b$ | [01010101]|
| $\sim a$ |[10010110] |
| $\sim b$ | [10101010]|
| $a\&b$ |[01000001] |
| $a\|b$ | [01111101] |
| $a^b$ | [00111100] |

## Practice Problem 2.9
 
### A

Black <=> White
Blue <=> Yellow
Green <=> Magenta
Cyan <=> Red 

### B

Blue | Green = 001 | 010 = 011 = Cyan  
Yellow & Cyan = 110 & 011 = 010 = Green  
Red ^ Magenta = 100 ^ 101 = 001 = Blue

## Practice Problem 2.10

|   Step     | *x |  *y |
|:--------|---:|---:|
| Initially | a | b |
| Step 1 | a | a^b |
| Step 2  | b |  a^b |
| Step 3  | b | a |

## Practice Problem 2.11

### A

First and last are equal.

### B 

Value is swapped with itself in `inplace_swap`.  
So it erases itself when using `^` => `a^a = 0`.

### C

In the for loop use `first < last`.

## Practice Problem 2.12

### A

`x = x & 0xFF`  

### B

`x = x ^ ~0xFF`

### C

`x = x | 0xFF`

## Practice Problem 2.13

```cpp
/* Declarations of functions implementing operations bis and bic */ 
int bis(int x, int m); 
int bic(int x, int m);

/* Compute x|y using only calls to functions bis and bic */ 
int bool_or(int x, int y) {
    int result = bis(x, y);
    return result; 
}

/* Compute x^y using only calls to functions bis and bic */ 
int bool_xor(int x, int y){
    int result = bic(x, y) + bic(y, x); // is equal to bis(bic(x, y), bic(y, x))
    return result;
}
```

## Practice Problem 2.14

0x66 = 0110 0110
0x39 = 0011 1001

|   Expression     | value |
|--------|---:|
| x & y | 0010 0000 = 0x20 | 
| x \| y | 0111 1111 = 0x7F | 
| ~x \| ~y  | 1101 1111 = 0xDF | 
| x & !y  | 0000 0000 = 0x00 | 
| x && y | 0000 0001 = 0x01 | 
| x \|\| y | 0000 0001 = 0x01 | 
| !x \|\| !y | 0000 0000 = 0x00 | 
| x && ~y  | 0000 0001 = 0x01 | 

## Practice Problem 2.15

```cpp
bool log_and(int x, int y) {
    return !(x^y);
}
```

## Practice Problem 2.16

| x | x | x<<3 | x <<3| Logical | x>>2 | Arithmetic | x>>2 |
|---:|---:|---:|---:|---:|---:|---:|---:|
|   Hex     | Binary | Binary | Hex | Binary | Hex | Binary | Hex | 
| 0xC3 | 1100 0011 | 0001 1000 | 0x18 | 0011 0000 | 0x30 | 1111 0000 | 0xF0 | 
| 0x75 | 0111 0101 | 1010 1000 | 0xA8 | 0001 1101 | 0x1D | 0001 1101 | 0x1D  | 
| 0x87 | 1000 0111 | 0011 1000 | 0x38 | 0010 0001 | 0x21 | 1110 0001 | 0xE1 | 
| 0x66 | 0110 0110 | 0011 0000 | 0x30 | 0001 1001 | 0x19 | 0001 1001  | 0x19 |

## Practice Problem 2.17

| Hexdecimal $\vec{x}$ | Binary $\vec{x}$ | $B2U_4(\vec{x})$ | $B2T_4(\vec{x})$ |
|---:|---:|---:|---:|
| 0xE | [1110]  | $2^3 + 2^2 + 2^1 = 14$ | $-2^3 + 2^2 + 2^1 = -2$ |
| 0x0 | [0000]  | $0$ | $0$ |
| 0x5 | [0101]  | $5$ | $5$|
| 0x8 | [1000]  | $8$ | $-8$ |
| 0xD | [1101]  | $13$ | $-3$ |
| 0xF | [1111]  | $15$ | $-1$|

## Practice Problem 2.18

| Line | Hex | Binary | Decimal |
|---:|---:|---:|---:|
|A| 0x2e0 | 0010 1110 0000 | 32+64+128+512 = 736  | 
|B| -0x58| -0101 1000 | -(8+16+64) = -88|
|C| 0x28| 0010 1000 | 40 | 
|D| -0x30| 0011 0000 | -48 |
|E| 0x78| 0111 1000 | 8+16+32+64=120 |
|F| 0x88| 1000 1000 | 8+128=136 |
|G| 0x1f8| 0001 1111 1000 | 8+16+32+64+128+256 = 504|
|H| 0xc0| 1100 0000 | 128+64 = 192 |
|I| -0x48| 0100 1000 | -(8 + 64) = -72 |

## Practice Problem 2.19

| x | $T2U_4(x)$ | 
|---:|---:|
|-8|8|
|-3|13|
|-2|14|
|-1|15|
|0|0|
|5|5|

## Practice Problem 2.20

Fill in x and calculate the result.

## Practice Problem 2.21

| Expression | Type | Evaluation |
|---:|---:|---:|
| -2147483647-1 == 2147483648U | Unsigned | 1 |
| -2147483647-1 < 2147483647 | Signed | 1 |
| -2147483647-1U < 2147483647  | Unsigned | 0 |
| -2147483647-1 < -2147483647  | Signed | 1 |
| -2147483647-1U < -2147483647 | Unsigned | 1 |

## Practice Problem 2.22

A: [1011] = -8 + 1 + 2 = 5
B: [11011] = -16 + 1 + 2 + 8 = 5
C: [111011] = -32 + 1 + 2 + 8 + 16 = 5

## Practice Problem 2.23

### A

| $w$ | $fun1(w)$ | $fun2(w)$ |
|---:|---:|---:|
| 0x00000076  | 0x00000076 | 0x00000076 |
| 0x87654321 | 0x00000021 | 0x00000021 |
| 0x000000C9 | 0x000000C9 | 0xFFFFFFC9 |
| 0xEDCBA987 | 0x00000087 | 0xFFFFFF87 |

### B

fun1: Extracts the least significant 2 bytes => $x \in [0,255]$  
fun2: Same but with sign extension => $x \in [-128,127]$

## Practice Problem 2.24

| Hex Orig | Hex trunc. | Unsigned Orig. |Unsigned Trunc. | 2com Orig. | 2com Trunc. |
|---:|---:|---:|---:|---:|---:|
|  0| 0 | 0 | 0 | 0| 0  |
| 2 | 2 | 2 | 2 | 2 | 2 |
| 9 | 1 | 9 | 1 | -7 | 1 |
| B | 3 | 11 | 3 | -5 | 3 |
| F | 7 | 15 | 7 | -1 | -1 |

## Practice Problem 2.25

For `length == 0` in the for loop `i<= -1u` so `-1u = U_{max}`.
Just use `i<length`.

## Practice Problem 2.26

### A + B

When `strlen(t) > strlen(s)` the value is negative resulting in a large positive value returning that `s` would be larger than `t`.

### C

Just return `return strlen(s) > strlen(t)`.

## Practice Problem 2.27

```cpp
/* Determine whether arguments can be added without overflow */ 
int uadd_ok(unsigned x, unsigned y) {
    unsigned s = x + y;
    return x <= s;
}
```

## Practice Problem 2.28

| Hex x | Decimal x | Decimal $-\frac{u}{4}x$ | Hex $-\frac{u}{4}x$ |
|---:|---:|---:|--:|
| 0  | 0 | 0 | 0 |
| 5  | 5 | 11 | B |
| 8  | 8 | 8 | 8 |
| D  | 13 | 3 | 3 |
| F  | 15 | 1 | 1 |

## Practice Problem 2.29

| x | y | x+y | $x+\frac{t}{5}y$ | Case |
|---:|---:|---:|---:|---:|
| -12  | -15 | -27 | 5 | 1 |
| [10100]  | [10001] | [100101] | [00101] |  |
| -8  | -8 | -16 | -16 | 2 |
| [11000]  | [11000] | [110000] | [10000] |  |
| -9  | 8 | -1 | -1 | 2 |
| [10111]  | [01000] | [11111] | [11111] |  |
|  2 | 5 | 7 | 7 | 3 |
| [00010]  | [00101] | [00111] | [00111] |  |
|  12 | 4 | 16 | -16 | 4 |
| [01100]  | [00100] | [010000] | [10000] |  |

## Practice Problem 2.30

```cpp
/* Determine whether arguments can be added without overflow */ 
int tadd_ok(int x, int y) {
    int s = x + y;
    if(x >= 0 && y>=0 && s<0) {
        return 0;
    }
    if(x < 0 && y<0 && s>=0) {
        return 0;
    }
    return 1
}
```

## Practice Problem 2.31

Check is true regardless of overflow since two's complement addition forms an abelian group and $(x+y)-x=y$ every time.

## Practice Problem 2.32

If $y=T_{min}$ this wont work.

## Practice Problem 2.33

| Hex x | Decimal x | Decimal $-\frac{t}{4}x$ | Hex $-\frac{t}{4}x$ |
|---:|---:|---:|--:|
| 0  | 0 | 0 | 0 |
| 5  | 5 | -5 | B |
| 8  | -8 | -8 | 8 |
| D  | -3 | 3 | 3 |
| F  | -1 | 1 | 1 |

## Practice Problem 2.34

| Mode| x | y | $x \cdot y$ | Truncated $x \cdot y$  |
|---:|---:|---:|---:|---:|
|Unsigned | 4 [100] | 5 [101] | 20 [010100] | 4 [100] | 
|Two's compl. | -4 [100] | -3 [101] | 12 [001100] | -4 [100] | 
|Unsigned | 2 [010] | 7 [111] | 14 [001110] | 6 [110] | 
|Two's compl. | 2 [010] | -1 [111] | -2 [111110] | -2 [110] | 
|Unsigned | 6 [110] | 6 [110] | 36 [100100] | 4 [100] | 
|Two's compl. | -2 [110] | -2 [110] | 4 [000100] | -4 [100] | 

## Practice Problem 2.35

### 1

Rewrite usig equation (2.3) => $ x \cdot y = v2^w + u$.  
$u = T2U_w(p)$  
Rewrite usig equation (2.6) => $ x \cdot y = p+t2^w$.  

### 2

By definition of integer division, dividing p by nonzero x gives a quotient q and a remainder r such that 
p=x-q +r, and |r| < |x|.

### 3

<!--> TODO: FIX euqaitons<-->
Suppose q = y. Then we have $x \cdot y =x-y+r-+t2$.  
From this, we can see that r + 12” =0. But |r| < |x| < 2”, and so this identity can hold only if t = 0, in which case r = 0.  
Suppose r = ft = 0. Then we will have x - y =x - q, implying that y = q. 

## Practice Problem 2.36

```cpp
/* Determine whether arguments can be multiplied without overflow */ 
int tmult_ok(int x, int y){ 
    int s32 = x*y;
    int64_t s64 = (int64_t) x*y;

    return s32==s64;
}
```

## Practice Problem 2.37

### A

Only if size_t would also be 64 bit. But this not the case here, so no.

### B

Throw error if mulitplication overflows.

```cpp
uint64_t required_size = ele_cnt * (uint64_t) ele_size; 
size_t request_size = (size_t) required_size; 

if (required_size != request_size) 
    /* Overflow must have occurred. Abort operation */ 
    return NULL; 
```

## Practice Problem 2.38

For each value of k, we can compute two multiples: $2^k$ (when b is 0) and $2^k + 1$
(when b is a). Thus, we can compute multiples 1, 2,3, 4, 5, 8, and 9. 

## Practice Problem 2.39

$- (x<<m)$

## Practice Problem 2.40

| K | Shifts | Add/Subs | Expression |
|---:|---:|---:|--:|
| 6  | 2 | 1 | (x<<2)+(x<<1) |
| 31  | 1 | 1 | (x<<5) - x |
| -6  | 2 | 1 | (x<<1)-(x<<3) |
| 55  | 2 | 2 | (x<<6) - (x<<3) - x |

## Practice Problem 2.41

Choose A when n=m, else B.

## Practice Problem 2.42

```cpp
    int div16(int x) {
        int bias = (x>>31) & 0xF; 
        return (x+bias)>>4;
    }
```

## Practice Problem 2.43

$ (x<<5) -x$ => x*31
$ (y>>3) $

M=31; N=8

## Practice Problem 2.44

A. false for $x=TMin_{32}$
B. true
C. false for some $x>2^16$
D. true
E. false for $x=TMin_{32}$
F. True
G. true

## Practice Problem 2.45

| Fractional | Binary | Decimal | 
|---:|---:|---:|
| $\frac{1}{8}$  | 0.001 | 0.125 | 
| $\frac{3}{4}$  | 0.11 | 0.75 | 
| $\frac{5}{16}$  | 0.0101 | 0.3125 | 
| $1\frac{9}{16}$  | 1.1001 | 1.5625 | 
| $2\frac{11}{16}$  | 10.1011 | 2.6875 | 
| $1\frac{1}{8}$  | 1.001 | 1.125 | 
| $5\frac{7}{8}$  | 101.111 | 5.875 | 
| $3\frac{3}{16}$  | 11.0011 | 3.1875 | 

## Practice Problem 2.46

A. $0.000110011[0011] \cdots_2 - 0.00011001100110011001100 =  0.000000000000000000000001100[1100]\cdots_2 $

B. $0.1 - x = \frac{1}{2^{20}}*\frac{1}{10} = 9.54e-8$

C. $9.54e-8*100h*10 = 9.54e-8*360000s*10 = 0,34344s$

D. $2000 m/s * 0,34344s = 686.88m$

## Practice Problem 2.47