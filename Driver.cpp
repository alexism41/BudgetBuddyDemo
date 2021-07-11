/**
 * Implementation of a driver to simulate a demo of the BudgetBuddy app
 * through the console.
 *
 * @author Alexis Muro
 */

#include "Driver.h"

void Driver::displayMain() {
    std::cout << std::setw(50) << std::right << "Budget Buddy" << std::endl;
    std::cout << "1. Create Trip \n2. Delete Trip \n3. Open Trip \n4. Exit\n";
}

void Driver::start() {
    running = true;
    char input;
    do{
        displayMain();
        std::cin >> input;
        switch (input) {
            case '1':
                std::cout << "CREATING A TRIP\n";
                break;
            case '2':
                std::cout << "DELETING A TRIP\n";
                break;
            case '3':
                std::cout << "OPENING A TRIP\n";
                break;
            case '4':
                std::cout << "EXITING\n";
                running = false;
                break;
            default:
                std::cout << "ENTER VALID OPTION\n";
                break;
        }

    }while(running);
}