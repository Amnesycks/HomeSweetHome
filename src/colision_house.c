/*
** EPITECH PROJECT, 2019
** Home Sweet Home
** File description:
** colision with house
*/

#include "ggj.h"

int is_wall(player *players)
{
    if (players->vector.y >= 700 && players->vector.y < 900 &&
        players->vector.x >= 700 && players->vector.x <= 710)
        return (1);
    if (players->vector.y >= 700 && players->vector.y < 900 &&
        players->vector.x >= 1185 && players->vector.x <= 1195)
        return (1);
    return (0);
}
