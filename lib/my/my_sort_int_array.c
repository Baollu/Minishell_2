/*
** EPITECH PROJECT, 2024
** sort
** File description:
** array
*/

#include "include/my_lib.h"

void swap_time(int *array_temp, int nbr, int i, int size)
{
    int temp = 0;

    for (int j = 0; j < size; j++){
        if (j == i){
            array_temp[i] = nbr;
        }
        if (nbr < array_temp[j]){
            temp = array_temp[j];
            array_temp[j] = nbr;
            nbr = temp;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    int array_temp[size];

    for (int i = 0; i < size; i++){
        swap_time(array_temp, array[i], i, size);
    }
    for (int i = 0; i < size; i++){
        array[i] = array_temp[i];
    }
}
