/*
** EPITECH PROJECT, 2024
** split
** File description:
** split
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my_lib.h"

int len_str(char const *str, char *sep)
{
    int len;

    for (len = 0; str[len] != '\0' && is_str(str[len], sep) == 0; len++);
    return len;
}

char *cut_str(char const *str, int *counter, char *c)
{
    int len = len_str(str, c);
    char *word = malloc(sizeof(char) * (len + 1));
    int i;

    for (i = 0; is_str(str[i], c) == 0 && str[i] != '\0'; i++)
        word[i] = str[i];
    word[i] = '\0';
    *counter += i - 1;
    return word;
}

char **my_split_str(char const *str, char *sep)
{
    int nbr_word = nbr_str(str, sep);
    char **array = NULL;
    int i = 0;
    int j = 0;

    if (str == NULL)
        return NULL;
    array = malloc(sizeof(char *) * (nbr_word + 1));
    for (i = 0; str[i] != '\0'; i++){
        if (is_str(str[i], sep) == 0){
            array[j] = cut_str(str + i, &i, sep);
            j++;
        }
    }
    array[nbr_word] = NULL;
    return array;
}
