/*
** EPITECH PROJECT, 2024
** the main of my bonus for radar
** File description:
** the one plane test
*/

#include "bonus.h"
int main(int ac, char **av)
{
    sfRenderWindow *window = NULL;
    radar_t rdr;

    if (help_bns(ac, av) == 84)
        return 84;
    if (ac == 2)
        return 0;
    if (my_strcmp(av[1], "-b") != 0)
        rdr.str = my_strdump(av[1]);
    else
        rdr.str = my_strdump(av[2]);
    if (parse_bns(rdr.str, &rdr) == 84)
        return 84;
    window = init_win();
    rdr.bns.compiled = 1;
    rdr.simulation = 0;
    rdr.crash = 0;
    menu(window, &rdr);
    sfRenderWindow_destroy(window);
    free(rdr.str);
    return 0;
}
