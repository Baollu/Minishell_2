/*
** EPITECH PROJECT, 2024
** find
** File description:
** func
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int func_env(shell_t *shell, env_t *environement)
{
    if (my_strcmp(shell->line, "setenv") == 0){
        shell->status = my_setenv(shell, &environement);
        return shell->status;
    }
    if (my_strcmp(shell->line, "env") == 0){
        my_env(environement);
        return 0;
    }
    return -1;
}

int find_function(shell_t *shell, env_t *environement)
{
    if (func_env(shell, environement) == 0)
        return 0;
    if (my_strcmp(shell->line, "exit") == 0){
        shell->status = my_exit(shell->status);
        return shell->status;
    }
    if (my_strcmp(shell->line, "cd") == 0){
        shell->status = my_cd(shell, &environement);
        return shell->status;
    }
    return -1;
}
