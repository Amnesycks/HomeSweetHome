/*
** EPITECH PROJECT, 2019
** HOME
** File description:
** Management of object
*/

#include "ggj.h"
#include <stdlib.h>

int get_id_item(house *houses)
{
    int rando = rand() % 5 ;
    if ((rando == 0) && (houses->sofa == 0 || houses->next->sofa == 0))
        return (1);
    if ((rando == 1) && (houses->tv == 0 || houses->next->tv == 0))
        return (2);
    if ((rando == 2) && (houses->lamp == 0 || houses->next->lamp == 0))
        return (3);
    if ((rando == 3) && (houses->photo == 0 || houses->next->photo == 0))
        return (4);
    if ((rando == 4) && (houses->trophee == 0 || houses->next->trophee == 0))
        return (5);
    return (0);
}

object_s *spawn_item(platform *platforms, house *houses)
{
    int i = 0;
    int random = 0;
    platform *temp = platforms;
    object_s *object = malloc(sizeof(object_s));

    if (object == NULL)
        exit (84);
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    temp = platforms;
    random = rand() % i;
    i = 0;
    while (temp != NULL && i != random) {
        i++;
        temp = temp->next;
    }
    if (temp != NULL) {
        object->id = get_id_item(houses);
        if (object->id == 1) {
            object->vector.x = temp->vector.x + 11;
            object->vector.y = temp->vector.y - 97;
        }
        if (object->id == 2) {
            object->vector.x = temp->vector.x + 90;
            object->vector.y = temp->vector.y - 87;
        }
        if (object->id == 3) {
            object->vector.x = temp->vector.x + 113;
            object->vector.y = temp->vector.y - 147;
        }
        if (object->id == 4) {
            object->vector.x = temp->vector.x + 100;
            object->vector.y = temp->vector.y - 135;
        }
        if (object->id == 5) {
            object->vector.x = temp->vector.x + 83;
            object->vector.y = temp->vector.y - 120;
        }
        houses->spawn = 1;
    }
    return (object);
}
