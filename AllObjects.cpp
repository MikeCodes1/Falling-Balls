/*
 * Author: Joshua Carroll, Michael Pressman
 * Assignment Title: Falling Balls
 * Assignment Description: This program runs a falling balls game using
 *       sdl plotter.
 * Class Description:This class represents all the objects in the game.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */
#include "AllObjects.h"

AllObjects::AllObjects(){
    _gameOver = false;
    started = false;
    points = 0;
}

void AllObjects::setStarted(bool b){
    started = b;
}

bool AllObjects::getStarted()const{
    return started;
}

int AllObjects::getPoints() const {
    return points;
}

void AllObjects::addObject(Object obj){
    allObjects.push_back(obj);
}

void AllObjects::addPoints(int p) {
    points += p;
}

int AllObjects::getNumObjects() const{
    return allObjects.size();
}

bool AllObjects::gameOver(){
    for(unsigned int i=0; i<allObjects.size(); i++) {
        if (allObjects.at(i).getLocation().y < 0 + allObjects.at(i).getRadius()) {
            _gameOver = true;
        }
    }
    return _gameOver;
}

void AllObjects::moveEmAllUp(SDL_Plotter& g) {
    for (unsigned int i = 0; i < allObjects.size(); i++) {
        allObjects.at(i).moveUp(g);
    }
}

void AllObjects::startObjects(SDL_Plotter& g, int p){
    if(!started) {
        srand(time(NULL));
        int x, y;
        int numObj = rand() % 4 + 1;
        int colW=450/numObj;
        for (int i = 0; i < numObj; i++) {
            Object obj;
            x=rand()%(colW - 2*obj.getRadius()) + (obj.getRadius()) + i*colW;
            y = 610 - obj.getRadius();
            obj.setLocation(point(x, y));
            obj.setHits((p/5)*2 + rand()%4 +1);
            if(rand()%16 == 2){
                obj.setAddBallObj();
            }
            allObjects.push_back(obj);
            obj.display(g,obj.getHits());
        }
        started = true;
    }
}


void AllObjects::checkAllCollisions(SDL_Plotter& g, AllBalls& b) {
    for(unsigned int j=0; j<b.getAmount(); j++) {
        for(unsigned int i=0; i<allObjects.size(); i++) {
            allObjects.at(i).checkCollision(g, b.getBall(j));
            if (allObjects.at(i).getDestroyed()) {
                if(allObjects.at(i).isAddBallObj()){
                    double x =allObjects.at(i).getLocation().x;
                    double y = allObjects.at(i).getLocation().y;
                    allObjects.at(i).display(g,0, true);
                    b.brokeBallObj(g, bPoint(x,y));
                    allObjects.at(i).setLocation(point(700, 500));
                }
                else{
                    points++;
                }
                allObjects.erase(allObjects.begin() + i);
                i--;
            }
        }
    }

}

void AllObjects::reset(SDL_Plotter& g, int p){
    moveEmAllUp(g);
    started = false;
    for(unsigned int i=0 ; i<allObjects.size(); i++){
        allObjects.at(i).reset();
    }
    startObjects(g, p);
}

void AllObjects::gameReset(SDL_Plotter& g){
    _gameOver = false;
    started = false;
    points = 0;
    for(unsigned int i=0; i<allObjects.size(); i++){
        allObjects.at(i).setDestroyed(g);
    }
    allObjects.clear();
}
