/*
** EPITECH PROJECT, 2024
** the travels
** File description:
** of the plane
*/

#include "my.h"

void end_travel(plane_t *plane)
{
    float dx = (plane->e_x - plane->s_x);
    float dy = (plane->e_y - plane->s_y);
    float d = sqrt(pow(dx, 2) + pow(dy, 2));

    if (d <= 15) {
        plane->arrival = 1;
    }
}

void travel_plane(plane_t *plane)
{
    float dx = (plane->e_x - plane->s_x);
    float dy = (plane->e_y - plane->s_y);
    float d = sqrt(pow(dx, 2) + pow(dy, 2));

    plane->s_x += ceil(((dx / d)) * plane->speed);
    plane->s_y += ceil(((dy / d)) * plane->speed);
}

void domain(plane_t *plane)
{
    if (plane->s_x >= 0 && plane->s_x <= 960
    && plane->s_y >= 0 && plane->s_y <= 540) {
        domaine1(plane);
        return;
    }
    if (plane->s_x >= 0 && plane->s_x <= 960
    && plane->s_y >= 540 && plane->s_y <= 1080) {
        domaine2(plane);
        return;
    }
    if (plane->s_x >= 960 && plane->s_x <= 1920
    && plane->s_y >= 0 && plane->s_y <= 540) {
        domaine3(plane);
        return;
    }
    if (plane->s_x >= 960 && plane->s_x <= 1920
    && plane->s_y >= 540 && plane->s_y <= 1080) {
        domaine4(plane);
        return;
    }
}

void travelling_bns_plane(plane_t *plane)
{
    if (plane->id_bool == 1 && plane->arrival == 0 && plane->speed > 0
    && plane->crash == 0) {
    domain(plane);
    end_travel(plane);
    sfSprite_setPosition(plane->bt.key, (sfVector2f) {plane->s_x, plane->s_y});
    sfRectangleShape_setPosition(plane->R, (sfVector2f) {plane->s_x - 26,
    plane->s_y - 25});
    }
}

void travelling_plane(plane_t *plane)
{
    if (plane->id_bool == 1 && plane->arrival == 0 && plane->speed > 0
    && plane->crash == 0) {
    domain(plane);
    travel_plane(plane);
    end_travel(plane);
    sfSprite_setPosition(plane->bt.key, (sfVector2f) {plane->s_x, plane->s_y});
    sfRectangleShape_setPosition(plane->R, (sfVector2f) {plane->s_x - 10,
    plane->s_y - 10});
    }
}
