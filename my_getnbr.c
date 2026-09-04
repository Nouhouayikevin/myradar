/*
** EPITECH PROJECT, 2024
** mygetnbr
** File description:
** find the number
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_getnbr(char *s)
{
    int j = 1;
    int n = 0;
    int i = 0;

    for (; s[i] != '\0' && s[i] != ' '; i++) {
        if (s[i] == '-') {
            j *= -1;
            i++;
        }
        if (s[i] == '+') {
            j = j;
            i++;
        }
        if (s[i] >= 48 && s[i] <= 57) {
            n = (n * 10) + s[i] - '0';
        }
    }
    return n * j;
}

void my_putnbr(int nbr)
{
    if (nbr < 0) {
        write(1, "-", 1);
        my_putnbr(-nbr);
    }
    if (nbr < 10 && nbr >= 0) {
        my_putchar(nbr + '0');
    }
    if (nbr >= 10) {
        my_putnbr(nbr / 10);
        my_putchar((nbr % 10) + '0');
    }
}
