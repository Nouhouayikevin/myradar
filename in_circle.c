/*
** EPITECH PROJECT, 2024
** when the travelling plane is in circle
** File description:
** and he is in circle
*/

#include "my.h"

sfVector2f *get_rect_corners(sfRectangleShape *rect)
{
    sfVector2f *t = malloc(sizeof(sfVector2f) * 4);

    t[0] = sfRectangleShape_getPosition(rect);
    t[1] = (sfVector2f){t[0].x + 20, t[0].y};
    t[2] = (sfVector2f){t[0].x, t[0].y + 20};
    t[3] = (sfVector2f){t[0].x + 20, t[0].y + 20};
    return (sfVector2f *) t;
}

int corner_in_circle(sfVector2f *center, sfVector2f *coin, double rayon)
{
    double d = pow((center->x - coin->x), 2) + pow((center->y - coin->y), 2);

    return (d <= pow(rayon, 2));
}

int in_circles(plane_t *plane, tower_t *t, int *j, int *k)
{
    sfVector2f p;
    sfVector2f *coins = get_rect_corners(plane->R);

    for (int i = 0; i < 4; i++) {
    p = (sfVector2f){t->pos_x, t->pos_y};
    if (corner_in_circle(&p, (sfVector2f *)&(coins[i]), t->r) == 1
    && plane->play == 0) {
    sfRectangleShape_setOutlineColor(plane->R, sfGreen);
    *j += 1;
    *k = 0;
    free(coins);
    return 1;
    }
    if (corner_in_circle(&p, &(coins[i]), t->r) != 1
    && plane->play == 0) {
    sfRectangleShape_setOutlineColor(plane->R, sfYellow);
    free(coins);
    return 0;
    }
    }
}

static void verify_in_circle(radar_t *rdr, int *i, int *j)
{
    if (*i == rdr->nb_plane)
        return;
    in_circles(&(rdr->plane[*i]), &(rdr->tower[*j]), i, j);
}

int get_time_elapsed(sfClock *clock)
{
    return (int)sfTime_asSeconds(sfClock_restart(clock));
}

static int change_bnsrect_color(plane_t *plane, tower_t *t, int *j)
{
    sfVector2f p;
    sfVector2f *coins = get_rect_corners(plane->R);

    for (int i = 0; i < 4; i++) {
    p = (sfVector2f){t->pos_x, t->pos_y};
    if (corner_in_circle(&p, (sfVector2f *)&(coins[i]), t->r) == 1
    && plane->play == 0) {
    plane->sec += get_time_elapsed(plane->bt.c);
    sfRectangleShape_setOutlineColor(plane->R, sfGreen);
    free(coins);
    return 1;
    }
    if (corner_in_circle(&p, &(coins[i]), t->r) != 1
    && plane->play == 0) {
    sfRectangleShape_setOutlineColor(plane->R, sfCyan);
    free(coins);
    return 0;
    }
    }
}

static void crash_out_bns(radar_t *rdr)
{
    for (int j = 0; j < rdr->nb_tower; j++) {
        if (1 == change_bnsrect_color(&(rdr->bns.plane), &(rdr->tower[j]), &j))
        return;
    }
}

void rect_color_change(radar_t *rdr)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < rdr->nb_plane; i++) {
        for (j = 0; j < rdr->nb_tower; j++) {
            verify_in_circle(rdr, &i, &j);
        }
    }
    if (rdr->simulation == 1 && rdr->bns.compiled == 1) {
        crash_out_bns(rdr);
    }
}
