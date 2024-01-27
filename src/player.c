#include "player.h"

#include "render.h"
#include "input.h"

float player_x,player_y = 50;

float gravity = 1;

int isGrounded = 0;
int isJumping = 0;
int jumpHeight = 0;
int isJumpingAllowd = 0;
int playerJump = 50;
int jump = PLAYER_JUMP_FORCE;

void player_update(){
    if(RIGHT_DOWN && player_x>=0 && player_x<=SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = player_x + 1 * PLAYER_SPEED;
    }
    else if(LEFT_DOWN && player_x>=0 && player_x<=SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = player_x - 1 * PLAYER_SPEED;
    }
    else if(player_x>=0 && player_x<=SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = player_x + LX * PLAYER_SPEED;
    }
    if(player_x<0){
        player_x = 0;
    }
    if(player_x>SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = SCREEN_WIDTH - PLAYER_WIDTH;
    }

    if(player_y>= 200 - PLAYER_HEIGHT){
        player_y = 200 - PLAYER_HEIGHT;
        gravity = 1;
        isGrounded = 1;
        isJumping = 0;
        jump = PLAYER_JUMP_FORCE;
    }else {
        gravity = gravity * 1.08;
        player_y = player_y + gravity;
    }

    if(isGrounded){
        if(CROSS_DOWN && !isJumping && isJumpingAllowd){
            isJumpingAllowd = 0;
            isGrounded = 0;
            isJumping = 1;
            jumpHeight = player_y;
        }else if(!CROSS_DOWN){
            isJumpingAllowd = 1;
        }
    }

    if(isJumping){
        jump = jump * 0.99;
        player_y = player_y - jump; 
    }
    

    
}

void player_render(){
    drawRect(player_x, player_y, PLAYER_WIDTH, PLAYER_HEIGHT, 0xFFFFFFFF);
}
