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
