/********************************************************************************************/
/* LAB. ASSIGNMENT #5 */
/* Employee class for lab 5
/* */
/* Programmer: Dylan Weaver
/* Class: CS 3420-60 */
/* Due Date: October 28, 2024 */
/*********************************************************************************************/

#include <iostream>
#include "BonusEmployee.h"  // Include BonusEmployee.h

using namespace std;

int main() {
    // Step 2: Create an Employee object with default values
    Employee empDefault;  // Default constructor
    cout << "Default Employee Information:" << endl;
    empDefault.printPInfo();  // Print personal info
    empDefault.readPayInfo();  // Read pay info
    empDefault.printPayInfo();  // Print pay info

    cout << endl;  // Line break for readability

    // Step 3: Create a BonusEmployee object with default values
    BonusEmployee bonusEmpDefault;  // Default constructor
    cout << "Default BonusEmployee Information:" << endl;
    bonusEmpDefault.printPInfo();  // Print personal info
    bonusEmpDefault.readPayInfo();  // Read pay info
    bonusEmpDefault.printPayInfo();  // Print pay info

    cout << endl;  // Line break for readability

    // Step 4: Initialize an Employee object with specific values
    Employee empJohn("John", "Doe", 111111, Date(10, 25, 2000), Date(5, 10, 2023), 1250);
    cout << "Employee Information for John Doe:" << endl;
    empJohn.printPInfo();  // Print personal info
    empJohn.readPayInfo();  // Read pay info
    empJohn.printPayInfo();  // Print pay info

    cout << endl;  // Line break for readability

    // Step 5: Initialize a BonusEmployee object with specific values
    BonusEmployee bonusEmpJobe("Jobe", "Daly", 222222, Date(1, 5, 1999), Date(6, 30, 2018), 1850, 500);
    cout << "BonusEmployee Information for Jobe Daly:" << endl;
    bonusEmpJobe.printPInfo();  // Print personal info
    bonusEmpJobe.readPayInfo();  // Read pay info
    bonusEmpJobe.printPayInfo();  // Print pay info

    cout << endl;  // Line break for readability

    // Step 6: Read personal and pay information of an Employee object
    Employee empInput;  // Create an empty Employee object
    cout << "Enter information for a new Employee:" << endl;
    empInput.readPInfo();  // Read personal info
    empInput.readPayInfo();  // Read pay info
    empInput.printPInfo();  // Print personal info
    empInput.printPayInfo();  // Print pay info

    cout << endl;  // Line break for readability

    // Step 7: Read personal and pay information of a BonusEmployee object
    BonusEmployee bonusEmpInput;  // Create an empty BonusEmployee object
    cout << "Enter information for a new BonusEmployee:" << endl;
    bonusEmpInput.readPInfo();  // Read personal info
    bonusEmpInput.readPayInfo();  // Read pay info
    bonusEmpInput.printPInfo();  // Print personal info
    bonusEmpInput.printPayInfo();  // Print pay info

    return 0;
}
