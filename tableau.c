/*
** EPITECH PROJECT, 2024
** tableaux
** File description:
** fonctions pour les chaines de caracteres
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    int k;
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    k = s1[i] - s2[i];
    return k;
}

char **create_tab_char(int i, int j)
{
    char **t = NULL;
    int k = 0;

    t = malloc((j + 1) * sizeof(char *));
    for (k = 0; k < j; k++) {
        t[k] = malloc((i + 1) * sizeof(char));
    }
    return t;
}

void free_tab(char **t)
{
    int k = 0;

    for (k = 0; t[k] != NULL; k++) {
        free(t[k]);
    }
    free(t);
}

char **read_line(char *filepath)
{
    char **L = NULL;
    char *tab = NULL;
    struct stat t;
    int fd = open(filepath, O_RDONLY);

    stat(filepath, &t);
    tab = malloc(sizeof(char) * (t.st_size + 1));
    read(fd, tab, t.st_size);
    tab[t.st_size] = '\0';
    close(fd);
    L = my_str_to_word_array(tab, '\n');
    free(tab);
    return L;
}
