/*
** EPITECH PROJECT, 2024
** less
** File description:
** than
*/

#include "my_lib.h"
#include "my.h"
#include "struct.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int less_than(tree_t *tree, env_t *env, shell_t *shell)
{
    int fd = open(tree->tree_right->value, O_RDONLY);
    pid_t p = 0;
    int status = 0;

    p = fork();
    if (p == 0){
        dup2(fd, STDIN_FILENO);
        close(fd);
        if (my_strcmp(tree->tree_left->value, "ls") == 0){
            execute_side(shell, env, tree->tree_left);
        } else {
            execute_path(shell);
        }
    } else {
        close(fd);
        wait(&status);
    }
    return 0;
}
