#include "input.h"
#include <pspctrl.h>
#include <math.h>

int TRIANGLE_DOWN = 0;
int CIRCLE_DOWN = 0;
int CROSS_DOWN = 0;
int SQUARE_DOWN = 0;
int UP_DOWN = 0;
int RIGHT_DOWN = 0;
int DOWN_DOWN = 0;
int LEFT_DOWN = 0;

float LX, LY = 0;

void input_setup(){
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
}

float normAnalog(int y){
    float x = (float) y;
    x = roundf((x/128 - 1) * 100.0f)/100.0f;
    if(x< -.15f ||x>.15f){
        return x;
    }
    return 0;
}

void input_stick(SceCtrlData *pad){
    if(!RIGHT_DOWN || !LEFT_DOWN){
        LX = normAnalog(pad->Lx);
        LY = normAnalog(pad->Ly);
    }
}

void input_button(SceCtrlData *_pad){

    SceCtrlData pad = *_pad;
    
    if(pad.Buttons & PSP_CTRL_TRIANGLE && !TRIANGLE_DOWN){
        TRIANGLE_DOWN = 1;
        printf("\nTriangle\n");
    }else if(!(pad.Buttons & PSP_CTRL_TRIANGLE) && TRIANGLE_DOWN){
        TRIANGLE_DOWN = 0;
    }

    if(pad.Buttons & PSP_CTRL_CIRCLE && !CIRCLE_DOWN){
        CIRCLE_DOWN = 1;
        printf("\nCircle\n");
    }else if(!(pad.Buttons & PSP_CTRL_CIRCLE) && CIRCLE_DOWN){
        CIRCLE_DOWN = 0;
    }

    if(pad.Buttons & PSP_CTRL_CROSS && !CROSS_DOWN){
        CROSS_DOWN = 1;
        printf("\nCross\n");
    }else if(!(pad.Buttons & PSP_CTRL_CROSS) && CROSS_DOWN){
        CROSS_DOWN = 0;
    }

    if(pad.Buttons & PSP_CTRL_SQUARE && !SQUARE_DOWN){
        SQUARE_DOWN = 1;
        printf("\nSquare\n");
    }else if(!(pad.Buttons & PSP_CTRL_SQUARE) && SQUARE_DOWN){
        SQUARE_DOWN = 0;
    }

    if(pad.Buttons & PSP_CTRL_UP && !UP_DOWN){
        UP_DOWN = 1;
        printf("\nUp\n");
    }else if(!(pad.Buttons & PSP_CTRL_UP) && UP_DOWN){
        UP_DOWN = 0;
    }

    if(pad.Buttons & PSP_CTRL_RIGHT && !RIGHT_DOWN){
        RIGHT_DOWN = 1;
    }else if(!(pad.Buttons & PSP_CTRL_RIGHT) && RIGHT_DOWN){
        RIGHT_DOWN = 0;
    }

    if(pad.Buttons & PSP_CTRL_DOWN && !DOWN_DOWN){
        DOWN_DOWN = 1;
        printf("\nDown\n");
    }else if(!(pad.Buttons & PSP_CTRL_DOWN) && DOWN_DOWN){
        DOWN_DOWN = 0;
    }

    if(pad.Buttons & PSP_CTRL_LEFT && !LEFT_DOWN){
        LEFT_DOWN = 1;
    }else if(!(pad.Buttons & PSP_CTRL_LEFT) && LEFT_DOWN){
        LEFT_DOWN = 0;
    }

    if(pad.Buttons & PSP_CTRL_HOLD){
        printf("                                   ");
    }
}
