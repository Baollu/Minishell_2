/*
** EPITECH PROJECT, 2024
** str
** File description:
** str
*/

#include "include/my_lib.h"
#include <stddef.h>

int nbr_str(char const *str, char *sep)
{
    int nbr_word = 0;
    int i = 0;

    if (str == NULL)
        return 0;
    for (i = 1; str[i] != '\0'; i++){
        if (is_str(str[i - 1], sep) == 0 && is_str(str[i], sep) == 1)
            nbr_word ++;
    }
    if (is_str(str[i - 1], sep) == 0)
        nbr_word ++;
    return nbr_word;
}
