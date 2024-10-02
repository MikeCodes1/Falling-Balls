/*
 * Author: Joshua Carroll, Jeremy Huggins
 * Assignment Title: Falling Balls
 * Assignment Description: This program runs a falling balls game using
 *       sdl plotter.
 * Class Description:This class represents all the balls in the game.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */

#include "AllBalls.h"

AllBalls::AllBalls(int n){
    started = false;
    allBalls = vector<Ball>(n);
}

Ball& AllBalls::getBall(int i){
    return allBalls.at(i);
}

unsigned int AllBalls::getAmount(){
    return allBalls.size();
}

void AllBalls::addBall(Ball b){
    allBalls.push_back(b);
}

void AllBalls::resetBalls(SDL_Plotter& g){
    allBalls.at(0).setLocation(bPoint(INIT_X,allBalls.at(0).getRadius()));
    allBalls.at(0).display(g);
    for(int i=1; i<allBalls.size(); i++){
        allBalls.at(i).reset(g);
    }
}

void AllBalls::startBalls(SDL_Plotter& g){
    if(!started) {
        resetBalls(g);
    }
}
bool AllBalls::isRoundOver(){
    bool over = true;
    for(unsigned int i=0; i<allBalls.size(); i++){
        if(!allBalls.at(i).isOffScreen()){
            over = false;
        }
    }
    if(over){
        started = false;
    }
    return over;
}

void AllBalls::launchNextBall(SDL_Plotter& g, point p){
    point prev;
    point curr;
    double minDist;
    double dist;
    if(!started) {
        initF = force(INIT_M, (-atan((p.x - 225.0) / (p.y)) + PI / 2.0));
        allBalls.at(0).setBallF(initF);
        allBalls.at(0).setMove(true);
        started = true;
    }
    minDist = 5 * allBalls.at(0).getRadius();
    curr = point(INIT_X,allBalls.at(0).getRadius());
    for(int i=1; i<allBalls.size(); i++){
        if(!allBalls.at(i).getMove() && allBalls.at(i-1).getMove()){
            prev = allBalls.at(i-1).getLocation();
            dist = sqrt(pow(prev.x - curr.x, 2) + (pow(prev.y - curr.y, 2)));
            if(dist > minDist){
                allBalls.at(i).setBallF(initF);
                allBalls.at(i).setLocation(bPoint(INIT_X,
                                                  allBalls.at(i).getRadius()));
                allBalls.at(i).display(g);
                allBalls.at(i).setMove(true);
            }
        }
    }
    moveEmAll(g);
}

void AllBalls::moveEmAll(SDL_Plotter& g){
    for(unsigned int i = 0; i < allBalls.size(); i++){
        if(allBalls.at(i).getMove()){
            allBalls.at(i).display(g, true);
            allBalls.at(i).move();
            allBalls.at(i).display(g);
        }
    }
}

void AllBalls::checkBallCollision() {
    for(unsigned int i=0; i<allBalls.size(); i++){
        for(unsigned int j=i+1; j<allBalls.size(); j++){
            handleBallCollision(allBalls.at(i), allBalls.at(j));
        }
    }
}


void AllBalls::handleBallCollision(Ball& ball, Ball& otherBall) {
    double minDist = ball.getRadius() + otherBall.getRadius();
    double dist, angle, dir1, dir2, rS, avgMag;
    force f1, f2;

    dist = sqrt(pow(otherBall.getLocation().x - ball.getLocation().x, 2) +
            pow(otherBall.getLocation().y - ball.getLocation().y, 2));
    if (ball.getInBall() && otherBall.getInBall()) {
        if (dist <= minDist) {
            ball.setInBall(false);
            otherBall.setInBall(false);
            angle = atan2(ball.getLocation().y - otherBall.getLocation().y,
                          ball.getLocation().x - otherBall.getLocation().x);
            dir1 = 2*angle - otherBall.getBallF().getDirection();
            dir2 = 2*angle - ball.getBallF().getDirection();
            rS = ball.getBallF().getMagnitude() -
                    otherBall.getBallF().getMagnitude();
            if (rS > 0) {
                dir1 -= PI/2;
            } else if (rS < 0) {
                dir2 += PI/2;
            }
            avgMag = (ball.getBallF().getMagnitude() +
                    otherBall.getBallF().getMagnitude())/2.0;
            f1 = force(avgMag, dir1);
            f2 = force(avgMag, dir2);
            ball.setBallF(f1);
            otherBall.setBallF(f2);
        }
    } else {
        if (dist > minDist) {
            ball.setInBall(true);
            otherBall.setInBall(true);
        }
    }
}

void AllBalls::brokeBallObj(SDL_Plotter& g, bPoint p){
    addBall(Ball());
    allBalls.at(allBalls.size()-1).setBallF(force(2, (3*PI)/2));
    allBalls.at(allBalls.size()-1).setLocation(p);
    allBalls.at(allBalls.size()-1).setMove(true);
}

void AllBalls::gameReset(){
    started = false;
    allBalls.clear();
    allBalls.push_back(Ball());
}
