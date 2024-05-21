/*
** EPITECH PROJECT, 2024
** put
** File description:
** str
*/

#include "include/my_lib.h"

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
