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
#include <vector>
#include <utility>

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
    /**
     * List of expenses for the trip.
     * Expenses will be stored as pairs, where the first value of the pair holds: the name of the expense
     * and the second value of the pair holds: the amount for the expense
     */
    std::vector<std::pair<std::string,long double>> expenses;
public:
    /**
     * Constructs a trip with a specified budget, warning limit and name
     * The balance is set equal to budget at initialization
     *
     * @param name the name of the trip
     * @param budget the total budget allocated for this trip
     * @param warningLimit the amount where a warning will be sent out to user
     * @throws invalid_argument if name is empty, if {@code budget < 1}, and if {@code warningLimit < 1 || warningLimit >= budget}
     */
    Trip(const std::string& name, long double budget, long double warningLimit);

    /**
     * Gets the starting budget for the trip
     *
     * @return the initial budget for the trip
     */
    [[nodiscard]] long double getBudget() const;

    /**
     * Gets the current balance
     *
     * @return the remaining balance for the trip
     */
    [[nodiscard]] long double getBalance() const;

    /**
     * Gets the warning limit that was set for the trip
     *
     * @return the warning limit amount
     */
    [[nodiscard]] long double getWarningLimit() const;

    /**
     * Gets the name of the trip
     *
     * @return the name of trip
     */
    [[nodiscard]] std::string getName() const;

    /**
     * Check if the balance is below 0
     *
     * @return {@code true} if {@code balance < 0}
     *         {@code false} if {@code balance >= 0}
     */
    [[nodiscard]] bool isOverBudget() const;

    /**
     * Check if the balance has reached the warning limit
     *
     * @return {@code true} if {@code balance <= warningLimit}
     *         {@code false} if {@code balance > warningLimit}
     */
    [[nodiscard]] bool isWarningActive() const;

    /**
     * Get the list of expenses for the trip
     *
     * @return the vector that holds the expenses
     */
    [[nodiscard]] std::vector<std::pair<std::string,long double>> getExpenses() const;

    /**
     * Adds an expense to the list of expenses for this trip
     *
     * @param name the name of the expense
     * @param amount the amount of the expense
     * @throws invalid_argument if name is empty or if {@code amount < 0}
     */
    void addExpense(std::string name, long double amount);
};


#endif //BUDGETBUDDY_TRIP_H
