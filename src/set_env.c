/*
** EPITECH PROJECT, 2024
** set_env
** File description:
** set_env
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int my_args_len(char **args)
{
    int i = 0;

    while (args[i] != NULL){
        i++;
    }
    return i;
}

int add_env(env_t **environement, env_t *env)
{
    env_t *list = malloc(sizeof(env_t));
    env_t *tmp = *environement;

    list->name = env->name;
    if (env->value != NULL)
        list->value = env->value;
    else
        list->value = NULL;
    list->next = NULL;
    if ((*environement) == NULL) {
        (*environement) = list;
        return 0;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = list;
    return 0;
}

int modif_env(char **command, env_t **list)
{
    env_t *environement = *list;
    env_t *env = malloc(sizeof(env_t));

    if (check_value(command[1]) == 1)
        return -1;
    env->name = my_strdup(command[1]);
    if (my_args_len(command) == 3){
        if (check_value(command[2]) == 1)
            return -1;
        env->value = my_strdup(command[2]);
    }
    while (environement != NULL){
        if (my_strcmp((environement)->name, command[1]) == 0){
            (environement)->value = env->value;
            return 0;
        }
        (environement) = (environement)->next;
    }
    add_env(&(*list), env);
    return 0;
}

int my_setenv(shell_t *shell, env_t **env)
{
    if (my_args_len(shell->command) > 3){
        mini_printf("setenv: Too many arguments.\n");
        return 1;
    }
    if (my_args_len(shell->command) == 1){
        my_env(*env);
        return 0;
    }
    if (modif_env(shell->command, env) == 1){
            return 1;
        }
    return 0;
}
