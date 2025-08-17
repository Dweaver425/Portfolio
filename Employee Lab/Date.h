/********************************************************************************************/
/* LAB. ASSIGNMENT #5 */
/* Employee class for lab 5
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 28, 2024 */
/*********************************************************************************************/



#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date 
{
private: 
    int month, day, year;
    bool isValid; 

public:
    // Default constructor
    Date();

    // Parameterized constructor
    Date(int month, int day, int year); 

    // Function to check the validity of the date
    void checkDate(); 

    // Function to input date
    void inputDate(); 

    // Function to output date
    void outputDate(); 

    // Getter methods
    int getMonth();
    int getDay();
    int getYear();
};

#endif // DATE_H
