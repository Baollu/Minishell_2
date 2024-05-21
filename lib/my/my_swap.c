/*
** EPITECH PROJECT, 2024
** swap
** File description:
** swap
*/

#include "include/my_lib.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
