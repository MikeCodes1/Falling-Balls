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
#ifndef GROUPPROJECT_ALLOBJECTS_H
#define GROUPPROJECT_ALLOBJECTS_H

#include <vector>
#include "Object.h"
#include "AllBalls.h"
#include <ctime>
using namespace std;

class AllObjects{
private:
    vector<Object> allObjects;
    bool _gameOver, started;
    int points;



public:
    /*
     * Description: Initializes an AllObjects object with default values.
     * Return Type: None
     * Precondition: None
     * Postcondition: AllObjects object is created with default values.
     */
    AllObjects();

    /*
     * Description: Sets the 'started' flag to the specified value.
     * Return Type: None
     * Precondition: b is a valid boolean value.
     * Postcondition: The 'started' flag is set to the specified value.
     */
    void setStarted(bool);

    /*
     * Description: Retrieves the value of the 'started' flag.
     * Return Type: bool
     * Precondition: None
     * Postcondition: Returns the value of the 'started' flag.
     */
    bool getStarted()const;

    /*
     * Description: Retrieves the current points.
     * Return Type: int
     * Precondition: None
     * Postcondition: Returns the current points.
     */
    int getPoints()const;

    /*
     * Description: Adds an Object to the AllObjects container.
     * Return Type: None
     * Precondition: obj is a valid Object.
     * Postcondition: Adds the Object to the AllObjects container.
     */
    void addObject(Object obj);

    /*
     * Description: Adds points to the total points.
     * Return Type: None
     * Precondition: p is a valid integer.
     * Postcondition: Adds p to the total points.
     */
    void addPoints(int);

    /*
     * Description: Retrieves the number of objects in the AllObject
     *      container.
     * Return Type: int
     * Precondition: None
     * Postcondition: Returns the number of objects in the AllObjects
     * container.
     */
    int getNumObjects() const;

    /*
     * Description: Checks if any object in the AllObjects container is above
     *      the top boundary, indicating game over.
     * Return Type: bool
     * Precondition: None
     * Postcondition: Returns true if any object is above the top boundary,
     *      false otherwise.
     */
    bool gameOver();

    /*
     * Description: Moves all objects in the AllObjects container
     *      upward on the SDL_Plotter.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object.
     * Postcondition: All objects are moved upward on the SDL_Plotter.
     */
    void moveEmAllUp(SDL_Plotter&);

    /*
     * Description: Initializes the game objects at the start of the game.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object, and p is a valid integer.
     * Postcondition: Game objects are initialized at the start of the game.
     */
    void startObjects(SDL_Plotter& g, int p);

    /*
     * Description: Checks for collisions between objects in the AllObjects
     * Container and Ball objects in the specified AllBalls container.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object, and b is a valid AllBalls
     * object.
     * Postcondition: Handles collisions between objects and Ball objects.
     */
    void checkAllCollisions(SDL_Plotter&, AllBalls& b);

    /*
     * description: Resets the game, moving objects up and starting new ones.
     * return: N/A
     * precondition: SDL_Plotter object and current points are passed as
     * parameters.
     * postcondition: If the game is not over, moves objects up and starts new
     * ones.
     *
     */
    void reset(SDL_Plotter& g, int p);

    /*
     * Description: Resets the game state, total points, and destroys all game
     *              objects.
     * Return Type: None
     * Precondition: g is a valid SDL_Plotter object.
     * Postcondition: Game state is reset, total points are set to zero,
     * and all game objects are destroyed.
     */
    void gameReset(SDL_Plotter& g);
};

#endif //GROUPPROJECT_ALLOBJECTS_H
