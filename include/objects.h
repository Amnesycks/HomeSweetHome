/*
** EPITECH PROJECT, 2019
** objects.c
** File description:
** objects.c
*/

#include <SFML/Graphics.h>

#ifndef _OBJECTS_H_
#define _OBJECTS_H_

typedef struct object object;
struct object
{
    sfVector2f pos_sofa;
    sfVector2f pos_tv;
    sfVector2f pos_lamp;
    sfVector2f pos_photo;
    sfVector2f pos_trophee;
    sfVector2f pos_tazer;
    sfVector2f pos_pan;
    sfVector2f pos_skate;
};

#endif 
