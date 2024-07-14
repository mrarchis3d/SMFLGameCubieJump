#include "GlobalGameStatistics.h"
unsigned int GlobalGameStatistics::frameRateLimit = 60;
float GlobalGameStatistics::fps = 0.f;
float GlobalGameStatistics::deltaTime = 0.f;

unsigned int GlobalGameStatistics::GetFrameRateLimit() {
    return frameRateLimit;
}

float GlobalGameStatistics::GetFPS() {
    return fps;
}

float GlobalGameStatistics::GetDeltaTime()
{
    return deltaTime;
}

void GlobalGameStatistics::SetFPS(float FPS) {
    fps = FPS;
}

void GlobalGameStatistics::SetDeltaTime(float DeltaTime)
{
    deltaTime = DeltaTime;
}
