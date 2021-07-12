/**
 * Implementation of a driver to simulate a demo of the BudgetBuddy app
 * through the console.
 *
 * @author Alexis Muro
 */

#include "Driver.h"

void Driver::displayMain() {
    displayMessage("Budget Buddy", true);
    displayMessage("1. Create Trip");
    displayMessage("2. Delete Trip");
    displayMessage("3. Open Trip");
    displayMessage("4. Exit");
}

void Driver::start() {
    running = true;
    char input;
    do{
        displayMain();
        std::cin >> input;
        switch (input) {
            case '1':
                displayMessage("CREATING A TRIP\n");
                createTrip();
                break;
            case '2':
                displayMessage("DELETING A TRIP\n");
                break;
            case '3':
                displayMessage("OPENING A TRIP\n");
                break;
            case '4':
                displayMessage("EXITING\n");
                running = false;
                break;
            default:
                displayMessage("ENTER VALID OPTION\n");
                break;
        }

    }while(running);
}

void Driver::displayMessage(std::string message,bool centered) {
    if(centered)
        std::cout << std::setw(50) << std::right << message << std::endl;
    else
        std::cout << message << std::endl;
}

void Driver::createTrip() {
    std::string userInput;
    std::string name;
    long double budget;
    long double warningLimit;

    displayMessage("Enter the name of this Trip: ");
    std::cin.ignore();
    std::getline(std::cin, name);

    displayMessage("Enter the budget for this Trip: ");
    std::getline(std::cin, userInput);
    budget = std::stold(userInput);

    displayMessage("Enter the warning limit for this Trip: ");
    std::getline(std::cin, userInput);
    warningLimit = std::stold(userInput);

    try{
        Trip trip(name,budget,warningLimit);
        trips.push_back(trip);
        displayTripMain(trips.size()-1);
    }
    catch (std::invalid_argument& e) {
        displayMessage(e.what());
    }
}

void Driver::displayTripMain(int index) {
    if(index < 0 || index >= trips.size()) throw std::invalid_argument("Invalid index entered");
    bool open = true;
    char input;

    do{
        displayMessage(trips[index].getName(),true);
        displayMessage("$" + std::to_string(trips[index].getBalance()), true);
        if(trips[index].isOverBudget())
            displayMessage("YOU ARE NOW OVER BUDGET FOR THIS TRIP!", true);
        if(trips[index].isWarningActive())
            displayMessage("You are now below your warning limit of: $" + std::to_string(trips[index].getWarningLimit()) + "\n");

        displayMessage("1. Add expense");
        displayMessage("2. View Trip Expenses");
        displayMessage("3. Close Trip");
        std::cin >> input;
        switch (input) {
            case '1':
                displayMessage("ADDING EXPENSE\n");
                addExpense(index);
                break;
            case '2':
                displayMessage("VIEWING EXPENSES\n");
                break;
            case '3':
                open = false;
                displayMessage("EXITING TRIP\n");
                break;
            default:
                displayMessage("ENTER VALID OPTION\n");
                break;
        }

    }while(open);

}

void Driver::addExpense(int index) {
    if(index < 0 || index >= trips.size()) throw std::invalid_argument("Invalid index entered");
    std::string name;
    std::string userInput;
    long double amount;

    displayMessage("Enter the name of this Expense: ");
    std::cin.ignore();
    std::getline(std::cin, name);

    displayMessage("Enter the expense amount: ");
    std::getline(std::cin, userInput);
    amount = std::stold(userInput);

    try{
        trips[index].addExpense(name,amount);
    }
    catch (std::invalid_argument& e) {
        displayMessage(e.what());
    }
}