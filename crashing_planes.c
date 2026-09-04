/*
** EPITECH PROJECT, 2024
** verify collisions
** File description:
** of the planes
*/

#include "my.h"

void plane_in_domain16_with_others(int i, radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_plane; j++) {
        if (i != j && rdr->plane[j].domain == 16 && rdr->plane[j].arrival == 0
        && rdr->plane[j].id_bool == 1 && rdr->plane[j].crash == 0 &&
        rdr->plane[i].crash == 0 &&
        intersects(&(rdr->plane[i]), &(rdr->plane[j])) == sfTrue) {
                rdr->plane[i].crash = 1;
                rdr->plane[j].crash = 1;
            }
    }
}

void crash_with_domain1(int i, radar_t *rdr)
{
    if (rdr->plane[i].domain == 1)
        plane_in_domain1_with_others(i, rdr);
    if (rdr->plane[i].domain == 2)
        plane_in_domain2_with_others(i, rdr);
    if (rdr->plane[i].domain == 3)
        plane_in_domain3_with_others(i, rdr);
    if (rdr->plane[i].domain == 4)
        plane_in_domain4_with_others(i, rdr);
    if (rdr->plane[i].domain == 5)
        plane_in_domain5_with_others(i, rdr);
}

void crash_with_domain2(int i, radar_t *rdr)
{
    if (rdr->plane[i].domain == 6)
        plane_in_domain6_with_others(i, rdr);
    if (rdr->plane[i].domain == 7)
        plane_in_domain7_with_others(i, rdr);
    if (rdr->plane[i].domain == 8)
        plane_in_domain8_with_others(i, rdr);
    if (rdr->plane[i].domain == 9)
        plane_in_domain9_with_others(i, rdr);
    if (rdr->plane[i].domain == 10)
        plane_in_domain10_with_others(i, rdr);
}

void crash_with_domain3(int i, radar_t *rdr)
{
    if (rdr->plane[i].domain == 11)
        plane_in_domain11_with_others(i, rdr);
    if (rdr->plane[i].domain == 12)
        plane_in_domain12_with_others(i, rdr);
    if (rdr->plane[i].domain == 13)
        plane_in_domain13_with_others(i, rdr);
    if (rdr->plane[i].domain == 14)
        plane_in_domain14_with_others(i, rdr);
    if (rdr->plane[i].domain == 15)
        plane_in_domain15_with_others(i, rdr);
    if (rdr->plane[i].domain == 16)
        plane_in_domain16_with_others(i, rdr);
}

void verif_crash_plane(radar_t *rdr)
{
    for (int i = 0; i < rdr->nb_plane; i++) {
        if (i == rdr->nb_plane)
            return;
        if (rdr->plane[i].domain >= 1 && rdr->plane[i].domain <= 5)
            crash_with_domain1(i, rdr);
        if (rdr->plane[i].domain >= 6 && rdr->plane[i].domain <= 10)
            crash_with_domain2(i, rdr);
        if (rdr->plane[i].domain >= 11 && rdr->plane[i].domain <= 16)
            crash_with_domain3(i, rdr);
    }
}
