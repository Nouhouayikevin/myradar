/*
** EPITECH PROJECT, 2024
** the functions to gesture windows
** File description:
** of radar
*/

#include "my.h"

static int delete;
int music_bool;

void display(sfRenderWindow *win, radar_t *rdr)
{
    int i = 0;

    verif_crash_plane(rdr);
    for (i = 0; i < rdr->nb_plane; i++) {
        clock_for_departure(&(rdr->plane[i]));
        travelling_plane(&(rdr->plane[i]));
        if (rdr->plane[i].arrival == 0 && rdr->plane[i].id_bool == 1 &&
        rdr->plane[i].crash == 0) {
            off_the_sprite(rdr, win, i);
            sfRenderWindow_drawRectangleShape(win, rdr->plane[i].R, NULL);
        }
    }
    for (i = 0; i < rdr->nb_tower; i++) {
        if (rdr->S == 0) {
        sfRenderWindow_drawSprite(win, rdr->tower[i].bt.key, NULL);
        }
        sfRenderWindow_drawCircleShape(win, rdr->tower[i].C, NULL);
    }
}

void destroy1(radar_t *rdr, bttn_t *mn, bttn_t *night)
{
    if (delete != 1) {
    for (int i = 0; i < rdr->nb_plane; i++) {
    sfTexture_destroy(rdr->plane[i].bt.T);
    sfClock_destroy(rdr->plane[i].bt.c);
    sfSprite_destroy(rdr->plane[i].bt.key);
    sfRectangleShape_destroy(rdr->plane[i].R);
    }
    for (int i = 0; i < rdr->nb_tower; i++) {
    sfSprite_destroy(rdr->tower[i].bt.key);
    sfCircleShape_destroy(rdr->tower[i].C);
    }
    destroy2(night, rdr, mn);
    delete = 1;
    }
}

static void the_page_menudisplay(sfRenderWindow *window, radar_t *rdr,
    bttn_t *mn, bttn_t *night)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, mn->key, NULL);
    sfRenderWindow_drawSprite(window, night->key, NULL);
    display(window, rdr);
    draw_flying_planes(window, rdr, mn);
    draw_time(window, mn);
    display_bns_plane(window, rdr);
    sfRenderWindow_display(window);
}

static void move_up(plane_t *plane)
{
    sfVector2f p;

    plane->s_y -= ceil(plane->speed / 2);
    p = (sfVector2f) {plane->s_x, plane->s_y};
    sfSprite_setPosition(plane->bt.key, p);
    sfRectangleShape_setPosition(plane->R, p);
}

static void move_down(plane_t *plane)
{
    sfVector2f p;

    plane->s_y += ceil(plane->speed / 2);
    p = (sfVector2f) {plane->s_x, plane->s_y};
    sfSprite_setPosition(plane->bt.key, p);
    sfRectangleShape_setPosition(plane->R, p);
}

static void move_right(plane_t *plane)
{
    sfVector2f p;

    plane->s_x -= ceil(plane->speed / 2);
    p = (sfVector2f) {plane->s_x, plane->s_y};
    sfSprite_setPosition(plane->bt.key, p);
    sfRectangleShape_setPosition(plane->R, p);
}

static void move_left(plane_t *plane)
{
    sfVector2f p;

    plane->s_x += ceil(plane->speed / 2);
    p = (sfVector2f) {plane->s_x, plane->s_y};
    sfSprite_setPosition(plane->bt.key, p);
    sfRectangleShape_setPosition(plane->R, p);
}

static void move_the_bns_plane(stt_t *plane, sfEvent *e, radar_t *r)
{
    if (plane->compiled == 1 && r->simulation == 1) {
    if (e->type == sfEvtKeyPressed && e->key.code == sfKeyUp)
        move_up(&(plane->plane));
    if (e->type == sfEvtKeyPressed && e->key.code == sfKeyDown)
        move_down(&(plane->plane));
    if (e->type == sfEvtKeyPressed && e->key.code == sfKeyRight)
        move_left(&(plane->plane));
    if (e->type == sfEvtKeyPressed && e->key.code == sfKeyLeft)
        move_right(&(plane->plane));
    }
    if (e->type == sfEvtKeyPressed && e->key.code == sfKeyM) {
        if (music_bool == 3) {
            music_bool--;
            return;
        }
        music_bool++;
    }
}

void music_event_menu(radar_t *r)
{
    if (music_bool == 2) {
        sfMusic_pause(r->m);
        music_bool = 0;
    }
    if (music_bool == 1) {
        sfMusic_play(r->m);
        music_bool = 3;
    }
}

void page_debut(sfRenderWindow *window, radar_t *rdr)
{
    bttn_t mn;
    bttn_t night;

    music_bool = 1;
    principal_init(&mn, &night, rdr);
    while (sfRenderWindow_isOpen(window)) {
        monitoring(rdr, &night);
        while (sfRenderWindow_pollEvent(window, &night.e)) {
            move_the_bns_plane(&(rdr->bns), &night.e, rdr);
            close_win(window, rdr, &night, &mn);
        }
        the_page_menudisplay(window, rdr, &mn, &night);
        if (rdr->bns.plane.arrival == 1) {
        rdr->bns.real_time = get_time_elapsed(mn.c);
        checker_result(window, rdr);
        }
    }
    destroy_bns_plane(rdr);
    destroy1(rdr, &mn, &night);
}
