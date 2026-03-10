#include "sprite.h"
#include "graphics.h"
#include "globals.h"

/*  Sprite class
 *  Stores position(_x, _y)
 *  Stores frame (_sourceRect)
 *  Stores texture (_spriteSheet)
 */

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
    float posX, float posY) :
        _x(posX),
        _y(posY)
{
    this->_sourceRect.x = sourceX;
    this->_sourceRect.y = sourceY;
    this->_sourceRect.w = width;
    this->_sourceRect.h = height;

    this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if (this->_spriteSheet == NULL){
        printf("\nError: Unable to load image\n");
    }
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics, int x, int y){
    SDL_Rect destinationRectangle = {
        x,
        y, 
        (int)(this->_sourceRect.w * globals::SPRITE_SCALE),
        (int)(this->_sourceRect.h * globals::SPRITE_SCALE)
    };
    
    graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

void Sprite::update() {}