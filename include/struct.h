/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/

#ifndef STRUCT_T
    #define STRUCT_T
    #define WRITE 1
    #define READ 0

typedef struct shell_s {
    char **path;
    char *line;
    char **command;
    int status;
} shell_t;

typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
} env_t;

typedef struct tree_s {
    char *value;
    struct tree_s *tree_left;
    struct tree_s *tree_right;
} tree_t;

#endif
