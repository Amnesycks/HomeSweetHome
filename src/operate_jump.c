/*
** GLOBAL GAME JAM, 2019
** Home
** File description:
** Operate jump
*/

#include "ggj.h"
#include <stddef.h>
#include <SFML/Graphics.h>

void operate_jumps_p1(player *players, sfClock *clock, platform *platforms)
{
    static int height = 0;
    static int end_jump = 0;

    if (players->jump == 1) {
        if (sfClock_getElapsedTime(clock).microseconds > 3500) {
            if (height < 450 && end_jump == 0) {
                players->vector.y -= 3;
                height += 5;
		players->rect.left = 60;
            }
            if (height >= 450) {
                end_jump = 1;
		players->rect.left = 120;
	    }
            if (end_jump == 1 && on_platform(platforms, players) == 1) {
                players->jump = 0;
                height = 0;
                end_jump = 0;
            }
            else if (end_jump == 1 && on_platform(platforms, players) != 1)
                players->vector.y += 3;
            sfClock_restart(clock);
	}
    }
}

void operate_jumps_p2(player *players, sfClock *clock, platform *platforms)
{
    static int height = 0;
    static int end_jump = 0;

    if (players->jump == 1) {
        if (sfClock_getElapsedTime(clock).microseconds > 5500) {
            if (height < 450 && end_jump == 0) {
                players->vector.y -= 3;
                height += 5;
		players->rect.left = 60;
            }
            if (height >= 450) {
                end_jump = 1;
		players->rect.left = 120;
	    }
            if (end_jump == 1 && on_platform(platforms, players) == 1) {
                players->jump = 0;
                height = 0;
                end_jump = 0;
            }
            else if (end_jump == 1 && on_platform(platforms, players) != 1)
                players->vector.y += 3;
            sfClock_restart(clock);
        }
    }
}
