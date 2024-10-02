/*
 * Author: Joshua Carroll, Michael Pressman
 * Assignment Title: Falling Balls
 * Assignment Description: This program runs a falling balls game using
 *       sdl plotter.
 * Class Description:This class represents the object in the game.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */

#include "Object.h"

Object::Object(point location , int rad , color c , int nhits){
    loc = location;
    _color = c;
    radius = rad;
    hits = nhits;
    destroyed = false;
    addBallObj = false;
    touching = false;
}

void Object::setLocation(point l){
    loc = l;
}
void Object::setColor(color c){
    _color = c;
}
void Object::setRadius(int r){
    radius = r;
}
void Object::setHits(int h){
    hits = h;
}

void Object::setDestroyed(SDL_Plotter& g ) {
    destroyed = true;
    display(g, 1,true);
    if(!addBallObj){
        loc.x = 651 + radius;
        loc.y = 451 + radius;;
    }

}
void Object::setAddBallObj(){
    addBallObj = true;
    _color.R = 175;
    _color.G = 0;
    _color.B = 200;
    radius = 20;
    hits = 1;
}

point Object::getLocation()const{
    return loc;
}
color Object::getColor()const{
    return _color;
}
int Object::getRadius() const{
    return radius;
}

int Object::getHits() const {
    return hits;
}
bool Object::getDestroyed() const{
    return destroyed;
}
bool Object::isAddBallObj() const{
    return addBallObj;
}

void Object::checkCollision(SDL_Plotter& g,Ball& ball){
    double minDist = radius + ball.getRadius();
    double dist;
    double angle;
    dist = sqrt(pow(ball.getLocation().x - loc.x, 2) +
            (pow(ball.getLocation().y - loc.y, 2)));
    if(touching){
        if(dist <= minDist ) {
            touching = false;
            angle = atan2(loc.y - ball.getLocation().y,
                          loc.x - ball.getLocation().x) - PI / 2;
            ball.collision(angle);
            display(g,1,true);
            hit(g);
            display(g, hits);
        }
    }
    else {
        if (dist > minDist ) {
            touching = true;
            display(g,hits);
        }
    }
}


void Object::display(SDL_Plotter& g, int h, bool ERASE){
    color c = _color;

    if (ERASE) {
        c.R = 255;
        c.G = 255;
        c.B = 255;
    }
    else if(!addBallObj){
        c.R = min(255, 50 + 20*h);
        c.G = min(255, 50 + int(0.5*20*h));
        c.B = 100;
    }
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            if (sqrt(pow(x, 2) + pow(y, 2)) <= radius) {
                g.plotPixel(x + loc.x, y + loc.y, c);
            }
        }
    }
}

void Object::moveUp(SDL_Plotter& g){
    display(g, hits,true);

    loc.y -= 125;
    display(g,hits);
}

void Object::hit(SDL_Plotter& g){
    hits--;
    if(hits <= 0){
        setDestroyed(g);
    }
    display(g,hits);
}

void Object::reset(){
    destroyed = false;
    touching = false;
}

