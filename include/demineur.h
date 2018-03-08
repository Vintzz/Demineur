/**
* @Author: vincent
* @Date:   2018-03-08T15:20:03+01:00
* @Filename: demineur.h
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T17:08:52+01:00
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <SFML/Graphics.h>

#define NB_TEXTURE      13
#define GAME_NAME       "SNAKE"
#define FRAME_RATE      30

#define ERROR           84

#define TEXTURE_CELL             "./img/cell.png"
#define TEXTURE_NONE             "./img/none.png"
#define TEXTURE_FLAG             "./img/flag.png"
#define TEXTURE_EXPLODEBOMB      "./img/explodebomb.png"
#define TEXTURE_REMOVEBOMB       "./img/removebomb.png"
#define TEXTURE_1                "./img/1.png"
#define TEXTURE_2                "./img/2.png"
#define TEXTURE_3                "./img/3.png"
#define TEXTURE_4                "./img/4.png"
#define TEXTURE_5                "./img/5.png"
#define TEXTURE_6                "./img/6.png"
#define TEXTURE_7                "./img/7.png"
#define TEXTURE_8                "./img/8.png"

typedef int bool;
#define true 1
#define false 0

typedef struct s_sprite
{
        sfSprite              *sprite;
        char                  *texture_name;
        sfTexture             *texture;
        sfVector2f            sprite_origin;
        sfVector2f            sprite_position;
        sfVector2f            sprite_scale;
}               t_sprite;

typedef struct		s_parameter_window
{
        const sfVideoMode               *mode;
        sfRenderWindow          	*window;
        sfVector2u	             	w_size;
        sfEvent	                	event;
}			t_parameter_window;

typedef struct s_cell
{
        sfVector2u      coord;
        bool            isBomb;
        bool            isFlag;
        int             bombAround;
        t_sprite        *sprite;
}               t_cell;


typedef struct s_demineur
{
        int             time;
        int             nBomb;

        sfVector2u      mapSize;       // MAX 36 par 64
        t_cell           **map;

}               t_demineur;

int	hash(char *str);

//      MAP         //

void init_map(t_demineur *demineur);
void create_map(t_demineur *demineur);
