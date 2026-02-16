#ifndef PLAYER_H
#define PLAYER_H

#include"animatedSprite.h"
#include"globals.h"
class Graphics;

class Player :public AnimatedSprite{
public:
    Player();
    Player(Graphics &graphics, float x, float y);
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    /* moveLeft
     *  moves the player left by -dx
     */
    void moveLeft();
    
    /*  moveRight
     *  move the player right by dx
     */
    void moveRight();
    
    /* stopMoving
     * stops moving the player
     */
    void stopMoving();

    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimations();

private:
    float _dx, _dy;

    Direction _facing;
};

#endif