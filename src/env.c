/*
** EPITECH PROJECT, 2024
** env
** File description:
** env
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int my_env(env_t *enviro)
{
    if (enviro->name == NULL)
        return 0;
    while (enviro != NULL){
        mini_printf("%s=", enviro->name);
        if (enviro->value != NULL)
            mini_printf("%s\n", enviro->value);
        else
            my_putchar('\n');
        enviro = enviro->next;
    }
    return 0;
}
