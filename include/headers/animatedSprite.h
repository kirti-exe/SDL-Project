#ifndef ANIMATED_SPRTIE_H
#define ANIMATED_SPRTIE_H

#include <vector>
#include <map>
#include <string>
#include "sprite.h"
#include "globals.h"
class Graphics;

/* AnimatedSprite class
 * Holds logic for animating sprites 
 */

class AnimatedSprite : public Sprite{
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
        float posX, float posY, float timeToUpdate);

    /* void playAnimation
     * Plays the animation provided if its not already playing
     */
    void playAnimation(std::string animation, bool once = false);
    
    /*void update
     * updates the animated sprite (timer)
     */
    void update(int elapsedTime);

    /* void draw
     *  draws the sprites to the screen
     */
   void draw(Graphics &graphics, int x, int y);

protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    /* void addAnimation
     * Adds on animation to the map of animations for the sprties
     */
    void addAnimation(int frames, int x, int y, std::string name, int widht, int height, Vector2 offset);

    /* void resetAnimations
     * Resets all  animations associated with this sprite
     */
    void resetAnimations();

    /* void stopAnimation
     * stop the current animations
     */
    void stopAnimation();

    /* void setVisible
     * changes the visibility of the animated sprite
     */
    void setVisible(bool visible);

    /* void animationDone
     * logic that happens when an animation ends
     */
    virtual void animationDone(std::string currentAnimation) = 0;

    /* void setupAnimations
     * a required function that sets up all animations for a sprite
     */
   virtual void setupAnimations() = 0;

private:
    std::map<std::string, std::vector<SDL_Rect>> _animations;
    std::map<std::string, Vector2> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};

#endif