/*
** EPITECH PROJECT, 2024
**  the help option for my bonus
** File description:
** radar bonus
*/

#include "bonus.h"
int error_bns(int ac, char **av)
{
    struct stat s;

    if (ac == 2 && my_strcmp(av[1], "-h") != 0) {
        if (stat(av[1], &s) == -1) {
            my_put("Filepath error!!. Try '-h' option for more understanding");
            return (84);
        }
    } else
        return 0;
    if ((ac == 3 && my_strcmp(av[2], "-b") == 0 &&  stat(av[1], &s) == 0)
    || (ac == 3 && my_strcmp(av[1], "-b") == 0 &&  stat(av[2], &s) == 0)) {
        return 0;
    } else {
        my_put("no bonus script!. Try '-h' option for more understanding");
        return (84);
    }
}

int help_bns(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
    my_put("./my_radar: bad arguments:\n");
    my_put("You tried a simulation and it's failed because of wrongs parameters\n");
        return (84);
    }
    if (error_bns(ac, av) == 84)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help_t();
        return (0);
    }
}