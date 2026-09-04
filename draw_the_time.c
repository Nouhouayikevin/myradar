/*
** EPITECH PROJECT, 2024
** the draw of the timer
** File description:
** of the plane
*/

#include "my.h"

void draw_time(sfRenderWindow *window, bttn_t *mn)
{
    char *s = time_to_str(mn);

    sfText_setString(mn->text, s);
    sfText_setPosition(mn->text, (sfVector2f) {0, 0});
    sfRenderWindow_drawText(window, mn->text, NULL);
    free(s);
}

void draw_flying_planes(sfRenderWindow *window, radar_t *r, bttn_t *mn)
{
    char *s = the_print_fly_plane(r);

    draw_crashing_planes(window, r);
    sfText_setString(mn->text1, s);
    sfText_setPosition(mn->text1, (sfVector2f){10, 860});
    sfRenderWindow_drawText(window, mn->text1, NULL);
    free(s);
}

void draw_crashing_planes(sfRenderWindow *window, radar_t *r)
{
    char *s = malloc(sizeof(char) * 40);
    char *str = reverse_string(int_to_str(r->crash));

    s[0] = '\0';
    my_strcat(s, "Crashed planes:");
    my_strcat(s, str);
    sfText_setString(r->text, s);
    sfText_setCharacterSize(r->text, 40);
    sfText_setPosition(r->text, (sfVector2f){1490, 900});
    sfRenderWindow_drawText(window, r->text, NULL);
    free(s);
    free(str);
}

char *time_to_str(bttn_t *mn)
{
    char *str = malloc(sizeof(char) * 6);
    char *s = NULL;
    sfTime t = sfClock_getElapsedTime(mn->c);
    int sec = (int)sfTime_asSeconds(t);
    int minutes = sec / 60;
    int seconds = sec % 60;

    str[0] = '\0';
    if (minutes < 10)
        str = my_strcat(str, "0");
    s = int_to_str(minutes);
    str = my_strcat(str, reverse_string(s));
    str = my_strcat(str, ":");
    free(s);
    if (seconds < 10)
        str = my_strcat(str, "0");
    s = int_to_str(seconds);
    str = my_strcat(str, reverse_string(s));
    free(s);
    return (str);
}
