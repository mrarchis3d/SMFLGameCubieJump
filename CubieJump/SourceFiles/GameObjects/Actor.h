#pragma once
#include <list>
#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "../GlobalEnums/AnimationType.h"

class Actor
{
    Animation* animation; 
private:
    void InitializeComponents();
public:
    Actor();
    ~Actor();
    void Update();
    Animation* GetAnimation() const;
    void SetAnimationType(AnimationType AnimationType);

};
