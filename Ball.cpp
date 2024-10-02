/*
 * Author: Joshua Carroll, Jeremy Huggins, Eli Hall, Michael Pressman
 * Assignment Title: Falling Balls
 * Assignment Description: This program runs a falling balls game using
 *       sdl plotter.
 * Class Description:This class represents all the balls in the game.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */
#include "Ball.h"

Ball::Ball(){
    loc.x = -100;
    loc.y = -100;
    _color.R = 175;
    _color.G = 0;
    _color.B = 200;
    radius = 15;
    f.setDirection(PI/2);
    f.setMagnitude(0);
    offWall = true;
    canMove = false;
    inBall = false;
}

void Ball::setColor(color c){
    _color = c;
}

void Ball::setLocation(bPoint p){
    loc = p;
}

void Ball::setRadius(int r){
    radius = r;
}
void Ball::setOffWall(bool b){
    offWall = b;
}

void Ball::setBallF(force otherF){
    f = otherF;
}

void Ball::setMove(bool b){
    canMove = b;
}
void Ball::setInBall(bool b){
    inBall=  b;
}


color Ball::getColor() const{
    return _color;
}

point Ball::getLocation() const{
    return point(loc.x,loc.y);
}
force Ball::getBallF()const{
    return f;
}
int Ball::getRadius() const{
    return radius;
}

bool Ball::getMove() const {
    return canMove;
}
bool Ball::getInBall()const{
    return inBall;
}

void Ball::display(SDL_Plotter& g, bool ERASE){
    color c = _color;
    if(ERASE){
        c.R = 255;
        c.G = 255;
        c.B = 255;
    }
    for(int x = -radius; x <= radius; x++){
        for(int y = -radius; y <= radius; y++){
            if(sqrt(pow(x, 2) + pow(y, 2)) <= radius){
                g.plotPixel(x + loc.x, y + loc.y, c);
            }
        }
    }
}

void Ball::move(){
    wallCollision();
    loc.y += f.getMagnitude() * sin(f.getDirection());
    loc.x += f.getMagnitude() * cos(f.getDirection());
    f.apply(GRAVITY);
}

void Ball::collision(double angle){
    f.setDirection(2 * angle - f.getDirection());
    f.setMagnitude(0.85 * f.getMagnitude());
}


void Ball::wallCollision() {
    if(offWall){
        if(loc.x > 450 - radius || loc.x < 0 + radius){
            f.setDirection(PI - f.getDirection());
            f.setMagnitude(0.85 * f.getMagnitude());
            offWall = false;
        }
        if(loc.y<=0){
            f.setDirection(-f.getDirection());
            offWall = false;
        }
    }
    else if(loc.x <= 450 - radius && loc.x >= 0 + radius){
        offWall = true;
    }
}

bool Ball::isOffScreen() const {
    bool offScreen= false;
    if(loc.y >= 650 + getRadius()){
        offScreen = true;
    }
    return offScreen;
}

void Ball::reset(SDL_Plotter&){
    loc.x = -100;
    loc.y = -100;
    offWall = true;
    canMove = false;
    inBall = false;
}
