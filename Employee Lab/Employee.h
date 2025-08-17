/********************************************************************************************/
/* LAB. ASSIGNMENT #5 */
/* Employee class for lab 5
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 28, 2024 */
/*********************************************************************************************/


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Date.h"  // Include the Date class

using namespace std;

class Employee {
    private:
        string firstName;      // Default is an empty string
        string lastName;       // Default is an empty string
        int iD;                // Default ID is 8888
        Date birthDay;         // Default birth day is 1/1/1980
        Date dateHired;        // Default date hired is 1/1/2023
        double basePay;        // Default base pay is $0.00

    public:
        // Constructors
        Employee();  // Default constructor
        Employee(string fName, string lName, int id, Date bDate, Date hireDate, double pay);

        // Member functions
        void readPInfo();           // Read personal info
        virtual void readPayInfo(); // Read pay info (virtual function)
        void printPInfo() const;    // Print personal info
        double getBpay() const;      // Get base pay
        void setBpay(double newBpay); // Set base pay
        virtual double getGpay() const; // Get gross pay (virtual function)
        double computeTax() const;   // Compute tax
        virtual void printPayInfo() const; // Print pay info (virtual function)
};

#endif
