/*
** EPITECH PROJECT, 2019
** ggj
** File description:
** ggj
*/

#include <SFML/Graphics.h>

#ifndef _GGJ_H_
#define _GGJ_H_

typedef struct texture texture;
struct texture
{
/*background*/
    sfTexture *platform;
    sfTexture *background;
/*Player 1*/
    sfTexture *player_static_left;
    sfTexture *player_static_right;
    sfTexture *left_running_right;
    sfTexture *left_running_left;
    //sfTexture *right_running_right;                                                                   
    //sfTexture *right_running_left;                                                                    
    sfTexture *player_left;
/*Player 2*/
    sfTexture *player_right;
    sfTexture *P2_running_right;
    sfTexture *P2_static_left;
    sfTexture *P2_static_right;
    sfTexture *P2_running_left;
/*Player Bonuses*/
    sfTexture *P1_object_right;
    sfTexture *P1_object_left;
    sfTexture *P2_object_right;
    sfTexture *P2_object_left;
    sfTexture *player_hand_punch;
    sfTexture *player_bat_punch;
    sfTexture *player_tazer_hit;
    sfTexture *player_stun;
/*Object*/
    sfTexture *sofa_left;
    sfTexture *sofa_right;
    sfTexture *tv_left;
    sfTexture *tv_right;
    sfTexture *lamp_left;
    sfTexture *lamp_right;
    sfTexture *photo_left;
    sfTexture *photo_right;
    sfTexture *trophee;
    sfTexture *tazer;
    sfTexture *pan;
    sfTexture *skate;
};

typedef struct house house;
struct house
{
    int sofa;
    int tv;
    int lamp;
    int photo;
    int trophee;
    int spawn;
    house *next;
};

typedef struct object_s object_s;
struct object_s
{
    sfVector2f vector;
    int id;
};

typedef struct player player;
struct player
{
    int direction;
    int hands;
    int jump;
    int pv;
    sfVector2f vector;
    sfIntRect rect;
    float joy_x;
    float joy_y;
    player *next;
};

typedef struct platform platform;
struct platform
{
    int x;
    int x_end;
    int y;
    sfVector2f vector;
    platform *next;
};

//Functions
object_s *spawn_item(platform *platforms, house *houses);

//compute_fall
void compute_fall_p1(player *players, platform *platforms);
void compute_fall_p2(player *players, platform *platforms);

//display
void display_players(sfRenderWindow *home, player *players, texture *textures);
void display_platforms(sfRenderWindow *home, texture *textures, platform *platforms);

//operate_jump
void operate_jumps_p1(player *players, sfClock *clock, platform *platforms);
void operate_jumps_p2(player *players, sfClock *clock, platform *platforms);

//start_game
int on_platform(platform *platforms, player *players);

int is_wall(player *players);
int check_player_valid(player *, platform *);
void display_background_h1(sfRenderWindow *, texture *, house *);
void display_background_h2(sfRenderWindow *, texture *, house *);

int getnbr(char *);
void toggle_event_player_two(sfEvent, player *);

void destroy_all(player *, house *, texture *, platform *);
void display_background(sfRenderWindow *, texture *, house *);

platform *create_platform(char *);
//void do_events(sfRenderWindow *, sfEvent, player *);
void start_home(player *, house *, texture *, platform *, sfRenderWindow *);
player *initiate_players(void);
house *initiate_houses(void);
texture *initiate_texture(void);

#endif
