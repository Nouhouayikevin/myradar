/*
** EPITECH PROJECT, 2024
** getting angle
** File description:
** of the plane
*/


#include "my.h"

sfRenderWindow *init_win(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
    "my_radar", sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(window, 32);
    return window;
}

float cod_to_angle(sfVector2f *start, sfVector2f *end)
{
    float dx = end->x - start->x;
    float dy = end->y -start->y;
    float angle = atan2f(dy, dx);

    if (angle >= 0)
        angle = (M_PI * 2) + angle;
    return (180 / M_PI * angle);
}
