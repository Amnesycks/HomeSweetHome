/*
** EPITECH PROJECT, 2019
** initiate structure
** File description:
** initiates all structures
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "ggj.h"

texture *initiate_texture(void)
{
    texture *textures = NULL;

    textures = malloc(sizeof(texture));
    if (textures == NULL)
        exit(84);
    /**background**/
    textures->platform = sfTexture_createFromFile("res/platform.png", NULL);
    textures->background = sfTexture_createFromFile("res/map.png", NULL);
    /**Player one**/
    textures->player_static_left = sfTexture_createFromFile("res/player_static_left.png", NULL);
    textures->player_static_right = sfTexture_createFromFile("res/player_static_right.png", NULL);
    textures->left_running_right = sfTexture_createFromFile("res/left_run_right.png", NULL);
    textures->left_running_left = sfTexture_createFromFile("res/left_run_left.png", NULL);
    /**player two**/
    textures->P2_running_right = sfTexture_createFromFile("res/P2_running_right.png", NULL);
    textures->P2_running_left = sfTexture_createFromFile("res/P2_running_left.png", NULL);
    textures->P2_static_left = sfTexture_createFromFile("res/P2_static_left.png", NULL);
    textures->P2_static_right = sfTexture_createFromFile("res/P2_static_right.png", NULL);
    /**Weapon**/
    textures->P1_object_right = sfTexture_createFromFile("res/player_carry_right.png", NULL);
    textures->P1_object_left = sfTexture_createFromFile("res/player_carry_left.png", NULL);
    textures->P2_object_right = sfTexture_createFromFile("res/P2_carry_right.png", NULL);
    textures->P2_object_left = sfTexture_createFromFile("res/P2_carry_left.png", NULL);
//    textures->player_hand_punch = sfTexture_createFromFile("", NULL);
//    textures->player_bat_punch = sfTexture_createFromFile("", NULL);
//    textures->player_tazer_hit = sfTexture_createFromFile("", NULL);
//    textures->player_stun = sfTexture_createFromFile("", NULL);
    /**Object**/
    textures->sofa_left = sfTexture_createFromFile("res/sofa_left.png", NULL);
    textures->sofa_right = sfTexture_createFromFile("res/sofa_right.png", NULL);
    textures->tv_left = sfTexture_createFromFile("res/tv_left.png", NULL);
    textures->tv_right = sfTexture_createFromFile("res/tv_right.png", NULL);
    textures->lamp_left = sfTexture_createFromFile("res/lamp_left.png", NULL);
    textures->lamp_right = sfTexture_createFromFile("res/lamp_right.png", NULL);
    textures->photo_left = sfTexture_createFromFile("res/photo_left.png", NULL);
    textures->photo_right = sfTexture_createFromFile("res/photo_right.png", NULL);
    textures->trophee = sfTexture_createFromFile("res/trophee.png", NULL);
    textures->tazer = sfTexture_createFromFile("res/tazer.png", NULL);
    textures->pan = sfTexture_createFromFile("res/pan.png", NULL);
    textures->skate = sfTexture_createFromFile("res/skate.png", NULL);

    return (textures);
}

house *initiate_houses(void)
{
    house *houses = NULL;
    house *house2 = NULL;

    houses = malloc(sizeof(house));
    house2 = malloc(sizeof(house));
    if (houses == NULL || house2 == NULL)
        exit(84);
    houses->sofa = 0;
    houses->tv = 0;
    houses->lamp = 0;
    houses->photo = 0;
    houses->trophee = 0;
    houses->next = house2;
    houses->spawn = 0;
    house2->sofa = 0;
    house2->tv = 0;
    house2->lamp = 0;
    house2->photo = 0;
    house2->trophee = 0;
    house2->next = NULL;
    return (houses);
}

player *initiate_players(void)
{
    player *players = NULL;
    player *player2 = NULL;
    sfVector2f vplayer = {1050, 900};
    sfVector2f vplayer2 = {850, 900};
    sfIntRect rect = {0, 0, 60, 100};

    players = malloc(sizeof(player));
    player2 = malloc(sizeof(player));
    if (players == NULL || player2 == NULL)
        exit(84);
    players->direction = 0;
    players->jump = 0;
    players->pv = 5;
    players->hands = 0;
    players->vector = vplayer;
    players->rect = rect;
    players->next = player2;
    player2->direction = 0;
    player2->jump = 0;
    player2->pv = 5;
    player2->hands = 0;
    player2->vector = vplayer2;
    player2->rect = rect;
    player2->next = NULL;
    return (players);
}
