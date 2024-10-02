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

#ifndef GROUPPROJECT_BALL_H
#define GROUPPROJECT_BALL_H

#include "SDL_Plotter.h"
#include <cmath>
#include "Force.h"

using namespace std;

const double INIT_M = 1;
const int INIT_X = 225;
const force GRAVITY(0.004, PI/2);

struct bPoint{
    double x,y;
    bPoint(){
        x = y = 0;
    }
    bPoint(double x, double y){
        this->x = x;
        this->y = y;
    }
};

class Ball{
private:
    bPoint loc;
    color _color;
    int radius;
    force f;
    bool offWall,inBall;
    bool canMove;

public:
    /*
     * description: Creates a ball that has a location, color, radius, and force
     * return: N/A
     * precondition: none
     * postcondition: the Ball is constructed with the default values
     */
    Ball();

    /*
     * description: sets the color of the Ball
     * return: N/A
     * precondition: The color is valid
     * postcondition: The color of the ball is updated.
     */
    void setColor(color);

    /*
     * description: Sets the location of the ball.
     * return: N/A
     * precondition: The bPoint is valid.
     * postcondition: The location of the ball is updated
     *
     */
    void setLocation(bPoint);

    /*
     * description:Sets the radius of the ball.
     * return: N/A
     * precondition: the int is valid
     * postcondition:The radius of the ball is updated.
     *
     */
    void setRadius(int);

    /*
     * description: Sets the off-wall status of the ball
     * return: N/A
     * precondition: the int is good
     * postcondition: The off-wall status of the ball is updated.
     *
     */
    void setOffWall(bool);

    /*
     * description: Sets the force of the ball
     * return: N/A
     * precondition: force type is good
     * postcondition: The force of the ball is updated.
     *
     */
    void setBallF(force otherF);

    /*
      * description: Sets the in-ball status of the ball.
      * return: N/A
      * precondition: the bool is good
      * postcondition: The in-ball status of the ball is updated.
      *
      */
    void setMove(bool);

    /*
     * description: Gets the color of the ball.
     * return: color
     * precondition: N/A
     * postcondition: Returns the color of the ball.
     *
     */

    void setInBall(bool);

    /*
     * description: Gets the color of the ball.
     * return: color
     * precondition: N/A
     * postcondition: Returns the color of the ball.
     *
     */

    color getColor() const;

    /*
     * description: Gets the location of the ball.
     * return: point type
     * precondition: N/A
     * postcondition: Returns the location of the ball.
     *
     */

    point getLocation() const;

    /*
     * description: Gets the force of the ball.
     * return: force
     * precondition: N/A
     * postcondition: Returns the force of the ball.
     *
     */
    force getBallF()const;

    /*
     * description: Gets the radius of the ball.
     * return: int
     * precondition: N/A
     * postcondition: Returns the radius of the ball.
     *
     */
    int getRadius() const;

    /*
     * description: Gets the move status of the ball.
     * return: bool
     * precondition: N/A
     * postcondition: Returns true if the ball is can move, false otherwise
     *
     */
    bool getMove()const;

    /*
     * description: Gets the status of an object being inside the ball.
     * return: bool
     * precondition: N/A
     * postcondition: Returns the status of the object being inside the ball.
     *
     */
    bool getInBall()const;

    /*
     * description: Displays the object on an SDL_Plotter.
     * return: void
     * precondition: the SDL_Plotter is good
     * postcondition: The object is displayed on the SDL_Plotter.
     *
     */
    void display(SDL_Plotter&, bool = false);

    /*
     * description: Moves the object.
     * return: void
     * precondition: N/A
     * postcondition: The object is moved according to its internal logic.
     *
     */
    void move();

    /*
     * description: Handles the collision of the object with a wall.
     * return: void
     * precondition: N/A
     * postcondition: The Balls force is adjusted to hadle wall collision.
     *
     */
    void wallCollision();

    /*
     * description: Checks if the object is off-screen.
     * return: bool
     * precondition: The size of the screen is 650 pixels long
     * postcondition: Returns true if the object is off-screen,
     *      false otherwise.
     *
     */
    bool isOffScreen()const;

    /*
     * description: Handles a collision with a specified angle.
     * return: void
     * precondition: N/A
     * postcondition: The object's position or state is adjusted based on the
     *      specified collision angle.
     *
     */
    void collision(double angle);

    /*
     * description: Resets the object, to its initial state or position.
     * return: void
     * precondition: N/A
     * postcondition: The object is reset to its initial state or position
     *      using the provided SDL_Plotter.
     *
     */
    void reset(SDL_Plotter&);
};
#endif //GROUPPROJECT_BALL_H
