/*
** EPITECH PROJECT, 2021
** new map
** File description:
** and -h functions
*/

#include "librunner.h"

int size(char **av)
{
    struct stat bufsize;

    stat(av[1], &bufsize);
    return (bufsize.st_size);
}

int new_map(char **av, context_t *context)
{
    int fd = 0;
    char *map = malloc(sizeof(char) * size(av));

    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        my_putstr("FAILURE\n");
        return (84);
    }
    read(fd, map, size(av));
    context->map = map;
    return (0);
}

int help_man(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'
    && (my_strlen(av[1]) == 2)) {
        my_putstr("Welcome to firefighter!\nRules:\n");
        my_putstr("-Have fun\n-Press esc to exit\n");
        my_putstr("-Press space to jump\n-Press x to kick\n");
        my_putstr("When the ball is on the ground jump");
        my_putstr(", when it is face-level kick\n");
        my_putstr("You have 1 live and you need to pass 20 balls to win\n");
        return (1);
    }
    return (0);
}