/*
** EPITECH PROJECT, 2024
** the crash of bns plane
** File description:
** with orthers
*/


#include "my.h"
void bns_plane_in_domain6_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 6 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain7_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 7 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain8_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 8 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain9_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 9 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain10_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 10 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}
