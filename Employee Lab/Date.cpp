/********************************************************************************************/
/* LAB. ASSIGNMENT #5 */
/* Employee class for lab 5
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 28, 2024 */
/*********************************************************************************************/

#include "Date.h"
#include <cstdlib> // For exit()

// Default constructor
Date::Date() 
{
    month = 1;
    day = 1; 
    year = 1980;
    isValid = false;
    checkDate(); // Validate default date
}

// Parameterized constructor
Date::Date(int month, int day, int year) 
{
    this->month = month;
    this->day = day; 
    this->year = year; 
    checkDate(); // Validate date upon initialization
}

// Function to check the validity of the date
void Date::checkDate() 
{
    isValid = true; // Initialize isValid to true

    if (month > 12 || month < 1)  // Check for valid month (1-12)
        isValid = false;          
    
    if (day > 31 || day < 1)      // Check for valid day (1-31)
        isValid = false;          

    if (year < 1980 || year > 2024) // Check for valid year (1980-2024)
        isValid = false;            


    if (!isValid) {
        cout << "Invalid date! Program will exit." << endl;
        exit(1); // Terminate program if date is invalid
    }
}

// Function to input date
void Date::inputDate()
{
    cout << "Enter month, day, and year: ";
    cin >> month >> day >> year;
    checkDate(); // Validate after input
}

// Function to output date
void Date::outputDate()
{
    cout << month << " / " << day << " / " << year << endl;
}

// Getter methods
int Date::getMonth()
{
    return month;
} 
    
int Date::getDay()
{
    return day;
}
    
int Date::getYear()
{
    return year;
}
