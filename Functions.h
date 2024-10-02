/*
 * Author: Joshua Carroll, Jeremy Huggins, Eli Hall, Michael Pressman
 * Assignment Title: Falling Balls
 * Assignment Description: This program runs a falling balls game using
 *       sdl plotter.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */

#ifndef GROUPPROJECT_FUNCTIONS_H
#define GROUPPROJECT_FUNCTIONS_H
#include "SDL_Plotter.h"

/*
 * description: colors the whole screen a given color
 * return: N/A
 * precondition: the given sdl plotter and color is good
 * postcondition: the pixles on the screen are set the given color
 */
void colorScreen(SDL_Plotter&, color);

#endif //GROUPPROJECT_FUNCTIONS_H
