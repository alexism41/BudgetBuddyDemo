/**
 * Implementation of a trip for BudgetBuddy app.
 * In charge of holding information related to the trip such as:
 * budget, budget warning limit, and name.
 *
 * @author Alexis Muro
 */

#include "Trip.h"

Trip::Trip(std::string name, long double budget, long double warningLimit){
    if(name.empty()) throw std::invalid_argument("Name cannot be empty");
    if(budget < 1 || warningLimit < 1) throw std::invalid_argument("Budget and warning limit must be at least 1");
    if(warningLimit > budget) throw std::invalid_argument("Warning limit cannot be greater than budget");
    this->name = name;
    this->budget = budget;
    this->balance = budget;
    this->warningLimit = warningLimit;
}

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