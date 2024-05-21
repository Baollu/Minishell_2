/*
** EPITECH PROJECT, 2024
** semicon
** File description:
** semicon
*/

#include <unistd.h>
#include <stddef.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"
#include <sys/wait.h>

int no_separator(shell_t *shell)
{
    for (int i = 0; shell->line[i] != '\0'; i++){
        if (shell->line[i] == '|'
            || shell->line[i] == '>'
            || shell->line[i] == '<')
            return 1;
    }
    execute_path(shell);
    return 0;
}

int semicolon(shell_t *shell, env_t *env)
{
    char **array = my_split_str(shell->line, ";");

    for (int i = 0; array[i] != NULL; i++){
        shell->line = array[i];
        shell->line = clean_str(shell->line, " ");
        if (no_separator(shell) == 0)
            return 0;
        shell->status = is_separator(shell, env);
    }
    return 0;
}

int find_semicolon(shell_t *shell, env_t *env)
{
    for (int i = 0; shell->line[i] != '\0'; i++)
        if (shell->line[i] == ';'){
            semicolon(shell, env);
            return 0;
        }
    return -1;
}
