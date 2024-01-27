// main.c
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pspgu.h>

#include "input.h"
#include "render.h"
#include "player.h"
#include "enviorment.h"

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

void init_gu(){
    sceGuInit();

    //Set up buffers
    sceGuStart(GU_DIRECT, list);
    sceGuDrawBuffer(GU_PSM_8888,(void*)0,BUFFER_WIDTH);
    sceGuDispBuffer(SCREEN_WIDTH,SCREEN_HEIGHT,(void*)0x88000,BUFFER_WIDTH);
    sceGuDepthBuffer((void*)0x110000,BUFFER_WIDTH);

    //Set up viewport
    sceGuOffset(2048 - (SCREEN_WIDTH / 2), 2048 - (SCREEN_HEIGHT / 2));
    sceGuViewport(2048, 2048, SCREEN_WIDTH, SCREEN_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    //Set some stuff
    sceGuDepthRange(65535, 0); //Use the full buffer for depth testing - buffer is reversed order

    sceGuDepthFunc(GU_GEQUAL); //Depth buffer is reversed, so GEQUAL instead of LEQUAL
    sceGuEnable(GU_DEPTH_TEST); //Enable depth testing

    sceGuFinish();
    sceGuDisplay(GU_TRUE);
}

void update(){
   player_update(); 
}

void render(){
   player_render(); 
   enviorment_render();
}

int main(){

    SceCtrlData pad;

    /* pspDebugScreenInit(); */
    setup_callback();
    
    input_setup();
    init_gu();

    float x = 32;
    float y = 32;
    
    
    while(!done){

        sceCtrlReadBufferPositive(&pad, 1);
        
        /* pspDebugScreenSetXY(50,1); */
        
        input_button(&pad);
        input_stick(&pad);

        x = x+LX;
        y = y+LY;

        update();
        start_frame();

        render();
         
        end_frame();


        
    }
    sceKernelExitGame();

    return 0;
}
