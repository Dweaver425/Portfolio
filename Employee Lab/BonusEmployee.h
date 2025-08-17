/********************************************************************************************/
/* LAB. ASSIGNMENT #5 */
/* Employee class for lab 5
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 28, 2024 */
/*********************************************************************************************/

#ifndef BONUSEMPLOYEE_H
#define BONUSEMPLOYEE_H

#include "Employee.h"   // Include the base Employee class
#include <iostream>     // For input/output
#include <iomanip>      // For setting output precision

class BonusEmployee : public Employee {
private:
    double bonus;  // Additional attribute for bonus, default value $0.0

public:
    // Default constructor
    BonusEmployee();

    // Parameterized constructor
    BonusEmployee(string fName, string lName, int id, Date bDate, Date hireDate, double pay, double bonusAmount);

    // Get bonus
    double getBonus() const;

    // Overridden function to read base pay and bonus
    void readPayInfo(); 
    
    // Overridden function to calculate gross pay (base pay + bonus)
    double getGpay() const;  

    // Overridden function to compute tax on gross pay
    double computeTax() const; 

    // Overridden function to print pay information
    void printPayInfo() const; 
};

#endif // BONUSEMPLOYEE_H
