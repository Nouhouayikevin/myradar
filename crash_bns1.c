/*
** EPITECH PROJECT, 2024
** the crash of bns
** File description:
** bns plane
*/

#include "my.h"

void bns_plane_in_domain1_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 1 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain2_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 2 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain3_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 3 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain4_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 4 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain5_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 5 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}
