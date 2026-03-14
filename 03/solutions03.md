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
