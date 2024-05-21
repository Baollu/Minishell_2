/*
** EPITECH PROJECT, 2024
** is
** File description:
** negative
*/

#include "include/my_lib.h"

int my_isneg(int nb)
{
    if (nb >= 0){
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
