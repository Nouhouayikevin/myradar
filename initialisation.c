/*
** EPITECH PROJECT, 2024
** gerer le cas de l'initialisation
** File description:
** pour les structures principales
*/

#include "my.h"
static void init_bonus_info(stt_t *s)
{
    sfVector2f p;
    sfVector2f scale;

    s->connection = 0;
    s->safetime = 0;
    p = (sfVector2f) {s->plane.s_x, s->plane.s_y};
    s->plane.bt.key = sp_creator("Images/plane_bns.png", p, (sfVector2f)
    {0.03, 0.03}, 0);
    s->plane.bt.T = sfTexture_createFromFile("Images/plane_bns.png", NULL);
    sfSprite_setTexture(s->plane.bt.key, s->plane.bt.T, sfTrue);
    scale = (sfVector2f) {s->plane.e_x, s->plane.e_y};
    sfSprite_setRotation(s->plane.bt.key, 0.0);
    sfSprite_setOrigin(s->plane.bt.key,
    (sfVector2f){880, 885});
    sfSprite_rotate(s->plane.bt.key, cod_to_angle(&p, &scale));
    p = (sfVector2f) {s->plane.s_x - 20, s->plane.s_y + 10};
    init_rect(&(s->plane), p, (sfVector2f) {50, 50});
    s->plane.play = 0;
    sfRectangleShape_setOutlineColor(s->plane.R, sfCyan);
    s->plane.domain = 0;
}

void plane_rotation(plane_t *plane)
{
    sfVector2f p = (sfVector2f) {plane->s_x, plane->s_y};
    sfVector2f s = (sfVector2f) {plane->e_x, plane->e_y};

    sfSprite_setRotation(plane->bt.key, cod_to_angle(&p, &s));
}

static void second_bonus_info_init(radar_t *r)
{
    sfVector2f scale = (sfVector2f) {0.125, 0.125};
    sfVector2f p = (sfVector2f) {550, 200};

    init_bonus_info(&(r->bns));
    r->bns.plane.bt.c = sfClock_create();
    r->bns.plane.play = 0;
    r->bns.pressure = 80000;
    r->bns.orage = sfSprite_create();
    r->bns.texture = sfTexture_createFromFile("Images/orage.png", NULL);
    sfSprite_setTexture(r->bns.orage, r->bns.texture, 1);
    sfSprite_setScale(r->bns.orage, scale);
    sfSprite_setPosition(r->bns.orage, p);
}

void principal_init(bttn_t *mn, bttn_t *night, radar_t *r)
{
    if (r->bns.compiled == 1 && r->simulation == 1) {
        parse_bns(r->str, r);
    }
    if (r->bns.compiled == 0)
        parse(r->str, r);
    init_main(mn);
    init_night(night);
    init_travels(r);
    r->pause = 0;
    r->S = 0;
    r->m = sfMusic_createFromFile("music/lofi-chillmusic.ogg");
    sfMusic_play(r->m);
    if (r->bns.compiled == 1 && r->simulation == 1) {
        second_bonus_info_init(r);
    } else
        r->bns.plane.play = 1;
}
