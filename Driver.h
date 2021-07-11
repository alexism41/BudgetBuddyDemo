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
    std::vector<Trip> trips;
    bool running = false;
    void displayMain();
public:
    void start();


};


#endif //BUDGETBUDDY_DRIVER_H
