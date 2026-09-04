/*
** EPITECH PROJECT, 2024
** second file for crash gestion
** File description:
** in the crashing planes
*/

#include "my.h"

void plane_in_domain5_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 5 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain6_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 6 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain7_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 7 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain8_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 8 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain9_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 9 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}
