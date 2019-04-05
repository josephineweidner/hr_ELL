/*
 * Josephine Weidner
 * Manager class implementation
 * 
 * Represents a MANAGER with the following fields:
 *    a list of employees, userID and name
 */

#include "Manager.h"
#include "Employee.h"

#include <iostream>
#include <stdio.h>
#include <vector>

/* Default constructor 
 * sets userID of manager to default: "USERID_DEFAULT"
 * sets name of manager to default: "NAME_DEFAULT"
 */
Manager::Manager()
{
    userID = "USERID_DEFAULT";
    Name = "NAME_DEFAULT";

	numEmployees = 0;
}

/* Destructor 
 */
Manager::~Manager()
{
	//nothing to be done
}

/* Parameterized constructor 
 * Parameters: string UserID, string name
 * sets stringID and name of manager to fields passed in
 */
Manager::Manager(string UserID, string name)
{
    userID = UserID;
    Name = name;

	numEmployees = 0;
}

/* authenticate()
 * parameters: string UserID
 * returns: true if UserID passed in as parameter is the 
 *          same as that of the manager, else false
 */
bool Manager::authenticate(string UserID)
{
    return (userID == UserID);
}

/* hasEmployee()
 * parameters: string UserID
 * returns: true if manager has an employee with the UserID passed in 
 *          else returns false
 */
bool Manager::hasEmployee(string UserID)
{
    unsigned long int i;
    for (i = 0; i < employees.size(); i++) {
        if (employees.at(i).authenticateEmp(UserID)) 
            return true;
    }
    return false;
}

/* addEmployee()
 * parameters: string UserID, string name
 * returns: adds employee to list of employees. Sets userID
 *          and name to fields passed in, and prompts user 
 *          for other employee field information
 */
void Manager::addEmployee(string userID, string name)
{
	Employee newEmployee(userID, name);
    newEmployee.setSalary();
    newEmployee.setVacationBalance();
    newEmployee.setAnnualBonus();

	employees.push_back(newEmployee);

	numEmployees++;
}

/* viewEmployee()
 * parameters: string Name
 * returns: if employee with name passed in is present in list of 
 *          employees, prints employee information, else prints 
 *          error message
 */
void Manager::viewEmployee(string Name)
{
	int i;
    unsigned long int j;
	bool found = false;
    for (i = 0; i < numEmployees; i++) {
    	if (employees.at(i).getName() == Name) {
    		cout << Name << "'s information" << endl;
    		cout << "Salary: " << employees.at(i).getSalary() << endl;
    		
    		cout << "Salary history: ";
            for (j = 0; j < employees.at(i).getSalaryHistory().size(); j++) {
            	cout << employees.at(i).getSalaryHistory().at(j);
            	if (j != employees.at(i).getSalaryHistory().size() - 1) {
            		cout << " -> ";
            	}
            }
            cout << endl;

    		cout << "Vacation balance: " << employees.at(i).getVacationBalance() << endl;
    		cout << "Annual bonus: " << employees.at(i).getAnnualBonus() << endl;
            found = true;
    	}
    }

    if (found == false) {
    	cout << "Employee " << Name << " not found" << endl;
    }
}

/* updateEmployee()
 * parameters: string Name
 * returns: if employee with name passed in is present in list of 
 *          employees, prompts user for input information to update
 *          given employee's information, else prints error message
 */
void Manager::updateEmployee(string Name)
{
    int i;
	bool found = false;

	for (i = 0; i < numEmployees; i++) {
    	if (employees.at(i).getName() == Name) {
    		found = true;
    		break;
    	}
    }

    if (found == false) {
    	cout << "Employee " << Name << " not found" << endl;
    	return;
    }

    cout << "Enter 1 to update salary" << endl <<
            "      2 to update vacation balance" << endl <<
            "      3 to update annual bonus" << endl;

    string input;
    cin >> input;

    if (input == "1") {
    	employees.at(i).setSalary();
    } else if (input == "2") {
    	employees.at(i).setVacationBalance();
    } else if (input == "3") {
    	employees.at(i).setAnnualBonus();
    } else return;
}











