/********************************************************************************************/
/* LAB. ASSIGNMENT #4 */
/* Employee class
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 16, 2024 */
/*********************************************************************************************/


#include <iostream>
#include "Employee.h"
#include "Date.h"  // Include the Date class if necessary

using namespace std;

int main() {
    // 1. Define an object with default values for the member variables and print them
    Employee empDefault;
    empDefault.printPInfo(); // Assuming printPInfo() prints personal info

    cout << endl; // Add a line break for readability

    // 2. Define an object and initialize its member variables
    Date birthDate(10, 25, 1990);  // 10/25/1990
    Date hireDate(11, 15, 2010);    // 11/15/2010
    Employee empInitialized("John", "Doe", 111111, birthDate, hireDate, 750.00);
    empInitialized.printPInfo(); // Print initialized info

    cout << endl; // Line break

    // 3. Define another object, read the values of its member variables, and print them
    Employee empRead;
    empRead.readPInfo(); // Assuming this reads the personal info
    empRead.printPInfo(); // Print the info read from user input

    cout << endl; // Line break

    // 4. Define another object and initialize it with an invalid date
    // This will trigger the validity check in the Date class
    Date invalidBirthDate(13, 25, 1990); // Invalid month (13)
    Date invalidHireDate(11, 32, 2010);  // Invalid day (32)

    // Initialize an employee with invalid dates
    Employee empInvalid("Invalid", "Date", 999999, invalidBirthDate, invalidHireDate, 500.00);
    empInvalid.printPInfo(); // This will likely not be reached due to invalid date handling

    return 0;
}
