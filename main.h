#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

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

#endif
