/*
** EPITECH PROJECT, 2024
** crash functions
** File description:
** the first part
*/

#include "my.h"

void plane_in_domain1_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 1 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain2_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 2 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain3_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 3 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain4_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 4 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void plane_in_domain10_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 10 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}
