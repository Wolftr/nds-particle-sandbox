#ifndef SIMULATION_H
#define SIMULATION_H

#include <nds.h>

class Simulation
{
public:
    Simulation(u16 width, u16 height);
    ~Simulation();

	void update();
	void draw();
private:
    void updateCell(u16 index);
private:
    u16 m_width;
    u16 m_height;

    u8* particleBuffer;
    u8* workingBuffer;

    u8 displayBackground;
};

#endif