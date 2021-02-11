/*
** EPITECH PROJECT, 2020
** events
** File description:
** move and close
*/

#include "librunner.h"

sfVector2f handle_events(sfEvent ent, sfVector2f pos, character_t *ch, int *x)
{
    if (ent.key.code == sfKeySpace && (ch->ship_rect.top == 80)) {
        ch->ship_rect.top = 640;
        ch->ship_rect.left = 0;
        *x = 6;
    } else if (ent.key.code == sfKeyX && (ch->ship_rect.top == 80)) {
        ch->ship_rect.top = 560;
        ch->ship_rect.left = 0;
        *x = 15;
    }
    return (pos);
}

void move_rect(sfIntRect *ship_rect, int offset, int max_value)
{
    ship_rect->left += offset;
    if (ship_rect->left == max_value) {
        ship_rect->left = 0;
        ship_rect->top = 80;
    }
}