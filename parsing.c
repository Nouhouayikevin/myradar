/*
** EPITECH PROJECT, 2024
** control the parsing of the radar
** File description:
** gesture of files
*/

#include "my.h"

int number_plane(char **t)
{
    int j = 0;
    int i = 0;

    for (; t[i] != NULL; i++) {
        if (t[i][0] == 'A')
            j++;
    }
    return j;
}

int number_tower(char **t)
{
    int j = 0;
    int i = 0;

    for (; t[i] != NULL; i++) {
        if (t[i][0] == 'T')
            j++;
    }
    return i;
}

void get_plane_info(char **t, radar_t *rdr)
{
    int i = 0;
    int j = 0;
    char **T = NULL;

    for (; t[i] != NULL; i++) {
        if (t[i][0] == 'A') {
            T = my_str_to_word_array(t[i], ' ');
            rdr->plane[j].s_x = my_getnbr(T[1]);
            rdr->plane[j].s_y = my_getnbr(T[2]);
            rdr->plane[j].e_x = my_getnbr(T[3]);
            rdr->plane[j].e_y = my_getnbr(T[4]);
            rdr->plane[j].speed = my_getnbr(T[5]);
            rdr->plane[j].t = my_getnbr(T[6]);
            get_plane_info2(&(rdr->plane[j]));
            free_tab(T);
            j++;
        }
    }
    rdr->nb_plane = j;
}

void get_tower_info(char **t, radar_t *rdr)
{
    int i = 0;
    int j = 0;
    char **T = NULL;

    for (; t[i] != NULL; i++) {
        if (t[i][0] == 'T') {
            T = my_str_to_word_array(t[i], ' ');
            rdr->tower[j].pos_x = my_getnbr(T[1]);
            rdr->tower[j].pos_y = my_getnbr(T[2]);
            rdr->tower[j].r = my_getnbr(T[3]);
            rdr->tower[j].id_bool = 1;
            free_tab(T);
            j++;
        }
    }
    rdr->nb_tower = j;
}

int parse(char *str, radar_t *rdr)
{
    char **T = read_line(str);

    if (error_in_parse(T) == 84) {
    free_tab(T);
    return (84);
    }
    rdr->plane = malloc(sizeof(plane_t) * (number_plane(T)));
    rdr->tower = malloc(sizeof(tower_t) * (number_tower(T)));
    get_plane_info(T, rdr);
    get_tower_info(T, rdr);
    rdr->fps = 0;
    rdr->flying = 0;
    free_tab(T);
}
