/*
** EPITECH PROJECT, 2024
** the flying planes
** File description:
** on the map
*/

#include "my.h"

void print_framerate(radar_t *rdr)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed;

    if (first == 1) {
    clock = sfClock_create();
    first = 0;
    }
        elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
    rdr->fps = fps + 1;
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}

char *the_print_fly_plane(radar_t *rdr)
{
    char *s = int_to_str(rdr->flying);
    char *str = malloc(sizeof(char) * 40);

    flying_planes(rdr);
    str[0] = '\0';
    str = my_strcat(str, "Flying planes:");
    str = my_strcat(str, reverse_string(s));
    if (my_strcmp(s, "0") != 0)
        free(s);
    str = my_strcat(str, "\nFPS:");
    s = int_to_str(rdr->fps);
    str = my_strcat(str, reverse_string(s));
    if (my_strcmp(s, "0") != 0)
        free(s);
    return str;
}

void flying_planes(radar_t *rdr)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < rdr->nb_plane; i++) {
        if (rdr->plane[i].arrival == 0 && rdr->plane[i].id_bool == 1 &&
        rdr->plane[i].crash == 0)
            j++;
    }
    rdr->flying = j;
    j = 0;
    for (i = 0; i < rdr->nb_plane; i++) {
        if (rdr->plane[i].crash == 1)
            j++;
    }
    rdr->crash = j;
    print_framerate(rdr);
}
