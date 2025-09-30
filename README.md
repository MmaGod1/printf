# 0x11. C - printf
### Description

------------

printf is the C language function to do format-ted printing. The same function is also available in PERL. The printf function sends formatted output to stdout.
_printf() function format string is a character string, beginning and ending in its initial shift state, if any. 
These arguments are placed using the percentage '%' operator

------------


#### Compilation

**$ gcc -Wall -Werror -Wextra -pedantic *.c**

###### Specifiers

Specifier                |Output                        |Examples |
|----------------|-------------------------------|-----------------------------|
| `c` | Character | y |
| `d` or `i` | Signed integer | 1024, -1024 |
| `s` | String of characters | Hello Holberton |
| `b` | Binary Representation of unsigned integer | 01010110 |
| `u` | Unsigned integer | 1024 |
| `o` | Unsigned octal | 432 |
| `x` | Unsigned hexadecimal integer | 3ca |
| `X` | Unsigned hexadecimal integer (uppercase) | 3CA |
| `S` | String with hex-ascii value replacing special chars | \x0A\x0A |
| `p` | Pointer address | 0x403212 |
| `r` | Reversed string of characters | dlroW olleH |
| `R` | ROT13 Translation of string | Uryyb |

###### Flags (In development...)

|Flag                |Description                        |
|----------------|-------------------------------|
| `-` |Left-justify the output within the field width that was given; Right justification is the default (see _width_ sub-specifier). |
| `+` |Preceeds the result with a plus or minus sign (`+` or `-`) even for positive numbers. By default, only negative numbers are preceded with a `-` sign. |
| `(space)` |If no sign is going to be written, a blank space is inserted before the value. |
| `#` |Used with `o`, `x` or `X` specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. |
| `0` |Left-pads the number with zeroes (`0`) instead of spaces when padding is specified (see _width_ sub-specifier). |

###### Width (In development...)

|Width                |Description                        |
|----------------|-------------------------------|
| `(number)` |Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
| `*` | The _width_ is not specified in the _format_ string, but as an additional integer value argument preceding the argument that has to be formatted.|

### Precision (In development...)

|.Precision               |Description                        |
|----------------|-------------------------------|
| `.(number)` |**For integer specifiers (`d`, `i`, `o`, `u`, `x`, `X`):** _precision_ specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A _precision_ of 0 means that no character is written for the value 0. **For `s`**: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for _precision_, 0 is assumed. |

### Lenght modifiers (In development...)

|Modifier/Specifier  |`d` & `i`  |`u`, `o`, `x`, `X` |`c` |`s` |`p` |
|----------------|---------|------------|-------------|-----|-------|
| `none` | int |unsigned int | int| char pointer| void pointer |
| `h` |short int|unsigned short int |     |     |              |
| `l` |long int |unsigned long int  |     |     |              |

------------

### 1. Education is when you read the fine print. Experience is what you get if you don't
#### Write a function that prints numbers, followed by a new line.
Handle the following conversion specifiers:
* d
* i
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers

#
### 2. Just because it's in print doesn't mean it's the gospel
#### Create a man page for your function.

##### File: man_3_printf
#
### 3. With a face like mine, I do better in print
#### Handle the following custom conversion specifiers:

* b: the unsigned int argument is converted to binary


#
### 4. What one has not experienced, one will never understand in print
#### Handle the following conversion specifiers:
* u
* o
* x
* X
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers


#
### 5. Nothing in fine print is ever good news
#### Use a local buffer of 1024 chars in order to call write as little as possible.


#
### 6. My weakness is wearing too much leopard print
#### Handle the following custom conversion specifier:
* S : prints the string.
* Non printable characters "(0 < ASCII value < 32 or >= 127)" are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

#
### 7. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print
#### Handle the following conversion specifier: p.
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers


#
### 8. The big print gives and the small print takes away
#### Handle the following flag characters for non-custom conversion specifiers:
* \+
* space
* \#


#
### 9. Sarcasm is lost in print
#### Handle the following length modifiers for non-custom conversion specifiers:
* l
* h
Conversion specifiers to handle: d, i, u, o, x, X


#
### 10. Print some money and give it to us for the rain forests
#### Handle the field width for non-custom conversion specifiers.


#
### 11. The negative is the equivalent of the composer's score, and the print the performance
#### Handle the precision for non-custom conversion specifiers.


#
### 12. It's depressing when you're still around and your albums are out of print.
#### Handle the 0 flag character for non-custom conversion specifiers.


#
### 13. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection.
#### Handle the - flag character for non-custom conversion specifiers.


#
### 14. Print is the sharpest and the strongest weapon of our party.
#### Handle the following custom conversion specifier:
* r : prints the reversed string


#
### 15. The flood of print has turned reading into a process of gulping rather than savoring 
#### Handle the following custom conversion specifier:
* R: prints the rot13'ed string


#
### 16. *
#### All the above options work well together.

