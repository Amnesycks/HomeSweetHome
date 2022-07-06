/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "ggj.h"
#include "my.h"

sfRenderWindow *create_window(int width, int height, int bitsPixel, char *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bitsPixel;
    window = sfRenderWindow_create(video_mode, \
    "Global Game Jam", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 100);
    return (window);
}

void display_main_menu(sfRenderWindow *window, sfEvent event, textures *textures)
{
    sfRenderWindow_clear(window, sfBlack);
    menu_background(window, textures);
    play_text(window, event, textures);
    interaction_text(window, event, textures);
    options_text(window, event, textures);
    exit_text(window, event, textures);
}

void game(sfRenderWindow *window, sfClock *clock, player *players, house *houses, texture *textures, platform *platforms)
{
    sfMusic *music = sfMusic_createFromFile("assets/sound/game.ogg");

    sfMusic_play(music);
    sfMusic_setVolume(music, 30);
    sfMusic_setLoop(music, sfTrue);
    sfRenderWindow_clear(window, sfBlack);
    start_home(players, houses, textures, platforms, window);
    sfMusic_destroy(music);
}

int modify_event(int game_menu, sfEvent event, sfRenderWindow *window)
{
    //sfMusic *music = sfMusic_createFromFile("assets/sound/menu.ogg");

    //CLIC SUR LA 1ERE MAP
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x > 500 \
        && event.mouseButton.x < 770 && event.mouseButton.y > 400 \
        && event.mouseButton.y < 500 && game_menu == 1)
        game_menu = 21;
    //CLIC SUR LA 2EME MAP
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x > 900 \
        && event.mouseButton.x < 1170 && event.mouseButton.y > 400      \
        && event.mouseButton.y < 500 && game_menu == 1)
        game_menu = 22;
    //CLIC SUR LA 3EME MAP                                                           
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x > 1300 \
        && event.mouseButton.x < 1570 && event.mouseButton.y > 400      \
        && event.mouseButton.y < 500 && game_menu == 1)
        game_menu = 23;
    //CLIC SUR PLAY
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x > 850 \
        && event.mouseButton.x < 1150 && event.mouseButton.y > 400 \
        && event.mouseButton.y < 500 && game_menu == 0)
	game_menu = 1;
    //BOUTON RETOUR AU MENU
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x > 1600 \
        && event.mouseButton.x < 1800 && event.mouseButton.y > 10 \
	&& event.mouseButton.y < 100 && (game_menu == 1 || game_menu == 3))
	game_menu = 0;
    //BOUTON INSTRUCTIONS
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x > 850 \
        && event.mouseButton.x < 1120 && event.mouseButton.y > 500 \
        && event.mouseButton.y < 600 && game_menu == 0)
        game_menu = 3;
    //BOUTON EXIT
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x > 850 \
        && event.mouseButton.x < 1000 && event.mouseButton.y > 700 \
        && event.mouseButton.y < 800 && game_menu == 0)
        sfRenderWindow_close(window);
    return (game_menu);
}

void destroy_struct(textures *textures)
{
    sfTexture_destroy(textures->menu_background);
    sfTexture_destroy(textures->play_text);
    sfTexture_destroy(textures->interaction_text);
    sfTexture_destroy(textures->exit_text);
    sfTexture_destroy(textures->options_text);
    sfTexture_destroy(textures->back_main_menu);
    sfTexture_destroy(textures->printing_first_choice);
    sfTexture_destroy(textures->printing_second_choice);
    sfTexture_destroy(textures->printing_third_choice);
    sfTexture_destroy(textures->Q);
    sfTexture_destroy(textures->Z);
    sfTexture_destroy(textures->D);
    sfTexture_destroy(textures->O);
    sfTexture_destroy(textures->K);
    sfTexture_destroy(textures->M);
    sfTexture_destroy(textures->print_first_map);
    sfTexture_destroy(textures->print_second_map);
    sfTexture_destroy(textures->print_third_map);
}

int handling_game_menus(sfEvent event, sfRenderWindow *window, int game_menu, sfClock *clock, textures *textures, player *players, house *houses, texture *textures2, platform *platforms)
{
    if (game_menu == 0)
	display_main_menu(window, event, textures);
    if (game_menu == 1)
	chosing_map(window, event, textures);
    if (game_menu == 21) {
        platforms = create_platform("script/script1");
        game(window, clock, players, houses, textures2, platforms);
    }
    if (game_menu == 22) {
        platforms = create_platform("script/script2");
        game(window, clock, players, houses, textures2, platforms);
    }
    if (game_menu == 23) {
        platforms = create_platform("script/script3");
        game(window, clock, players, houses, textures2, platforms);
    }
    if (game_menu == 3)
	print_instructions(window, event, textures);
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = create_window(1920, 1080, 32, "Global Game Jam");
    sfEvent event;
    int game_menu = 0;
    sfClock *clock = sfClock_create();
    textures *my_texture = initiate_structure();
    player *players = initiate_players();
    house *houses = initiate_houses();
    texture *textures = initiate_texture();
    platform *platforms = NULL;

    srand(time(NULL));
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
	while (sfRenderWindow_pollEvent(window, &event)) {
	    game_menu = modify_event(game_menu, event, window);
	    handling_game_menus(event, window, game_menu, clock, my_texture, players, houses, textures, platforms);
	}
    }
    sfRenderWindow_destroy(window);
    destroy_struct(my_texture);
//    destroy_all(players, houses, textures, platforms);
}
