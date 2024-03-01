#include "enviorment.h"
#include "common/render.h"

//color = abgr

int env_cords[][2] = {{0,200},{200,160}};
int env_cords_len = sizeof(env_cords)/sizeof(env_cords[0]);

void enviorment_render(){
    for(int i=0; i<sizeof(env_cords)/sizeof(env_cords[0]); i++){
        drawRect(env_cords[i][0], env_cords[i][1], SCREEN_WIDTH, 40, 0xFF0000FF);
    }
    /* drawRect(0, 200, SCREEN_WIDTH, 40, 0xFF0000FF); */
    /* drawRect(200, 160, SCREEN_WIDTH, 40, 0xaa0000FF); */
}
