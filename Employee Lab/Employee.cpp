/********************************************************************************************/
/* LAB. ASSIGNMENT #5 */
/* Employee class for lab 5
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 28, 2024 */
/*********************************************************************************************/


#include "Employee.h"

// Default constructor
Employee::Employee()
    : firstName(""), lastName(""), iD(8888), 
      birthDay(Date(1, 1, 1980)), dateHired(Date(1, 1, 2023)), basePay(0.00) {}

// Parameterized constructor
Employee::Employee(string fName, string lName, int id, Date bDate, Date hireDate, double pay)
    : firstName(fName), lastName(lName), iD(id), 
      birthDay(bDate), dateHired(hireDate), basePay(pay) {}

// Read personal info
void Employee::readPInfo() {
    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Enter ID number: ";
    cin >> iD;

    // Input for birth date
    int day, month, year;
    cout << "Enter birth date (day month year): ";
    cin >> day >> month >> year;
    birthDay = Date(month, day, year);  // Initialize with month, day, year

    // Input for hire date
    cout << "Enter date hired (day month year): ";
    cin >> day >> month >> year;
    dateHired = Date(month, day, year);  // Initialize with month, day, year
}

// Read pay info
void Employee::readPayInfo() {
    cout << "Enter base pay: ";
    cin >> basePay;
}

void Employee::printPInfo() const {
    // Use a temporary Date object to avoid const issues
    Date tempBirthDay = birthDay;
    Date tempDateHired = dateHired;

    cout << "Name: " << lastName << ", " << firstName << endl;
    cout << "ID: " << iD << endl;
    cout << "DOB: " << tempBirthDay.getMonth() << "/" 
         << tempBirthDay.getDay() << "/" << tempBirthDay.getYear() << endl;
    cout << "DOH: " << tempDateHired.getMonth() << "/" 
         << tempDateHired.getDay() << "/" << tempDateHired.getYear() << endl;
         printPayInfo();
}


// Get base pay
double Employee::getBpay() const {
    return basePay;
}

// Set base pay
void Employee::setBpay(double newBpay) {
    basePay = newBpay;
}

// Get gross pay
double Employee::getGpay() const {
    return basePay;  // Gross pay is equal to base pay
}

// Compute tax
double Employee::computeTax() const {
    double grossPay = getGpay();
    double tax = 0.0;

    if (grossPay >= 1000) {
        tax = grossPay * 0.20;  // 20% tax
    }
    else if (grossPay >= 700) {
        tax = grossPay * 0.18;  // 18% tax
    }
    else if (grossPay >= 500) {
        tax = grossPay * 0.15;  // 15% tax
    }
    else {
        tax = grossPay * 0.10;  // 10% tax
    }

    return tax;
}

// Print pay info
void Employee::printPayInfo() const {
    double grossPay = getGpay();
    double tax = computeTax();
    double netPay = grossPay - tax;

    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Tax Deduction: $" << tax << endl;
    cout << "Net Pay: $" << netPay << endl;
}


