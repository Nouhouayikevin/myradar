/*
** EPITECH PROJECT, 2024
** 3rd functions of crash
** File description:
** of crashings planes
*/

#include "my.h"

void plane_in_domain11_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 11 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain12_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 12 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain13_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 13 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain14_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 14 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain15_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 15 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}
