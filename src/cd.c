/*
** EPITECH PROJECT, 2024
** cd
** File description:
** cd
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

void find_oldpwd(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++);
    chdir(array[i - 1]);
}

int cd_back(env_t **env)
{
    char **array = NULL;

    while (*env != NULL){
        if (my_strcmp((*env)->name, "OLDPWD") == 0){
            array = my_split_str((*env)->value, "/");
            find_oldpwd(array);
            return 0;
        }
        *env = (*env)->next;
    }
    return 1;
}

int good_file(shell_t *shell)
{
    int fd = open(shell->command[1], O_RDONLY);
    DIR *dir = opendir(shell->command[1]);

    if (fd == -1 && dir == NULL) {
        mini_printf("%s: No such file or directory.\n", shell->command[1]);
        closedir(dir);
        close(fd);
        return 1;
    }
    if (dir == NULL && fd != -1){
        mini_printf("%s: Not a directory.\n", shell->command[1]);
        closedir(dir);
        close(fd);
        return 1;
    }
    return 0;
}

int return_repo(env_t **env)
{
    while (*env != NULL){
        if (my_strcmp((*env)->name, "HOME") == 0){
            chdir((*env)->value);
            return 0;
        }
        if (my_strcmp((*env)->name, "PWD") == 0
            && (*env)->value == NULL) {
            chdir((*env)->value);
            return 0;
        }
        *env = (*env)->next;
    }
    return 1;
}

int my_cd(shell_t *shell, env_t **env)
{
    if (shell->command[2] != NULL){
        mini_printf("cd: Too many arguments.\n");
        return 1;
    }
    if (my_strcmp(shell->command[0], "cd") == 0
        || my_strcmp(shell->command[1], "~") == 0){
        if (shell->command[1] == NULL
            || my_strcmp(shell->command[1], "~") == 0){
            shell->status = return_repo(env);
            return shell->status;
        }
        if (my_strcmp(shell->command[1], "-") == 0){
            shell->status = cd_back(env);
            return shell->status;
        }
        if (good_file(shell) == 0)
            shell->status = chdir(shell->command[1]);
    }
    return shell->status;
}
