#include "main.h"

/**
 * apply_width - applies width, zero, and minus flags to a string
 * @str: string to format
 * @buffer: main output buffer
 * @buf_index: pointer to buffer index
 * @flags: active format flags
 *
 * Return: number of characters written
 */
int apply_width(const char *str, char *buffer,
                int *buf_index, format_flags flags)
{
    int count = 0, pad_len = 0, i;
    int len = strlen(str);
    char pad_char = ' ';

    if (flags.zero && !flags.minus)
        pad_char = '0';

    if (flags.width > len)
        pad_len = flags.width - len;

    if (!flags.minus)  /* right align (default) */
    {
        for (i = 0; i < pad_len; i++)
            count += buf_add(buffer, buf_index, pad_char);
        for (i = 0; i < len; i++)
            count += buf_add(buffer, buf_index, str[i]);
    }
    else  /* left align */
    {
        for (i = 0; i < len; i++)
            count += buf_add(buffer, buf_index, str[i]);
        for (i = 0; i < pad_len; i++)
            count += buf_add(buffer, buf_index, ' ');
    }

    return count;
}
