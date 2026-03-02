# Chapter 2 - Representing and Manipulating Information

## 2.1 - Information Storage 
- most computers use **bytes**, each having a unique memory address

### 2.1.1 - Hexadecimal Notation 
- Hex notation (base 16) can be used to describe bit patterns, it goes from 0-F, and in C starts with 0x (case doesn't matter)
- Each character in hex represents 4 bits.

### 2.1.2 - Data Sizes 
- **word size** - size of pointer data, which determines how many unique memory addresses there can be (virtual address space)

### 2.1.3 - Addressing and Byte Ordering
- For objects spanning multiple bytes, they are stored in a contiguous sequence
- **Big Endian** - Bytes are stored from most to least significant
- **Little Endian** - Bytes stored from least to most significant

### 2.1.4 - Representing Strings
- Each character is represented with an ASCII code
- man ascii on linux to see ascii table

### 2.1.6 - Introduction to Boolean Algebra
- **~** - bitwise not
- **|** - bitwise or
- **^** - bitwise exclusive or
- **&** - bitwise and

### 2.1.8 - Logical Operators in C
return either 0 (false) or 1 (true)
- **!** - logical not
- **||** - logical or
- **&&** - logical and

### 2.1.9 - Shift Operations in C
- **>>** - right shift
- **<<** - left shift
- **logical right shift** - fills end with k 0's
- **arithmetic right shift** - fills end with k of the most significant bit

## 2.2 - Integer Representations

### 2.2.2 - Unsigned encodings
- for a bit vector with w bits, it can represent the range from 0 to 2^w - 1
- each number has a unique bit value

### 2.2.3 - Two's-Complement Encodings
- used to represent negative and positive numbers, where the most significant bit has negative weight
- can represent one more negative number than positive

### 2.2.4 - Conversions between signed and unsigned
- when converting from signed to unsigned or vice versa in c, the bits do not change, but they are interpered in a different way

### 2.2.5 - Signed vs Unsigned in C
- if an operation is performed on one signed and one unsigned number, C casts the signed argument to unsigned

### 2.2.6 - Expanding the Bit Representation of a Number
- **zero extension** - when converting an unsigned number to a larger data type, we can add more leading 0's
- **sign extension** - converting a two's complement number to a larger data type, add copies of most significant bit

### 2.2.7 - Truncating Numbers
- when converting to smaller data type, we truncate the numbers
- in a two's complement number, its the same expect the leading bit is converted into a sign bit

## 2.3 Integer Arithmetic

### 2.3.1 - Unsigined Addition
- if x+y > 2^w - 1, then the sum overflows

### 2.3.2 - Two's-Complement Addition
- there can be overflow when the amount of bits isn't enough to represent the number
- **positive overflow** -> 2^(w-1) <= x+y
- **negative overflow** -> x+y < -2^(w+1)
- you can detect overflow if positive + positive = negative or negative + negative = positive

### 2.3.3 - Two's-Complement Negation

### 2.3.4 - Unsigned Multiplication
- (x * y ) mod 2^w

### 2.3.5 - Two's-Complement Multiplication
- it can use up 2w bits, so in C its trunctaed to w bits
- bit level representation of unsigned and two's complement multiplication are the same

### 2.3.6 - Multiplying by Constants
- when multiplying by a power of two, you can add k zero's to the end where 2^k represents the number so a left shift by k 

### 2.3.7 - Dividing by Powers of 2
- with an unsigned number x/2^k, we can do x >> k (logical right shift)
- with a two's complement number if it is positive it works regularly and rounds down
- if its negative it rounds down in a right bit shift rather than in division where it rounds towards 0
- (x + (1 << k) - 1) >> k to bias it and make this act like division on negative numbers

## 2.4 Floating Point

### 2.4.1 - Fractional Binary Numbers
- can be represented with points above decimal being powers of 2^k and below the decimals being powers of 2^-k

