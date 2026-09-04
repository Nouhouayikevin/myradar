/*
** EPITECH PROJECT, 2024
** the differents domain of the planes
** File description:
** spliting the screen
*/

#include "my.h"

void domaine1(plane_t *plane)
{
    if (plane->s_x >= 0 && plane->s_x <= 480
    && plane->s_y >= 0 && plane->s_y <= 270) {
        plane->domain = 1;
        return;
    }
    if (plane->s_x >= 0 && plane->s_x <= 480
    && plane->s_y >= 270 && plane->s_y <= 540){
        plane->domain = 3;
        return;
    }
    if (plane->s_x >= 480 && plane->s_x <= 960
    && plane->s_y >= 0 && plane->s_y <= 270) {
        plane->domain = 2;
        return;
    }
    if (plane->s_x >= 480 && plane->s_x <= 960
    && plane->s_y >= 270 && plane->s_y <= 540) {
        plane->domain = 4;
        return;
    }
}

void domaine2(plane_t *plane)
{
    if (plane->s_x >= 0 && plane->s_x <= 480
    && plane->s_y > 540 && plane->s_y < 810) {
        plane->domain = 5;
        return;
    }
    if (plane->s_x >= 0 && plane->s_x <= 480
    && plane->s_y > 810 && plane->s_y < 1080) {
        plane->domain = 7;
        return;
    }
    if (plane->s_x >= 480 && plane->s_x <= 960
    && plane->s_y > 540 && plane->s_y < 810) {
        plane->domain = 6;
        return;
    }
    if (plane->s_x >= 480 && plane->s_x <= 960
    && plane->s_y > 810 && plane->s_y < 1080) {
        plane->domain = 8;
        return;
    }
}

void domaine3(plane_t *plane)
{
    if (plane->s_x > 960 && plane->s_x <= 1440
    && plane->s_y >= 0 && plane->s_y <= 270)
        plane->domain = 9;
    if (plane->s_x > 960 && plane->s_x <= 1440
    && plane->s_y >= 270 && plane->s_y <= 540)
        plane->domain = 11;
    if (plane->s_x > 1440 && plane->s_x <= 1920
    && plane->s_y >= 270 && plane->s_y <= 540)
        plane->domain = 12;
    if (plane->s_x > 1440 && plane->s_x <= 1920
    && plane->s_y >= 0 && plane->s_y <= 270)
        plane->domain = 10;
}

void domaine4(plane_t *plane)
{
    if (plane->s_x > 960 && plane->s_x <= 1440
    && plane->s_y >= 540 && plane->s_y <= 810) {
        plane->domain = 13;
        return;
    }
    if (plane->s_x > 960 && plane->s_x <= 1440
    && plane->s_y >= 810 && plane->s_y <= 1080) {
        plane->domain = 15;
        return;
    }
    if (plane->s_x > 1440 && plane->s_x <= 1920
    && plane->s_y >= 810 && plane->s_y <= 1080) {
        plane->domain = 16;
        return;
    }
    if (plane->s_x > 1440 && plane->s_x <= 1920
    && plane->s_y >= 540 && plane->s_y <= 810) {
        plane->domain = 14;
        return;
    }
}
