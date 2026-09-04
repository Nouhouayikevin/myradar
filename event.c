/*
** EPITECH PROJECT, 2024
** the events for radar
** File description:
** the event functions
*/

#include "my.h"

void close_win(sfRenderWindow *window, radar_t *rdr, bttn_t *n, bttn_t *mn)
{
    if (n->e.type == sfEvtKeyPressed && n->e.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (n->e.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (n->e.type == sfEvtKeyPressed && n->e.key.code == sfKeyN) {
        n->animate += 1;
        if (n->animate == 3)
            n->animate = 0;
    }
    event_on_sprite(window, rdr, mn, n);
}

void get_plane_info2(plane_t *plane)
{
    plane->id_bool = 0;
    plane->bt.c = sfClock_create();
    plane->arrival = 0;
    plane->crash = 0;
}
