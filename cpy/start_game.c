/*
** EPITECH PROJECT, 2019
** start game
** File description:
** start of game
*/

#include <SFML/Graphics.h>
#include "ggj.h"

sfRenderWindow *initiate_window(void)
{
    sfRenderWindow *home = NULL;
    sfVideoMode video_mode = {1920, 1080, 32};

    home = sfRenderWindow_create(video_mode, "home", sfDefaultStyle, NULL);
    return (home);
}

void toggle_jump(sfEvent event, player *players)
{
    if (event.key.code == sfKeySpace)
        players->jump = 1;
}

void toggle_event_player_one(sfEvent event, player *players)
{
    if (event.key.code == sfKeyQ && players->direction == 2) {
        players->direction = 0;
        players->rect.left = 0;
    }
    else if (event.key.code == sfKeyQ && players->direction != 2) {
        players->direction = 1;
        players->vector.x -= 10;
        players->rect.left += 100;
        if (players->rect.left >= 600)
            players->rect.left = 0;
    }
    if (event.key.code == sfKeyD && players->direction == 1) {
        players->direction = 0;
        players->rect.left = 0;
    }
    else if (event.key.code == sfKeyD && players->direction != 1) {
        players->direction = 2;
        players->vector.x += 10;
        players->rect.left += 100;
        if (players->rect.left >= 600)
            players->rect.left = 0;
    }
    toggle_jump(event, players);
    //_Bool LeftKey = event.key.code == sfKeyD;
    toggle_event_player_two(event, players->next);
}

void toggle_event_player_two(sfEvent event, player *players)
{
    if (event.key.code == sfKeyK && players->direction == 2) {
        players->direction = 0;
        players->rect.left = 0;
    }
    else if (event.key.code == sfKeyK && players->direction != 2) {
        players->direction = 1;
        players->vector.x -= 10;
        players->rect.left += 100;
        if (players->rect.left >= 600)
            players->rect.left = 0;
    }
    if (event.key.code == sfKeyM && players->direction == 1) {
        players->direction = 0;
        players->rect.left = 0;
    }
    else if (event.key.code == sfKeyM && players->direction != 1) {
        players->direction = 2;
        players->vector.x += 10;
        players->rect.left += 100;
        if (players->rect.left >= 600)
            players->rect.left = 0;
    }
}

void do_events(sfRenderWindow *home, sfEvent event, player *players)
{
    while (sfRenderWindow_pollEvent(home, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(home);
        if (event.type == sfEvtKeyPressed)
            toggle_event_player_one(event, players);
    }
}

void display_background(sfRenderWindow *home, texture *textures, house *houses)
{
    sfSprite *sprite = sfSprite_create();
    house *elem = houses;
    sfVector2f pos = {10, 700};

    sfSprite_setTexture(sprite, textures->background, sfTrue);
    sfRenderWindow_drawSprite(home, sprite, NULL);
    for (; elem != NULL; elem = elem->next) {
        if (elem->sofa == 1) {
            sfSprite_setTexture(sprite, textures->sofa, sfTrue);
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(home, sprite, NULL);
        }
        pos.x += 200;
        if (elem->tv == 1) {
            sfSprite_setTexture(sprite, textures->tv, sfTrue);
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(home, sprite, NULL);
        }
        pos.x += 200;
        if (elem->lamp == 1) {
            sfSprite_setTexture(sprite, textures->lamp, sfTrue);
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(home, sprite, NULL);
        }
        pos.x += 200;
        if (elem->photo == 1) {
            sfSprite_setTexture(sprite, textures->photo, sfTrue);
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(home, sprite, NULL);
        }
        pos.x += 200;
        if (elem->trophee == 1) {
            sfSprite_setTexture(sprite, textures->trophee, sfTrue);
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(home, sprite, NULL);
        }
        pos.x += 200;
    }
    sfSprite_destroy(sprite);
}

void display_players(sfRenderWindow *home, player *players, texture *textures)
{
    sfSprite *sprite = sfSprite_create();
    player *elem = players;

    for (; elem != NULL; elem = elem->next) {
        if (elem->direction == 0)
            sfSprite_setTexture(sprite, textures->player_static, sfTrue);
        if (elem->direction == 1)
            sfSprite_setTexture(sprite, textures->player_left, sfTrue);
        if (elem->direction == 2)
            sfSprite_setTexture(sprite, textures->player_right, sfTrue);
        sfSprite_setTextureRect(sprite, elem->rect);
        sfSprite_setPosition(sprite, elem->vector);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    sfSprite_destroy(sprite);
}

void display_platforms(sfRenderWindow *home, texture *textures, platform *platforms)
{
    platform *elem = platforms;
    sfSprite *sprite = sfSprite_create();

    for (; elem != NULL; elem = elem->next) {
        sfSprite_setTexture(sprite, textures->platform, sfTrue);
        sfSprite_setPosition(sprite, elem->vector);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    sfSprite_destroy(sprite);
}

int on_platform(platform *platforms, player *players)
{
    platform *elem = platforms;

    for (; elem != NULL; elem = elem->next) {
        if ((players->vector.y + 90 <= elem->y &&
            players->vector.y + 92 >= elem->y) &&
            (players->vector.x >= elem->x &&
            players->vector.x + 30 <= elem->x_end)) {
            players->vector.y = elem->y - 90;
            return (1);
        }
    }
    return (0);
}

void operate_jumps(player *players, sfClock *clock, platform *platforms)
{
    static int height = 0;
    static int end_jump = 0;

    if (players->jump == 1) {
        if (sfClock_getElapsedTime(clock).microseconds > 10000) {
            if (height < 200 && end_jump == 0) {
                players->vector.y -= 3;
                height += 3;
            }
            if (height >= 200)
                end_jump = 1;
            if (end_jump == 1 && on_platform(platforms, players) == 1) {
                players->jump = 0;
                height = 0;
                end_jump = 0;
            }
            else if (end_jump == 1 && height > 0) {
                players->vector.y += 3;
                height -= 3;
            }
            if (end_jump == 1 && height <= 0) {
                players->jump = 0;
                height = 0;
                end_jump = 0;
            }
            sfClock_restart(clock);
        }
    }
}

void compute_fall(player *players, platform *platforms)
{
    static int fall = 0;
    platform *elem = platforms;

    for (; elem != NULL; elem = elem->next) {
        printf("%d and %d\n", *players.vector.x, players->vector.x);
        if (*players.vector.x + 60 < elem->x ||
            players->vector.x + 30 > elem->x_end)
            fall = 1;
    }
    if (fall == 1) {
        players->vector.y += 4;
    }
}

void start_home(player *players, house *houses, texture *textures, platform *platforms)
{
    sfEvent event;
    sfRenderWindow *home = initiate_window();
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(home)) {
        display_background(home, textures, houses);
        display_platforms(home, textures, platforms);
        compute_fall(players, platforms);
        operate_jumps(players, clock, platforms);
        display_players(home, players, textures);
        sfRenderWindow_display(home);
        do_events(home, event, players);
    }
}
