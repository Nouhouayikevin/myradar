/*
** EPITECH PROJECT, 2024
** the help for radar
** File description:
** of the project
*/

#include "my.h"

void help_t(void)
{
    my_put("Air traffic simulation panel\n\n");
    my_put("USAGE\n ./my_radar [OPTIONS] path_to_script\n");
    my_put("  path_to_script    The path to the script file.\n\n");
    my_put("OPTIONS\n -h\t\t   print the usage and quit.\n");
    my_put(" -b\t\t   to activate the 'simulation_unit_test'\n\n");
    my_put("USER INTERACTIONS\n 'L' key\tenable/disable hitboxes");
    my_put(" and areas.\n");
    my_put(" 'S' key\tenable/disable sprites.\n");
    my_put(" 'N' key\tenable/disable (Night or Day)\n");
    my_put(" 'M' key\tenable/disable Music\n");
    my_put(" 'SPACE' key\tplay/pause (simulation/simulation_unit_test)\n");
}

int error(int ac, char **av)
{
    int a = 0;
    struct stat s;

    if (ac == 2 && my_strcmp(av[1], "-h") != 0) {
        a = stat(av[1], &s);
        if (a == -1) {
            my_put("Filepath error!!. Try '-h' option for more understanding");
            return (84);
        }
        a = 1;
    }
    if (a != 1 && my_strcmp(av[1], "-h") != 0 && a != -1) {
        my_put("Bad argument try '-h'!\n");
        return (84);
    }
}

int help(int ac, char **av)
{
    if (ac != 2) {
        my_put("./my_radar: bad arguments: ");
        my_putnbr(ac - 1);
        my_put(" given but 84 is required\nretry with -h\n");
        return (84);
    }
    if (error(ac, av) == 84)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help_t();
        return (0);
    }
}
