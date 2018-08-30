/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~(~x & ~y);
    /* x or y also means not (not x and not y) because at least one has to be true
        cuz it cant just be like neither is true so its not (neither is true)*/
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    int x = 0x55;
    x = (x << 8) | x;/*shift x by 8 bits adding 8 zeros essentially and then add 0101 0101 which is 0x55 turning it into 0101 0101 0101 0101*/
    x = (x << 8) | x;/* now that we have 0101 0101 0101 0101 we add 16 zeroes and add that to itself resulting in the answer*/
    x = (x << 8) | x;
    return x;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
    int x = 0 << 31;/*unceccessary because everything is a word*/
    x = ~(x);/*complement of a 32 bit word holding all 0 is all 1s*/
    return x;
    
    
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
    int maker = 0x55;/*we are trying to make 0x55555555 like we did it in eveBits*/
    maker = (maker<<8) | maker;
    maker = (maker << 16) | maker;
    
    
    x = x&maker;/*we and x with maker and that should return maker if x is indeed all even bits*/
    
    x = x^maker;/*if we xor it with maker it should return all 0 if x is indeed all even bits*/
    
    return !x;/*if it is all even bits x^maker will be zero and !0 is 1 but if its not 0 then !(!0) is 0*/
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
    int maker = 0xAA;
    maker = (maker << 8) | maker;/* produces 0xAA00 and then produces 0xAAAA*/
    maker = (maker << 16) | maker;/* produces 0xAAAA 0000 and then produces 0xAAAA AAAA*/
    x = x&maker; /* and with 1010 and 0101 will produce a 0 and and with 1010 will produce a number and !(!0) is 0 and !(!number) is 1*/
    return !(!x);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */

int byteSwap(int x, int n, int m) {
    
    
    int originaln = 0;
    int originalm = 0;
    int masker = 0xff;
    int nbyte = 0;
    int mbyte = 0;  
    
    int negator = 0x1;
    negator = negator << 31;
    
    n = n << 3;
    m = m << 3;
    masker = masker << n;
    nbyte = masker & x;
    masker = 0xff;
    masker = masker << m;
    mbyte = masker & x;
    
    

    originaln = nbyte;
    originalm = mbyte;
    
    


    
   
    
    
    nbyte = ((nbyte >> n) & ~(((negator) >> n) << 1)) << m;/*understand this mane*/
    mbyte = ((mbyte >> m) & ~(((negator) >> m) << 1)) << n; //mask to remove everytthing after msb
    
    /*
    nbyte = (nbyte >> n) << m;
    mbyte = (mbyte >> m) << n;
    */
    
    
    
    
    x = x^originalm;
    x = x^originaln;
    
    x = x | nbyte;
    x = x | mbyte;
    
    /*x ^= negator;*/

    
    return x;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    
    
   
    int boolean = 0;
    int maker = 0;
    int bitgetter = 0;
    int z = 0;
    int zgetter = 0;
    int booler = 0;

    boolean = !((x^y) >> 31);
    maker = ~(boolean) + 1;

    x = x & maker;
    y = y & maker;

    bitgetter = ((x&(1 << 31)) >> 31) & 1;

    z = x+y;

    zgetter = ((z&(1 << 31)) >> 31) & 1;

    booler = bitgetter^zgetter;

    return !booler;
    
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    int mask = 0;
    int res = 0;
    
    
    mask = !x + ~(0);/*0 if false 1111....1111 if true*/
    res = (~(mask)&z) | ((mask)& y);/*not mask and z  will give you y straight up if x is true, and z if x is false*/
  return res;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    int bitgetter1 = 0x30;
    int bitgetter2 = 0;
    int zer0 = 0;
    int answer = 0;
    int ander = 0;
    int neg = 0;
    int others = x& ~(63);

    ander = x&0x30;
    
    bitgetter1 = (ander^bitgetter1);/*if it is 0x30 then this will be 1 otherwise itll be 0*/
  
    
    
    bitgetter2 = x&15;
    
    bitgetter2 = 10 + ((~bitgetter2) + 1);/*<=0 if false >0 if true*/
    zer0 = !(0^bitgetter2);/* 0 if 0 otherwise a number*/
    neg = bitgetter2 >>31;//bad if not 0


    
    answer = (others + bitgetter1 + neg + zer0);
    
    return !(answer);
    
}/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
    
    int masker = 0xff;
    int byter = 0;
    n = n << 3;
    masker = masker << n;
    byter = x&masker;
    
    x = x^byter;
    
    c = c << n;
    
    x = x|c;
    
    
    
    
  return x;
}
/* reverseBits - reverse the bits in a 32-bit integer,
              i.e. b0 swaps with b31, b1 with b30, etc
 *  Examples: reverseBits(0x11111111) = 0x88888888
 *            reverseBits(0xdeadbeef) = 0xf77db57b
 *            reverseBits(0x88888888) = 0x11111111
 *            reverseBits(0)  = 0
 *            reverseBits(-1) = -1
 *            reverseBits(0x9) = 0x90000000
 *  Legal ops: ! ~ & ^ | + << >> and unsigned int type
 *  Max ops: 90
 *  Rating: 4
 */
int reverseBits(int x) {
  return 0;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x2, int y2) {
       /*return int max if  positive overflow(add two +) and int min if negative overflow*/
    int boolean = 0;
    int x = x2;
    int y = y2;
    int maker = 0;
    int bitgetter = 0;
    int z = 0;
    int zgetter = 0;
    int booler = 0;
    int mask = 0;
    int negatoor = 1<<31;
    int res = 0;
    int bitgetter2 = 0;

    boolean = !((x^y) >> 31);
    maker = ~(boolean) + 1;

    x = x & maker;
    y = y & maker;

    bitgetter = ((x&(negatoor)) >> 31);/* zero if + 1 if negative*/
    bitgetter2 = bitgetter;
    bitgetter = bitgetter&1;

    z = x+y;

    zgetter = ((z&(1 << 31)) >> 31) & 1;

    booler = !(bitgetter^zgetter);/*1 means no overflow, 0 means overflow*/

    /*--*/
    booler = !booler;
    
    
    mask = !booler + ~(0);/*0 if false 1111....1111 if true*/
    res = (~(mask)&(x2+y2)) | ((mask)& (bitgetter2^(~negatoor)));/*not mask and z  will give you y straight up if x is true, and z if x is false*/
    /* if x y otherwise z */
    
    
    
    return res;
}
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  return 2;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  return 2;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  return 2;
}
