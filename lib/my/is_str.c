/*
** EPITECH PROJECT, 2024
** isstr
** File description:
** istr
*/

#include "include/my_lib.h"

int is_str(char c, char *sep)
{
    int i = 0;

    for (; sep[i] != '\0'; i++){
        if (sep[i] == c){
            return 1;
        }
    }
    return 0;
}
