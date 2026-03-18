# Chapter 3 Solutions

## 3.1
%rax -> 0x100 <br>
0x104 -> 0xAB <br>
$0x108 -> 0x108 <br>
(%rax) -> 0xFF <br>
4(%rax) -> 0xAB <br>
9(%rax, %rdx) -> 0x11 <br>
260(%rcx, %rdx) -> 0x13 <br>
0xFC(,%rcx, 4) -> 0xFF <br>
(%rax, %rdx, 4) -> 0x11 <br>

## 3.2
```asm
movl %eax, (%rsp)
movw (%rax), %dx
movb $0xFF, %bl
movb (%rsp,%rdx,4), %dl
movq (%rdx), %rax
movw %dx, (%rax)
```

## 3.3
explain whats wrong with each of these <br>
```
movb $0xF, (%ebx)     # can't address a 32 bit register
movl %rax, (%rsp)     # rax is 64 bit, use movq
movw (%rax),4(%rsp)   # can't move memory value into another
movb %al,%sl          # %sl is not a register
movq %rax,$0x123      # cant move value into a constant
movl %eax,%rdx        # eax and rdx aren't same size
movb %si, 8(%rbp)     # si is 16 bit, use movw
```

## 3.4
```
*dp = (dest_t) *sp;
sp = rdi, dp = rsi

sp = char -> dp = int
movsbl (%rdi), %eax
movl %eax, (%rsi)

sp = char -> dp = unsigned
movsbl (%rdi), %eax
movl %eax, (%rsi)

sp = unsigned char -> dp = long
movzbl (%rdi), %eax
movq %rax, (%rsi)

sp = int -> dp = char
movl (%rdi), %eax
movb %al, (%rsi)

sp = unsigned -> dp = unsigned char
movl (%rdi), %eax
movb %al, (%rsi)

sp = char -> dp = short
movsbw (%rdi), %ax
movb %ax, (%rsi)
```

## 3.5
```
void decode1(long *xp, long *yp, long *zp)
xp in %rdi, yp in %rsi, zp in %rdx
decode1:
  movq (%rdi), %r8
  movq (%rsi), %rcx
  movq (%rdx), %rax
  movq %r8, (%rsi)
  movq %rcx, (%rdx)
  movq %rax, (%rdi)
ret

void decode1(long *xp, long *yp, long *zp) {
  long x = *xp;
  long y = *yp;
  long z = *zp;
  *yp = x;
  *zp = y;
  *xp = z;
}
```

## 3.6
```
%rbx = p, %rdx = q
leaq 9(%rdx), %rax -> rax = 9 + q
leaq (%rdx,%rbx), %rax -> rax = q + p
leaq (%rdx,%rbx,3), %rax -> rax = q + 3p
leaq 2(%rbx,%rbx,7), %rax -> rax = 8p + 2
leaq 0xE(,%rdx,3), %rax -> rax = 3q + 14
leaq 6(%rbx,%rdx,7), %rax -> rax = p + 7q + 6
```

## 3.7
```
short scale3 (short x, short y, short z) {
  short t = 10 * y + z + y * x;
  return t;
}
```

## 3.8
```
addq %rcx,(%rax)
dest -> 0x100 value -> 0x100
subq %rdx,8(%rax)
dest -> 0x108 value -> 0xA8
imulq $16,(%rax,%rdx,8)
dest -> 0x118 value -> 0x110
incq 16(%rax)
dest -> 0x110 -> value -> 0x14
decq %rcx
dest -> %rcx value -> 0x0
subq %rdx,%rax
dest -> %rax value -> 0xFD
```

## 3.9
```
long shift_left4_rightn(long x, long n) {
  x <<= 4;
  x >>= n;
  return x;
}
x in %rdi, n in %rsi
shift_left4_rightn:
  movq %rdi, %rax
  salq $4, %rax
  movl %esi, %ecx
  sarq %cl, %rax
  ret
```

## 3.10
```c
short arith3(short x, short y, short z) {
  short p1 = z | y;
  short p2 = p1 >> 9;
  short p3 = ~p2;
  short p4 = y - p3; 
}
```

## 3.12
```
uremdiv:
  movq %rdx, %r8
  movq %rdi, %rax
  movl $0, %edx
  idivq %rsi
  movq %rax, (%r8)
  movq %rdx, (%rcx)
  ret
```

## 3.13
A. int, comparison: < (signed) <br>
B. short, comparison: >= (signed) <br>
C. unsigned char, comparison: > (signed) <br>
D. long, unsigned long, comparison: ~ <br>

## 3.14
A. long, comparison: >= (signed) <br>
B. short, unsigned short, comparison: = <br>
C. unsigned char, comparison: > (unsigned) <br>
D. int, comparison: <= (signed) <br>

## 3.15
A. 4003fe <br>
B. 400425 <br>
C. ja -> 400543, pop -> 400545 <br>
D. 400560 <br>

## 3.16
```c
// A.
void goto_cond(short a, short *p) {
    if (a == 0) {
      goto done;
    if (a >= *p)
      goto done;
    *p = a;
  done:
    return;
  }
}
```
B. Because it needs to perform 2 comparisons in that one if statement <br>

## 3.17
```c
// A.
long lt_cnt = 0;
long ge_cnt = 0;
long absdiff_se(long x, long y) {
  long result;
  if (x < y)
    goto true;
  ge_cnt++; 
  result = x - y;
  return result;
  true:
    lt_cnt++;
    result = y - x;
    return result;
}
```

## 3.18
```c
short test (short x, short y, short z) {
  short val = z + y - x;
  if (z > 5) {
    if (y > 2)
      val = x / z;
    else
      val = x / y;
  } else if (z < 3)
      val = z / y;
  return val;
}
```

## 3.19
A. 40 cycles <br>
B. 65 cycles <br>

## 3.20
A. / <br>

```asm
# B
arith:
  leaq 15(%rdi), %rbx   # temp = x + 15
  testq %rdi, %rdi      # test x
  cmovns %rdi, %rbx     # if x >= 0, rbx = x
  sarq $4, %rbx         # arithmetic right shift by 4
  ret
```

## 3.21
```c
short test(short x, short y) {
  short val = y + 12;
    if (x < 0) {
      if (x < y)
        val = x * y;
      else
        val = x | y;
  } else if (y >= 10)
    val = x / y;
  return val;
}
```

## 3.23
A. %rbx, %rcx, %rdx <br>
B. using the lea instruction, it gets the value in that address <br>

## 3.24
```c
short loop_while(short a, short b) {
  short result = 0;
  while (a > b) {
    result = result + a * b;
    a = a - 1;
  }
  return result
}

```
