/*
** EPITECH PROJECT, 2024
** the parsing function
** File description:
** of my bonus
*/

#include "bonus.h"
static int error_letter_infront_bns(char **T)
{
    char c;
    int i = 0;

    while (T[i] != NULL) {
        c = T[i][0];
        if (c != 'A' && c != 'T' && c != 'a')
            return (84);
        i++;
    }
    return 0;
}

static int error_in_parse_bns(char **T)
{
    if (error_letter_infront_bns(T) == 84)
    if (error_charandspace(T) == 84)
        return 84;
}

static int get_plane_bonus_info(char **t, radar_t *rdr)
{
    int j = 0;
    char **T = NULL;

    for (int i = 0; t[i] != NULL; i++) {
        if (t[i][0] == 'a') {
            T = my_str_to_word_array(t[i], ' ');
            rdr->bns.plane.s_x = my_getnbr(T[1]);
            rdr->bns.plane.s_y = my_getnbr(T[2]);
            rdr->bns.plane.e_x = my_getnbr(T[3]);
            rdr->bns.plane.e_y = my_getnbr(T[4]);
            rdr->bns.plane.speed = my_getnbr(T[5]);
            rdr->bns.plane.t = my_getnbr(T[6]);
            get_plane_info2(&(rdr->bns.plane));
            free_tab(T);
            j++;
        }
        if (j == 2)
            return 84;
    }
    return (j == 0) ? 84 : 0;
}

int parse_bns(char *str, radar_t *rdr)
{
    char **T = read_line(str);

    if (error_in_parse_bns(T) == 84) {
    free_tab(T);
    return (84);
    }
    rdr->plane = malloc(sizeof(plane_t) * (number_plane(T)));
    rdr->tower = malloc(sizeof(tower_t) * (number_tower(T)));
    get_plane_info(T, rdr);
    get_tower_info(T, rdr);
    if (get_plane_bonus_info(T, rdr) == 84) {
        free_tab(T);
        return 84;
    }
    rdr->fps = 0;
    rdr->flying = 0;
    free_tab(T);
    rdr->bns.compiled = 1;
    return 0;
}