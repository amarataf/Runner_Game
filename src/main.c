/*
** EPITECH PROJECT, 2020
** window
** File description:
** window try
*/

#include "librunner.h"

int frame(character_t *ch, int x, context_t *context)
{
    if (x > 0 && x < 7) {
        move_rect(&ch->ship_rect, 70, 420);
        if (x >= 4)
            ch->ship_pos.y = ch->ship_pos.y - 80;
        else
            ch->ship_pos.y = ch->ship_pos.y + 80;
        x--;
    } else if (x > 10 && x < 16) {
        move_rect(&ch->ship_rect, 70, 350);
        x--;
    } else
        move_rect(&ch->ship_rect, 70, 280);
    sfClock_restart(context->clock);
    return (x);
}

void start(backw_t backw, character_t ch, back_t back, context_t context)
{
    int x = 0;
    int hit = 0;

    sfRenderWindow_setFramerateLimit(context.window, 40);
    while (sfRenderWindow_isOpen(context.window)) {
        sfRenderWindow_display(context.window);
        context.time = sfClock_getElapsedTime(context.clock);
        context.seconds = (context.time.microseconds / 1000000.0);
        if (context.seconds > 0.1)
            x = frame(&ch, x, &context);
        hit = is_open(&backw, &back, &context, &ch);
        if (hit == 1 || context.turn == 21)
            sfRenderWindow_close(context.window);
        while (sfRenderWindow_pollEvent(context.window, &context.event)) {
            ch.ship_pos = handle_events(context.event, ch.ship_pos, &ch, &x);
            if (context.event.type == sfEvtClosed
            || context.event.key.code == sfKeyEscape)
                sfRenderWindow_close(context.window);
        }
    }
}

int main(int ac, char **av)
{
    int x = 0;
    int ret = 0;

    ret = help_man(ac, av);
    if (ret == 1)
        return (0);
    context_t context;
    context = init_context(context);
    ret = new_map(av, &context);
    if (ret == 84)
        return (84);
    backw_t backw;
    backw = init_backw(backw);
    character_t ch;
    ch = init_char(ch, context);
    back_t back;
    back = init_back(back);
    start(backw, ch, back, context);
    return (0);
}