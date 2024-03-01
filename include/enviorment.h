#ifndef ENVIORMENT_H
#define ENVIORMENT_H

typedef struct enviorment {
   float x;
   float y;
   float length;
   float height;
} Enviorment;

extern Enviorment enviorment[];
extern int env_cords_len;


void enviorment_update();

void enviorment_render();

#endif
