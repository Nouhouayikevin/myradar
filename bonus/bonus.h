/*
** EPITECH PROJECT, 2024
** the header file of my bonus
** File description:
** in the myradar
*/

#ifndef BONUS_H_
    #define BONUS_H_
    #include "../my.h"

void help_t(void);
void verif_bns_crash(radar_t *rdr);
void init_rect(plane_t *plane, sfVector2f p, sfVector2f s);
void draw_flying_planes(sfRenderWindow *window, radar_t *r, bttn_t *mn);
int help_bns(int ac, char **av);
void get_plane_info(char **t, radar_t *rdr);
void get_tower_info(char **t, radar_t *rdr);
int error_charandspace(char **T);
int parse_bns(char *str, radar_t *rdr);
#endif
