/*
** EPITECH PROJECT, 2024
** the collisions of  the planes
** File description:
** planes collides or not
*/

#include "my.h"

int intersects(plane_t *p1, plane_t *p2)
{
    sfVector2f t2 = sfRectangleShape_getPosition(p2->R);
    sfVector2f t1 = sfRectangleShape_getPosition(p1->R);
    sfColor green = sfRectangleShape_getOutlineColor(p1->R);

    if (green.g == 255 && green.r == 0 && green.b == 0)
        return 0;
    green = sfRectangleShape_getOutlineColor(p2->R);
    if (green.g == 255 && green.r == 0 && green.b == 0)
        return 0;
    if ((t1.x + 10 < t2.x - 10 || t1.x - 10 > t2.x + 10
    || t1.y + 10 < t2.y - 10 || t1.y + 10 > t2.y + 10))
        return 0;
    else
        return 1;
}
