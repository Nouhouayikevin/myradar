/*
** EPITECH PROJECT, 2024
** the simulation of the night part
** File description:
** of the map
*/

#include "my.h"

void pos_updt(bttn_t *obj)
{
    obj->vecp.x += 20;
    if (obj->vecp.x >= 1400) {
        obj->vecp.x = 0;
        obj->rect.left = 0;
        sfSprite_setTextureRect(obj->key, obj->rect);
    }
    sfSprite_setPosition(obj->key, (sfVector2f)obj->vecp);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value) {
        rect->left += offset;
    } else {
        rect->left = 0;
    }
}

void animation(bttn_t *bird, double timelaspe, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > timelaspe) {
    move_rect(&(bird->rect), 20, 1400);
    sfSprite_setTextureRect(bird->key, bird->rect);
    pos_updt(bird);
    sfClock_restart(clock);
    }
}

void sim_night(bttn_t *obj)
{
    animate0(obj);
    animate1(obj);
    animate2(obj);
}

void init_night(bttn_t *mn)
{
    sfVector2f p = {0};
    sfVector2f s = {1, 1};

    mn->key = sp_creator("Images/world_map.png", p, s, 0);
    mn->c = sfClock_create();
    mn->T = sfTexture_createFromFile("Images/world_map_night.png", NULL);
    sfSprite_setTexture(mn->key, mn->T, sfTrue);
    mn->rect = (sfIntRect) {0, 0, 500, 1080};
    sfSprite_setTextureRect(mn->key, mn->rect);
    mn->vecp = p;
    mn->animate = 1;
    mn->play = 1;
}
