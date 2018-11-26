# BDH-Calc
  by Scott Hammond

Fully functional 64 bit calculator that does standard arithmatic and logic on signed and unsigned integers. 
## Features
* Selectable word size from 8 to 64 bits; binary, decimal, and hexadecimal converstion (its namesake)
* 10 memory registers
* Small screen footprint so it doesnt get in the way 

## Screenshot
![screenshot](https://github.com/nishanth1232/BDH-Calc/blob/master/images/screenshot.png)

## Key explanations

*C*: Clears the display and any previously entered numbers. For example, the sequence, 3 * 6 C, clears both the 6 and the 3 from memory.

*Bin/Dec/Hex buttons*: Converts the display between these 3 different number bases- binary, decimal, and hexadecimal. (Octal lovers should stay in the ocean =) )

*Signed/unsigned and word size popup*:  Allows you to select what kind of numbers you want to compute with. uint64 is an unsigned long long (64 bits). Likewise, int16 is a signed short (16 bits). Etc.

*2X*: This is actually "2 to the Xth power" .. standard BButtons have no way to actually display that other than 2X. Someday Ill make a custom button to display it correctly. Usage:  5 2X produces 32, that is 2 to the 5th power is 32. This can be useful at times.. say you forget how many colors a 24bit color depth can display... enter 24 then hit 2X and you get 16777216.

*10X*: Same as above, 10 to the Xth power. I had room for 2 extra buttons, so I added these two.

*and*: bitwise and. 5 and 3 = 1. Only those bits that are the same in both numbers are left on.

*or*: bitwise or. 5 or 3 = 7. All on bits from both numbers are left on.

*xor*: bitwise xor. 5 xor 3 = 6. Only bits that are on in one number, but not the other are left on.

*not*: bitwise not. 5 not = 18446744073709551610. Note that this depends on the word size. All on bits are turned off, all off bits are turned on, thus 5 does not produce 5 again. This is actually a special case.  

*STO and RCL*: STORE and RECALL. Allows you to access the 10 memory registers (numbers 0-9) example: Entering 5 STO 0, stores a 5 in register 0. Also entering the sequence 5 + 2 = STO 9, saves a 7 in register 9  Recall: if you have 5 stored in register 1, entering "2 + RCL 1 =", produces 7. Note, keyboard equvalents work for STO and RCL, that is, clicking on STO then pressing the 3 key will store the current number in register 3. 

*shl, shr*: Left and Right bitwise shifts. This basically multiplies (left) and divides (right) a number by 2. Ex:  5 shl becomes 10.  Note: No remainder... thus 5 shr becomes 2.

*rol, ror*: Left and Right bitwise rotation. Similar to shifts, although no bits are lost, they are simply tacked on to the other side, thus this depends on the word size again. Ex: in a 64 bit word size, 1 shr becomes 0, while 1 ror becomes 9223372036854775808. Assembly language note: these instructions are the same as rol and ror from x86 assembly, they do not rotate though carry, i.e. rcl and rcr.

*mod*: Modulus. This is the remainer from division. Examples: 11 mod 3 = 2,  11 mod 5 = 1, 11 mod 6 = 5, etc.


## Keyboard equivalents

*0-9*, *A-F*, *a-f*   -- Numbers

+, -, *, /, %  -- Plus, minus, times, divide, modulus

&, |, !, ^ -- And, or, not, xor

delete -- Clear

=, enter --  Equal and enter do the same thing.

Command (alt) C  will copy the output to the clipboard.

There are no keyboard equivalents for left and right shift and rotates, 2 to the X, 10 to the X, and binary/decimal/hexadecimal buttons.

## Notes

You can chain together functions, but there is no precidence checking.. eg 2 + 3 * 4 =  results in 20, not 14.

When you are using a large word size, 64 or 32, the NOT button is pretty useless.. not 7 in uint64 mode, and you get 18446744073709551608!. Not 7 in uint8 mode is 248 -- probably the result that you were looking for.  TRICK: NOT 0 to get the largest number than the current word size can produce -- 18446744073709551615 for 64bit, 4294967295 for 32 bit, 65535 for 16 bit, etc.

IMPORTANT!
Not, left and right shifts and rotates, the +/- key,  2 to the X, 10 to the X, STORE and RECALL keys are non-invalidating operations!  That is, they modify the number that is displayed without entering it into memory.
Examples:
This sequence: 5 * 3 shr =   produces 5, not 7! (the shr operation does not enter the 3, it shifts it right once to produce 1, and when you hit =, 5 * 1 is 5).
The sequence: 1 2 STO 3 4 leaves you with 124 as the number displayed, and 12 stored in register #3.  Entering the sequence 1 (+/-) 2 (+/-) 3 (+/-) produces -123.
Entering the sequence 1 + 2 = (+/-) * 5 =   produces -15.

Let me know how you like this, if its useful, if it can be improved or the user interface changed in any way.
