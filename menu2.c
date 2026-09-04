/*
** EPITECH PROJECT, 2024
** the second menu_page of the radar
** File description:
** with the choice option
*/

#include "my.h"

void event_for_menu2(sfRenderWindow *window, radar_t *rdr, menu_t *menu)
{
    sfVector2i p = sfMouse_getPosition((const sfWindow*)window);

    if (menu->A.e.type == sfEvtMouseButtonPressed && p.x > 0
    && p.x < 115 && p.y > 373 && p.y < 410)
        sfRenderWindow_close(window);
    if (menu->A.e.type == sfEvtMouseButtonPressed && p.x > 0
    && p.x <= 160 && p.y >= 273 && p.y <= 312)
        guide(window, rdr);
    if (menu->A.e.type == sfEvtMouseButtonPressed && p.x > 0
    && p.x <= 628 && p.y >= 150 && p.y <= 190 && rdr->bns.compiled == 1) {
        rdr->simulation = 1;
        sfMusic_pause(menu->C.m);
        page_debut(window, rdr);
    }
    if (menu->A.e.type == sfEvtMouseButtonPressed && p.x > 0
    && p.x <= 341 && p.y >= 0 && p.y <= 50) {
        rdr->simulation = 0;
        sfMusic_pause(menu->C.m);
        page_debut(window, rdr);
    }
}

void close_menu2(sfRenderWindow *window, radar_t *rdr, menu_t *menu)
{
    if (menu->A.e.type == sfEvtKeyPressed && menu->A.e.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (menu->A.e.type == sfEvtClosed)
        sfRenderWindow_close(window);
    event_for_menu2(window, rdr, menu);
}

void menu2(sfRenderWindow *win, radar_t *r, menu_t *menu)
{
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &menu->A.e)) {
            close_menu2(win, r, menu);
        }
        random_slide(win, menu);
        menu_animation(&(menu->E), 0.1, menu->A.c);
        sfRenderWindow_drawText(win, menu->B.text, NULL);
        sfRenderWindow_drawText(win, menu->E.text, NULL);
        sfRenderWindow_drawText(win, menu->C.text, NULL);
        sfRenderWindow_drawText(win, menu->D.text, NULL);
        sfRenderWindow_setFramerateLimit(win, 32);
        sfRenderWindow_display(win);
        sfMusic_setLoop(menu->C.m, 1);
        sfRenderWindow_clear(win, sfBlack);
    }
}
