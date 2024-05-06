#ifndef SUB_DISPLAY_H
#define SUB_DISPLAY_H

#include <nds.h>

class SubDisplay
{
public:
	SubDisplay();

	void swapBuffers();
public:
	const u16 BUFFER_SIZE = SCREEN_WIDTH * SCREEN_HEIGHT;

	const VideoMode FB_A_MODE = MODE_FB2;
	const VideoMode FB_B_MODE = MODE_FB3;
private:
	u16* activeBuffer;
	u16* workingBuffer;
};

#endif