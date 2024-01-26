#include <pspkernel.h>
#include <pspgu.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include "input.h"
#include "pspdebug.h"
#include "render.h"

PSP_MODULE_INFO("gutest", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU | THREAD_ATTR_USER);

/* #define BUFFER_WIDTH 512 */
/* #define BUFFER_HEIGHT 272 */
/* #define SCREEN_WIDTH 480 */
/* #define SCREEN_HEIGHT BUFFER_HEIGHT */

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

/* char list[0x20000] __attribute__((aligned(64))); */

void initGu(){
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

/* void endGu(){ */
/*     sceGuDisplay(GU_FALSE); */
/*     sceGuTerm(); */
/* } */

/* void startFrame(){ */
/*     sceGuStart(GU_DIRECT, list); */
/*     sceGuClearColor(0xFFFFFFFF); // White background */
/*     sceGuClear(GU_COLOR_BUFFER_BIT); */
/* } */

/* void endFrame(){ */
/*     sceGuFinish(); */
/*     sceGuSync(0, 0); */
/*     sceDisplayWaitVblankStart(); */
/*     sceGuSwapBuffers(); */
/* } */

/* typedef struct { */
/*     unsigned short u, v; */
/*     float x, y, z; */
/* } Vertex; */

/* void drawRect(float x, float y, float w, float h) { */

/*     Vertex* vertices = (struct Vertex*)sceGuGetMemory(2 * sizeof(Vertex)); */

/*     vertices[0].x = x; */
/*     vertices[0].y = y; */

/*     vertices[1].x = x + w; */
/*     vertices[1].y = y + h; */

/*     sceGuColor(0xFF0000FF); // Red, colors are ABGR */
/*     sceGuDrawArray(GU_SPRITES, GU_TEXTURE_16BIT | GU_VERTEX_32BITF | GU_TRANSFORM_2D, 2, 0, vertices); */
/* } */


int main() {
    SceCtrlData pad;
    setup_callback();
    input_setup();
    initGu();
    pspDebugScreenInit();
    float x,y = 32;
    while(!done){
        
        sceCtrlReadBufferPositive(&pad, 1);
        
        input_stick(&pad);
        x = x+LX;
        y = y+LY;
        
        /* pspDebugScreenSetXY(0,1); */
        /* pspDebugScreenPrintf("X: %f  Y: %f   ", LX, LY); */
        start_frame();

        

        drawRect(x, y, 64, 64);

        end_frame();
    }

    return 0;
}
