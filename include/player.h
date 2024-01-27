#ifndef PLAYER_H
#define PLAYER_H


#define PLAYER_WIDTH 15
#define PLAYER_HEIGHT PLAYER_WIDTH

#define PLAYER_SPEED 2.4
#define PLAYER_JUMP_FORCE 10

extern float player_x,player_y;
extern float gravity;

void player_update();

void player_render();

#endif
