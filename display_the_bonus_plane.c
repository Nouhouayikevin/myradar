/*
** EPITECH PROJECT, 2024
** the bonus plane
** File description:
** on the map
*/

#include "my.h"
static int delete;
static int angle;
static void bns_plane_rotation(stt_t *s)
{
    sfVector2f p = (sfVector2f) {s->plane.s_x, s->plane.s_y};
    sfVector2f sc = (sfVector2f) {s->plane.e_x, s->plane.e_y};

    angle += cod_to_angle(&p, &sc);
    srand(time(NULL));
    delete = 1;
    sfSprite_setRotation(s->plane.bt.key, cod_to_angle(&p, &sc));
    if (p.x >= 550 && p.x <= 858 && p.y >= 200 && p.y <= 508) {
        sfRectangleShape_setOutlineColor(s->plane.R, sfRed);
        sfSprite_rotate(s->plane.bt.key, angle);
        s->pressure -= rand() % (100 - 50 + 1) + 50;
    }
    if (s->pressure < 60192)
        s->plane.arrival = 1;
}

static void off_the_sprite_bns(radar_t *rdr, sfRenderWindow *win)
{
    if (rdr->S == 0) {
        bns_plane_rotation(&(rdr->bns));
        sfRenderWindow_drawSprite(win, rdr->bns.plane.bt.key, NULL);
    }
}

void destroy_bns_plane(radar_t *rdr)
{
    if (delete == 1)
    return;
    if (rdr->bns.compiled != 1)
        return;
    if (rdr->simulation == 0)
        return;
    sfTexture_destroy(rdr->bns.plane.bt.T);
    sfClock_destroy(rdr->bns.plane.bt.c);
    sfSprite_destroy(rdr->bns.plane.bt.key);
    sfRectangleShape_destroy(rdr->bns.plane.R);
    sfSprite_destroy(rdr->bns.orage);
    sfTexture_destroy(rdr->bns.texture);
}

void display_bns_plane(sfRenderWindow *win, radar_t *rdr)
{
    int i = 0;

    if (rdr->bns.compiled != 1)
        return;
    if (rdr->simulation == 0)
        return;
    verif_bns_crash(rdr);
    rdr->bns.connection += (rdr->bns.plane.crash == 1);
    rdr->bns.plane.crash = 0;
    clock_for_departure(&(rdr->bns.plane));
    travelling_bns_plane(&(rdr->bns.plane));
    if (rdr->bns.plane.arrival == 0 && rdr->bns.plane.id_bool == 1 &&
    rdr->bns.plane.crash == 0) {
        off_the_sprite_bns(rdr, win);
        sfRenderWindow_drawRectangleShape(win, rdr->bns.plane.R, NULL);
        sfRenderWindow_drawSprite(win, rdr->bns.orage, NULL);
    }
}
