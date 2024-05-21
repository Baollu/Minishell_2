/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

int minishell(shell_t *shell, env_t *environement)
{
    while (1){
        if (isatty(STDIN_FILENO))
            mini_printf("$> ");
        shell->status = take_command(shell);
        if (shell->status == -1)
            return 0;
        shell->command = my_split_str(shell->line, " ");
        shell->status = find_semicolon(shell, environement);
        shell->status = is_separator(shell, environement);
        shell->status = find_function(shell, environement);
        if (shell->status == -1)
            shell->status = execute_path(shell);
    }
    return shell->status;
}
