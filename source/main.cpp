#include <nds.h>
#include "simulation.h"

int main()
{
	// Initialize the video modes of both screens
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);

	// Create the simulation
	Simulation simulation = Simulation(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Game loop
	while (true)
	{
		simulation.update();
		
		simulation.draw();

		swiWaitForVBlank();
	}

	return 0;
}