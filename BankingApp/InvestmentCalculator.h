//
// Created by Michael Mathews on 11/30/24.
//

#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H
#include <string>


//Class definitions to run all investment calculations and get input/display output
class InvestmentCalculator {
public:
    std::string userInput;
    bool running = true;
    InvestmentCalculator(double m_startingInvestment, double m_monthlyDeposit, double m_annualInterest, int m_numberOfYears);
    double getUserInvestment() const;
    void setUserInvestment(double m_startingInvestment);
    double getMonthlyDeposit() const;
    void setMonthlyDeposit(double m_monthlyDeposit);
    double getAnnualInterest() const;
    void setAnnualInterest(double m_annualInterest);
    double getNumberOfYears();
    void setNumberOfYears(int m_numberOfYears);
    void printInvestmentData();
    void printInvestmentOutput();
    void loop();
    void errorMessage();

private:
    //private member variables
    double m_startingInvestment = 0, m_monthlyDeposit = 0, m_annualInterest = 0;
    int m_numberOfYears = 0;



};



#endif //INVESTMENTCALCULATOR_H
