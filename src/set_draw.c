/*
** EPITECH PROJECT, 2021
** set and draw functions
** File description:
** set and draw
*/

#include "librunner.h"

void drawer(context_t *context, back_t *back, backw_t *backw, character_t *ch)
{
    sfRenderWindow_drawSprite(context->window, back->sky_spr, NULL);
    sfRenderWindow_drawSprite(context->window, backw->skyw_spr, NULL);
    sfRenderWindow_drawSprite(context->window, back->mount_spr, NULL);
    sfRenderWindow_drawSprite(context->window, backw->mountw_spr, NULL);
    sfRenderWindow_drawSprite(context->window, ch->ship_spr, NULL);
    sfRenderWindow_drawSprite(context->window, ch->ball_spr, NULL);
    sfRenderWindow_drawSprite(context->window, back->forest_spr, NULL);
    sfRenderWindow_drawSprite(context->window, backw->forestw_spr, NULL);
}

void positioner(back_t *back, backw_t *backw, character_t *ch)
{
    sfSprite_setTexture(ch->ship_spr, ch->ship_txt, sfFalse);
    sfSprite_setTexture(ch->ball_spr, ch->ball_txt, sfFalse);
    sfSprite_setTextureRect(ch->ship_spr, ch->ship_rect);
    sfSprite_setPosition(ch->ship_spr, ch->ship_pos);
    sfSprite_setPosition(ch->ball_spr, ch->ball_pos);
    sfSprite_setPosition(backw->mountw_spr, backw->mountw_pos);
    sfSprite_setPosition(back->mount_spr, back->mount_pos);
    sfSprite_setPosition(backw->forestw_spr, backw->forestw_pos);
    sfSprite_setPosition(back->forest_spr, back->forest_pos);
    sfSprite_setPosition(backw->skyw_spr, backw->skyw_pos);
    sfSprite_setPosition(back->sky_spr, back->sky_pos);
}

void setter(back_t *back)
{
    sfVector2f scale = {7.1, 6.4};

    sfSprite_setTexture(back->forest_spr, back->forest_txt, sfFalse);
    sfSprite_setTexture(back->mount_spr, back->mount_txt, sfFalse);
    sfSprite_setTexture(back->sky_spr, back->sky_txt, sfFalse);
    sfSprite_setScale(back->sky_spr, scale);
    sfSprite_setScale(back->mount_spr, scale);
    sfSprite_setScale(back->forest_spr, scale);
}

void setterw(backw_t *backw)
{
    sfVector2f scale = {7.1, 6.4};

    sfSprite_setTexture(backw->forestw_spr, backw->forestw_txt, sfFalse);
    sfSprite_setTexture(backw->mountw_spr, backw->mountw_txt, sfFalse);
    sfSprite_setTexture(backw->skyw_spr, backw->skyw_txt, sfFalse);
    sfSprite_setScale(backw->skyw_spr, scale);
    sfSprite_setScale(backw->mountw_spr, scale);
    sfSprite_setScale(backw->forestw_spr, scale);
}