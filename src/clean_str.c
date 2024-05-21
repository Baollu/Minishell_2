/*
** EPITECH PROJECT, 2024
** clean
** File description:
** str
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int check_delimi(char c, char *delimi)
{
    for (int i = 0; delimi[i] != '\0'; i++){
        if (c == delimi[i])
            return 1;
    }
    return 0;
}

char *clean_str(char *str, char *delimi)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *new_str = NULL;

    for (i = 0; check_delimi(str[i], delimi) == 1; i++);
    for (j = 0; str[j] != '\0'; j++);
    for (; check_delimi(str[j], delimi) == 1; j--);
    new_str = malloc(sizeof(char) * (j - i) + 1);
    while (i != j - 1){
        new_str[k] = str[i];
        k++;
        i++;
    }
    new_str[k] = '\0';
    return new_str;
}
