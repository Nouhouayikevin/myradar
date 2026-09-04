/*
** EPITECH PROJECT, 2024
** the crash with the bns plane
** File description:
** the minimals functions
*/

#include "my.h"

static void bns_crash_with_domain1(radar_t *rdr)
{
    if (rdr->bns.plane.domain == 1)
        bns_plane_in_domain1_with_others(rdr);
    if (rdr->bns.plane.domain == 2)
        bns_plane_in_domain2_with_others(rdr);
    if (rdr->bns.plane.domain == 3)
        bns_plane_in_domain3_with_others(rdr);
    if (rdr->bns.plane.domain == 4)
        bns_plane_in_domain4_with_others(rdr);
    if (rdr->bns.plane.domain == 5)
        bns_plane_in_domain5_with_others(rdr);
}

static void bns_crash_with_domain2(radar_t *rdr)
{
    if (rdr->bns.plane.domain == 6)
        bns_plane_in_domain6_with_others(rdr);
    if (rdr->bns.plane.domain == 7)
        bns_plane_in_domain7_with_others(rdr);
    if (rdr->bns.plane.domain == 8)
        bns_plane_in_domain8_with_others(rdr);
    if (rdr->bns.plane.domain == 9)
        bns_plane_in_domain9_with_others(rdr);
    if (rdr->bns.plane.domain == 10)
        bns_plane_in_domain10_with_others(rdr);
}

void bns_plane_in_domain11_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 11 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain12_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 12 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain13_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 13 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void bns_plane_in_domain14_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 14 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

static void bns_plane_in_domain15_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 15 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

static void bns_plane_in_domain16_with_others(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (rdr->plane[j].domain == 16 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        intersects(&(rdr->bns.plane), &(rdr->plane[j])) == sfTrue) {
                rdr->bns.plane.crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

static void bns_crash_with_domain3(radar_t *rdr)
{
    if (rdr->bns.plane.domain == 11)
        bns_plane_in_domain11_with_others(rdr);
    if (rdr->bns.plane.domain == 12)
        bns_plane_in_domain12_with_others(rdr);
    if (rdr->bns.plane.domain == 13)
        bns_plane_in_domain13_with_others(rdr);
    if (rdr->bns.plane.domain == 14)
        bns_plane_in_domain14_with_others(rdr);
    if (rdr->bns.plane.domain == 15)
        bns_plane_in_domain15_with_others(rdr);
    if (rdr->bns.plane.domain == 16)
        bns_plane_in_domain16_with_others(rdr);
}

void verif_bns_crash(radar_t *rdr)
{
    if (rdr->bns.plane.domain >= 1 && rdr->bns.plane.domain <= 5) {
        bns_crash_with_domain1(rdr);
        return;
    }
    if (rdr->bns.plane.domain >= 6 && rdr->bns.plane.domain <= 10) {
        bns_crash_with_domain2(rdr);
        return;
    }
    if (rdr->bns.plane.domain >= 11 && rdr->bns.plane.domain <= 16) {
        bns_crash_with_domain3(rdr);
        return;
    }
}
