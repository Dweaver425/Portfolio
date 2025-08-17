/********************************************************************************************/
/* LAB. ASSIGNMENT #3 */
/* Program to Check for a valid date
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 16, 2024 */
/*********************************************************************************************/
#include "Date.h"
#include <iostream>

using namespace std;

int main() 
{
    // Default constructor
    Date D1;
    D1.outputDate(); // Output the default date
    cout << D1.getMonth() << " / " << D1.getDay() << " / " << D1.getYear() << endl;

    // Parameterized constructor with a valid date
    Date D2(3, 1, 2024);
    D2.outputDate();
    cout << D2.getMonth() << " / " << D2.getDay() << " / " << D2.getYear() << endl;

    // Input and output a valid date
    D2.inputDate();
    D2.outputDate();
    cout << D2.getMonth() << " / " << D2.getDay() << " / " << D2.getYear() << endl;

    // Parameterized constructor with an invalid date
    Date invalid(15, 20, 2030); // This will cause the program to exit

    return 0;
}
