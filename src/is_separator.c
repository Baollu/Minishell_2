/*
** EPITECH PROJECT, 2024
** separator
** File description:
** separator
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_lib.h"
#include "my.h"
#include "struct.h"

tree_t *create_node(char *str)
{
    tree_t *node = malloc(sizeof(tree_t));

    node->value = my_strdup(str);
    node->tree_right = NULL;
    node->tree_left = NULL;
    return node;
}

tree_t *join_tree(tree_t *node, tree_t *tree)
{
    if (tree == NULL) {
        tree = node;
        return tree;
    }
    if (my_strcmp(node->value, ">") == 0
        || my_strcmp(node->value, "<") == 0
        || my_strcmp(node->value, "|") == 0){
        node->tree_right = tree;
        return node;
    } else {
        tree->tree_left = node;
        return tree;
    }
    return tree;
}

void find_separator(tree_t *tree, env_t *env, shell_t *shell)
{
    if (my_strcmp(tree->value, "|") == 0)
        my_pipe(tree, env, shell);
    if (my_strcmp(tree->value, ">") == 0)
        great_than(tree, env, shell);
    if (my_strcmp(tree->value, "<") == 0)
        less_than(tree, env, shell);
}

void display_tree(tree_t *tree, env_t *env, shell_t *shell, char **array)
{
    if (tree == NULL)
        return;
    if (tree->tree_left != NULL)
        display_tree(tree->tree_left, env, shell, array);
    find_separator(tree, env, shell);
    if (tree->tree_right != NULL){
        display_tree(tree->tree_right, env, shell, array);
    }
}

int is_separator(shell_t *shell, env_t *env)
{
    char **array = NULL;
    int i = 0;
    tree_t *tree = NULL;

    for (int i = 0; shell->line[i] != '\0'; i++)
        shell = what_separator(shell, i);
    array = my_split_str(shell->line, "*");
    for (i = 0; array[i] != NULL; i++);
    tree = create_node(array[i - 1]);
    for (int j = i - 2; j != -1; j--){
        tree = join_tree(create_node(array[j]), tree);
    }
    display_tree(tree, env, shell, array);
    return 0;
}
