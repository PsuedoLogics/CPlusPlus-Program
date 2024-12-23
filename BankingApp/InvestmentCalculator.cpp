//
// Created by Michael Mathews on 11/30/24.
//

#include "InvestmentCalculator.h"
#include <cmath>
#include <iomanip>
#include <iostream>

InvestmentCalculator::InvestmentCalculator(double m_startingInvestment, double m_monthlyDeposit, double m_annualInterest, int m_numberOfYears) {}

//GETTERS AND SETTERS
double InvestmentCalculator::getUserInvestment() const {
    return m_startingInvestment;
}

void InvestmentCalculator::setUserInvestment(double t_startingInvestment) {
    m_startingInvestment = t_startingInvestment;
}

double InvestmentCalculator::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

void InvestmentCalculator::setMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}

double InvestmentCalculator::getAnnualInterest() const {
    return m_annualInterest;
}

void InvestmentCalculator::setAnnualInterest(double t_annualInterest) {
    m_annualInterest = t_annualInterest;
}

double InvestmentCalculator::getNumberOfYears() {
    return m_numberOfYears;
}

void InvestmentCalculator::setNumberOfYears(int t_numberOfYears) {
    m_numberOfYears = t_numberOfYears;
}
//END GETTERS AND SETTERS---------------------


//Display inputs
void InvestmentCalculator::printInvestmentData() {
    std::cout << "*********************" << std::endl;
    std::cout << "|*****DATA INPUT****|" << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << "INITIAL INVESTMENT: $" << m_startingInvestment << std::endl;
    std::cout << "MONTHLY DEPOSIT:    $" << m_monthlyDeposit << std::endl;
    std::cout << "ANNUAL INTEREST:     " << m_annualInterest << "%" << std::endl;
    std::cout << "NUMBER OF YEARS:     " << m_numberOfYears << std::endl;
    std::cout << "_____________________" << std::endl;
}

//Outputs from the data that was input
void InvestmentCalculator::printInvestmentOutput() {
    //Print header for menu with no monthly deposits
    std::cout << "**********************************************************" << std::endl;
    std::cout << "**BALANCE AND INTEREST NO MONTHLY DEPOSITS**************" << std::endl;
    std::cout << "**YEAR****YEAR END BALANCE****YEAR END EARNED INTEREST****" << std::endl;
    std::cout << "**********************************************************" << std::endl;
    //Set variables for loop
    double annualInterest = (getAnnualInterest()/100.0);
    double startingBalance = getUserInvestment();
    double yearEndBalance;
    double yearlyInterest;
    //foreach year print results
    for(int i = 1; i <= getNumberOfYears(); i++) {
        yearlyInterest = startingBalance * annualInterest;
        yearEndBalance = startingBalance + yearlyInterest;
        std::cout << "*  "<< i << "  **** $" << std::fixed << std::setprecision(2) << yearEndBalance << " ******************* $" << yearlyInterest <<std::endl;
        startingBalance = yearEndBalance;
    }

    //INVESTMENT WITH MONTHLY DEPOSITS
    std::cout << "**********************************************************" << std::endl;
    std::cout << "**BALANCE AND INTEREST WITH MONTHLY DEPOSITS**************" << std::endl;
    std::cout << "**YEAR****YEAR END BALANCE****YEAR END EARNED INTEREST****" << std::endl;
    std::cout << "**********************************************************" << std::endl;

    double startBalance = getUserInvestment();
    double totalInterest;

    for(int i = 1; i <= getNumberOfYears(); i++) {
       totalInterest = 0.0;
       for(int x = 0; x < 12; x++) {
           double monthlyInterest = startBalance * ((annualInterest / 100.0) / 12.0);
           totalInterest += monthlyInterest;
           startBalance += getMonthlyDeposit() + monthlyInterest;
       }

        std::cout << "*  "<< i << "  **** $" << std::fixed << std::setprecision(2) << startBalance << " ******************* $" << totalInterest <<std::endl;
    }
}


//Main loop to get inputs and display the menu
void InvestmentCalculator::loop() {
    while(running) {

        //Get all inputs, with protected try/catch statements
        std::cout << "Enter Initial Investment(00.00 format): ";
        std::cin >> userInput;
            try {
                setUserInvestment(std::stod(userInput));
            }
            catch(std::exception e) {
               errorMessage();
            }
        std::cout << "Enter Monthly Deposit amount(00.00 format): ";
        std::cin >> userInput;
            try {
                setMonthlyDeposit(std::stod(userInput));
            }
            catch (std::exception e) {
                errorMessage();
            }

        std::cout << "Enter Annual Interest(I.E. 5 for 5% or 10 for 10%): ";
        std::cin >> userInput;
            try {
                setAnnualInterest(std::stod(userInput));
            }
            catch (std::exception e) {
                errorMessage();
            }
        std::cout << "Number of Years for investment(I.E. 1 or 3 or 5): ";
        std::cin >> userInput;
            try {
                setNumberOfYears(std::stoi(userInput));
            }
            catch(std::exception e) {
                std::cout << "Non-Convertable type: Integer required.." << std::endl;
            }

        //Line break before data output
        std::cout << std::endl;

        printInvestmentData();

        std::cout << "Press any key to continue (Q or q to quit)..." << std::endl;

        std::cin >> userInput;

        if(userInput == "Q" || userInput == "q")
            running = false;
        //If there is a value in number of years, print the investment report(s)
        else if((userInput != "q" || userInput != "Q") && getNumberOfYears() > 0) {
            printInvestmentOutput();
        }
    }
}

//User input not of the right type required
void InvestmentCalculator::errorMessage() {
    std::cout << "Non-Convertable type: Integer or integer with decimal required.." << std::endl;
}










