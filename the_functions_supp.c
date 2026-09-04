/*
** EPITECH PROJECT, 2024
** supplementary function
** File description:
** to be used
*/

#include "my.h"

int nbrlen(int nb)
{
    int i = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb /= 10;
        i++;
    }
    return i;
}

char *int_to_str(int nb)
{
    int i = nbrlen(nb);
    int j = 0;
    int k = pow(10, i);
    char *str = malloc(sizeof(char) * (i + 2));

    if (nb == 0)
        return my_strdump("0");
    while (j < i) {
        str[j] = (nb % 10) + '0';
        nb = nb / 10;
        j++;
    }
    str[i] = '\0';
    return str;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int k = 0;

    for (i = 0; dest[i] != '\0'; i++);
    for (k = 0; src[k] != '\0'; k++) {
        dest[i] = src[k];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void echange(char *s, char *p1)
{
    char c;

    c = *s;
    *s = *p1;
    *p1 = c;
}

char *reverse_string(char *str)
{
    char *j = str;
    char *p = str;
    int i = 0;
    int k = 0;

    while (*str != '\0') {
        str++;
        i++;
    }
    str--;
    while (k < (i / 2)) {
        echange(str, p);
        p++;
        str--;
        k++;
    }
    return j;
}
