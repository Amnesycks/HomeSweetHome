/*
** GLOBAL GAME JAM, 2019
** Home
** File description:
** Display
*/

#include <SFML/Graphics.h>
#include "ggj.h"

void display_players(sfRenderWindow *home, player *players, texture *textures)
{
    sfSprite *sprite = sfSprite_create();

    if (players->direction == 0) {
        if (players->next != NULL)
            sfSprite_setTexture(sprite, textures->player_static_left, sfTrue);
        else {
            sfSprite_setTexture(sprite, textures->P2_static_left, sfTrue);
        }
    }
    if (players->direction == 3) {
        if (players->next != NULL)
            sfSprite_setTexture(sprite, textures->player_static_right, sfTrue);
        else {
            sfSprite_setTexture(sprite, textures->P2_static_right, sfTrue);
        }
    }
    if (players->direction == 1) {
        if (players->next != NULL)
            sfSprite_setTexture(sprite, textures->left_running_left, sfTrue);
        else {
            sfSprite_setTexture(sprite, textures->P2_running_left, sfTrue);
        }
    }
    if (players->direction == 2) {
        if (players->next != NULL)
            sfSprite_setTexture(sprite, textures->left_running_right, sfTrue);
        else {
            sfSprite_setTexture(sprite, textures->P2_running_right, sfTrue);
        }
    }
    if (players->hands > 0 && players->next != NULL && players->direction == 2)
        sfSprite_setTexture(sprite, textures->P1_object_right, sfTrue);
    else if (players->hands > 0 && players->next != NULL && players->direction == 1)
        sfSprite_setTexture(sprite, textures->P1_object_left, sfTrue);
    if (players->hands > 0 && players->next == NULL && players->direction == 2)
        sfSprite_setTexture(sprite, textures->P2_object_right, sfTrue);
    else if (players->hands > 0 && players->next == NULL && players->direction == 1)
    sfSprite_setTexture(sprite, textures->P2_object_left, sfTrue);
    if (players->direction == 0 || players->direction == 3)
        players->rect.left = 0;
    if (players->hands == 0)
        sfSprite_setTextureRect(sprite, players->rect);
    sfSprite_setPosition(sprite, players->vector);
    sfRenderWindow_drawSprite(home, sprite, NULL);
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

