/*
** EPITECH PROJECT, 2024
** find
** File description:
** path
*/

#include "my.h"
#include "my_lib.h"
#include "struct.h"
#include <stddef.h>
#include <stdio.h>

int line_path(char *name)
{
    char *str = "PATH=";

    if (my_strcmp(name, str) == 0){
        return 1;
    }
    return 0;
}

char **find_path(env_t *env)
{
    env_t *tmp = env;

    while (tmp != NULL){
        if (line_path(tmp->name) == 1) {
            return my_split_str(tmp->value, ":");
        }
        tmp = tmp->next;
    }
    return NULL;
}
