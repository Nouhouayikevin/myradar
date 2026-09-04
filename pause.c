/*
** EPITECH PROJECT, 2024
** pause the window
** File description:
** in the simulation
*/

#include "my.h"

void free_radar(radar_t *rdr)
{
    if (rdr->plane != NULL) {
    free(rdr->plane);
    free(rdr->tower);
    }
    if (rdr->m != NULL) {
    sfMusic_destroy(rdr->m);
    sfText_destroy(rdr->text);
    sfFont_destroy(rdr->font);
    }
}

void window_in_loop(sfRenderWindow *win, sfEvent *e, radar_t *rdr, bttn_t *mn)
{
    while (sfRenderWindow_pollEvent(win, e)) {
        if (e->type == sfEvtKeyPressed && e->key.code == sfKeySpace) {
            rdr->pause += 1;
            break;
        }
        if (e->type == sfEvtKeyPressed && e->key.code == sfKeyEscape)
        sfRenderWindow_close(win);
    }
    sfRenderWindow_display(win);
}

void the_pause_of_win(sfRenderWindow *win, sfEvent *e, radar_t *rdr,
    bttn_t *mn)
{
    while (sfRenderWindow_isOpen(win)) {
            window_in_loop(win, e, rdr, mn);
            if (rdr->pause == 2)
                break;
        }
}

void pause_window(sfRenderWindow *win, sfEvent *e, radar_t *rdr, bttn_t *mn)
{
    if (rdr->pause == 1) {
        the_pause_of_win(win, e, rdr, mn);
        }
    if (rdr->pause == 2)
        rdr->pause = 0;
}
