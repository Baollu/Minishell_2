/*
** EPITECH PROJECT, 2024
** execcute
** File description:
** execute
*/

#include "my_lib.h"
#include "my.h"
#include "struct.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int print_execute(shell_t *shell, char *path)
{
    char **array = my_split_str(shell->line, " ;");
    char *execute = NULL;
    pid_t p = fork();
    int status = 0;

    if (p == -1)
        write(2, "ForkFail", 8);
    if (p == 0){
        for (int i = 0; array[i] != NULL; i++){
            execute = my_strcat_alloc(path, "/");
            execute = my_strcat_alloc(execute, array[i]);
            execve(execute, array, shell->path);
            exit(status);
        }
    }
    if (p > 0)
        waitpid(p, &status, 0);
    return shell->status;
}

int have_access(char *path, shell_t *shell)
{
    if (access(path, X_OK) == 0)
        shell->status = print_execute(shell, path);
    return shell->status;
}

int execute_path(shell_t *shell)
{
    int i = 0;

    for (i = 0; shell->path[i] != NULL; i++)
        shell->status = have_access(shell->path[i], shell);
    return shell->status;
}
