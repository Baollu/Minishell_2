/*
** EPITECH PROJECT, 2024
** str
** File description:
** len
*/

#include "include/my_lib.h"
#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}
