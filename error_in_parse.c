/*
** EPITECH PROJECT, 2024
** the error in the file
** File description:
** the script for the parsing
*/

#include "my.h"

int char_isnum(char *str)
{
    int i = 1;

    while (str[i] != '\0') {
        if (!((str[i] >= 48 && str[i] <= 57) || str[i] == '.'
        || str[i] == ' ')) {
            my_put("Error in file!");
            return (84);
        }
        i++;
    }
    return 0;
}

int error_letter_infront(char **T)
{
    char c;
    int i = 0;

    while (T[i] != NULL) {
        c = T[i][0];
        if (c != 'A' && c != 'T')
            return (84);
        i++;
    }
    return 0;
}

int space_number_verif(char *str)
{
    int k = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            k++;
    }
    if (str[0] == 'A') {
        if (k != 10) {
            my_put("Error in File!\n");
            return (84);
        }
    }
    if (str[0] == 'T') {
        if (k != 5) {
            my_put("Error in File!\n");
            return (84);
        }
    }
    return k;
}

int error_charandspace(char **T)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; T[i] != NULL; i++) {
        if (char_isnum(T[i]) == 84)
            return 84;
    }
    return 0;
}

int error_in_parse(char **T)
{
    if (error_letter_infront(T) == 84)
    if (error_charandspace(T) == 84)
        return 84;
}
