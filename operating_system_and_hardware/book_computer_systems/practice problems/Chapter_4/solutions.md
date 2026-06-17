# Solutions Chapter 4

## Practice Problem 4.1

```asm
pos 0x100 # Start code at address 0x100 
0x100    irmovq $15, %rbx     0x30F30F000000000000000
0x10a   rrmovq %rbx, %rcx     0x2031
loop: 
0x10c    rmmovq %rcx,-3(%rbx) 0x4013DFFFFFFFFFFFFFFFF
0x116    addq   %rbx, %rcx    0x6031
0x118    jmp loop             0x700c01000000000000000
```

## Practice Problem 4.2

// Skipping some parts here (TODO)
A. 
0x100: 30f3fcffffffffffffff = irmovq $-4,%rbx
0x110: 40630008000000000000 = rmmovq 

B. 0x200: a06f800c020000000000000030f 30a00000000000000 = pushq %rsi

C. 0x300: 5054070000000000000010f = mrmovq 7(%rsp), %rbp

D. 0x400: 6113730004000000000000000 = subq %rcx, %rbx

E. 0x500: 6362a0f0 = xorq %rsi,%rdx

## Practice Problem 4.3

```asm
sum: 
    xorg %rax,%rax 
    andq %rsi,%rsi 
    jmp test
    
loop: 
    mrmovq (%rdi),%r10 
    addq %r10,%rax 
    iaddq $8,%rdi 
    iaddq $-1,%rsi 

test: 
    jne loop 
    ret 
```

## Practice Problem 4.4



