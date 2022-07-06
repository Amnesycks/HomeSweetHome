/*
** EPITECH PROJECT, 2019
** start game
** File description:
** start of game
*/

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Window/JoystickIdentification.h>
#include <SFML/Graphics.h>
#include "ggj.h"

void toggle_jump(sfEvent event, player *players, platform *platforms)
{
    if (sfEvtJoystickButtonPressed) {
        if ((sfJoystick_isButtonPressed(0, 0) == TRUE) &&
            (on_platform(platforms, players) == 1))
            players->jump = 1;
        if ((sfJoystick_isButtonPressed(1, 0) == TRUE) &&
            (on_platform(platforms, players) == 1))
            players->next->jump = 1;
    }
}

void do_events(sfRenderWindow *home, sfEvent event, player *players, platform *platforms,\
 sfClock *clock_move)
{
    players->joy_x = sfJoystick_getAxisPosition(0, sfJoystickX);
    players->joy_y = sfJoystick_getAxisPosition(0, sfJoystickY);
    players->next->joy_x = sfJoystick_getAxisPosition(1, sfJoystickX);
    players->next->joy_y = sfJoystick_getAxisPosition(1, sfJoystickY);
    // Ajout d'une clock                                                                  
    if (sfClock_getElapsedTime(clock_move).microseconds > 55000) {
        //Conditions changées                                                             
        if (players->vector.x > 1 && players->joy_x < -20 && players->direction != 2 &&
            !is_wall(players)) {
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
        if (players->joy_x > 20 && players->direction != 2) {
            players->direction = 3;
            players->rect.left = 0;
        }

        if (players->next->vector.x > 1 && players->next->joy_x < -20 && players->next->direction != 2
            && !is_wall(players->next)) {
            players->next->direction = 1;
            players->next->vector.x -= 12;
            players->next->rect.left += 60;
            if (players->next->rect.left >= 200)
                players->next->rect.left = 0;
        }
        if (players->next->vector.x < 1919 && players->next->joy_x > 20 &&
            players->next->direction != 1 && !is_wall(players->next)) {
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
    /** Ground **/
    if (players->vector.y + 90 >= 1020.0 &&
        players->vector.y + 92 >= 1020.0 &&
	players->vector.x >= -50.0 && players->vector.x + 30 <= 1900) {
            players->vector.y = 930;
            return (1);
    }
    /** Red House **/
    if (players->vector.y + 90 >= 630.0 &&
	players->vector.y + 92 <= 635.0 &&
        players->vector.x >= -50.0 && players->vector.x + 30 <= 700.0) {
        players->vector.y = 540;
        return (1);
    }
    /** Blue House **/
    if (players->vector.y + 90 >= 630.0 &&
        players->vector.y + 92 <= 635.0 &&
        players->vector.x >= 1150.0 && players->vector.x + 30 <= 1900.0) {
        players->vector.y = 540;
        return (1);
    }
    return (0);
}

void item_animation(player *players, texture *textures, sfRenderWindow *window, house *houses, object_s *object) 
{
    sfSprite *item_sprite = sfSprite_create();
    sfVector2f item_vector = object->vector;
    static int count = 0;
    static int count2 = 0;
    static int item_position = 0;
    sfVector2f vplayer = {850, 900};
    sfVector2f vplayer2 = {1050, 900};

    if (object->id == 1)
        sfSprite_setTexture(item_sprite, textures->sofa_left, sfTrue);
    if (object->id == 2)
        sfSprite_setTexture(item_sprite, textures->tv_left, sfTrue);
    if (object->id == 3)
        sfSprite_setTexture(item_sprite, textures->lamp_left, sfTrue);
    if (object->id == 4)
        sfSprite_setTexture(item_sprite, textures->photo_left, sfTrue);
    if (object->id == 5)
        sfSprite_setTexture(item_sprite, textures->trophee, sfTrue);

    if ((players->vector.x >= item_vector.x && players->vector.x <= item_vector.x + 100 && players->vector.y >= item_vector.y && players->vector.y <= item_vector.y + 50) || count == 1) {
	item_vector.y = players->vector.y - 80;
	item_vector.x = players->vector.x - 30;
	count = 1;
        players->hands = 1;
    }
    else if ((players->next->vector.x >= item_vector.x && players->next->vector.x <= item_vector.x + 100 && players->next->vector.y >= item_vector.y && players->next->vector.y <= item_vector.y + 50) || count2 == 1) {
        item_vector.y = players->next->vector.y - 80;
        item_vector.x = players->next->vector.x - 30;
        count2 = 1;
        players->next->hands = 1;
    }
    //SI SOFA ET JOUEUR A GAUCHE
    if (object->id == 1) {
        if ((players->vector.x >= 0 && players->vector.x <= 400 && players->vector.y >= 800 && players->vector.y <= 1080 && count == 1) || item_position == 1) {
            houses->sofa = 1;
            houses->spawn = 0;
            players->hands = 0;
            players->vector = vplayer;
            count = 0;
	}
        //SI SOFA ET JOUEUR A DROITE
        else if ((players->next->vector.x >= 1500 && players->next->vector.x <= 1920 && players->next->vector.y >= 800 && players->next->vector.y <= 1080 && count2 == 1) || item_position == 2) {
            houses->next->sofa = 1;
            houses->spawn = 0;
            players->next->hands = 0;
            players->next->vector = vplayer2;
            count2 = 0;
        }
    }
    //SI LAMPE ET JOUEUR A GAUCHE
    if (object->id == 3) {
        if ((players->vector.x >= 0 && players->vector.x <= 400 && players->vector.y >= 800 && players->vector.y <= 1080 && count == 1) || item_position == 1) {
            players->hands = 0;
            houses->lamp = 1;
            players->vector = vplayer;
            houses->spawn = 0;
            count = 0;
        }
        //SI LAMPE ET JOUEUR A DROITE // 1805 860
        else if ((players->next->vector.x >= 1500 && players->next->vector.x <= 1920 && players->next->vector.y >= 800 && players->next->vector.y <= 1080 && count2 == 1) || item_position == 2) {
            houses->next->lamp = 1;
            players->next->hands = 0;
            players->next->vector = vplayer2;
            houses->spawn = 0;
            count2 = 0;
        }
    }
    if (object->id == 2) {
        //SI TELE ET JOUEUR A GAUCHE
        if ((players->vector.x >= 0 && players->vector.x <= 400 && players->vector.y >= 800 && players->vector.y <= 1080 && count == 1) || item_position == 1) {
            players->hands = 0;
            houses->spawn = 0;
            players->vector = vplayer;
            houses->tv = 1;
            count = 0;
        }
        //SI TELE ET JOUEUR A DROITE
        else if ((players->next->vector.x >= 1500 && players->next->vector.x <= 1920 && players->next->vector.y >= 800 && players->next->vector.y <= 1080 && count2 == 1) || item_position == 2) {
            players->next->hands = 0;
            houses->spawn = 0;
            players->next->vector = vplayer2;
            houses->next->tv = 1;
            count2 = 0;
        }
    } if (object->id == 5) {
        //SI TROPHEE ET JOUEUR A GAUCHE // 495 718
        if ((players->vector.x >= 0 && players->vector.x <= 400 && players->vector.y >= 800 && players->vector.y <= 1080 && count == 1) || item_position == 1) {
            players->hands = 0;
            houses->spawn = 0;
            players->vector = vplayer;
            houses->trophee = 1;
            count = 0;
        }
        //SI TROPHEE ET JOUEUR A DROITE
        else if ((players->next->vector.x >= 1500 && players->next->vector.x <= 1920 && players->next->vector.y >= 800 && players->next->vector.y <= 1080 && count2 == 1) || item_position == 2) {
            players->next->hands = 0;
            houses->spawn = 0;
            players->next->vector = vplayer2;
            houses->next->trophee = 1;
            count2 = 0;
        }
    } if (object->id == 4) {
        //SI PHOTO ET JOUEUR A GAUCHE
        if (players->vector.x >= 0 && players->vector.x <= 400 && count == 1 || item_position == 1) {
            players->hands = 0;
            houses->spawn = 0;
            players->vector = vplayer;
            houses->photo = 1;
            count = 0;
        }
        //SI PHOTO ET JOUEUR A DROITE
        if ((players->next->vector.x >= 1500 && players->next->vector.x <= 1920 && players->next->vector.y >= 800 && players->next->vector.y <= 1080 && count2 == 1) || item_position == 2) {
            players->next->hands = 0;
            houses->spawn = 0;
            players->next->vector = vplayer2;
            houses->next->photo = 1;
            count2 = 0;
        }
    }
    sfSprite_move(item_sprite, item_vector);
    sfRenderWindow_drawSprite(window, item_sprite, NULL);
}

void first_player_win(sfRenderWindow *window)
{
    sfFont *font;
    sfText* text;
    sfVector2f vector = {600, 450};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "FIRST PLAYER WIN");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfText_destroy(text); sfFont_destroy(font);
}

void second_player_win(sfRenderWindow *window)
{
    sfFont *font; sfText* text; sfVector2f vector = {600, 450}; font = sfFont_createFromFile("assets/font.ttf"); text = sfText_create(); sfText_setString(text, "SECOND PLAYER WIN"); sfText_setFont(text, font); sfText_setCharacterSize(text, 100); sfText_setColor(text, sfBlack); sfText_move(text, vector); sfRenderWindow_drawText(window, text, NULL); sfText_destroy(text); sfFont_destroy(font); }

void start_home(player *players, house *houses, texture *textures, platform *platforms, sfRenderWindow *home)
{
    sfEvent event;
    object_s *object = NULL;
    sfClock *clock_p1 = sfClock_create();
    sfClock *clock_p2 = sfClock_create();
    sfJoystickIdentification joystick1 = sfJoystick_getIdentification(0);
    sfJoystickIdentification joystick2 = sfJoystick_getIdentification(1);
    sfClock *clock_move = sfClock_create();

    sfRenderWindow_setFramerateLimit(home, 60);
    while (sfRenderWindow_isOpen(home)) {
        if (houses->sofa == 1 && houses->tv == 1 && houses->lamp == 1 && houses->photo == 1 && houses->trophee == 1)
            first_player_win(home);
        else if (houses->next->sofa == 1 && houses->next->tv == 1 && houses->next->lamp == 1 && houses->next->photo == 1 && houses->next->trophee == 1)
            second_player_win(home);
        else {
            sfJoystick_update();
            display_background_h1(home, textures, houses);
            display_platforms(home, textures, platforms);
            compute_fall_p1(players, platforms);
            compute_fall_p2(players->next, platforms);
            operate_jumps_p1(players, clock_p1, platforms);
            operate_jumps_p2(players->next, clock_p2, platforms);
            if (houses->spawn == 0)
                object = spawn_item(platforms, houses);
            item_animation(players, textures, home, houses, object);
            display_players(home, players, textures);
            display_players(home, players->next, textures);
            sfRenderWindow_display(home);
            do_events(home, event, players, platforms, clock_move);
            sfRenderWindow_clear(home, sfBlack);
        }
    }
    sfClock_destroy(clock_p1);
    sfClock_destroy(clock_p2);
}
