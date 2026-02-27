# Solutions for Chapter 2

## 2.1
A. 0x25B9D2 = 0010 0101 1011 1001 1101 0010
B. 1010 1110 0100 1001 = 0xAE49
C. 0xA8B3D = 1010 1000 1011 0011 1101
D. 11 0010 0010 1101 1001 0110 - 0X322D96

## 2.2
5 32 0x20
23 8388608 0x800000
15 32768 0x8000
13 8192 0x2000
12 4096 0x1000
6 64 0x40
8 256 0x100

## 2.3
0 0000 0000 0x00
158 1001 1110 0x9E
76 0100 1100 0x4C
145 1001 0001 0x91
174 1010 1110 0xAE

## 2.4
A. 0x605c + 0x5 = 0x6061
B. 0x605c - 0x20 = 0x603c
C. 0x605c + 32 = 0x20 0x607c
D. 0x60fa - 0x605c = 0x9E

## 2.5
A. Little endian - 78
Big endian - 12
B. Little endian - 78 56
Big endian - 12 34
C. Little endian - 78 56 34
Big endian - 12 34 56

## 2.6
A. 0x0027C8F8 - 0000 0000 0010 0111 1101 1000 1111 1000
   0x4A1F23E0 - 0100 1010 0001 1111 0010 0011 1110 0000 
B. 
00000000001001111101100011111000
  01001010000111110010001111100000   
21 matching bits

## 2.7
6D 6E 6F 70 71 72

## 2.8
~a = 10110001
~b = 00011110
a&b = 01000000
a|b = 11101111
a^b = 10101111

## 2.9
A. Black + White, Blue + Yellow, Green + Magenta, Cyan + Red
B. Blue | Green = Cyan
Yellow & Cyan = Green
Red ^ Magenta = Blue

## 2.10
a = 0x61 0110 0001
b = 0x62 0110 0010
step 1. x = 0110 0001, y = 0000 0011
step 2. x = 0110 0010, y = 0000 0011
step 3. x = 0110 0010, y = 0110 0001

## 2.12
A. `x & 0xFF`
B. `x ^ ~0xFF`
C. `x | 0xFF`

## 2.13
```
int bis(int x, int m);
int bic(int y, int m);

int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y) {
    int result = bis(bic(x,y), bic(y,x));
    return result;
}
```

## 2.14
a = 0x55 0101 0101
b = 0x46 0100 0110
1010 1010
1011 1001
a & b = 0100 0100 0x44
a | b = 0101 0111 0x57
`~a | ~b = 1011 1011 0xBB`
a & !b = 0x00
a && b = 0x01
a || b = 0x01
!a || !b = 0x00
a && ~b = 0x01

## 2.15
`!(x ^ y)`

## 2.16
a = 0xD4 1101 0100
a << 2 = 0101 0000 0x50
logical a >> 3 = 0001 1010 0x1A
arimetic a >> 3 = 1111 1010 0xFA

## 2.17 
0x1 0001 1 1
0xB 1011 11 -5
0x2 0010 2 2


