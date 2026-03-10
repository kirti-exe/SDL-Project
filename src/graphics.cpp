#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include "graphics.h"
#include "globals.h"

/* Graphics
 * Handles all rendering
 * Converts images to GPU textures
 * Manages sprite sheets and rendering rectangles
 * Handles screen clearing and double-buffering
 */

Graphics::Graphics(){
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "CaveStory");
}

Graphics::~Graphics(){
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath){
    if(this->_spriteSheets.count(filePath) == 0){
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle){
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip(){
    SDL_RenderPresent(this->_renderer);
}
    
void Graphics::clear(){
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const{
    return this->_renderer;
}