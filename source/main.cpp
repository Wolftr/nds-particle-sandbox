#include <nds.h>
#include <stdio.h>
#include "subDisplay.h"

int main()
{
	// Put the main rendering system on the bottom screen
	lcdMainOnBottom();

	// Initialize the main screen to frame buffer mode
	videoSetMode(MODE_FB0);

	// Map VRAM A and B to LCD
	vramSetBankA(VRAM_A_LCD);
	vramSetBankB(VRAM_B_LCD);

	// Set the active and working buffer
	u16* activeBuffer = VRAM_A;
	u16* workingBuffer = VRAM_B;

	// Game loop
	while (true)
	{
		// Write to the buffer
		for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		{
			workingBuffer[i] = ARGB16(1, 0, 0, rand() % 31);
		}


		// Swap buffers
		u16* temp = activeBuffer;
		activeBuffer = workingBuffer;
		workingBuffer = temp;

		if (activeBuffer == VRAM_A)
			videoSetMode(MODE_FB0);
		else
			videoSetMode(MODE_FB1);
	}

	return 0;
}