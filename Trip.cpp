/**
 * Implementation of a trip for BudgetBuddy app.
 * In charge of holding information related to the trip such as:
 * budget, budget warning limit, and name.
 *
 * @author Alexis Muro
 */

#include "Trip.h"

Trip::Trip(const std::string& name, long double budget, long double warningLimit): name(name), budget(budget), balance(budget), warningLimit(warningLimit)
{
    if(name.empty()) throw std::invalid_argument("Name cannot be empty");
    if(budget < 1 || warningLimit < 1) throw std::invalid_argument("Budget and warning limit must be at least 1");
    if(warningLimit >= budget) throw std::invalid_argument("Warning limit cannot be greater or equal to budget");
}

long double Trip::getBudget() const {
    return budget;
}

long double Trip::getBalance() const {
    return balance;
}

long double Trip::getWarningLimit() const {
    return warningLimit;
}

std::string Trip::getName() const {
    return name;
}

bool Trip::isOverBudget() const {
    return balance < 0;
}

bool Trip::isWarningActive() const {
    return balance <= warningLimit;
}

std::vector<std::pair<std::string,long double>> Trip::getExpenses() const {
    return expenses;
}

void Trip::addExpense(std::string name, long double amount) {
    if(name.empty()) throw std::invalid_argument("Name cannot be empty");
    if(amount < 0) throw std::invalid_argument("Amount must be greater than 0");
    balance -= amount;
    std::pair<std::string, long double> expense(name, amount);
    expenses.push_back(expense);
}