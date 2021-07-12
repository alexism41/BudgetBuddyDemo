/**
 * Implementation of a driver to simulate a demo of the BudgetBuddy app
 * through the console.
 *
 * @author Alexis Muro
 */

#ifndef BUDGETBUDDY_DRIVER_H
#define BUDGETBUDDY_DRIVER_H

#include "Trip.h"
#include <iomanip>
#include <iostream>

class Driver {
private:
    /** List of Trips for the current user **/
    std::vector<Trip> trips;
    /** Flag to check if the driver is running **/
    bool running = false;
    /**
     * Displays main menu options to the user
     */
    void displayMain();

    /**
     * Displays a simple line of text to the user, text is left aligned by default
     *
     * @param message the text to be displayed to the user
     * @param centered {@code true} to display centered text
     */
    static void displayMessage(std::string message, bool centered = false);

    /**
     * Handles the creation of a new trip by getting user input for the name, budget and warning limit
     * and adds the trip to the list of current trips if it was successfully created.
     * If the trip was created successfully it is then opened and presents user with the Trip main menu options
     */
    void createTrip();

    /**
     * Displays the trip main menu options for the trip at the desired index in the trips list
     * and handles user input for the trip menu
     *
     * @param index the index in the trips vector to open
     * @throws invalid_argument if {@code index < 0 || index >= trips.size()}
     */
    void displayTripMain(int index);

    /**
     * Gets user input for the name and amount of an expense and adds it
     * to the current trip if valid
     *
     * @param index the index in the trips vector to add the expense to
     * @throws invalid_argument if {@code index < 0 || index >= trips.size()}
     */
    void addExpense(int index);
public:
    /**
     * Starts the driver and handles user interaction
     */
    void start();


};


#endif //BUDGETBUDDY_DRIVER_H
