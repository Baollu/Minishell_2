/*
** EPITECH PROJECT, 2024
** put
** File description:
** nbr
*/

#include "include/my_lib.h"

int my_put_nbr(int nb)
{
    int stored[10];
    int i = 0;

    if (nb < 0){
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb < 10){
        my_putchar(nb + 48);
        return (0);
    }
    while (nb > 0){
        stored[i] = nb % 10;
        nb = nb / 10;
        i++;
    }
    for (i = i; i > 0; i--){
        my_putchar(stored[i - 1] + 48);
    }
    return (0);
}
