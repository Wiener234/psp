#include "enviorment.h"
#include "common/render.h"

//color = abgr

Enviorment enviorment[] ={
    {0, 200, 200, 40},
    {200, 160, 200, 40},
    {200, 200, SCREEN_WIDTH, 40},

    
    /* {100, 100, 20, 100}, */
    /* {120, 80, 100, 20}, */
    /* {120, 200, 100, 20}, */
    /* {220, 100, 20, 100}, */
    
};
int env_cords_len = sizeof(enviorment)/sizeof(enviorment[0]);

void enviorment_render(){
    for(int i=0; i<env_cords_len; i++){
        drawRect(enviorment[i].x, enviorment[i].y, enviorment[i].length, enviorment[i].height, 0xFF0000FF);
    }
    /* drawRect(0, 200, SCREEN_WIDTH, 40, 0xFF0000FF); */
    /* drawRect(200, 160, SCREEN_WIDTH, 40, 0xaa0000FF); */
}
