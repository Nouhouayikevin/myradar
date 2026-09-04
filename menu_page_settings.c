/*
** EPITECH PROJECT, 2024
** the functions of my radar
** File description:
** in the radar
*/

#include "my.h"

static void destroy_menu2(menu_t *mn)
{
    sfSprite_destroy(mn->A.key);
    sfSprite_destroy(mn->B.key);
    sfSprite_destroy(mn->C.key);
    sfSprite_destroy(mn->D.key);
    sfSprite_destroy(mn->E.key);
    sfMusic_destroy(mn->C.m);
    sfText_destroy(mn->A.text);
    sfFont_destroy(mn->A.font);
    sfRectangleShape_destroy(mn->A.R);
    sfText_destroy(mn->B.text);
    sfFont_destroy(mn->B.font);
    sfText_destroy(mn->C.text);
    sfFont_destroy(mn->C.font);
    sfText_destroy(mn->D.text);
    sfFont_destroy(mn->D.font);
}

void destroy_menu(menu_t *mn)
{
    sfClock_destroy(mn->A.c);
    sfClock_destroy(mn->B.c);
    sfClock_destroy(mn->C.c);
    sfTexture_destroy(mn->A.T);
    sfTexture_destroy(mn->B.T);
    sfTexture_destroy(mn->C.T);
    sfTexture_destroy(mn->D.T);
    sfTexture_destroy(mn->E.T);
    destroy_menu2(mn);
}

void pos_updt_menu(bttn_t *obj)
{
    if (obj->vecp.x < 1500)
        obj->vecp.x += 1.4;
    if (obj->vecp.y >= 450) {
        obj->vecp.y -= 1.8;
    }
    if (obj->vecp.x >= 660) {
        obj->vecp.x -= 2.1;
    }
    if (obj->vecp.y < 510)
        obj->vecp.y += 2.9;
    sfSprite_setPosition(obj->key, (sfVector2f)obj->vecp);
}

void menu_animation(bttn_t *bird, double timelaspe, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > timelaspe) {
    pos_updt_menu(bird);
    sfClock_restart(clock);
    }
}

void random_display(sfRenderWindow *win, menu_t *mn, int i)
{
    if (i == 1)
    sfRenderWindow_drawSprite(win, mn->A.key, NULL);
    if (i == 2)
    sfRenderWindow_drawSprite(win, mn->B.key, NULL);
    if (i == 3)
    sfRenderWindow_drawSprite(win, mn->C.key, NULL);
}
