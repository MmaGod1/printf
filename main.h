#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * struct format_flags - stores active flag characters and settings for a format specifier
 * @plus:   set to 1 if '+' flag is present (forces sign on positive numbers)
 * @space:  set to 1 if ' ' flag is present (prefixes positive numbers with space)
 * @hash:   set to 1 if '#' flag is present (adds prefix for o, x, X formats)
 * @width:  minimum field width (pads output with spaces if shorter than this)
 * @minus:  set to 1 if '-' flag is present (left-align output within field width)
 * @zero:   '0' pad numbers with leading zeros
 * @precision: if not specified
 * @length: length modifier:
 *          0 = none (default, int/unsigned int)
 *          1 = 'h' (short/unsigned short)
 *          2 = 'l' (long/unsigned long)
 *
 * Description:
 * This struct is used inside _printf to keep track of flags, field width,
 * alignment, and length modifiers specified before a conversion specifier.
 * It allows helper functions (e.g., buf_number_flags, buf_hex_flags) to format
 * numbers and strings consistently, handling padding, alignment, and size.
 */
typedef struct format_flags
{
    int plus;    /* '+' */
    int space;   /* ' ' */
    int hash;    /* '#' */
    int width;   /* field width */
    int minus;   /* left align (if '-') */
    int zero;
    int precision; /* -1 if not specified */
    int length;  /* 0 = none, 1 = 'h', 2 = 'l' */
} format_flags;


/* Main printf function */
int _printf(const char *format, ...);

/* Helper print functions */
int print_char(va_list args);
int print_string(char *s);
int print_percent(void);
int print_unknown(char spec);
int print_number(int n);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n);
int print_HEX(unsigned int n);


/* Buffered helpers */
int buf_char(va_list args, char *buffer, int *buf_index, format_flags flags);
int buf_string(char *str, char *buffer, int *buf_index, format_flags flags);
int buf_percent(char *buffer, int *buf_index);
int buf_number(int n, char *buffer, int *buf_index);
int buf_binary(unsigned int n, char *buffer, int *buf_index);
int buf_uint(unsigned int n, char *buffer, int *buf_index);
int buf_octal(unsigned int n, char *buffer, int *buf_index);
int buf_hex(unsigned int n, char *buffer, int *buf_index);
int buf_HEX(unsigned int n, char *buffer, int *buf_index);
int buf_unknown(char spec, char *buffer, int *buf_index);
void buf_addchar(char *buffer, int *buf_index, char c);
int buf_S(char *s, char *buffer, int *buf_index);
int buf_pointer(void *ptr, char *buffer, int *buf_index);
int buf_add(char *buffer, int *buf_index, char c);

/* flags-aware helpers */
int buf_number_flags(long num, char *buffer, int *buf_index, format_flags flags);
int buf_octal_flags(unsigned long num, char *buffer, int *buf_index, format_flags flags);
int buf_uint_flags(unsigned long num, char *buffer, int *buf_index, format_flags flags);
int buf_hex_flags(unsigned long num, char *buffer, int *buf_index,
		format_flags flags, int uppercase);
int buf_pointer_flags(void *ptr, char *buffer, int *buf_index, format_flags flags);
int buf_plus_flag(int n, char *buffer, int *buf_index);
int buf_space_flag(int n, char *buffer, int *buf_index);
int buf_hash_flag(char specifier, unsigned int n,
		char *buffer, int *buf_index);
int buf_reverse(char *str, char *buffer, int *buf_index);
int buf_rot13(char *str, char *buffer, int *buf_index);

#endif
