/*
** EPITECH PROJECT, 2024
** on and off the night
** File description:
** enable day only, day and night, night only
*/

#include "my.h"
char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strdump(char *s)
{
    char *str = malloc(sizeof(char) * (my_strlen(s) + 1));

    return my_strcpy(str, s);
}

void destroy2(bttn_t *night, radar_t *rdr, bttn_t *mn)
{
    sfText_destroy(mn->text);
    sfFont_destroy(mn->font);
    sfText_destroy(mn->text1);
    sfFont_destroy(mn->font1);
    sfTexture_destroy(mn->T);
    sfSprite_destroy(mn->key);
    sfTexture_destroy(night->T);
    sfSprite_destroy(night->key);
}
