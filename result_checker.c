/*
** EPITECH PROJECT, 2024
** the result of the unit_test checker
** File description:
** the unit_test results
*/

#include "my.h"
int indice_checker;
static float seconds;

static char *bns_time_to_str(int sec)
{
    char *s = NULL;
    char *str = malloc(sizeof(char) * 30);
    int minutes = sec / 60;
    int seconds = sec % 60;

    str[0] = '\0';
    if (minutes < 10)
        str = my_strcat(str, "0");
    s = int_to_str(minutes);
    str = my_strcat(str, reverse_string(s));
    str = my_strcat(str, ":");
    free(s);
    if (seconds < 10)
        str = my_strcat(str, "0");
    s = int_to_str(seconds);
    str = my_strcat(str, reverse_string(s));
    free(s);
    return (str);
}

static void checker_menu_init3(menu_t *menu, radar_t *r)
{
    char *str = NULL;

    menu->D.text = sfText_create();
    menu->D.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->D.text, menu->D.font);
    str = reverse_string(int_to_str(r->bns.plane.speed));
    sfText_setString(menu->D.text, str);
    sfText_setCharacterSize(menu->D.text, 40);
    sfText_setPosition(menu->D.text, (sfVector2f){600, 685});
    if (r->bns.plane.speed < 6)
        sfText_setColor(menu->D.text, sfRed);
    if (r->bns.plane.speed > 6 && r->bns.plane.speed < 15)
        sfText_setColor(menu->D.text, sfYellow);
    if (r->bns.plane.speed >= 15) {
        sfText_setColor(menu->D.text, sfGreen);
        indice_checker++;
    }
    free(str);
}

static void checker_menu_init2(menu_t *menu, radar_t *r)
{
    char *str = NULL;

    menu->C.text = sfText_create();
    menu->C.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->C.text, menu->C.font);
    seconds = r->bns.plane.sec / (r->bns.real_time + 1);
    str = bns_time_to_str(r->bns.real_time - r->bns.plane.sec);
    sfText_setString(menu->C.text, str);
    sfText_setCharacterSize(menu->C.text, 40);
    sfText_setPosition(menu->C.text, (sfVector2f){670, 560});
    if (seconds < 0.4)
        sfText_setColor(menu->C.text, sfRed);
    if (seconds > 0.4 && seconds < 0.7)
        sfText_setColor(menu->C.text, sfYellow);
    if (seconds >= 0.7) {
        sfText_setColor(menu->C.text, sfGreen);
        indice_checker++;
    }
    free(str);
}

static void checker_menu_init1(menu_t *menu, radar_t *r)
{
    char *str = NULL;

    menu->B.text = sfText_create();
    menu->B.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->B.text, menu->B.font);
    str = reverse_string(int_to_str(r->bns.pressure));
    sfText_setString(menu->B.text, str);
    sfText_setCharacterSize(menu->B.text, 40);
    sfText_setPosition(menu->B.text, (sfVector2f){550, 480});
    if (r->bns.pressure <= 65000)
        sfText_setColor(menu->B.text, sfRed);
    if (r->bns.pressure > 65000 && r->bns.pressure < 76000) {
        sfText_setColor(menu->B.text, sfGreen);
        indice_checker++;
    }
    if (r->bns.pressure >= 76000)
        sfText_setColor(menu->B.text, sfYellow);
    free(str);
}

static void checker_menu_init0(menu_t *menu, radar_t *r)
{
    char *str = NULL;

    menu->A.key = sp_creator("Images/Conclusion.png", (sfVector2f){0, 0},
    (sfVector2f) {1.8, 1.8}, 0);
    menu->A.T = sfTexture_createFromFile("Images/Conclusion.png", NULL);
    sfSprite_setTexture(menu->A.key, menu->A.T, 1);
    menu->A.text = sfText_create();
    menu->A.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->A.text, menu->A.font);
    str = reverse_string(int_to_str(r->bns.connection));
    sfText_setString(menu->A.text, str);
    sfText_setCharacterSize(menu->A.text, 40);
    sfText_setPosition(menu->A.text, (sfVector2f){850, 350});
    free(str);
}

static void checker_menu_init4(menu_t *menu, radar_t *r)
{
    char *choice[] = {"Good choice\n you might normally arrive \nin security",
    "You can sleep during the travel",
    "Rest on alert \nyou might have a crash \nwith this travel",
    "My Dear \nPray before you travel", "Death is on your Way",
    "Best travel to suicide yourself", NULL};

    if (indice_checker > 2)
        set_text_e_1(menu, r);
    if (indice_checker == 1)
        set_text_e_2(menu, r);
    if (indice_checker < 1)
        set_text_e_3(menu, r);
    set_text_e_4(indice_checker, choice, menu);
}

void checker_menu_init(menu_t *menu, radar_t *r)
{
    char *str = NULL;

    indice_checker = 0;
    checker_menu_init0(menu, r);
    if (r->bns.connection <= 6)
        sfText_setColor(menu->A.text, sfGreen);
    if (r->bns.connection > 7 && r->bns.connection < 20)
        sfText_setColor(menu->A.text, sfYellow);
    if (r->bns.connection > 20)
        sfText_setColor(menu->A.text, sfRed);
    checker_menu_init1(menu, r);
    checker_menu_init2(menu, r);
    checker_menu_init3(menu, r);
    checker_menu_init4(menu, r);
}

void event_close(sfRenderWindow *window, sfEvent *e, radar_t *rdr)
{
    sfVector2i p = sfMouse_getPosition((const sfWindow*)window);

    if (e->type == sfEvtKeyPressed && e->key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (e->type == sfEvtMouseButtonPressed && p.x > 0 && p.y > 895
    && p.x < 240 && p.y < 953) {
        rdr->bns.plane.arrival = 0;
        sfMusic_stop(rdr->m);
        page_debut(window, rdr);
        return;
    }
    if (e->type == sfEvtMouseButtonPressed && p.x > 570 && p.y > 890
    && p.x < 790 && p.y < 954) {
        rdr->bns.plane.arrival = 0;
        sfMusic_stop(rdr->m);
        menu(window, rdr);
        return;
    }
}

void destroy_checker(menu_t *menu)
{
    sfSprite_destroy(menu->A.key);
    sfTexture_destroy(menu->A.T);
    sfText_destroy(menu->A.text);
    sfFont_destroy(menu->A.font);
    sfText_destroy(menu->B.text);
    sfFont_destroy(menu->B.font);
    sfText_destroy(menu->C.text);
    sfFont_destroy(menu->C.font);
    sfText_destroy(menu->D.text);
    sfFont_destroy(menu->D.font);
    sfText_destroy(menu->E.text);
    sfFont_destroy(menu->E.font);
    sfText_destroy(menu->F.text);
    sfFont_destroy(menu->F.font);
}

void checker_result(sfRenderWindow *win, radar_t *r)
{
    menu_t menu;

    checker_menu_init(&menu, r);
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &menu.A.e)) {
            event_close(win, &menu.A.e, r);
        }
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, menu.A.key, NULL);
        sfRenderWindow_drawText(win, menu.A.text, NULL);
        sfRenderWindow_drawText(win, menu.B.text, NULL);
        sfRenderWindow_drawText(win, menu.C.text, NULL);
        sfRenderWindow_drawText(win, menu.D.text, NULL);
        sfRenderWindow_drawText(win, menu.E.text, NULL);
        sfRenderWindow_drawText(win, menu.F.text, NULL);
        sfRenderWindow_display(win);
    }
    destroy_checker(&menu);
}
