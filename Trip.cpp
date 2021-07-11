/**
 * Implementation of a trip for BudgetBuddy app.
 * In charge of holding information related to the trip such as:
 * budget, budget warning limit, and name.
 *
 * @author Alexis Muro
 */

#include "Trip.h"

Trip::Trip(std::string name, long double budget, long double warningLimit): name(name), budget(budget), balance(budget), warningLimit(warningLimit)
{}

long double Trip::getBudget() {
    return budget;
}

long double Trip::getBalance() {
    return balance;
}

long double Trip::getWarningLimit() {
    return warningLimit;
}

std::string Trip::getName() {
    return name;
}