#ifndef ANIMATION_INCLUDE
#define ANIMATION_INCLUDE

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../GlobalEnums/AnimationType.h"

class Animation
{
    AnimationType animationType;

public:
    Animation(
        sf::Texture* texture,
        AnimationType animationType,
        sf::Vector2u imageCount,
        float switchTime);
    ~Animation();

    void Update(int row, float deltaTime);
public:
    sf::IntRect uvRect;
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float totalTime;
    float switchTime;
};

#endif // ANIMATION_INCLUDE