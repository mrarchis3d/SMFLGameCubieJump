#include "Actor.h"

void Actor::InitializeComponents()
{
    
}

Animation* Actor::GetAnimation() const
{
    return animation;
}

Actor::Actor()
{
    InitializeComponents();
}

Actor::~Actor()
{
}

void Actor::Update()
{

}

