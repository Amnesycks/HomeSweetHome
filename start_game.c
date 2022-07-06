/*
** EPITECH PROJECT, 2019
** start game
** File description:
** start of game
*/

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <SFML/Window/JoystickIdentification.h>
#include <SFML/Graphics.h>
#include "ggj.h"

sfRenderWindow *initiate_window(void)
{
    sfRenderWindow *home = NULL;
    sfVideoMode video_mode = {1920, 1080, 32};

    home = sfRenderWindow_create(video_mode, "home", sfFullscreen, NULL);
    return (home);
}

void toggle_jump(sfEvent event, player *players, platform *platforms)
{
    if (sfEvtJoystickButtonPressed) {
        if ((sfJoystick_isButtonPressed(0, 0) == TRUE) && (check_player_valid(players, platforms) == 1))
            players->jump = 1;
        if ((sfJoystick_isButtonPressed(1, 0) == TRUE) && (check_player_valid(players->next, platforms) == 1))
            players->next->jump = 1;
    }
}

void do_events(sfRenderWindow *home, sfEvent event, player *players, platform *platforms, sfClock *clock_move)
{
    players->joy_x = sfJoystick_getAxisPosition(0, sfJoystickX);
    players->joy_y = sfJoystick_getAxisPosition(0, sfJoystickY);
    players->next->joy_x = sfJoystick_getAxisPosition(1, sfJoystickX);
    players->next->joy_y = sfJoystick_getAxisPosition(1, sfJoystickY);
    // Ajout d'une clock
    if (sfClock_getElapsedTime(clock_move).microseconds > 55000) {
        //Conditions changées
        if (players->vector.x > 1 && players->joy_x < -20 && players->direction != 2
            && !is_wall(players)) {
            players->direction = 1;
            players->vector.x += -12;
            players->rect.left += 60;
            if (players->rect.left >= 200)
                players->rect.left = 0;
        }
        if (players->vector.x < 1919 && players->joy_x > 20 && players->direction != 1
            && !is_wall(players)) {
            players->direction = 2;
            players->vector.x += 12;
            players->rect.left += 60;
            if (players->rect.left >= 200)
                players->rect.left = 0;
        }
        if (players->joy_x < -20 && players->direction != 1) {
            players->direction = 0;
            players->rect.left = 0;
        }
        if (players->joy_x > 20 && players->direction != 2) {
            players->direction = 3;
            players->rect.left = 0;
        }

        if (players->next->vector.x > 1 && players->next->joy_x < -20 && players->next->direction != 2
            && !is_wall(players)) {
            players->next->direction = 1;
            players->next->vector.x -= 12;
            players->next->rect.left += 60;
            if (players->next->rect.left >= 200)
                players->next->rect.left = 0;
        }
        if (players->next->vector.x < 1919 && players->next->joy_x > 20 && players->next->direction != 1
            && !is_wall(players)){
            players->next->direction = 2;
            players->next->vector.x += 12;
            players->next->rect.left += 60;
            if (players->next->rect.left >= 200)
                players->next->rect.left = 0;
        }
        if (players->next->joy_x < -20 && players->next->direction != 1) {
            players->next->direction = 0;
            players->next->rect.left = 0;
        }
        if (players->next->joy_x > 20 && players->next->direction != 2) {
            players->next->direction = 3;
            players->next->rect.left = 0;
        }
        sfClock_restart(clock_move);
    }
    toggle_jump(event, players, platforms);
    while (sfRenderWindow_pollEvent(home, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(home);
}

void display_players(sfRenderWindow *home, player *players, texture *textures)
{
    sfSprite *sprite = sfSprite_create();
    player *elem = players;
    //Ajout d'une direction
    for (; elem != NULL; elem = elem->next) {
        if (elem->direction == 0)
            sfSprite_setTexture(sprite, textures->player_static_left, sfTrue); // Dans le fichier initiate structures changer les fichiers source
        if (elem->direction == 3)
            sfSprite_setTexture(sprite, textures->player_static_right, sfTrue);
        if (elem->direction == 1)
            sfSprite_setTexture(sprite, textures->left_running_left, sfTrue);
        if (elem->direction == 2)
            sfSprite_setTexture(sprite, textures->left_running_right, sfTrue);
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
            (players->vector.x  + 60 >= elem->x &&
            players->vector.x + 30 <= elem->x_end)){
            players->vector.y = elem->y - 90;
            return (1);
        }
    }
    if (players->vector.y + 90 >= 1080.0 &&
        players->vector.y + 92 >= 1080.0 &&
        players->vector.x >= 0.0 && players->vector.x + 30 <= 1920) {
            players->vector.y = 990;
            return (1);
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 0.0 && players->vector.x + 30 <= 656.0) {
        players->vector.y = 540;
            return (1);
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 1200.0 && players->vector.x + 30 <= 1920.0) {
        players->vector.y = 540;
        return (1);
    }
    
    return (0);
}

void operate_jumps_p1(player *players, sfClock *clock, platform *platforms)
{
    static int height = 0;
    static int end_jump = 0;

    if (players->jump == 1) {
        if (sfClock_getElapsedTime(clock).microseconds > 5500) {
            if (height < 300 && end_jump == 0) {
                players->vector.y -= 3;
                height += 5;
            }
            if (height >= 300)
                end_jump = 1;
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
            if (height < 300 && end_jump == 0) {
                players->vector.y -= 3;
                height += 5;
            }
            if (height >= 300)
                end_jump = 1;
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
    if (players->vector.y + 90 >= 1080.0 &&
        players->vector.y + 92 >= 1080.0 &&
        players->vector.x >= 0.0 && players->vector.x + 30 <= 1920) {
            players->vector.y = 990;
            fall = 0;
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 0.0 && players->vector.x + 30 <= 656.0) {
        players->vector.y = 540;
        fall = 0;
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 1200.0 && players->vector.x + 30 <= 1920.0) {
        players->vector.y = 540;
        fall = 0;
    }
    if (fall == 1)
        players->vector.y += 1;
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
    if (players->vector.y + 90 >= 1080.0 &&
        players->vector.y + 92 >= 1080.0 &&
        players->vector.x >= 0.0 && players->vector.x + 30 <= 1920) {
            players->vector.y = 990;
            fall = 0;
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 0.0 && players->vector.x + 30 <= 656.0) {
        players->vector.y = 540.0;
        fall = 0;
    }
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 1200.0 && players->vector.x + 30 <= 1920.0) {
        players->vector.y = 540;
        fall = 0;
    }
    if (fall == 1)
        players->vector.y += 1;
}

void start_home(player *players, house *houses, texture *textures, platform *platforms)
{
    sfEvent event;
    sfRenderWindow *home = initiate_window();
    sfClock *clock_p1 = sfClock_create();
    sfClock *clock_p2 = sfClock_create();
    sfClock *clock_move = sfClock_create();
    sfJoystickIdentification joystick1 = sfJoystick_getIdentification(0);
    sfJoystickIdentification joystick2 = sfJoystick_getIdentification(1);

    while (sfRenderWindow_isOpen(home)) {
        sfJoystick_update();
        display_background_h1(home, textures, houses);
        display_platforms(home, textures, platforms);
        compute_fall_p1(players, platforms);
        compute_fall_p2(players->next, platforms);
        operate_jumps_p1(players, clock_p1, platforms);
        operate_jumps_p2(players->next, clock_p2, platforms);
        display_players(home, players, textures);
        sfRenderWindow_display(home);
        do_events(home, event, players, platforms, clock_move);
        sfRenderWindow_clear(home, sfBlack);
    }
    sfRenderWindow_destroy(home);
    sfClock_destroy(clock_p1);
    sfClock_destroy(clock_p2);
}
