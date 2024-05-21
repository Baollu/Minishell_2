/*
** EPITECH PROJECT, 2024
** read
** File description:
** write
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int write_pipe(tree_t *tree, char **env_array, shell_t *shell)
{
    char *execute = NULL;
    char **array = my_split_str(tree->value, " ");

    for (int i = 0; shell->path[i] != NULL; i++){
        if (access(shell->path[i], X_OK) == 0){
            execute = concate_pipe(array[0], shell->path[i]);
        }
        execve(execute, array, env_array);
    }
    return 0;
}

int read_pipe(tree_t *tree, char **env_array, shell_t *shell)
{
    char *execute = NULL;
    char **array = my_split_str(tree->value, " ");
    int p = fork();
    int status = 0;

    for (int i = 0; shell->path[i] != NULL; i++){
        if (access(shell->path[i], X_OK) == 0){
            execute = concate_pipe(array[0], shell->path[i]);
        }
        if (p == 0)
            execve(execute, array, env_array);
        else
            wait(&status);
    }
    return 0;
}
