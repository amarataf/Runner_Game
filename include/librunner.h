/*
** EPITECH PROJECT, 2020
** my
** File description:
** header file
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct back_s {
    sfTexture *sky_txt;
    sfSprite *sky_spr;
    sfVector2f sky_pos;
    sfTexture *mount_txt;
    sfSprite *mount_spr;
    sfVector2f mount_pos;
    sfTexture *forest_txt;
    sfSprite *forest_spr;
    sfVector2f forest_pos;
} back_t;

typedef struct backw_s {
    sfTexture *skyw_txt;
    sfSprite *skyw_spr;
    sfVector2f skyw_pos;
    sfTexture *mountw_txt;
    sfSprite *mountw_spr;
    sfVector2f mountw_pos;
    sfTexture *forestw_txt;
    sfSprite *forestw_spr;
    sfVector2f forestw_pos;
} backw_t;

typedef struct character_s {
    sfTexture *ship_txt;
    sfSprite *ship_spr;
    sfVector2f ship_pos;
    sfIntRect ship_rect;
    sfTexture *ball_txt;
    sfSprite *ball_spr;
    sfVector2f ball_pos;
    int ball_direction;
    int ball_speed;
} character_t;

typedef struct context_s {
    sfVideoMode video;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    sfFont *letter;
    sfText *text;
    float seconds;
    char *map;
    int turn;
} context_t;

void my_putchar(char);
int my_putstr(char*);
int my_put_nbr(int);

int my_strlen(char*);
char *my_strcpy(char*);
char *my_strncpy(char*);
char *my_revstr(char*);
char *my_strstr(char*, char const*);
int my_strcmp(char const*, char const*);
int my_strncmp(char const*, char const*, int);

char *my_strupcase(char*);
char *my_strlowcase(char*);
char *my_strcapitalize(char*);

char *my_strcat(char*, char const*);
char *my_strncat(char*, char const*, int);

int my_str_isalpha(char const*);
int my_str_isnum(char const*);
int my_str_islower(char const*);
int my_str_isupper(char const*);
int my_str_isprintable(char const*);

void my_sort_int_array(int*, int);
int my_isneg(int);
void my_swap(int*, int*);
int my_find_prime_sup(int);
int my_is_prime(int);
int my_compute_square_root(int);
int my_compute_power_rec(int, int);
int my_getnbr(char const*);

sfVector2f handle_events(sfEvent event, sfVector2f ship_pos, character_t *ch, int *x);
void move_rect(sfIntRect *ship_rect, int offset, int max_value);
character_t init_char(character_t ch, context_t context);
back_t init_back(back_t back);
context_t init_context(context_t co);
backw_t init_backw(backw_t backw);
int is_open(backw_t *backw, back_t *back, context_t *context, character_t *ch);
void setter(back_t *back);
void setterw(backw_t *backw);
void positioner(back_t *back, backw_t *backw, character_t *ch);
void drawer(context_t *context, back_t *back, backw_t *backw, character_t *ch);
void move_mountain(back_t *back, backw_t *backw);
void move_sky(back_t *back, backw_t *backw);
void move_forest(back_t *back, backw_t *backw);
int size(char **av);
int new_map(char **av, context_t *context);
int help_man(int ac, char **av);

#endif
