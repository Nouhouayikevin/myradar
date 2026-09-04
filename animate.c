/*
** EPITECH PROJECT, 2024
** the function in animation
** File description:
** animate night
*/

#include "my.h"
void animate1(bttn_t *obj)
{
    if (obj->animate == 1) {
        if (obj->play == 0) {
        obj->vecp = (sfVector2f){0, 0};
        obj->rect = (sfIntRect){0, 0, 500, 1080};
        sfSprite_setTextureRect(obj->key, obj->rect);
        sfSprite_setPosition(obj->key, obj->vecp);
        obj->play = 1;
        }
        sfSprite_setTextureRect(obj->key, obj->rect);
            animation(obj, 0.5, obj->c);
    }
}

void animate2(bttn_t *obj)
{
    if (obj->animate == 2) {
        obj->rect = (sfIntRect){0, 0, 1920, 1080};
        sfSprite_setTextureRect(obj->key, obj->rect);
        sfSprite_setPosition(obj->key, (sfVector2f){0, 0});
        obj->play = 0;
    }
}

void animate0(bttn_t *obj)
{
    if (obj->animate == 0) {
        obj->rect = (sfIntRect){0, 0, 0, 0};
        sfSprite_setTextureRect(obj->key, obj->rect);
        sfSprite_setPosition(obj->key, (sfVector2f) {0, 0});
        obj->play = 0;
    }
}
