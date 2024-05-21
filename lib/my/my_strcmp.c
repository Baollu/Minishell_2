/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] > s2[i]){
            return -1;
        }
        if (s1[i] < s2[i])
            return 1;
        i++;
    }
    return 0;
}
