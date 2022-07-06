/*
** EPITECH PROJECT, 2019
** text_main_menu
** File description:
** TOM
*/

#include "my.h"
#include <stdlib.h>

textures *initiate_structure(void)
{
    textures *textures = NULL;

    textures = malloc(sizeof(struct textures));
    if (textures == NULL)
	exit (84);
    textures->menu_background = sfTexture_createFromFile("assets/sprites/menu.png", NULL);
    textures->play_text = sfTexture_createFromFile("assets/sprites/play.png", NULL);
    textures->interaction_text = sfTexture_createFromFile("assets/sprites/interaction.png", NULL);
    textures->exit_text = sfTexture_createFromFile("assets/sprites/exit.png", NULL);
    textures->options_text = sfTexture_createFromFile("assets/sprites/options.png", NULL);
    textures->back_main_menu = sfTexture_createFromFile("assets/sprites/main_menu.png", NULL);
    textures->printing_first_choice = sfTexture_createFromFile("assets/sprites/map1.png", NULL);
    textures->printing_second_choice =  sfTexture_createFromFile("assets/sprites/map2.png", NULL);
    textures->printing_third_choice = sfTexture_createFromFile("assets/sprites/map3.png", NULL);
    textures->Q = sfTexture_createFromFile("assets/sprites/croix.png", NULL);
    textures->Z = sfTexture_createFromFile("assets/sprites/carré.png", NULL);
    textures->D = sfTexture_createFromFile("assets/sprites/rond.png", NULL);
    textures->O = sfTexture_createFromFile("assets/sprites/B.png", NULL);
    textures-> K = sfTexture_createFromFile("assets/sprites/A.png", NULL);
    textures->M = sfTexture_createFromFile("assets/sprites/X.png", NULL);
    textures->print_first_map = sfTexture_createFromFile("assets/sprites/carré.png", NULL);
    textures->print_second_map = sfTexture_createFromFile("assets/sprites/carré.png", NULL);
    textures->print_third_map = sfTexture_createFromFile("assets/sprites/carré.png", NULL);
    return (textures);
}

void menu_background(sfRenderWindow *window, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = textures->menu_background;

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void play_text(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *second = sfSprite_create();
    sfTexture *texture = textures->play_text;
    sfTexture *second_text = sfTexture_createFromFile("assets/sprites/second_play.png", NULL);
    sfVector2f vector = {850, 400};

    if (sfMouse_getPositionRenderWindow(window).x >= 850 && sfMouse_getPositionRenderWind\
ow(window).x < 1000 && sfMouse_getPositionRenderWindow(window).y >= 400 && sfMouse_getPos\
itionRenderWindow(window).y <= 460) {
        sfSprite_setTexture(second, second_text, sfTrue);
        sfSprite_setPosition(second, vector);
        sfRenderWindow_drawSprite(window, second, NULL);
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, vector);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(second);
    sfTexture_destroy(second_text);
}

void interaction_text(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *second = sfSprite_create();
    sfTexture *texture = textures->interaction_text;
    sfTexture *second_text = sfTexture_createFromFile("assets/sprites/second_interaction.png", NULL);
    sfVector2f vector = {850, 500};

    if (sfMouse_getPositionRenderWindow(window).x >= 850 && sfMouse_getPositionRenderWind\
ow(window).x < 1000 && sfMouse_getPositionRenderWindow(window).y >= 500 && sfMouse_getPos\
itionRenderWindow(window).y <= 560) {
	sfSprite_setTexture(second, second_text, sfTrue);
        sfSprite_setPosition(second, vector);
        sfRenderWindow_drawSprite(window, second, NULL);
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, vector);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(second);
    sfTexture_destroy(second_text);
}

void exit_text(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *second = sfSprite_create();
    sfTexture *texture = textures->exit_text;
    sfTexture *second_text = sfTexture_createFromFile("assets/sprites/second_exit.png", NULL);
    sfVector2f vector = {850, 700};

    if (sfMouse_getPositionRenderWindow(window).x >= 850 && sfMouse_getPositionRenderWind\
ow(window).x < 1000 && sfMouse_getPositionRenderWindow(window).y >= 700 && sfMouse_getPos\
itionRenderWindow(window).y <= 760) {
        sfSprite_setTexture(second, second_text, sfTrue);
        sfSprite_setPosition(second, vector);
        sfRenderWindow_drawSprite(window, second, NULL);
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, vector);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(second);
    sfTexture_destroy(second_text);
}

void options_text(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *second = sfSprite_create();
    sfTexture *texture = textures->options_text;
    sfTexture *second_text = sfTexture_createFromFile("assets/sprites/second_options.png"\
, NULL);
    sfVector2f vector = {850, 600};

    if (sfMouse_getPositionRenderWindow(window).x >= 850 && sfMouse_getPositionRenderWind\
ow(window).x < 1000 && sfMouse_getPositionRenderWindow(window).y >= 600 && sfMouse_getPos\
itionRenderWindow(window).y <= 660) {
	sfSprite_setTexture(second, second_text, sfTrue);
        sfSprite_setPosition(second, vector);
        sfRenderWindow_drawSprite(window, second, NULL);
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, vector);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(second);
    sfTexture_destroy(second_text);
}

void back_to_main_menu(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *second = sfSprite_create();
    sfTexture *texture = textures->back_main_menu;
    sfTexture *second_text = sfTexture_createFromFile("assets/sprites/second_main_men\
u.png", NULL);
    sfVector2f vector = {1600, 10};

    if (sfMouse_getPositionRenderWindow(window).x >= 1600 && sfMouse_getPositionRende\
rWindow(window).x < 1800 && sfMouse_getPositionRenderWindow(window).y >= 10 && sfMous\
e_getPositionRenderWindow(window).y <= 210) {
        sfSprite_setTexture(second, second_text, sfTrue);
        sfSprite_setPosition(second, vector);
        sfRenderWindow_drawSprite(window, second, NULL);
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, vector);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(second);
    sfTexture_destroy(second_text);
}

void printing_first_choice(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *second = sfSprite_create();
    sfTexture *texture = textures->printing_first_choice;
    sfTexture *second_text = sfTexture_createFromFile("assets/sprites/second_map1.png", N\
ULL);
    sfVector2f vector = {500, 400};

    if (sfMouse_getPositionRenderWindow(window).x >= 500 && sfMouse_getPositionRenderWind\
ow(window).x < 770 && sfMouse_getPositionRenderWindow(window).y >= 400 && sfMouse_getPosi\
tionRenderWindow(window).y <= 500) {
        sfSprite_setTexture(second, second_text, sfTrue);
        sfSprite_setPosition(second, vector);
        sfRenderWindow_drawSprite(window, second, NULL);
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, vector);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(second);
    sfTexture_destroy(second_text);
}

void printing_second_choice(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *second = sfSprite_create();
    sfTexture *texture = textures->printing_second_choice;
    sfTexture *second_text = sfTexture_createFromFile("assets/sprites/second_map2.png\
", NULL);
    sfVector2f vector = {900, 400};

    if (sfMouse_getPositionRenderWindow(window).x >= 900 && sfMouse_getPositionRender\
Window(window).x < 1170 && sfMouse_getPositionRenderWindow(window).y >= 400 && sfMous\
e_getPositionRenderWindow(window).y <= 500) {
        sfSprite_setTexture(second, second_text, sfTrue);
        sfSprite_setPosition(second, vector);
        sfRenderWindow_drawSprite(window, second, NULL);
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, vector);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(second);
    sfTexture_destroy(second_text);
}

void printing_third_choice(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite *second = sfSprite_create();
    sfTexture *texture = textures->printing_third_choice;
    sfTexture *second_text = sfTexture_createFromFile("assets/sprites/second_map3.png\
", NULL);
    sfVector2f vector = {1300, 400};

    if (sfMouse_getPositionRenderWindow(window).x >= 1300 && sfMouse_getPositionRende\
rWindow(window).x < 1570 && sfMouse_getPositionRenderWindow(window).y >= 400 && sfMou\
se_getPositionRenderWindow(window).y <= 500) {
        sfSprite_setTexture(second, second_text, sfTrue);
        sfSprite_setPosition(second, vector);
        sfRenderWindow_drawSprite(window, second, NULL);
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, vector);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfSprite_destroy(sprite);
    sfSprite_destroy(second);
    sfTexture_destroy(second_text);
}

void print_middle_bar(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {870, 300};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "|");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 400);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void print_first_user_interaction(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {200, 200};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "INTERACTIONS PLAYSTATION");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void print_second_user_interaction(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {1100, 200};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "INTERACTIONS XBOX");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void Q(sfRenderWindow *window, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = textures->Q;
    sfVector2f vector = {100, 300};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, vector);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void Z(sfRenderWindow *window, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = textures->Z;
    sfVector2f vector = {85, 440};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, vector);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void Z_interaction(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {300, 640};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "PICK UP ITEMS");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void Q_interaction(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {300, 480};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "ATTACK");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void D_interaction(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {300, 340};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "JUMP");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void D(sfRenderWindow *window, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = textures->D;
    sfVector2f vector = {100, 570};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, vector);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void O(sfRenderWindow *window, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = textures->O;
    sfVector2f vector = {1005, 450};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, vector);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void K(sfRenderWindow *window, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = textures->K;
    sfVector2f vector = {1000, 300};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, vector);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void O_interaction(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {1200, 470};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "ATTACK");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void K_interaction(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {1200, 320};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "JUMP");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void M(sfRenderWindow *window, textures *textures)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = textures->M;
    sfVector2f vector = {1000, 600};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, vector);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void M_interaction(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {1200, 620};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "PICK UP ITEMS");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void select_your_map(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {800, 100};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "SELECT YOUR MAP");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 80);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void chosing_map(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfRenderWindow_clear(window, sfBlack);
    menu_background(window, textures);
    select_your_map(window);
    printing_first_choice(window, event, textures);
    printing_second_choice(window, event, textures);
    printing_third_choice(window, event, textures);
    back_to_main_menu(window, event, textures);
}

void rules(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfText *second_text = sfText_create();
    sfVector2f vector = {180, 800};
    sfVector2f second_vector = {520, 900};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "THE GOAL OF THIS GAME IS TO FILL YOUR HOME WITH ITEMS AS FAST\
");
    sfText_setString(second_text, "AS POSSIBLE BEFORE YOUR NEIGHBOUR");
    sfText_setFont(text, font);
    sfText_setFont(second_text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setCharacterSize(second_text, 60);
    sfText_setColor(text, sfBlack);
    sfText_setColor(second_text, sfBlack);
    sfText_move(text, vector);
    sfText_move(second_text, second_vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_drawText(window, second_text, NULL);
    sfText_destroy(text);
    sfText_destroy(second_text);
    sfFont_destroy(font);
}

void moving_rules(sfRenderWindow *window)
{
    sfFont* font;
    sfText* text;
    sfVector2f vector = {650, 50};

    font = sfFont_createFromFile("assets/font.ttf");
    text = sfText_create();
    sfText_setString(text, "USE THE JOYSTICK TO MOVE");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setColor(text, sfBlack);
    sfText_move(text, vector);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void print_instructions(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfRenderWindow_clear(window, sfBlack);
    menu_background(window, textures);
    print_first_user_interaction(window);
    print_middle_bar(window);
    Z(window, textures);
    Z_interaction(window);
    Q(window, textures);
    Q_interaction(window);
    D(window, textures);
    D_interaction(window);
    print_second_user_interaction(window);
    O(window, textures);
    O_interaction(window);
    K(window, textures);
    K_interaction(window);
    M(window, textures);
    M_interaction(window);
    moving_rules(window);
    rules(window);
    back_to_main_menu(window, event, textures);
}
