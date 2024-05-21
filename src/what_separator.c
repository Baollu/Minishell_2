/*
** EPITECH PROJECT, 2024
** what
** File description:
** separator
*/

#include "my_lib.h"
#include "my.h"
#include "struct.h"

shell_t *replace_space(shell_t *shell, int i)
{
    shell->line[i - 1] = '*';
    shell->line[i + 1] = '*';
    return shell;
}

int is_simple_separator(shell_t *shell, int i)
{
    if (shell->line[i - 1] == ' ' && shell->line[i + 1] == ' ')
        return 1;
    return 0;
}

shell_t *multi_redirect(shell_t *shell, int i)
{
    if (shell->line[i - 1] == ' ' && shell->line[i + 1] != ' ')
        shell->line[i - 1] = '*';
    if (shell->line[i - 1] != ' ' && shell->line[i + 1] == ' ')
        shell->line[i + 1] = '*';
    return shell;
}

shell_t *what_separator(shell_t *shell, int i)
{
    if (shell->line[i] == '>'){
        if (is_simple_separator(shell, i) == 1)
            shell = replace_space(shell, i);
        if (is_simple_separator(shell, i) == 0)
            shell = multi_redirect(shell, i);
    }
    if (shell->line[i] == '<'){
        if (is_simple_separator(shell, i) == 1)
            shell = replace_space(shell, i);
        if (is_simple_separator(shell, i) == 0)
            shell = multi_redirect(shell, i);
    }
    if (shell->line[i] == '|')
        shell = replace_space(shell, i);
    return shell;
}
