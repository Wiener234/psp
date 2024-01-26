#include "player.h"

#include "render.h"
#include "input.h"

float player_x,player_y = 50;

float gravity = 1;

int isGrounded = 0;
int isJumping = 0;
int jumpHeight = 0;
int playerJump = 50;
int jump = 10;

void player_update(){
    if(player_x>=0 && player_x<=SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = player_x + LX * 1.2;
    }else if(player_x<0){
        player_x = 0;
    }else if(player_x>SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = SCREEN_WIDTH - PLAYER_WIDTH;
    }
    /* if(player_y>=0 && player_y<=SCREEN_HEIGHT - PLAYER_HEIGHT){ */
    /*     player_y = player_y + LY; */
    /* }else if(player_y<0){ */
    /*     player_y = 0; */
    /* }else if(player_y>SCREEN_HEIGHT - PLAYER_HEIGHT){ */
    /*     player_y = SCREEN_HEIGHT - PLAYER_HEIGHT; */
    /* } */

    if(player_y>= 80 - PLAYER_HEIGHT){
        player_y = 80 - PLAYER_HEIGHT;
        gravity = 1;
        isGrounded = 1;
        isJumping = 0;
        jump = 10;
    }else {
        gravity = gravity * 1.08;
        player_y = player_y + gravity;
    }

    if(isGrounded){
        if(CROSS_DOWN){
            isGrounded = 0;
            isJumping = 1;
            jumpHeight = player_y;
        }
    }

    if(isJumping){
        jump = jump * 0.99;
        player_y = player_y - jump; 
    }
    

    
}

void player_render(){
    drawRect(player_x, player_y, PLAYER_WIDTH, PLAYER_HEIGHT);
}
