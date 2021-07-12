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
public:
    /**
     * Starts the driver and handles user interaction
     */
    void start();


};


#endif //BUDGETBUDDY_DRIVER_H
