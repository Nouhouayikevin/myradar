/*
** EPITECH PROJECT, 2024
** the main function of Radar
** File description:
** the function principal
*/

#include "my.h"

int main(int ac, char **av)
{
    sfRenderWindow *window = NULL;
    radar_t rdr;

    if (help(ac, av) == 84)
        return 84;
    if (parse(av[1], &rdr) == 84)
        return 84;
    free_radar(&rdr);
    rdr.str = my_strdump(av[1]);
    window = init_win();
    rdr.simulation = 0;
    rdr.bns.compiled = 0;
    rdr.crash = 0;
    menu(window, &rdr);
    sfRenderWindow_destroy(window);
    free(rdr.str);
    free_radar(&rdr);
    return 0;
}
