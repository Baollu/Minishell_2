/*
** EPITECH PROJECT, 2024
** linked
** File description:
** list
*/

#include "my.h"
#include "my_lib.h"
#include "struct.h"
#include <stddef.h>
#include <stdlib.h>

char *my_value(char const *src, char sep)
{
    char *str = NULL;
    int j = 0;
    int i = 0;

    if (src == NULL)
        return NULL;
    while (src[j] != sep && src[j] != '\0')
        ++j;
    if (src[j] == '\0')
        return NULL;
    i = my_strlen(src) - (j + 1);
    str = malloc(sizeof(char) * (i + 1));
    j += 1;
    for (int k = 0; src[j] != '\0'; k++) {
        str[k] = src[j];
        j++;
    }
    str[i] = '\0';
    return str;
}

char *my_strndup(char const *src, char sep)
{
    char *str = NULL;
    int j = 0;

    if (src == NULL)
        return NULL;
    while (src[j] != sep && src[j] != '\0')
        j++;
    str = malloc(sizeof(char) * (j + 1));
    for (int i = 0; src[i] != sep && src[i] != '\0'; i++){
        str[i] = src[i];
    }
    str[j] = '\0';
    return str;
}

void push_to_list(env_t **environement, char *env)
{
    env_t *list = malloc(sizeof(env_t));
    env_t *tmp = *environement;

    if (env != NULL){
        list->name = my_strndup(env, '=');
        list->value = my_value(env, '=');
        list->next = NULL;
    }
    if ((*environement) == NULL) {
        (*environement) = list;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = list;
    return;
}

env_t *set_linked_lists(char **env)
{
    env_t *environement = NULL;

    for (int i = 0; env[i] != NULL; i++){
        push_to_list(&environement, env[i]);
    }
    return environement;
}
