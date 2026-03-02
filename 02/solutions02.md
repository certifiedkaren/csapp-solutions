# Solutions for Chapter 2

## 2.1
A. 0x25B9D2 = 0010 0101 1011 1001 1101 0010 <br>
B. 1010 1110 0100 1001 = 0xAE49 <br>
C. 0xA8B3D = 1010 1000 1011 0011 1101 <br>
D. 11 0010 0010 1101 1001 0110 - 0X322D96 <br>

## 2.2
5 32 0x20 <br>
23 8388608 0x800000 <br>
15 32768 0x8000 <br>
13 8192 0x2000 <br>
12 4096 0x1000 <br>
6 64 0x40 <br>
8 256 0x100 <br>

## 2.3
0 0000 0000 0x00 <br>
158 1001 1110 0x9E <br>
76 0100 1100 0x4C <br>
145 1001 0001 0x91 <br>
174 1010 1110 0xAE <br>

## 2.4
A. 0x605c + 0x5 = 0x6061 <br>
B. 0x605c - 0x20 = 0x603c <br>
C. 0x605c + 32 = 0x20 0x607c <br>
D. 0x60fa - 0x605c = 0x9E <br>

## 2.5
A. Little endian - 78 <br>
Big endian - 12 <br>
B. Little endian - 78 56 <br>
Big endian - 12 34 <br>
C. Little endian - 78 56 34 <br>
Big endian - 12 34 56 <br>

## 2.6
A. 0x0027C8F8 - 0000 0000 0010 0111 1101 1000 1111 1000 <br>
   0x4A1F23E0 - 0100 1010 0001 1111 0010 0011 1110 0000  <br>
B. 
00000000001001111101100011111000 <br>
  01001010000111110010001111100000    <br>
21 matching bits <br>

## 2.7
6D 6E 6F 70 71 72 <br>

## 2.8
~a = 10110001 <br>
~b = 00011110 <br>
a&b = 01000000 <br>
a|b = 11101111 <br>
a^b = 10101111 <br>

## 2.9
A. Black + White, Blue + Yellow, Green + Magenta, Cyan + Red <br>
B. Blue | Green = Cyan <br>
Yellow & Cyan = Green <br>
Red ^ Magenta = Blue <br>

## 2.10
a = 0x61 0110 0001 <br>
b = 0x62 0110 0010 <br>
step 1. x = 0110 0001, y = 0000 0011 <br>
step 2. x = 0110 0010, y = 0000 0011 <br>
step 3. x = 0110 0010, y = 0110 0001 <br>

## 2.12
A. `x & 0xFF` <br>
B. `x ^ ~0xFF` <br>
C. `x | 0xFF` <br>

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
a = 0x55 0101 0101 <br>
b = 0x46 0100 0110 <br>
1010 1010 <br>
1011 1001 <br>
a & b = 0100 0100 0x44 <br>
a | b = 0101 0111 0x57 <br>
`~a | ~b = 1011 1011 0xBB` <br>
a & !b = 0x00 <br>
a && b = 0x01 <br>
a || b = 0x01 <br>
!a || !b = 0x00 <br>
a && ~b = 0x01 <br>

## 2.15
`!(x ^ y)` <br>

## 2.16
a = 0xD4 1101 0100 <br>
a << 2 = 0101 0000 0x50 <br>
logical a >> 3 = 0001 1010 0x1A <br>
arimetic a >> 3 = 1111 1010 0xFA <br>

## 2.17 
0x1 0001 1 1 <br>
0xB 1011 11 -5 <br>
0x2 0010 2 2 <br>

## 2.22
A. 1100  -8 + 4 = -4 <br>
B. 11100 -16 + 8 + 4 = -4 <br>
C. 111100 -32 + 16 + 8 + 4 = -4 <br>

## 2.23
0x00000076 0x00000076 0x00000076 <br>
0x87654321 0x00000021 0x00000021 <br>
0x000000C9 0x000000C9 0xFFFFFFC9 <br>
0xEBCBA987 0x00000087 0xFFFFFF87 <br>

## 2.24
Unsigned <br>
1 -> 1 <br>
3 -> 3 <br>
5 -> 5 <br>
12 -> 4 <br>
14 -> 6 <br>

Two's complement <br>
1 -> 1 <br>
3 -> 3 <br>
5 -> 5 <br>
-4 -> 4 <br>
-2 -> 6 <br>

## 2.25
when length is 0, there is a memory error because the length is unsigned so when you do length-1 you get umax which you can't access that element <br>
fix by doing i < length instead of i < length -1 <br>

## 2.26
A. if strlen(s) < strlen(s) <br>
B. the program will produce an incorrect result because the unsigned representation of the negative will be greater than 0 <br>
C. `return strlen(s) > strlen(t)` <br>

## 2.27
```
// Determine whether arguments can be added without overflow
int uadd_ok(unsigned x, unsigned y) {
    return (x + y) >= x;
}
```

## 2.29
10100 + 10001 = 100101 (-27) <br>
two's-complement = 00101 (5), negative overflow <br>
11000 + 11000 = 110000 (-16) <br>
two's-complement = 10000 (-16), no overflow <br>

## 2.30
```
// Determine whether arguments can be added without overflow
int tadd_ok(int x, int y) {
    if (x < 0 && y < 0) {
        return x + y > 0 ? 0 : 1;  
    }
    if (x > 0 && y > 0) {
        return x + y < 0 ? 0 : 1;
    }
    return 1;
}
```

## 2.31
because if there is an overflow error it will cause undefined behavior before the statement can catch it <br>

## 2.33
2 -> E <br>
3 -> D <br>
9 -> 9 <br>
B -> 7 <br>
C -> 4 <br>


## 2.35
A. it would not fix the problem because the call to malloc would still wrap around when overflowing <br>
B. <br>
```
size_t count = (size_t) ele_cnt;
if (ele_cnt > 0 && count > SIZE_MAX / ele_size)
    return NULL;
void *result = malloc(ele_cnt * ele_size);
if (result = NULL)
    return NULL;
```

## 2.38
1, 2, 3, 4, 5, 8, 9 <br>

## 2.40
7 -> (x << 3) - x <br>
30 -> (x << 4) + (x << 3) + (x << 2) + (x << 1) <br>
28 -> (x << 5) - (x << 2) <br>
55 -> (x << 6) - (x << 3) - x <br>

## 2.45
1/8 -> 0.001 -> 0.125 <br>
3/4 -> 0.11 -> 0.75 <br>
5/16 -> 0.0101 -> 0.3125 <br>
2 11/16 -> 10.1011 -> 10.6875 <br>

## 2.46
A. 0.1 - x = 0.0000000000000000000000011001100...
B. 9.54 * 10^-8
C. 9.54 * 10^-8 * 3600000 = 0.343 sec error
D. 0.343 * 2000 = 686.6m
