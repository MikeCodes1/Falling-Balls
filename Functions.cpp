/*
 * Author: Joshua Carroll, Jeremy Huggins, Eli Hall, Michael Pressman
 * Assignment Title: Falling Balls
 * Assignment Description: This program runs a falling balls game using
 *       sdl plotter.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */

#include "Functions.h"

void colorScreen(SDL_Plotter& g, color c){
    for(int i=0; i<651; i++){
        for(int j =0; j < 451; j++){
            g.plotPixel(point(j,i),c);
        }
    }
}
