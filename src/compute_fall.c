/*
** GLOBAL GAME JAM, 2019
** HOme
** File description:
** Compute Fall
*/

#include <stddef.h>
#include <stdlib.h>
#include "ggj.h"

void compute_fall_p1(player *players, platform *platforms)
{
    static int fall = 0;
    platform *elem = platforms;

    for (; elem != NULL; elem = elem->next) {
        if ((players->jump == 0) && (
             players->vector.y + 90 > elem->y ||
             players->vector.y + 92 < elem->y) &&
            (players->vector.x + 60 < elem->x ||
             players->vector.x + 30 > elem->x_end))
            fall = 1;
    }
    for (elem = platforms; elem != NULL; elem = elem->next) {
        if ((players->vector.y + 90 <= elem->y &&
             players->vector.y + 92 >= elem->y) &&
            (players->vector.x  + 60 >= elem->x &&
             players->vector.x + 30 <= elem->x_end)){
            players->vector.y = elem->y - 90;
            fall = 0;
        }
    }
    if (players->vector.y + 90 >= 1020.0 &&
        players->vector.y + 92 >= 1020.0 &&
        players->vector.x >= -50.0 && players->vector.x + 30 <= 1900) {
            players->vector.y = 930;
            fall = 0;
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= -50.0 && players->vector.x + 30 <= 656.0) {
        players->vector.y = 540;
        fall = 0;
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 1200.0 && players->vector.x + 30 <= 1900.0) {
        players->vector.y = 540;
        fall = 0;
    }
    if (fall == 1)
        players->vector.y += 4;
    free(elem);
}

void compute_fall_p2(player *players, platform *platforms)
{
    static int fall = 0;
    platform *elem = platforms;

    for (; elem != NULL; elem = elem->next) {
        if ((players->jump == 0) && (
             players->vector.y + 90 > elem->y ||
             players->vector.y + 92 < elem->y) &&
            (players->vector.x + 60 < elem->x ||
             players->vector.x + 30 > elem->x_end))
            fall = 1;
    }
    for (elem = platforms; elem != NULL; elem = elem->next) {
        if ((players->vector.y + 90 <= elem->y &&
             players->vector.y + 92 >= elem->y) &&
            (players->vector.x  + 60 >= elem->x &&
             players->vector.x + 30 <= elem->x_end)){
            players->vector.y = elem->y - 90;
            fall = 0;
        }
    }
    if (players->vector.y + 90 >= 1020.0 &&
        players->vector.y + 92 >= 1020.0 &&
        players->vector.x >= -50.0 && players->vector.x + 30 <= 1900) {
            players->vector.y = 930;
            fall = 0;
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= -50.0 && players->vector.x + 30 <= 656.0) {
        players->vector.y = 540;
        fall = 0;
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 1200.0 && players->vector.x + 30 <= 1900.0) {
        players->vector.y = 540;
        fall = 0;
    }
    if (fall == 1)
        players->vector.y += 4;
    free(elem);
}
