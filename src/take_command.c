/*
** EPITECH PROJECT, 2024
** take
** File description:
** command
*/

#include "my_lib.h"
#include "my.h"
#include <stdio.h>
#include "struct.h"
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int take_command(shell_t *shell)
{
    size_t size = 0;
    int x = 0;

    x = getline(&shell->line, &size, stdin);
    if (x == -1)
        return -1;
    for (int i = 0; shell->line[i] != '\0'; i++){
        if (shell->line[x - 1] == '\n')
            shell->line[x - 1] = ' ';
            }
    return x;
}
