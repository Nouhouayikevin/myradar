/*
** EPITECH PROJECT, 2024
** the function for the  gestion of sprite
** File description:
** of radar
*/

#include "my.h"

sfSprite *sp_creator(char *filename, sfVector2f p, sfVector2f s, float a)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setPosition(sprite, p);
    sfSprite_setScale(sprite, s);
    sfSprite_setRotation(sprite, a);
    return sprite;
}

void plane_set_texture(plane_t *plane)
{
    plane->bt.T = sfTexture_createFromFile("Images/plane.png", NULL);
    sfSprite_setTexture(plane->bt.key, plane->bt.T, sfTrue);
}

void tower_set_texture(tower_t *tower)
{
    tower->bt.T = sfTexture_createFromFile("Images/tower.png", NULL);
    sfSprite_setTexture(tower->bt.key, tower->bt.T, sfTrue);
}
