/*
** EPITECH PROJECT, 2024
** the second event
** File description:
** that make the sprite  dessapear
*/

#include "my.h"

static void menu_bool_init(bttn_t *mn)
{
    mn->play = 0;
    mn->animate = 0;
}

void off_hitboxes_and_circles(radar_t *rdr, bttn_t *mn)
{
    if (mn->animate == 1 && mn->play == 0) {
    for (int i = 0; i < rdr->nb_plane; i++) {
        sfRectangleShape_setOutlineColor(rdr->plane[i].R, sfTransparent);
        rdr->plane[i].play = 1;
    }
    sfRectangleShape_setOutlineColor(rdr->bns.plane.R, sfTransparent);
    for (int i = 0; i < rdr->nb_tower; i++)
        sfCircleShape_setOutlineColor(rdr->tower[i].C, sfTransparent);
    mn->play = 1;
    }
    if (mn->animate == 2 && mn->play == 1) {
    for (int i = 0; i < rdr->nb_plane; i++) {
        sfRectangleShape_setOutlineColor(rdr->plane[i].R, sfYellow);
        rdr->plane[i].play = 0;
    }
    sfRectangleShape_setOutlineColor(rdr->bns.plane.R, sfCyan);
    for (int i = 0; i < rdr->nb_tower; i++)
        sfCircleShape_setOutlineColor(rdr->tower[i].C, sfBlue);
    menu_bool_init(mn);
    }
}

void off_the_sprite(radar_t *rdr, sfRenderWindow *win, int i)
{
    if (rdr->S == 0) {
        plane_rotation(&(rdr->plane[i]));
        sfRenderWindow_drawSprite(win, rdr->plane[i].bt.key, NULL);
    }
}

void event_on_sprite(sfRenderWindow *window, radar_t *rdr, bttn_t *mn,
    bttn_t *n)
{
        if (n->e.type == sfEvtKeyPressed && n->e.key.code == sfKeyL) {
            mn->animate += 1;
            off_hitboxes_and_circles(rdr, mn);
        }
        if (n->e.type == sfEvtKeyPressed && n->e.key.code == sfKeyS) {
            rdr->S += 1;
            if (rdr->S == 2)
            rdr->S = 0;
        }
        if (n->e.type == sfEvtKeyPressed && n->e.key.code == sfKeySpace) {
            rdr->pause += 1;
        pause_window(window, &(n->e), rdr, mn);
        }
}
