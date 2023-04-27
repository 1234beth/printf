#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;
    char c;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // move past '%'
            switch (*format) {
                case 'c':
                    c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++; // move to next character in format string
    }

    va_end(args);
    return count;
}

