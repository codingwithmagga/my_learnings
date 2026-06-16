# Chapter 3

## 3.59

// dest in %rdi, x in %rsi, y %rdx

y in %rax
x nach %rcx
x >> 63 in %rcx // sign left => x_h
y_l * x_h in %rcx
x_l* y_l in %rdx
y_l * x_h + y_l*y_l nach %rcx
x*y => x_h*y_h in rdx, s_l in rax
x_h*y_h + y_l * x_h + y_l*y_l nach rdx
x_h, y_h nach 8(%rdi)

## 3.60



