/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** mini_printf
*/

#include "include/my_lib.h"
#include <stdarg.h>

int mini_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, *format);
    for (int i = 0; i != my_strlen(format); i++){
        if (format[i] != '%'){
            my_putchar(format[i]);
            continue;
        }
        i++;
        if (format[i] == 'c')
            my_putchar(va_arg(ap, int));
        if (format[i] == 'd' || format[i] == 'i')
            my_put_nbr(va_arg(ap, int));
        if (format[i] == 's')
            my_putstr(va_arg(ap, char *));
        if (format[i] == '%')
            my_putchar('%');
    }
    return 0;
}
