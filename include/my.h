/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** All .h functions
*/
#ifndef _MY_H_
#define _MY_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include "struct_menu.h"

textures *initiate_structure(void);
void menu_background(sfRenderWindow *window, textures *textures);
void play_text(sfRenderWindow *window, sfEvent event, textures *textures);
void interaction_text(sfRenderWindow *window, sfEvent event, textures *textures);
void exit_text(sfRenderWindow *window, sfEvent event, textures *textures);
void options_text(sfRenderWindow *window, sfEvent event, textures *textures);
void chosing_map(sfRenderWindow *window, sfEvent event, textures *textures);
void print_instructions(sfRenderWindow *window, sfEvent event, textures *textures);

#endif
