/*
** EPITECH PROJECT, 2024
** str
** File description:
** toword
*/

#include "include/my_lib.h"
#include <stdlib.h>

int is_alpha_num(char c, char sep)
{
    if (c == sep)
        return 1;
    return 0;
}

int get_len(char const *str, int nbr, char sep)
{
    int i = 0;

    for (i = nbr; is_alpha_num(str[i], sep) == 0; i++);
    return i;
}

int get_nbr_word(char const *str, char c)
{
    int i = 0;
    int nbr_word = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == c && str[i + 1] != c){
            nbr_word++;
        }
    }
    if (i != 0 && str[i - 1] != c)
        nbr_word++;
    return nbr_word;
}

int skip_non_alphanum(char const *str, int z, char sep)
{
    int i = 0;

    for (i = z; is_alpha_num(str[i], sep) == 1; i++);
    return i;
}

char **my_str_to_word_array(char const *str, char sep)
{
    int i = 0;
    int j = 0;
    int z = 0;
    int len = 0;
    int nbr_word = get_nbr_word(str, sep);
    char **array = malloc(sizeof(char *) * (nbr_word + 1));

    for (i = 0; i != nbr_word; i++){
        len = get_len(str, len, sep);
        array[i] = malloc(sizeof(char) * len + 1);
        for (j = 0; is_alpha_num(str[z], sep) == 0; j++){
            array[i][j] = str[z];
            z++;
        }
        array[i][j] = '\0';
        z = skip_non_alphanum(str, z, sep);
    }
    array[i] = NULL;
    return array;
}
