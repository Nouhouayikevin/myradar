/*
** EPITECH PROJECT, 2024
** the collision checker of the bns plne
** File description:
** to calculate travel security
*/

#include "my.h"

void set_text_e_1(menu_t *menu, radar_t *r)
{
    menu->E.text = sfText_create();
    menu->E.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->E.text, menu->E.font);
    sfText_setString(menu->E.text, "GOOD");
    sfText_setCharacterSize(menu->E.text, 40);
    sfText_setColor(menu->E.text, sfGreen);
    sfText_setPosition(menu->E.text, (sfVector2f){580, 770});
}

void set_text_e_2(menu_t *menu, radar_t *r)
{
    menu->E.text = sfText_create();
    menu->E.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->E.text, menu->E.font);
    sfText_setString(menu->E.text, "MEDIUM");
    sfText_setColor(menu->E.text, sfYellow);
    sfText_setCharacterSize(menu->E.text, 40);
    sfText_setPosition(menu->E.text, (sfVector2f){580, 770});
}

void set_text_e_3(menu_t *menu, radar_t *r)
{
    menu->E.text = sfText_create();
    menu->E.font = sfFont_createFromFile("font/Dino Care.otf");
    sfText_setFont(menu->E.text, menu->E.font);
    sfText_setString(menu->E.text, "BAD");
    sfText_setColor(menu->E.text, sfRed);
    sfText_setCharacterSize(menu->E.text, 40);
    sfText_setPosition(menu->E.text, (sfVector2f){580, 770});
}

void set_text_e_4(int i, char *choice[], menu_t *menu)
{
    srand(time(NULL));
    if (i > 2)
        i = rand() % (1 - 0 + 1);
    if (i == 1)
        i = rand() % (3 - 2 + 1) + 2;
    if (i < 1)
        i = rand() % (5 - 4 + 1) + 4;
    menu->F.text = sfText_create();
    menu->F.font = sfFont_createFromFile("font/falling_sky.otf");
    sfText_setFont(menu->F.text, menu->F.font);
    sfText_setString(menu->F.text, choice[i]);
    sfText_setColor(menu->F.text, sfBlack);
    sfText_setCharacterSize(menu->F.text, 40);
    sfText_setPosition(menu->F.text, (sfVector2f){1020, 200});
}
