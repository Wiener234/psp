#include "render.h"

#include <pspgu.h>
#include <pspdisplay.h>

char list[0x20000] __attribute__((aligned(64)));

//look header
/* void init_gu(){ */
/*     sceGuInit(); */

/*     //Set up buffers */
/*     sceGuStart(GU_DIRECT, list); */
/*     sceGuDrawBuffer(GU_PSM_8888,(void*)0,BUFFER_WIDTH); */
/*     sceGuDispBuffer(SCREEN_WIDTH,SCREEN_HEIGHT,(void*)0x88000,BUFFER_WIDTH); */
/*     sceGuDepthBuffer((void*)0x110000,BUFFER_WIDTH); */

/*     //Set up viewport */
/*     sceGuOffset(2048 - (SCREEN_WIDTH / 2), 2048 - (SCREEN_HEIGHT / 2)); */
/*     sceGuViewport(2048, 2048, SCREEN_WIDTH, SCREEN_HEIGHT); */
/*     sceGuEnable(GU_SCISSOR_TEST); */
/*     sceGuScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); */

/*     //Set some stuff */
/*     sceGuDepthRange(65535, 0); //Use the full buffer for depth testing - buffer is reversed order */

/*     sceGuDepthFunc(GU_GEQUAL); //Depth buffer is reversed, so GEQUAL instead of LEQUAL */
/*     sceGuEnable(GU_DEPTH_TEST); //Enable depth testing */

/*     sceGuFinish(); */
/*     sceGuDisplay(GU_TRUE); */
/* } */

void end_gu(){
    sceGuDisplay(GU_FALSE);
    sceGuTerm();
}

void start_frame(){
    sceGuStart(GU_DIRECT, list);
    sceGuClearColor(0xFFFFFFFF); // White background
    sceGuClear(GU_COLOR_BUFFER_BIT);
}

void end_frame(){
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

void drawRect(float x, float y, float w, float h, unsigned char color) {

    Vertex* vertices = (struct Vertex*)sceGuGetMemory(2 * sizeof(Vertex));

    vertices[0].x = x;
    vertices[0].y = y;

    vertices[1].x = x + w;
    vertices[1].y = y + h;

    sceGuColor(color); // Red, colors are ABGR
    sceGuDrawArray(GU_SPRITES, GU_TEXTURE_16BIT | GU_VERTEX_32BITF | GU_TRANSFORM_2D, 2, 0, vertices);
}
