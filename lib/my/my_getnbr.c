/*
** EPITECH PROJECT, 2024
** get
** File description:
** nbr
*/

#include "include/my_lib.h"

int is_neg(char const *str, int i)
{
    int neg = 0;

    if (str[i] >= '0' && str[i] <= '9'){
        if (str[i - 1] == '-'){
            neg = -1;
        } else {
            neg = 1;
        }
    }
    return neg;
}

int nbr_in_str(char const *str, int i, int nbr)
{
    int neg = is_neg(str, i);
    int j = 0;

    for (; str[i] >= '0' && str[i] <= '9'; i++){
        nbr = (nbr * 10) + (str[i] - 48) * neg;
        j++;
    }
    if (j > 10)
        return 0;
    return nbr;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] >= '0' && str[i] <= '9'){
            nbr = nbr_in_str(str, i, nbr);
            return nbr;
        }
    }
    return 0;
}
