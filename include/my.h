/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include "struct.h"

#ifndef LIB
    #define LIB

void push_to_list(env_t **environment, char *env);
shell_t *init_struct(void);
env_t *set_linked_lists(char **env);
char **find_path(env_t *env);
int line_path(char *env);
int print_execute(shell_t *shell, char *path);
int have_access(char *path, shell_t *shell);
int execute_path(shell_t *shell);
char *my_value(char const *src, char sep);
char *my_strndup(char const *src, char sep);
int take_command(shell_t *shell);
int minishell(shell_t *shell, env_t *environement);
int my_args_len(char **args);
int add_env(env_t **environement, env_t *env);
void modif_func(char **command, env_t **list);
int my_setenv(shell_t *shell, env_t **env);
int my_env(env_t *enviro);
int find_function(shell_t *shell, env_t *environement);
void free_struct(shell_t *shell);
int my_exit(int status);
int cd_back(env_t **env);
int my_cd(shell_t *shell, env_t **env);
int check_value(char *str);
int check_first_letter(char c);
int func_env(shell_t *shell, env_t *environement);
int is_separator(shell_t *shell, env_t *env);
void display_tree(tree_t *tree, env_t *env, shell_t *shell, char **array);
tree_t *join_tree(tree_t *node, tree_t *tree);
tree_t *create_node(char *str);
int my_pipe(tree_t *tree, env_t *env, shell_t *shell);
char *concate_pipe(char *str, char *path);
char **env_to_array(env_t *env);
int nbr_str_env(env_t *env);
int read_pipe(tree_t *tree, char **env_array, shell_t *shell);
int write_pipe(tree_t *tree, char **env_array, shell_t *shell);
shell_t *replace_space(shell_t *shell, int i);
int is_simple_separator(shell_t *shell, int i);
shell_t *multi_redirect(shell_t *shell, int i);
shell_t *what_separator(shell_t *shell, int i);
int less_than(tree_t *tree, env_t *env, shell_t *shell);
char *clean_str(char *str, char *delimi);
int check_delimi(char c, char *delimi);
int semicolon(shell_t *shell, env_t *env);
int find_semicolon(shell_t *shell, env_t *env);
int great_than(tree_t *tree, env_t *env, shell_t *shell);
int execute_side(shell_t *shell, env_t *env, tree_t *tree);

#endif
