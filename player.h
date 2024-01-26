#ifndef PLAYER_H
#define PLAYER_H


#define PLAYER_WIDTH 15
#define PLAYER_HEIGHT PLAYER_WIDTH

extern float player_x,player_y;
extern float gravity;

void player_update();

void player_render();

#endif
