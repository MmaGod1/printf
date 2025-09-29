#include "main.h"

/**
 * buf_number_flags - Formats and buffers a signed integer with flags.
 *
 * Supports:
 *   - '+' flag: forces a '+' sign before positive numbers.
 *   - ' ' flag: prefixes a space before positive numbers if '+' not set.
 *   - field width: pads output with spaces or zeros.
 *   - '-' flag: left-aligns the output within the field width.
 *   - '0' flag: pads with zeros instead of spaces (ignored if '-' is set).
 */
int buf_number_flags(long num, char *buffer, int *buf_index, format_flags flags)
{
    char temp[64];
    int len, count = 0, pad, i, t_index = 0;
    char pad_char = ' ';

    if (num >= 0)
    {
        if (flags.plus)
            temp[t_index++] = '+';
        else if (flags.space)
            temp[t_index++] = ' ';
    }

    sprintf(temp + t_index, "%ld", num);
    len = strlen(temp);

    pad = (flags.width > len) ? flags.width - len : 0;
    if (flags.zero && !flags.minus)
        pad_char = '0';

    if (!flags.minus)
        for (i = 0; i < pad; i++)
            count += buf_add(buffer, buf_index, pad_char);

    for (i = 0; i < len; i++)
        count += buf_add(buffer, buf_index, temp[i]);

    if (flags.minus)
        for (i = 0; i < pad; i++)
            count += buf_add(buffer, buf_index, ' ');

    return (count);
}
