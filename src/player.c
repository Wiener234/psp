#include "player.h"

#include "enviorment.h"
#include "common/render.h"
#include "common/input.h"

float player_x = 150,player_y = 150;

float gravity = 1;

int isGrounded = 0;
int isJumping = 0;
int jumpHeight = 0;
int isJumpingAllowd = 0;
int jump = PLAYER_JUMP_FORCE;
int noRightWall = 0;

int currentCollision = 0;

enum player_collision_stat {
    TL = 1,
    TR = 2,
    BL = 4,
    BR = 9,
};

int TLO = 0;
int TRO = 0;
int BLO = 0;
int BRO = 0;

void player_update(){
    //move on x right
    if(RIGHT_DOWN && player_x>=0 && player_x<=SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = player_x + 1 * PLAYER_SPEED;
    }
    //move on x left
    else if(LEFT_DOWN && player_x>=0 && player_x<=SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = player_x - 1 * PLAYER_SPEED;
    }
    /* if(UP_DOWN && player_y >= 0 && player_y<= SCREEN_HEIGHT - PLAYER_HEIGHT){ */
    /*     player_y = player_y - 1 * PLAYER_SPEED; */
    /* } */
    /* else if(DOWN_DOWN && player_y>=0 && player_y<=SCREEN_HEIGHT - PLAYER_HEIGHT){ */
    /*     player_y = player_y + 1 * PLAYER_SPEED; */
    /* } */

    // keep player in bounds
    if(player_x<0){
        player_x = 0;
    }
    if(player_x>SCREEN_WIDTH - PLAYER_WIDTH){
        player_x = SCREEN_WIDTH - PLAYER_WIDTH;
    }

    if(player_y<0){
        player_y = 0;
    }
    if(player_y>SCREEN_HEIGHT - PLAYER_HEIGHT){
        player_y = SCREEN_HEIGHT - PLAYER_HEIGHT;
    }

    currentCollision = 0;
    TLO = 0;
    TRO = 0;
    BLO = 0;
    BRO = 0;
    for(int i=0; i<env_cords_len; i++){
        // top left corner collision
        if(enviorment[i].x <= player_x && player_x <= enviorment[i].x + enviorment[i].length
           && enviorment[i].y <=player_y && player_y <= enviorment[i].y + enviorment[i].height){
            currentCollision += TL;
            TLO = i;
        }
        // bottom right corner collision
        if(enviorment[i].x <= player_x + PLAYER_WIDTH && player_x + PLAYER_WIDTH <= enviorment[i].x + enviorment[i].length
           && enviorment[i].y <=player_y + PLAYER_HEIGHT && player_y + PLAYER_HEIGHT <= enviorment[i].y + enviorment[i].height){
            noRightWall = 1;
            currentCollision += BR;
            BRO = i;
        }
        // top right corner collision
        if(enviorment[i].x <= player_x + PLAYER_WIDTH && player_x + PLAYER_WIDTH <= enviorment[i].x + enviorment[i].length
           && enviorment[i].y <=player_y && player_y <= enviorment[i].y + enviorment[i].height){
            currentCollision += TR;
            TRO = i;
        }
        // bottom left corner collision
        if(enviorment[i].x <= player_x && player_x <= enviorment[i].x + enviorment[i].length
           && enviorment[i].y <=player_y +PLAYER_HEIGHT && player_y + PLAYER_HEIGHT <= enviorment[i].y + enviorment[i].height){
            currentCollision += BL;
            BLO = i;
        }
    }

    
    // jump and grounded logic
    if(currentCollision == BL + BR || currentCollision == BL && currentCollision != TL + BL ){
        player_y = enviorment[BLO].y - PLAYER_HEIGHT;
        gravity = 1;
        isGrounded = 1;
        isJumping = 0;
        jump = PLAYER_JUMP_FORCE;
    }
    else if(currentCollision == TL + BL + BR){
        player_y = enviorment[BRO].y - PLAYER_HEIGHT;
        gravity = 1;
        isGrounded = 1;
        isJumping = 0;
        jump = PLAYER_JUMP_FORCE;
    }
    else if(currentCollision == TR + BR + BL){
        player_y = enviorment[BRO].y - PLAYER_HEIGHT;
        gravity = 1;
        isGrounded = 1;
        isJumping = 0;
        jump = PLAYER_JUMP_FORCE;
    }
    else if(currentCollision == BR && currentCollision != BR + TR){
        player_y = enviorment[BRO].y - PLAYER_HEIGHT;
        gravity = 1;
        isGrounded = 1;
        isJumping = 0;
        jump = PLAYER_JUMP_FORCE;
    }
    else{
        gravity = gravity * 1.08;
        player_y = player_y + gravity;
    }

    if(isGrounded){
        if(CROSS_DOWN && !isJumping && isJumpingAllowd){
            isJumpingAllowd = 0;
            isGrounded = 0;
            isJumping = 1;
        }else if(!CROSS_DOWN){
            isJumpingAllowd = 1;
        }
    }

    if(isJumping){
        jump = jump * 0.99;
        player_y = player_y - jump; 
    }

    if(currentCollision == TL + BL || currentCollision == TL + BL + BR || currentCollision == TL){
        player_x = enviorment[TLO].x + enviorment[TLO].length;
    }
    if(currentCollision == TR + BR || currentCollision == TR + BR + BL || currentCollision == TR){
        player_x = enviorment[TRO].x - PLAYER_WIDTH - .1;
    }
    

    
}

void player_render(){
    drawRect(player_x, player_y, PLAYER_WIDTH, PLAYER_HEIGHT, 0x00000000);
    if(currentCollision == TL + BL){
        drawRect(10, 10, 15, 15, 0xff00ff);
    }
}
