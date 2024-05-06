#include "simulation.h"

Simulation::Simulation(u16 width, u16 height)
{
    // Set the simulation width and height
    m_width = width;
    m_height = height;

    // Allocate the particle buffer and working buffer
    particleBuffer = (u8*)malloc(m_width * m_height);
    workingBuffer = (u8*)malloc(m_width * m_height);

    // Clear the particle buffer
    memset(particleBuffer, 0, m_width * m_height);

    // Initialize the simulation's display
    displayBackground = bgInitSub(2, BgType_Bmp8, BgSize_B8_256x256, 0, 0);

    // Set up the background palette
    BG_PALETTE_SUB[0] = ARGB16(1, 0, 0, 0);
    BG_PALETTE_SUB[1] = ARGB16(1, 10, 10, 10);
    BG_PALETTE_SUB[2] = ARGB16(1, 20, 20, 20);
    BG_PALETTE_SUB[3] = ARGB16(1, 31, 31, 31);
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
    memset(workingBuffer, 0, m_width * m_height);

    // Update each cell
    for (int i = 0; i < m_width * m_height; i++)
    {
        workingBuffer[i] = (particleBuffer[i] + 1) % 4;
    }

    // Copy the working buffer back to the particle buffer
    memcpy(particleBuffer, workingBuffer, m_width * m_height);
}

void Simulation::draw()
{
    // Copy the particle buffer
    u16* gfxPtr = bgGetGfxPtr(displayBackground);
    memcpy(gfxPtr, particleBuffer, m_width * m_height);
}