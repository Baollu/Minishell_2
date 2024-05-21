/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** mylib
*/

#ifndef MY_LIB
    #define MY_LIB

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int nbr_in_str(char const *str, int i, int nbr);
int is_neg(char const *str, int i);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char **my_str_to_word_array(char const *str, char sep);
int get_nbr_word(char const *str, char c);
int get_len(char const *str, int nbr, char sep);
int is_alpha_num(char c, char sep);
int skip_non_alphanum(char const *str, int z, char sep);
void my_sort_int_array(int *tab, int size);
void swap_time(int *array, int nbr, int i, int size);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int mini_printf(const char *format, ...);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
int is_str(char c, char *sep);
int nbr_str(char const *str, char *sep);
int len_str(char const *str, char *c);
char *cut_str(char const *str, int *counter, char *c);
char **my_split_str(char const *str, char *sep);
char *my_strcat_alloc(char *dest, char const *src);

#endif
