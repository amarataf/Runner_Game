/*
** EPITECH PROJECT, 2021
** backgrounds
** File description:
** backgrounds
*/

#include "librunner.h"

void move_mountain(back_t *back, backw_t *backw)
{
    back->mount_pos.x = back->mount_pos.x - 2;
    backw->mountw_pos.x = backw->mountw_pos.x - 2;
    if (backw->mountw_pos.x == 0)
        back->mount_pos.x = 1920;
    if (back->mount_pos.x == 0)
        backw->mountw_pos.x = 1920;
}

void move_sky(back_t *back, backw_t *backw)
{
    back->sky_pos.x = back->sky_pos.x - 2;
    backw->skyw_pos.x = backw->skyw_pos.x - 2;
    if (backw->skyw_pos.x == 0)
        back->sky_pos.x = 1920;
    if (back->sky_pos.x == 0)
        backw->skyw_pos.x = 1920;
}

void move_forest(back_t *back, backw_t *backw)
{
    back->forest_pos.x = back->forest_pos.x - 5;
    backw->forestw_pos.x = backw->forestw_pos.x - 5;
    if (backw->forestw_pos.x == 0)
        back->forest_pos.x = 1920;
    if (back->forest_pos.x == 0)
        backw->forestw_pos.x = 1920;
}