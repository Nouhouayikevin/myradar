/*
** EPITECH PROJECT, 2024
** the functions of initialization
** File description:
** for the bttn sprite
*/

#include "my.h"

void init_rect(plane_t *plane, sfVector2f p, sfVector2f s)
{
    plane->R = sfRectangleShape_create();
    sfRectangleShape_setFillColor(plane->R, sfTransparent);
    sfRectangleShape_setOutlineThickness(plane->R, 2);
    sfRectangleShape_setOutlineColor(plane->R, sfYellow);
    sfRectangleShape_setPosition(plane->R, (sfVector2f) {plane->s_x -10,
    plane->s_y - 10});
    sfRectangleShape_setSize(plane->R, s);
}

void init_planes(radar_t *rdr, int i)
{
    sfVector2f p;
    sfVector2f s;

    p = (sfVector2f) {rdr->plane[i].s_x, rdr->plane[i].s_y};
    rdr->plane[i].bt.key = sp_creator("Images/plane.png", p, (sfVector2f)
    {0.07, 0.07}, 0);
    plane_set_texture(&(rdr->plane[i]));
    s = (sfVector2f) {rdr->plane[i].e_x, rdr->plane[i].e_y};
    sfSprite_setRotation(rdr->plane[i].bt.key, 0.0);
    sfSprite_setOrigin(rdr->plane[i].bt.key,
    (sfVector2f){(285) / 2, (268) / 2});
    sfSprite_rotate(rdr->plane[i].bt.key, cod_to_angle(&p, &s));
    init_rect(&(rdr->plane[i]), p, (sfVector2f) {20, 20});
    rdr->plane[i].play = 0;
}

void init_travels(radar_t *rdr)
{
    sfVector2f p;
    sfVector2f s;

    for (int i = 0; i < rdr->nb_plane; i++) {
        init_planes(rdr, i);
        rdr->plane[i].crash = 0;
        rdr->plane[i].domain = 0;
    }
    rdr->text = sfText_create();
    rdr->font = sfFont_createFromFile("font/skyfont.otf");
    sfText_setFont(rdr->text, rdr->font);
    sfText_setString(rdr->text, "");
    for (int i = 0; i < rdr->nb_tower; i++) {
    p = (sfVector2f) {rdr->tower[i].pos_x - 20, rdr->tower[i].pos_y};
    rdr->tower[i].bt.key = sp_creator("Images/tower.png", p, (sfVector2f)
    {0.09, 0.09}, 0);
    tower_set_texture(&(rdr->tower[i]));
    rdr->tower[i].C = create_circle((sfVector2f) {rdr->tower[i].pos_x -
    rdr->tower[i].r, rdr->tower[i].pos_y - rdr->tower[i].r}, rdr->tower[i].r);
    }
}

void clock_for_departure(plane_t *plane)
{
    sfTime elapsed;

    elapsed = sfClock_getElapsedTime(plane->bt.c);
    if (sfTime_asSeconds(elapsed) < plane->t) {
        plane->id_bool = 0;
        plane->arrival = 0;
        return;
    }
    if (sfTime_asSeconds(elapsed) >= plane->t) {
        plane->id_bool = 1;
        return;
    }
}

void init_main(bttn_t *mn)
{
    sfVector2f p = {0};
    sfVector2f s = {1, 1};

    mn->key = sp_creator("Images/world_map.png", p, s, 0);
    mn->c = sfClock_create();
    mn->T = sfTexture_createFromFile("Images/world_map.png", NULL);
    sfSprite_setTexture(mn->key, mn->T, sfTrue);
    mn->font = sfFont_createFromFile("font/skyfont.otf");
    mn->text = sfText_create();
    sfText_setString(mn->text, "");
    sfText_setFont(mn->text, mn->font);
    sfText_setCharacterSize(mn->text, 60);
    mn->font1 = sfFont_createFromFile("font/falling_sky.otf");
    mn->text1 = sfText_create();
    sfText_setString(mn->text1, "");
    sfText_setFont(mn->text1, mn->font);
    sfText_setCharacterSize(mn->text1, 60);
    mn->play = 0;
    mn->animate = 0;
}
