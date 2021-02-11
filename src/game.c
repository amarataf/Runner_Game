/*
** EPITECH PROJECT, 2021
** main game functionality
** File description:
** main game functions
*/

#include "librunner.h"

int hitbox(character_t *ch)
{
    if (ch->ball_pos.x > 80 && ch->ball_pos.x < 200 &&
    ch->ship_pos.y == 740 && ch->ball_pos.y == 860)
        return (1);
    if (ch->ball_pos.x > 80 && ch->ball_pos.x < 200 &&
    ch->ship_rect.top != 560 && ch->ball_pos.y == 700)
        return (1);
    if (ch->ball_pos.x > 80 && ch->ball_pos.x < 200 &&
    ch->ship_rect.top == 560 && ch->ball_pos.y == 700)
        ch->ball_direction = 1;
    return (0);
}

void ball_face(character_t *ch, context_t *con)
{
    if (ch->ball_direction == 1) {
        ch->ball_pos.x = ch->ball_pos.x + 100;
        ch->ball_pos.y = ch->ball_pos.y - 80;
        if (ch->ball_pos.x >= 1920 || ch->ball_pos.y <= -50) {
            ch->ball_pos.x = 1920;
            if (con->map[con->turn] == '0')
                ch->ball_pos.y = 860;
            if (con->map[con->turn] == '1')
                ch->ball_pos.y = 700;
            con->turn = con->turn + 1;
            ch->ball_direction = -1;
            ch->ball_speed = ch->ball_speed + 3;
        }
    }
}

void ball_ground(character_t *ch, context_t *con)
{
    if (ch->ball_direction == -1) {
        ch->ball_pos.x = ch->ball_pos.x - ch->ball_speed;
        if (ch->ball_pos.x <= -50) {
            ch->ball_pos.x = 1920;
            if (con->map[con->turn] == '0')
                ch->ball_pos.y = 860;
            if (con->map[con->turn] == '1')
                ch->ball_pos.y = 700;
            con->turn = con->turn + 1;
            ch->ball_speed = ch->ball_speed + 3;
        }
    }
}

char *int_to_str(int turn)
{
    char *str = malloc(sizeof(char) * 3);
    if (turn < 10) {
        str[0] = turn + 48;
        str[1] = '\0';
    } else if (turn >= 10) {
        str[0] = '1';
        str[1] = turn - 10 + 48;
    }
    str[2] = '\0';
    return (str);
}

int is_open(backw_t *backw, back_t *back, context_t *context, character_t *ch)
{
    int spawn = 0;
    int ret = 0;
    sfVector2f score = {955, 950};

    move_mountain(back, backw);
    move_sky(back, backw);
    move_forest(back, backw);
    ball_ground(ch, context);
    ball_face(ch, context);
    sfRenderWindow_clear(context->window, sfBlack);
    positioner(back, backw, ch);
    sfText_setString(context->text, int_to_str(context->turn - 1));
    sfText_setPosition(context->text, score);
    sfText_setFont(context->text, context->letter);
    sfText_setCharacterSize(context->text, 50);
    drawer(context, back, backw, ch);
    sfRenderWindow_drawText(context->window, context->text, NULL);
    ret = hitbox(ch);
    return (ret);
}