/*
** EPITECH PROJECT, 2024
** check
** File description:
** setenv
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int check_first_letter(char c)
{
    if ((c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || c == '_')
        return 0;
    return 1;
}

int check_value(char *str)
{
    int i = 0;

    if (check_first_letter(str[0]) == 1){
        mini_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (i = 1; str[i] != '\0'; i++){
        if ((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || str[i] == '_'
            || (str[i] >= '0' && str[i] <= '9'))
            continue;
        mini_printf("setenv: Variable name must contain"
                    " alphanumeric characters.\n");
        return 1;
    }
    return 0;
}
