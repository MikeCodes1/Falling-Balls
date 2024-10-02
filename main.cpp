/*
 * Author: Joshua Carroll, Jeremy Huggins, Eli Hall, Michael Pressman
 * Assignment Title: Falling Balls
 * Assignment Description: This program runs a falling balls game using
 *       sdl plotter.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */

#include "AllObjects.h"
#include "Font.h"
#include "Functions.h"
using namespace std;

int main(int argc, char** argv) {
    //Data Abstraction
    SDL_Plotter g(650, 450);
    AllBalls allBalls(1);
    char key;
    bool roundStart = false, overScreen = false, beginScreen = true;
    AllObjects allObj;
    int points = 0;
    unsigned int count = 0;
    Font text1(4, point(45,200), color(70,120,80));		//start screen
    Font text2(4, point(115,200), color(150,30,30));		//end screen
    Font text3(4, point(45,285), color(150,30,30));		//retry screen
    Font num(5, point(410,10),color(100,100,100));
    char start[14]={'C','L','I','C','K',' ','T','O',' ','S','T','A','R','T'};
    char end[9] = {'G','A','M','E',' ','O','V','E','R'};
    char retry[14]={'C','L','I','C','K',' ','T','O',' ','R','E','T','R','Y'};

    //Input
    //Process
    while(!g.getQuit()) {
        if(g.kbhit()) {
            key = g.getKey();
            switch(toupper(key)) {
                case 'C': g.clear();
                    break;
            }
        }

        count++;
        if(count%30==0) {
            //Update
            //start screen
            if(g.mouseClick() && overScreen){
                g.getMouseClick();
                overScreen = false;
                allObj.gameReset(g);
                points = 0;
                allBalls.gameReset();
                colorScreen(g, color(255,255,255));
            }


            if(beginScreen){
                colorScreen(g,color(100,255,100));
                text1.PrintText(g, start, 14);
                if(g.mouseClick()){
                    g.getMouseClick();
                    beginScreen = false;
                    for(int i=0; i<651; i++){
                        for(int j =0; j < 451; j++){
                            g.plotPixel(point(j,i),color(255,255,255));
                        }
                    }
                }
            }
            if(!overScreen && !beginScreen) {
                allObj.startObjects(g, 0);
                allBalls.startBalls(g);
                if (g.mouseClick() && !roundStart) {
                    roundStart = true;
                }
                //Round begins
                if (roundStart) {
                    allBalls.launchNextBall(g, g.getMouseClick());
                    allObj.checkAllCollisions(g, allBalls);
                    allBalls.checkBallCollision();
                    num.PrintScore(g,points, true);
                    points = allObj.getPoints();
                    num.PrintScore(g,points);

                    if (allBalls.isRoundOver()) {
                        roundStart = false;
                        allBalls.resetBalls(g);
                        allObj.reset(g, points);
                        if (allObj.gameOver()) {
                            overScreen = true;
                            colorScreen(g,color(255,100,100));
                            text2.PrintText(g, end, 9);
                            text3.PrintText(g, retry, 14);
                        }
                    }
                }
            }
            //Output
            g.update();
        }
    }
    return 0;
}
