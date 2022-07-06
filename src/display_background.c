/*
** EPITECH PROJECT, 2019
** display background
** File description:
** all the functions to display the background
*/

#include "ggj.h"

void display_background_h1(sfRenderWindow *home, texture *textures, house *houses)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {150, 902};

    sfSprite_setTexture(sprite, textures->background, sfTrue);
    sfRenderWindow_drawSprite(home, sprite, NULL);
    if (houses->sofa == 1) {
        sfSprite_setTexture(sprite, textures->sofa_left, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    pos.x = 408;
    pos.y = 918;
    if (houses->tv == 1) {
        sfSprite_setTexture(sprite, textures->tv_left, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    pos.x = 69;
    pos.y = 853;
    if (houses->lamp == 1) {
        sfSprite_setTexture(sprite, textures->lamp_left, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    pos.x = 307;
    pos.y = 752;
    if (houses->photo == 1) {
        sfSprite_setTexture(sprite, textures->photo_left, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    pos.x = 497;
    pos.y = 720;
    if (houses->trophee == 1) {
        sfSprite_setTexture(sprite, textures->trophee, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    display_background_h2(home, textures, houses->next);
}

void display_background_h2(sfRenderWindow *home, texture *textures, house *houses)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {1576, 902};

    if (houses->sofa == 1) {
        sfSprite_setTexture(sprite, textures->sofa_right, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    pos.x = 1421;
    pos.y = 918;
    if (houses->tv == 1) {
        sfSprite_setTexture(sprite, textures->tv_right, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    pos.x = 1803;
    pos.y = 853;
    if (houses->lamp == 1) {
        sfSprite_setTexture(sprite, textures->lamp_right, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    pos.x = 1504;
    pos.y = 752;
    if (houses->photo == 1) {
        sfSprite_setTexture(sprite, textures->photo_right, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    pos.x = 1342;
    pos.y = 720;
    if (houses->trophee == 1) {
        sfSprite_setTexture(sprite, textures->trophee, sfTrue);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(home, sprite, NULL);
    }
    sfSprite_destroy(sprite);
}
