/**
 * Implementation of a trip for BudgetBuddy app.
 * In charge of holding information related to the trip such as:
 * budget, budget warning limit, and name.
 *
 * @author Alexis Muro
 */

#ifndef BUDGETBUDDY_TRIP_H
#define BUDGETBUDDY_TRIP_H

#include <string>
#include <stdexcept>

class Trip {
private:
    /** Name of trip **/
    std::string name;
    /** Budget allocated for trip **/
    long double budget = 0;
    /** Balance remaining for the trip **/
    long double balance = 0;
    /** Warning limit allocated for trip **/
    long double warningLimit = 0;

public:
    /**
     * Constructs a trip with a specified budget, warning limit and name
     *
     * @param name the name of the trip
     * @param budget the total budget allocated for this trip
     * @param warningLimit the amount where a warning will be sent out to user
     * @throws invalid_argument if any parameter is NULL
     */
    Trip(std::string name, long double budget, long double warningLimit);

};


#endif //BUDGETBUDDY_TRIP_H
