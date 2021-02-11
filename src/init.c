/*
** EPITECH PROJECT, 2020
** init
** File description:
** initialise functions here
*/

#include "librunner.h"

character_t init_ball(character_t ch, context_t context)
{
    sfVector2f scale_ball = {0.2, 0.2};

    ch.ball_txt = sfTexture_createFromFile("src/char/fireball.png", NULL);
    ch.ball_spr = sfSprite_create();
    ch.ball_pos.x = 1600;
    if (context.map[0] == '0')
        ch.ball_pos.y = 860;
    else
        ch.ball_pos.y = 700;
    ch.ball_direction = -1;
    ch.ball_speed = 20;
    sfSprite_setScale(ch.ball_spr, scale_ball);
    return (ch);
}

character_t init_char(character_t ch, context_t context)
{
    sfVector2f scale_ship = {3, 3};

    ch.ship_txt = sfTexture_createFromFile("src/char/fighter.png", NULL);
    ch.ship_spr = sfSprite_create();
    ch.ship_pos.x = 90;
    ch.ship_pos.y = 740;
    ch.ship_rect.width = 70;
    ch.ship_rect.height = 80;
    ch.ship_rect.top = 80;
    ch.ship_rect.left = 0;
    ch = init_ball(ch, context);
    sfSprite_setScale(ch.ship_spr, scale_ship);
    return (ch);
}

back_t init_back(back_t back)
{
    back.sky_txt = sfTexture_createFromFile("src/back/Sky.png", NULL);
    back.sky_spr = sfSprite_create();
    back.sky_pos.x = 0;
    back.sky_pos.y = 0;
    back.mount_txt = sfTexture_createFromFile("src/back/Mountains.png", NULL);
    back.mount_spr = sfSprite_create();
    back.mount_pos.x = 0;
    back.mount_pos.y = 0;
    back.forest_txt = sfTexture_createFromFile("src/back/Forest.png", NULL);
    back.forest_spr = sfSprite_create();
    back.forest_pos.x = 0;
    back.forest_pos.y = 0;
    setter(&back);
    return (back);
}

backw_t init_backw(backw_t backw)
{
    backw.skyw_txt = sfTexture_createFromFile("src/backw/Skyw.png", NULL);
    backw.skyw_spr = sfSprite_create();
    backw.skyw_pos.x = 1920;
    backw.skyw_pos.y = 0;
    backw.mountw_txt = sfTexture_createFromFile("src/backw/Mountw.png", NULL);
    backw.mountw_spr = sfSprite_create();
    backw.mountw_pos.x = 1920;
    backw.mountw_pos.y = 0;
    backw.forestw_txt = sfTexture_createFromFile("src/backw/Forw.png", NULL);
    backw.forestw_spr = sfSprite_create();
    backw.forestw_pos.x = 1920;
    backw.forestw_pos.y = 0;
    setterw(&backw);
    return (backw);
}

context_t init_context(context_t co)
{
    co.video.width = 1920;
    co.video.height = 1080;
    co.video.bitsPerPixel = 32;
    co.window = sfRenderWindow_create(co.video, "RUN", sfDefaultStyle, NULL);
    co.event;
    co.clock = sfClock_create();
    co.time;
    co.seconds = 0;
    co.turn = 1;
    co.letter = sfFont_createFromFile("src/char/Pixeled.ttf");
    co.text = sfText_create();
    return (co);
}