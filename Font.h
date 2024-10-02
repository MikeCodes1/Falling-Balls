/*
 * Author:Eli Hall
 * Assignment Title: Falling Balls
 * Class Description: This class represents the font in the game.
 * Due Date: 12/6/2023
 * Date Created: 11/26/2023
 * Date Last Modified: 12/6/2023
 */

#ifndef GROUPPROJECT_FONT_H
#define GROUPPROJECT_FONT_H

#include "SDL_Plotter.h"
#include <string>
#include <fstream>
#include <cmath>

class Font{
private:
    int size;
    point loc;
    color _color;
public:

    /*
    * description: Creates a font with a size, location, and color
    * return: N/A
    * precondition: None
    * postcondition: A font is created
    *
    */
    Font();

    /*
     * description: Creates a font given a size, point, and color
     * return: N/A
     * precondition: An int, point, and color are given
     * postcondition: A font is created
     *
     */
    Font(int s, point p, color c);

    /*
     * description: Sets the font size
     * return: N/A
     * precondition: An int is given
     * postcondition: The font’s size is set to the int
     *
     */
    void setSize(int);

    /*
     * description: Sets the font location given a point.
     * return: N/A
     * precondition: A point is given.
     * postcondition: The font’s location is set to the point
     *
     */
    void setLoc(point);

    /*
     * description: Sets the font color given a color.
     * return: N/A
     * precondition: A color is given.
     * postcondition: The  font’s color is set to the given color.
     *
     */
    void setColor(color);



    /*
     * description: Prints the game’s score given an int
     * return: N/A
     * precondition: A SDL_Plotter and a score int are given.
     * postcondition: The score is updated on the display.
     *
     */
    void PrintScore(SDL_Plotter&, int, bool = false);

    /*
    * description: Prints a line of text given a char array.
     * return: N/A
     * precondition: A SDL_Plotter, char array, and int for the size of the
     * array are given
     * postcondition: The char array is displayed on the screen
     *
     */
    void PrintText(SDL_Plotter&, char[], int, bool = false);

};


#endif //GROUPPROJECT_FONT_H
