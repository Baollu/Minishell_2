/*
** EPITECH PROJECT, 2024
** pipe
** File description:
** pipe
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int nbr_str_env(env_t *env)
{
    int len = 0;

    while (env != NULL){
        len++;
        env = env->next;
    }
    return len;
}

char **env_to_array(env_t *env)
{
    char **env_array = malloc(sizeof(char *) * (nbr_str_env(env) + 1));
    int i = 0;

    while (env != NULL){
        env_array[i] = my_strcat_alloc(env->name, "=");
        env_array[i] = my_strcat_alloc(env_array[i], env->value);
        i++;
        env = env->next;
    }
    env_array[i] = NULL;
    return env_array;
}

char *concate_pipe(char *str, char *path)
{
    char *execute = NULL;

    execute = my_strcat_alloc(path, "/");
    execute = my_strcat_alloc(execute, str);
    return execute;
}

void close_dup(int closed, int duped, int std)
{
    close(closed);
    dup2(duped, std);
}

int my_pipe(tree_t *tree, env_t *env, shell_t *shell)
{
    int fd[2] = {0};
    char **env_array = env_to_array(env);
    int save = dup(STDIN_FILENO);
    int status = 0;
    pid_t p = 0;

    if (pipe(fd) == -1)
        return 84;
    p = fork();
    if (p == 0){
        close_dup(fd[READ], fd[WRITE], STDOUT_FILENO);
        write_pipe(tree->tree_left, env_array, shell);
    } else {
        close_dup(fd[WRITE], fd[READ], STDIN_FILENO);
        read_pipe(tree->tree_right, env_array, shell);
        close_dup(fd[READ], save, STDIN_FILENO);
        wait(&status);
    }
    return 0;
}
