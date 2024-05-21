/*
** EPITECH PROJECT, 2024
** put
** File description:
** char
*/

#include "include/my_lib.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
