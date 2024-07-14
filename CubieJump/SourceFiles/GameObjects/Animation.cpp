#include "Animation.h"

#include <stdexcept>

Animation::Animation(
        sf::Texture* texture,
        AnimationType animationType,
        sf::Vector2u imageCount,
        float switchTime) : animationType(animationType), imageCount(imageCount),
                            totalTime(0.f),
                            switchTime(switchTime)
{
    if(texture == nullptr)
        throw std::invalid_argument("Animation should have texture");
    uvRect.width = texture->getSize().x / imageCount.x;
    uvRect.height = texture->getSize().y / imageCount.y;
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime)
{
    currentImage.y = row;
    totalTime += deltaTime;
    if(totalTime>=switchTime)
    {
        totalTime-=switchTime;
        currentImage.x++;
        if(currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }
    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}
