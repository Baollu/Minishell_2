/*
** EPITECH PROJECT, 2024
** str
** File description:
** cat
*/

#include <stddef.h>
#include <stdlib.h>
#include "include/my_lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0'){
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat_alloc(char *dest, char const *src)
{
    size_t len_dest = my_strlen(dest);
    size_t len_src = my_strlen(src);
    size_t len_str = len_dest + len_src;
    char *str = malloc(sizeof(char) * (len_str + 1));
    size_t j = 0;

    if (dest != NULL)
        for (size_t i = 0; dest[i] != '\0'; i++){
            str[i] = dest[i];
            j++;
        }
    if (str != NULL)
        for (size_t i = 0; src[i] != '\0'; i++)
            str[i + j] = src[i];
    str[len_str] = '\0';
    return str;
}
