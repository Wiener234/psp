#ifndef INPUT_H
#define INPUT_H
#include <pspctrl.h>
#include <pspdebug.h>

#define printf pspDebugScreenPrintf

extern int TRIANGLE_DOWN;
extern int CIRCLE_DOWN;
extern int CROSS_DOWN;
extern int SQUARE_DOWN;
extern int UP_DOWN;
extern int RIGHT_DOWN;
extern int DOWN_DOWN;
extern int LEFT_DOWN;

extern float LX, LY;

void input_setup();

void input_button(SceCtrlData *pad);

void input_stick(SceCtrlData *pad);
#endif
