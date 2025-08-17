/********************************************************************************************/
/* LAB. ASSIGNMENT #5 */
/* Employee class for lab 5
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 28, 2024 */
/*********************************************************************************************/

#include "BonusEmployee.h"

using namespace std;

// Default constructor
BonusEmployee::BonusEmployee() : Employee(), bonus(0.0) {}

// Parameterized constructor
BonusEmployee::BonusEmployee(string fName, string lName, int id, Date bDate, Date hireDate, double pay, double bonusAmount)
    : Employee(fName, lName, id, bDate, hireDate, pay), bonus(bonusAmount) {}

// Get bonus amount
double BonusEmployee::getBonus() const {
    return bonus;
}

// Overridden function to read base pay and bonus
void BonusEmployee::readPayInfo() {
    Employee::readPayInfo();  // Call base class function to read base pay
    cout << "Enter bonus: ";
    cin >> bonus;
}

// Overridden function to calculate gross pay (base pay + bonus)
double BonusEmployee::getGpay() const {
    return Employee::getGpay() + bonus; // Call base class function to get base pay and add bonus
}

// Overridden function to compute tax on gross pay
double BonusEmployee::computeTax() const {
    double grossPay = getGpay();
    double tax = 0.0;

    if (grossPay >= 1000) {
        tax = grossPay * 0.20;
    } else if (grossPay >= 700) {
        tax = grossPay * 0.18;
    } else if (grossPay >= 500) {
        tax = grossPay * 0.15;
    } else {
        tax = grossPay * 0.10;
    }

    return tax;
}

// Overridden function to print pay information
void BonusEmployee::printPayInfo() const {
    double grossPay = getGpay();
    double tax = computeTax();
    double netPay = grossPay - tax;

    cout << fixed << setprecision(2);
    cout << "Base Pay: $" << getBpay() << endl; // Call base class function to get base pay
    cout << "Bonus: $" << bonus << endl;
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Tax Deduction: $" << tax << endl;
    cout << "Net Pay: $" << netPay << endl;
}
