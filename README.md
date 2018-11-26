# BDH-Calc
  by Scott Hammond

Fully functional 64 bit calculator that does standard arithmatic and logic on signed and unsigned integers. 
## Features
* Selectable word size from 8 to 64 bits; binary, decimal, and hexadecimal converstion (its namesake)
* 10 memory registers
* Small screen footprint so it doesnt get in the way 

## Screenshot
![screenshot](https://github.com/nishanth1232/BDH-Calc/blob/master/images/screenshot.png)

New in 1.1
---------------------------

Updated spacing for Haiku to fit larger font sizes
Select between Bin, Dec, Hex radio buttons via tab key navigation
Backspace key deletes a single number
Added about window accessed from right click context menu
You can move the window on from any empty area


Key explanations:
---------------------------

C: clears the display and any previously entered numbers.  for example the sequence, 3 * 6 C, clears both the 6 and the 3 from memory.

Bin/Dec/Hex buttons: converts the display between these 3 different number bases- binary, decimal, and hexadecimal.  (Octal lovers should stay in the ocean =)

signed/unsigned and word size popup:  Allows you to select what kind of numbers you want to compute with. uint64 is an unsigned long long (64 bits).  Likewise, int16 is a signed short (16 bits). etc.

2X: this is actually "2 to the Xth power" .. standard BButtons have no way to actually display that other than 2X.  Someday Ill make a custom button to display it correctly.  usage:  5 2X produces 32, that is 2 to the 5th power is 32.  This is can be useful at times.. say you forget how many colors a 24bit color depth can display... enter 24 then hit 2X and you get 16777216.

10X: same as above, 10 to the Xth power.  I had room for 2 extra buttons, so I added these two.

and: bitwise and.  5 and 3 = 1.  Only those bits that are the same in both numbers are left on.

or: bitwise or.  5 or 3 = 7.  All on bits from both numbers are left on.

xor: bitwise xor.  5 xor 3 = 6.  Only bits that are on in one number, but not the other are left on.

not: bitwise not.  5 not = 18446744073709551610.  Note that this depends on the WORD size!!!  All on bits are turned off, all off bits are turned on, thus 5 not not produces 5 again.  This is actually a special case xor.  

STO and RCL:  STORE and RECALL.  Allows you to access the 10 memory registers (numbers 0-9) example:  entering 5 STO 0, stores a 5 in register 0.  Also entering the sequence 5 + 2 = STO 9, saves a 7 in register 9.  Recall:  if you have 5 stored in register 1, entering "2 + RCL 1 =", produces 7.  Note, keyboard equvalents work for STO and RCL -- that is, clicking on STO then pressing the 3 key will store the current number in register 3. 

shl, shr:  Left and Right bitwise shifts.  This basically multiplies (left) and divides (right) a number by 2.  Ex:  5 shl becomes 10.  Note: no remainder... thus 5 shr becomes 2.

rol, ror: Left and Right bitwise rotation.  Similar to shifts, although no bits are lost, they are simply tacked on to the other side, thus this depends on the WORD size again!  Ex: in a 64 bit word size, 1 shr becomes 0, while 1 ror becomes 9223372036854775808.  Assembly language note: these instructions are the same as rol and ror from x86 assembly, they are not rotate though carry, i.e. rcl and rcr.

mod:  modulus.  This is the remainer from division.  examples: 11 mod 3 = 2,  11 mod 5 = 1, 11 mod 6 = 5, etc.


Keyboard equivalents:
----------------------------------
0-9, A-F, a-f   -- numbers

+, -, *, /, %  -- plus, minus, times, divide, modulus

&, |, !, ^ -- and, or, not, xor

delete -- clear

=, enter --  equal and enter do the same thing.

command (alt) C  will copy the output to the clipboard

There are no keyboard equivalents for left and right shift and rotates, 2 to the X, 10 to the X, and binary/decimal/hexadecimal buttons.



Notes:
---------
You can chain together functions, but there is no precidence checking.. eg 2 + 3 * 4 =  results in 20, not 14.

When you are using a large word size, 64 or 32, the NOT button is pretty useless.. not 7 in uint64 mode, and you get 18446744073709551608!  not 7 in uint8 mode is 248 -- probably the result that you were looking for.  TRICK: NOT 0 to get the largest number than the current word size can produce -- 18446744073709551615 for 64bit, 4294967295 for 32 bit, 65535 for 16 bit, etc.

IMPORTANT!
not, left and right shifts and rotates, the +/- key,  2 to the X, 10 to the X, STORE and RECALL keys are non-invalidating operations!  That is, they modify the number that is displayed without entering it into memory.
Examples:
This sequence: 5 * 3 shr =   produces 5, not 7! (the shr operation does not enter the 3, it shifts it right once to produce 1, and when you hit =, 5 * 1 is 5).
The sequence: 1 2 STO 3 4 leaves you with 124 as the number displayed, and 12 stored in register #3.  Entering the sequence 1 (+/-) 2 (+/-) 3 (+/-) produces -123.
Entering the sequence 1 + 2 = (+/-) * 5 =   produces -15.


TO DO:
-----------

a fix for the hidden high long word in 64 bit binary mode.

replication replication replication.

floating point support.  Youll notice that FP is in the popupmenu -- I already have FP functions decided upon, I just need to get it done.  They are:
e to the x,
ln x,
1/x,
log x,
10 to the x (same as the integer funcion.. now you know why its there),
2 to the x (ditto),
square root,
y to the x,
PI,
a degrees to radians button,
sin, asin,
cos, acos,
tan, atan.
Of couse, all FP calculations will use 64 bit doubles.

Let me know how you like this, if its useful, if it can be improved or the user interface changed in any way.

http://www.mindspring.net/~sehammond/beos.html

sehammond@mindspring.com
seh1@acpub.duke.edu
