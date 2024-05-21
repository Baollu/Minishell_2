/*
** EPITECH PROJECT, 2024
** unset
** File description:
** env
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int several_unsetenv(shell_t *shell, env_t *list)
{
    int i = 0;

    while (shell->command[i] != NULL){
        if ((my_strcmp(list->name, shell->command[i]) == 0)
            || my_strcmp(list->value, shell->command[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

int my_unsetenv(shell_t *shell, env_t **env)
{
    env_t *list = *env;
    env_t *tmp = (*env)->next;

    if (shell->command[1] == NULL){
        mini_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    while (list != NULL){
        if (several_unsetenv(shell, list->next) == 1){
            tmp = list->next->next;
            free(list->next->name);
            free(list->next->value);
            list->next = tmp;
            return 0;
        } else {
            list = list->next;
        }
    }
    return -1;
}
