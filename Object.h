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

#ifndef GROUPPROJECT_OBJECT_H
#define GROUPPROJECT_OBJECT_H
#include "Ball.h"

class Object{
private:
    point loc ;
    color _color ;
    int radius;
    int hits;
    bool destroyed, touching, addBallObj;


public:
    /*
     * description: Creates an object with a location, radius, color, and
     * hitpoints.
     * return: N/A
     * precondition: None
     * postcondition: An object is created with the given values.
     *
     */
    Object(point location = point(250, 300), int rad = 40,
           color c = color(100,100,100), int nhits=1);

    /*
    * description: Sets the location of an object.
     * return: N/A
     * precondition: An object exists and a point is given.
     * postcondition: The object’s location is set to the point.
     *
     */
    void setLocation(point l);

    /*
     * description: Sets the color of an object.
     * return: N/A
     * precondition: An object exists and a color is given.
     * postcondition: The object’s color is set to the given color.
     *
     */
    void setColor(color c);

    /*
    * description: Sets the radius of an object.
    * return: N/A
    * precondition: An int is given.
    * postcondition: The object’s radius is set to the int.
    *
    */
    void setRadius(int r);

    /*
     * description: Sets the hit points of an object.
     * return: N/A
     * precondition: An int is given.
     * postcondition: The object’s hit points are set to the int.
     *
     */
    void setHits(int h);


    /*
     * description: Sets the destroyed status of the object.
     * return: N/A
     * precondition: SDL_Plotter object is passed as a parameter.
     * postcondition: The object is marked as destroyed, displayed, and its
     *      location is updated if it's not an additional ball object.
     *
     */
    void setDestroyed(SDL_Plotter&);

    /*
     * description: Sets the additional ball object flag.
     * return: N/A
     * precondition: None.
     * postcondition: The additional ball object flag is set to true,
     *      and color, radius, and hits are updated accordingly.
     *
     */
    void setAddBallObj();

    /*
     * description: Gets the object’s location as a point.
     * return: point
     * precondition: An object with a location exists.
     * postcondition: The object’s location is returned.
     *
     */
    point getLocation()const;

    /*
    * description: Gets the object’s color.
    * return: color
    * precondition: An object with a color exists.
    * postcondition: The object’s color is returned.
    *
    */
    color getColor()const;

    /*
    * description: Gets the object’s radius.
    * return: int
    * precondition: An object with a radius exists.
    * postcondition: The object’s radius is returned.
    *
    */
    int getRadius() const;

    /*
    * description: Gets the object’s hit points.
    * return: int
    * precondition: An object with hit points exists.
    * postcondition: The object’s hit points are returned.
    *
    */
    int getHits() const;

    /*
     * description: Gets the destroyed status of the object.
     * return: bool
     * precondition: None
     * postcondition: Returns true if the object is destroyed, false otherwise.
     *
     */
    bool getDestroyed() const;

    /*
     * description: Gets the additional ball object flag.
     * return: bool
     * precondition: N/A
     * postcondition: Returns true if the object is an additional ball object,
     *          false otherwise.
     *
     */
    bool isAddBallObj() const;

    /*
     * description: Checks for collision with a ball.
     * return: N/A
     * precondition: SDL_Plotter object and a Ball object are passed as
     *       parameters.
     * postcondition: Updates the touching status and performs collision
     *       handling.
     *
     */
    void checkCollision(SDL_Plotter& g,Ball&);

    /*
    * description: Displays the object on the SDL_Plotter.
    * return: N/A
    * precondition: SDL_Plotter object is passed as a parameter.
    * postcondition: The object is displayed with the specified color and
    *                radius.
    *
    */
    void display(SDL_Plotter&, int h, bool=false);

    /*
     * description: Moves the object upward on the SDL_Plotter.
     * return: N/A
     * precondition: SDL_Plotter object is passed as a parameter.
     * postcondition: The object is displayed, moved upward, and redisplayed.
     *
     */
    void moveUp(SDL_Plotter&);

    /*
     * description: Handles a hit on the object.
     * return: N/A
     * precondition: SDL_Plotter object is passed as a parameter.
     * postcondition: The hits count is decremented, and if hits reach zero,
     *      the object is marked as destroyed and displayed accordingly.
     *
     */
    void hit(SDL_Plotter& g);

    /*
     * description: resets the objects values for collision
     * return: N/A
     * precondition: the object is good
     * postcondition: the balls values for checking collision are reset.
     *
     */
    void reset();
};
#endif //GROUPPROJECT_OBJECT_H
