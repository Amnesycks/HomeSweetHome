/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** destroy
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "ggj.h"

void destroy_all(player *players, house *houses, texture *textures, platform *platforms)
{
    platform *elem = platforms;

    free(players->next);
    free(players);
    free(houses->next);
    free(houses);
    free(platforms);
    sfTexture_destroy(textures->platform);
    sfTexture_destroy(textures->background);
    sfTexture_destroy(textures->player_static_left);
    sfTexture_destroy(textures->player_left);
    sfTexture_destroy(textures->player_right);
//    sfTexture_destroy(textures->player_object_hand);
//    sfTexture_destroy(textures->player_hand_punch);
//    sfTexture_destroy(textures->player_bat_punch);
//    sfTexture_destroy(textures->player_tazer_hit);
    sfTexture_destroy(textures->player_stun); 
    sfTexture_destroy(textures->sofa_left);
    sfTexture_destroy(textures->sofa_right);
    sfTexture_destroy(textures->tv_left);
    sfTexture_destroy(textures->tv_right);
    sfTexture_destroy(textures->lamp_left);
    sfTexture_destroy(textures->lamp_right);
    sfTexture_destroy(textures->photo_left);
    sfTexture_destroy(textures->photo_right);
    sfTexture_destroy(textures->trophee);
    sfTexture_destroy(textures->tazer);
    sfTexture_destroy(textures->pan);
    sfTexture_destroy(textures->skate);
    free(textures);
}
