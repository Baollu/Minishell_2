/*
** EPITECH PROJECT, 2024
** redi
** File description:
** redi
*/

#include "my_lib.h"
#include "my.h"
#include "struct.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int execute_side(shell_t *shell, env_t *env, tree_t *tree)
{
    char *execute = NULL;
    char **array = my_split_str(tree->value, " ");
    char **env_array = env_to_array(env);

    for (int i = 0; shell->path[i] != NULL; i++){
        if (access(shell->path[i], X_OK) == 0){
            execute = concate_pipe(array[0], shell->path[i]);
        }
        execve(execute, array, env_array);
    }
    return 0;
}

int create_file(tree_t *tree)
{
    int fd = 0;

    tree->tree_right->value = clean_str(tree->tree_right->value, " ");
    fd = open(tree->tree_right->value, O_CREAT
    | O_WRONLY | O_TRUNC, 0644);
    return fd;
}

int great_than(tree_t *tree, env_t *env, shell_t *shell)
{
    int fd = create_file(tree);
    int save = dup(STDIN_FILENO);
    pid_t p = 0;
    int status = 0;

    p = fork();
    if (p == 0){
        dup2(fd, STDOUT_FILENO);
        close(fd);
        execute_side(shell, env, tree->tree_left);
    } else {
        dup2(save, STDOUT_FILENO);
        wait(&status);
    }
    return 0;
}
