/*
** EPITECH PROJECT, 2024
** the menu
** File description:
** for radar
*/

#include "my.h"
static int pauser;
static int anim_bool;

static void go_to_menu2(menu_t *menu, sfRenderWindow *win, radar_t *r)
{
    if (menu->A.e.type == sfEvtMouseButtonPressed)
        menu2(win, r, menu);
}

static void second_event(sfRenderWindow *window, menu_t *menu, radar_t *r)
{
    sfVector2i p = sfMouse_getPosition((const sfWindow *)window);

    if (p.x > 759 && p.x < 1000 && p.y > 450 && p.y < 497 &&
    anim_bool == 1) {
        sfRectangleShape_setOutlineColor(menu->A.R, sfYellow);
        sfRectangleShape_setSize(menu->A.R, (sfVector2f){250, 60});
        go_to_menu2(menu, window, r);
    } else {
        if (anim_bool == 1) {
        sfRectangleShape_setSize(menu->A.R, (sfVector2f){250, 60});
        sfRectangleShape_setOutlineColor(menu->A.R, sfCyan);
        }
    }
}

void close_menu(sfRenderWindow *window, radar_t *rdr, menu_t *menu)
{
    if (menu->A.e.type == sfEvtKeyPressed && menu->A.e.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (menu->A.e.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (menu->A.e.type == sfEvtKeyPressed && menu->A.e.key.code == sfKeyM) {
        pauser++;
        if (pauser == 1)
        sfMusic_pause(menu->C.m);
        if (pauser == 2) {
        sfMusic_play(menu->C.m);
        pauser = 0;
        }
    }
    second_event(window, menu, rdr);
}

void random_slide(sfRenderWindow *win, menu_t *mn)
{
    static int i = 0;
    static int first = 1;
    static sfClock *clock_slide;
    sfTime elapsed;

    srand(time(NULL));
    if (first == 1) {
    clock_slide = sfClock_create();
    first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock_slide);
    if (sfTime_asSeconds(elapsed) < 5 && anim_bool == 0)
        sfRenderWindow_drawSprite(win, mn->D.key, NULL);
    if (sfTime_asSeconds(elapsed) >= 5) {
    i = rand() % (3 - 1 + 1) + 1;
        random_display(win, mn, i);
        sfClock_restart(clock_slide);
        anim_bool = 1;
    } else
        random_display(win, mn, i);
}

static void display_for_menu(sfRenderWindow *win, menu_t *menu)
{
        random_slide(win, menu);
        menu_animation(&(menu->E), 0.1, menu->A.c);
    if (anim_bool == 1) {
        sfRectangleShape_setSize(menu->A.R, (sfVector2f){250, 60});
        sfRenderWindow_drawSprite(win, menu->E.key, NULL);
    }
        sfRenderWindow_drawText(win, menu->A.text, NULL);
        sfRenderWindow_drawRectangleShape(win, menu->A.R, NULL);
        sfRenderWindow_setFramerateLimit(win, 32);
        sfRenderWindow_display(win);
        sfMusic_setLoop(menu->C.m, 1);
        sfRenderWindow_clear(win, sfBlack);
}

void menu(sfRenderWindow *win, radar_t *r)
{
    menu_t menu;

    menu_initialisation(&menu);
    sfMusic_play(menu.C.m);
    r->m = menu.C.m;
    pauser = 0;
    anim_bool = 0;
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &menu.A.e)) {
            close_menu(win, r, &menu);
        }
        display_for_menu(win, &menu);
    }
    destroy_menu(&menu);
}
