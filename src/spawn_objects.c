/*
** EPITECH PROJECT, 2019
** spawn_objects.c
** File description:
** spawn_object.c
*/

#define TRUE 1
#define FALSE 0
#include <SFML/Window/JoystickIdentification.h>
#include <SFML/Graphics.h>
#include "ggj.h"
#include "time.h"
#include "stdlib.h"
#include "../include/objects.h"

object *initiate_objects(void)
{
    object *objects = NULL;
    objects = malloc(sizeof(object));
    srand(time(NULL));
    objects->pos_sofa = {300, 200};
    objects->pos_tv = {1000, 200};
    objects->pos_lamp = {800, 400};
    objects->pos_photo = {900, 900};
    objects->pos_trophee = {900, 800};
    return (objects);
}

void spawn_objects(sfRenderWindow *window, sfEvent event, texture *textures,  platform *platforms)
{
    platform *elem = platforms;
    object *objects = initiate_objects();

    sfSprite *sprite1 = sfSprite_create();
    sfSprite *sprite2 =	sfSprite_create();
    sfSprite *sprite3 =	sfSprite_create();
    sfSprite *sprite4 =	sfSprite_create();
    sfSprite *sprite5 =	sfSprite_create();
    sfSprite *sprite6 =	sfSprite_create();
    sfSprite *sprite7 =	sfSprite_create();
    sfSprite *sprite8 =	sfSprite_create();

    //Sofa
    if ((objects->pos_sofa.y + 90 <= elem->y &&
         objects->pos_sofa.y + 92 >= elem->y) &&
        (objects->pos_sofa.x  + 60 >= elem->x &&
         objects->pos_sofa.x + 30 <= elem->x_end)){
        objects->pos_sofa.y = elem->y - 90;
        objects->pos_sofa.y += 5;
    }
    sfSprite_setTexture(sprite1, textures->pos_sofa, sfTrue);
    sfSprite_setPosition(sprite1, objects->pos_sofa);
    sfRenderWindow_drawSprite(window, sprite1, NULL);
    //TV
    if ((objects->pos_tv.y + 90 <= elem->y &&
         objects->pos_tv.y + 92 >= elem->y) &&
        (objects->pos_tv.x  + 60 >= elem->x &&
         objects->pos_tv.x + 30 <= elem->x_end)){
        objects->pos_tv.y = elem->y - 90;
        objects->pos_tv.y += 5;
    }
    sfSprite_setTexture(sprite2, textures->pos_tv, sfTrue);
    sfSprite_setPosition(sprite2, objects->pos_tv);
    sfRenderWindow_drawSprite(window, sprite1, NULL);
    //Lamp
    if ((objects->pos_lamp.y + 90 <= elem->y &&
         objects->pos_lamp.y + 92 >= elem->y) &&
        (objects->pos_lamp.x  + 60 >= elem->x &&
         objects->pos_lamp.x + 30 <= elem->x_end)){
        objects->pos_lamp.y = elem->y - 90;
        objects->pos_lamp += 5;
    }
    sfSprite_setTexture(sprite3, textures->lamp, sfTrue);
    sfSprite_setPosition(sprite3, objects->pos_lamp);
    sfRenderWindow_drawSprite(window, sprite3, NULL);
    //Photo
    if ((objects->pos_photo.y + 90 <= elem->y &&
         objects->pos_photo.y + 92 >= elem->y) &&
        (objects->pos_photo.x  + 60 >= elem->x &&
         objects->pos_photo.x + 30 <= elem->x_end)){
        objects->pos_photo.y = elem->y - 90;
        objects->pos_photo += 5;
    }
    sfSprite_setTexture(sprite4, textures->photo, sfTrue);
    sfSprite_setPosition(sprite4, objects->pos_photo);
    sfRenderWindow_drawSprite(window, sprite4, NULL);
    //Trophee
    if ((objects->pos_trophee.y + 90 <= elem->y &&
         objects->pos_trophee.y + 92 >= elem->y) &&
        (objects->pos_trophee.x  + 60 >= elem->x &&
         objects->pos_trophee.x + 30 <= elem->x_end)){
        objects->pos_trophee.y = elem->y - 90;
        objects->pos_trophee += 5;
    }
    sfSprite_setTexture(sprite5, textures->trophee, sfTrue);
    sfSprite_setPosition(sprite5, objects->pos_trophee);
    sfRenderWindow_drawSprite(window, sprite5, NULL);

    sfSprite_destroy(sprite1);
    sfSprite_destroy(sprite2);
    sfSprite_destroy(sprite3);
    sfSprite_destroy(sprite4);
    sfSprite_destroy(sprite5);
    sfSprite_destroy(sprite6);
    sfSprite_destroy(sprite7);
    sfSprite_destroy(sprite8);   
}
