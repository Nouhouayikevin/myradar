/*
** EPITECH PROJECT, 2024
** les fonctions d'affichage
** File description:
** pour gerer l'affichage
*/

#include "my.h"
int my_strlen(char *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++);
    return i;
}

void my_put(char *s)
{
    write(1, s, my_strlen(s));
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        my_putchar(s[i]);
    }
}
