/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "my.h"
#include "my_lib.h"

shell_t *init_struct(void)
{
    shell_t *init = malloc(sizeof(shell_t));

    init->path = NULL;
    init->command = NULL;
    init->line = NULL;
    init->status = 0;
    return init;
}

int main(int, char **, char **env)
{
    shell_t *init = init_struct();
    env_t *environement = set_linked_lists(env);

    init->path = find_path(environement);
    return minishell(init, environement);
}
