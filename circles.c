/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** circles of towers
*/

#include "my.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *c = sfCircleShape_create();

    sfCircleShape_setRadius(c, radius);
    sfCircleShape_setPosition(c, position);
    sfCircleShape_setOutlineThickness(c, 2);
    sfCircleShape_setOutlineColor(c, sfBlue);
    sfCircleShape_setFillColor(c, sfTransparent);
    return c;
}
