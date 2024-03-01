#ifndef RENDER_H
#define RENDER_H
#include <pspgu.h>

#define BUFFER_WIDTH 512
#define BUFFER_HEIGHT 272
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT BUFFER_HEIGHT

extern char list[];

typedef struct {
    unsigned short u, v;
    float x, y, z;
} Vertex;

//not working when in other file
/* void init_gu(); */

void end_gu();

void start_frame();

void end_frame();

void drawRect(float x, float y, float width, float height, unsigned int color);


#endif
