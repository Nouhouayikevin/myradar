/*
** EPITECH PROJECT, 2024
** the initialisation of the menu
** File description:
** menu of radar
*/

#include "my.h"

static void menu_initialisation2(menu_t *menu)
{
    menu->A.R = sfRectangleShape_create();
    sfRectangleShape_setFillColor(menu->A.R, sfTransparent);
    sfRectangleShape_setPosition(menu->A.R, (sfVector2f){750, 455});
    sfRectangleShape_setSize(menu->A.R, (sfVector2f){500, 200});
    menu->A.text = sfText_create();
    menu->A.font = sfFont_createFromFile("font/Dimsum Week.ttf");
    sfText_setFont(menu->A.text, menu->A.font);
    sfText_setString(menu->A.text, "MY_RADAR");
    sfText_setCharacterSize(menu->A.text, 50);
    sfText_setPosition(menu->A.text, (sfVector2f){760, 450});
    sfRectangleShape_setOutlineThickness(menu->A.R, 3);
    sfRectangleShape_setOutlineColor(menu->A.R, sfYellow);
}

static void menu_initialisation1(menu_t *menu, char **choice)
{
    sfVector2f s = {2, 2};
    sfVector2f p = {0};

    menu->A.key = sp_creator("Images/map.png", p, (sfVector2f){1.9, 1.9}, 0);
    menu->A.c = sfClock_create();
    menu->A.T = sfTexture_createFromFile(choice[0], NULL);
    sfSprite_setTexture(menu->A.key, menu->A.T, sfTrue);
    menu->B.key = sp_creator("Images/planer1.png", p,
    (sfVector2f){1.8, 1.8}, 0);
    menu->B.c = sfClock_create();
    menu->B.T = sfTexture_createFromFile(choice[1], NULL);
    sfSprite_setTexture(menu->B.key, menu->B.T, sfTrue);
    menu->C.key = sp_creator(choice[0], p, s, 0);
    menu->C.c = sfClock_create();
    menu->C.T = sfTexture_createFromFile(choice[2], NULL);
    sfSprite_setTexture(menu->C.key, menu->C.T, sfTrue);
}

static void menu_initialisation3(menu_t *menu)
{
    menu->B.text = sfText_create();
    menu->B.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->B.text, menu->B.font);
    sfText_setString(menu->B.text, "simulation");
    sfText_setCharacterSize(menu->B.text, 50);
    sfText_setPosition(menu->B.text, (sfVector2f){0, 0});
    sfText_setOutlineThickness(menu->B.text, 2);
    sfText_setOutlineColor(menu->B.text, sfWhite);
    sfText_setColor(menu->B.text, sfGreen);
    menu->C.text = sfText_create();
    menu->C.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->C.text, menu->C.font);
    sfText_setString(menu->C.text, "simulation unit_test");
    sfText_setCharacterSize(menu->C.text, 50);
    sfText_setPosition(menu->C.text, (sfVector2f){0, 140});
    sfText_setColor(menu->C.text, sfYellow);
    sfText_setOutlineThickness(menu->C.text, 2);
    sfText_setOutlineColor(menu->C.text, sfWhite);
    menu->D.text = sfText_create();
    menu->D.font = sfFont_createFromFile("font/Dino Care.otf");
}

static void menu_initialisation4(menu_t *menu)
{
    sfText_setCharacterSize(menu->D.text, 50);
    sfText_setPosition(menu->D.text, (sfVector2f){0, 360});
    sfText_setColor(menu->D.text, sfBlue);
    menu->E.text = sfText_create();
    menu->E.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setOutlineThickness(menu->E.text, 2);
    sfText_setOutlineColor(menu->E.text, sfWhite);
    sfText_setFont(menu->E.text, menu->E.font);
    sfText_setString(menu->E.text, "Guide");
    sfText_setOutlineThickness(menu->E.text, 2);
    sfText_setOutlineColor(menu->E.text, sfWhite);
    sfText_setCharacterSize(menu->E.text, 50);
    sfText_setPosition(menu->E.text, (sfVector2f){0, 260});
    sfText_setColor(menu->E.text, sfRed);
    sfText_setFont(menu->D.text, menu->D.font);
    sfText_setOutlineThickness(menu->D.text, 2);
    sfText_setOutlineColor(menu->D.text, sfWhite);
    sfText_setString(menu->D.text, "Exit");
    sfText_setOutlineThickness(menu->D.text, 2);
    sfText_setOutlineColor(menu->D.text, sfWhite);
}

void menu_initialisation(menu_t *menu)
{
    char *choice[] = {"Images/plane2.png", "Images/plane3.png",
    "Images/planer1.png", "Images/logo.png", NULL};
    sfVector2f p = {0};
    sfVector2f s = {2, 2};

    menu_initialisation1(menu, choice);
    menu->C.m = sfMusic_createFromFile("music/sunshine.ogg");
    menu->D.key = sp_creator("Images/logo.png", (sfVector2f){750, 320},
    (sfVector2f){1, 1}, 0);
    menu->D.T = sfTexture_createFromFile(choice[3], NULL);
    sfSprite_setTexture(menu->D.key, menu->D.T, sfTrue);
    menu->E.key = sp_creator("Images/plane5.png", (sfVector2f){680, 500},
    (sfVector2f){0.5, 0.5}, 0);
    menu->E.T = sfTexture_createFromFile("Images/plane5.png", NULL);
    sfSprite_setTexture(menu->E.key, menu->E.T, sfTrue);
    menu->E.vecp = (sfVector2f){660, 450};
    menu_initialisation2(menu);
    menu_initialisation3(menu);
    menu_initialisation4(menu);
}
