/*
** EPITECH PROJECT, 2024
** the guide the radar
** File description:
** radar
*/


#include "my.h"

void monitoring(radar_t *rdr, bttn_t *night)
{
    sfMusic_setLoop(rdr->m, 1);
    rect_color_change(rdr);
    sim_night(night);
    music_event_menu(rdr);
}

void guide_evt(sfRenderWindow *window, sfEvent *e, radar_t *rdr)
{
    sfVector2i p = sfMouse_getPosition((const sfWindow*)window);

    if (e->type == sfEvtKeyPressed && e->key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (e->type == sfEvtMouseButtonPressed
    && p.x > 93 && p.x < 481 && p.y > 807 && p.y < 970) {
        sfMusic_pause(rdr->m);
        menu(window, rdr);
        return;
    }
}

static void guide_init(menu_t *menu, radar_t *r)
{
    menu->A.key = sp_creator("Images/Guide.png", (sfVector2f){0, 0},
    (sfVector2f) {1.8, 1.8}, 0);
    menu->A.T = sfTexture_createFromFile("Images/Guide.png", NULL);
    sfSprite_setTexture(menu->A.key, menu->A.T, 1);
}

void guide(sfRenderWindow *win, radar_t *r)
{
    menu_t menu;

    guide_init(&menu, r);
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &menu.A.e)) {
            guide_evt(win, &menu.A.e, r);
        }
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, menu.A.key, NULL);
        sfRenderWindow_display(win);
    }
    sfSprite_destroy(menu.A.key);
    sfTexture_destroy(menu.A.T);
}
