#pragma once

class GlobalGameStatistics
{
    static unsigned int frameRateLimit;
    static float fps;
    static float deltaTime;
public:
    static unsigned int GetFrameRateLimit();
    static float GetFPS();
    static float GetDeltaTime();
protected:
    static void SetFPS(float FPS);
    static void SetDeltaTime(float DeltaTime);
};