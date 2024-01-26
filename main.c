// main.c
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


PSP_MODULE_INFO("Dev", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

#define printf pspDebugScreenPrintf

int done = 0;

int exit_callback(int arg1, int arg2, void *common){
    done = 1;
    return 0;
}

int callback_thread(SceSize args, void *argp){
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
    return 0;
}

int setup_callback(){
    int thid = sceKernelCreateThread("update_thread", callback_thread, 0x11, 0xFA0, 0, NULL);
    if(thid >= 0){
        sceKernelStartThread(thid, 0, 0);
    }
    return thid;
}

float normAnalog(int y){
    float x = (float) y;
    if(y == 128){
        return 0;
    }
    return roundf((x/128 - 1) * 100.0f)/100.0f;
}

int main(){

    SceCtrlData pad;

    int pressed = 0;

    int triangleDown = 0;
    int circleDown = 0;
    int crossDown = 0;
    int squareDown = 0;
    int upDown = 0;
    int rightDown = 0;
    int downDown = 0;
    int leftDown = 0;
    
    pspDebugScreenInit();
    setup_callback();
    
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
    
    while(!done){

        sceCtrlReadBufferPositive(&pad, 1);
        
        pspDebugScreenSetXY(0,1);
        

        printf("X: %.2f Y: %.2f      \n", normAnalog(pad.Lx), normAnalog(pad.Ly));

        if(pad.Buttons & PSP_CTRL_TRIANGLE && !triangleDown){
            triangleDown = 1;
            printf("\nTriangle\n");
        }else if(!(pad.Buttons & PSP_CTRL_TRIANGLE) && triangleDown){
            triangleDown = 0;
        }
        
        if(pad.Buttons & PSP_CTRL_CIRCLE && !circleDown){
            circleDown = 1;
            printf("\nCircle\n");
        }else if(!(pad.Buttons & PSP_CTRL_CIRCLE) && circleDown){
            circleDown = 0;
        }
        
        if(pad.Buttons & PSP_CTRL_CROSS && !crossDown){
            crossDown = 1;
            printf("\nCross\n");
        }else if(!(pad.Buttons & PSP_CTRL_CROSS) && crossDown){
            crossDown = 0;
        }
        
        if(pad.Buttons & PSP_CTRL_SQUARE && !squareDown){
            squareDown = 1;
            printf("\nSquare\n");
        }else if(!(pad.Buttons & PSP_CTRL_SQUARE) && squareDown){
            squareDown = 0;
        }
        
        if(pad.Buttons & PSP_CTRL_UP && !upDown){
            upDown = 1;
            printf("\nUp\n");
        }else if(!(pad.Buttons & PSP_CTRL_UP) && upDown){
            upDown = 0;
        }
        
        if(pad.Buttons & PSP_CTRL_RIGHT && !rightDown){
            rightDown = 1;
            printf("\nRight\n");
        }else if(!(pad.Buttons & PSP_CTRL_RIGHT) && rightDown){
            rightDown = 0;
        }

        if(pad.Buttons & PSP_CTRL_DOWN && !downDown){
            downDown = 1;
            printf("\nDown\n");
        }else if(!(pad.Buttons & PSP_CTRL_DOWN) && downDown){
            downDown = 0;
        }
        
        if(pad.Buttons & PSP_CTRL_LEFT && !leftDown){
            leftDown = 1;
            printf("\nLeft\n");
        }else if(!(pad.Buttons & PSP_CTRL_LEFT) && leftDown){
            leftDown = 0;
        }
        
        if(pad.Buttons & PSP_CTRL_HOLD){
            printf("                                   ");
        }
    }
    sceKernelExitGame();

    return 0;
}
