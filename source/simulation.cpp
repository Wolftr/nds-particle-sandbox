#include "simulation.h"

Simulation::Simulation(u16 width, u16 height)
{
    // Set the simulation width and height
    m_width = width;
    m_height = height;

    // Allocate the working buffer
    workingBuffer = (u8*)malloc(m_width * m_height);

    // Initialize the simulation's display
    displayBackground = bgInitSub(2, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
    
    // Get the pointer to the texture data
    particleBuffer = (u8*)bgGetGfxPtr(displayBackground);

    // Set up the background palette
    for (int i = 0; i < 32; i++)
    {
        BG_PALETTE_SUB[i] = ARGB16(1, i, i, i);
    }
}

Simulation::~Simulation()
{
    // Free the particle buffer and the working buffer
    free(particleBuffer);
    free(workingBuffer);
}

void Simulation::update()
{
    // Clear the working buffer
    // memset(workingBuffer, 0, m_width * m_height);

    // Update each cell
    for (int i = 0; i < m_width * m_height; i++)
    {
        workingBuffer[i] = i % 32;
    }
}

void Simulation::draw()
{
    // Copy the working buffer to the particle buffer
    DC_FlushRange(workingBuffer, m_width * m_height);
    for (int i = 0; i < m_height - 127; i++)
    {
        dmaCopy(workingBuffer, particleBuffer + (i * m_width), m_width);
    }
}