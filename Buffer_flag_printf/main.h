#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct format_flags - stores active flag characters for a format specifier
 * @plus:  set to 1 if '+' flag is present (forces sign on positive numbers)
 * @space: set to 1 if ' ' flag is present (prefixes positive numbers with space)
 * @hash:  set to 1 if '#' flag is present (adds prefix for o, x, X formats)
 *
 * Description: This struct is used inside _printf to keep track
 * of which flags were specified before a conversion specifier.
 * It allows helper functions (e.g., buf_number_flags, buf_hex_flags)
 * to decide how to format the output consistently.
 */
typedef struct format_flags
{
	int plus;   /* '+' */
	int space;  /* ' ' */
	int hash;   /* '#' */
	int length; /* 0 = none, 1 = h, 2 = l */
} format_flags;

/* Main printf function */
int _printf(const char *format, ...);


/* Buffered helpers */
int buf_char(va_list args, char *buffer, int *buf_index);
int buf_string(char *s, char *buffer, int *buf_index);
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
int buf_number_flags(int num, char *buffer, int *buf_index, format_flags flags);
int buf_uint_flags(unsigned int num, char *buffer, int *buf_index, format_flags flags);
int buf_octal_flags(unsigned int num, char *buffer, int *buf_index, format_flags flags);
int buf_hex_flags(unsigned int num, char *buffer, int *buf_index, format_flags flags, int uppercase);
int buf_pointer_flags(void *ptr, char *buffer, int *buf_index, format_flags flags);
int buf_plus_flag(int n, char *buffer, int *buf_index);
int buf_space_flag(int n, char *buffer, int *buf_index);
int buf_hash_flag(char specifier, unsigned int n,
		char *buffer, int *buf_index);

#endif
