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

#ifndef GROUPPROJECT_ALLBALLS_H
#define GROUPPROJECT_ALLBALLS_H
#include "Ball.h"

class AllBalls{
private:
    vector<Ball> allBalls;
    bool started;
    force initF;

public:

    /*
     * Description: Initializes an AllBalls object with a specified number
     *              of Ball objects. The game state is set to not started.
     * Return Type: None
     * Precondition: n is a valid number of balls to create.
     * Postcondition: AllBalls object is created with n Ball objects.
     */
    AllBalls(int);

    /*
     * Description: Retrieves a reference to a specific Ball object in the
     *              AllBalls container.
     * Return Type: Ball&
     * Precondition: i is a valid index within the bounds of the container.
     * Postcondition: Returns a reference to the Ball object at index i.
     */
    Ball& getBall(int i);

    /*
     * Description: Retrieves the number of Ball objects in the AllBalls
     *      container.
     * Return Type: unsigned int
     * Precondition: None
     * Postcondition: Returns the size of the AllBalls container.
     */
    unsigned int getAmount();

    /*
     * Description: Adds a Ball object to the AllBalls container.
     * Return Type: None
     * Precondition: b is a valid Ball object.
     * Postcondition: Adds the Ball object to the AllBalls container.
     */
    void addBall(Ball b);

    /*
     * Description: Resets the positions of all Ball objects in the AllBalls
     *              container and displays them on the SDL_Plotter.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object.
     * Postcondition: All Ball objects are reset and displayed on the
     *      SDL_Plotter.
     */
    void resetBalls(SDL_Plotter& g);

    /*
     * Description: Starts the game by resetting all Ball objects in the
     *      AllBalls container and setting the game state to started.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object.
     * Postcondition: All Ball objects are reset, and the game state is
     *      set to started.
     */
    void startBalls(SDL_Plotter& g);

    /*
     * Description: Checks if all Ball objects in the AllBalls container
     *      are off the screen, indicating that the round is over.
     * Return Type: bool
     * Precondition: None
     * Postcondition: Returns true if all Ball objects are off the screen,
     *      false otherwise.
     */
    bool isRoundOver();

    /*
     * Description: Launches the next Ball in the AllBalls container based
     *      on the mouse click position and the initial force.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object, and p is a valid point.
     * Postcondition: The next Ball is launched with the specified force and
     *      position.
     */
    void launchNextBall(SDL_Plotter& g, point p);


    /*
     * Description: Moves all Ball objects in the AllBalls container.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object.
     * Postcondition: All Ball objects are moved and displayed on the
     *      SDL_Plotter.
     */
    void moveEmAll(SDL_Plotter& g);

    /*
     * Description: Checks for collisions between Ball objects in the AllBalls
     * container.
     * Return Type: None
     * Precondition: None
     * Postcondition: Handles collisions between Ball objects in the AllBalls
     * container.
     */
    void checkBallCollision();

    /*
     * Description: Handles collisions between two Ball objects by adjusting
     *      their velocities after collision.
     * Return Type: None
     * Precondition: ball and otherBall are valid Ball objects.
     * Postcondition: Adjusts the velocities of ball and otherBall after
     *      collision.
     */
    void handleBallCollision(Ball&, Ball&);

    /*
     * Description: Adds a new Ball object to the AllBalls container,
     *      initialized as a broken ball.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object, and p is a valid bPoint.
     * Postcondition: Adds a new Ball object to the AllBalls container with a
     *      specified location and force.
     */
    void brokeBallObj(SDL_Plotter& g, bPoint p);

    /*
     * Description: Resets the game state and clears the AllBalls container.
     * Return Type: None
     * Precondition: None
     * Postcondition: Resets the game state and clears the AllBalls container.
     */
    void gameReset();

};


#endif //GROUPPROJECT_ALLBALLS_H
