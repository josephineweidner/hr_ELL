/*
 * Josephine Weidner
 * Employee class implementation
 * 
 * Represents an EMPLOYEE with the following fields:
 *    salary, salary history, vacation balance, annual bonus
 *    userID and name (for authentication and identification purposes)
 */

#include <string>
#include <cstdio>
#include <iostream>

#include "Employee.h"

using namespace std;

/* Default constructor for Employee
 * Initializes an instance of Employee to defaults
 */
Employee::Employee()
{
    UserID = "USERID_DEFAULT";
	Name = "NAME_DEFAULT";

	salary = 0.0;
	vacationBalance = 0;
	annualBonus = 0;
}

/* Destructor
 */
Employee::~Employee()
{
    //nothing to be done - memory management taken care of by STL vector
}

/* Parameterized constructor for Employee
 * Parameters: string userID, string name
 * Purpose: Initializes an instance of Employee to defaults and userID + name
 */
Employee::Employee(string userID, string name)
{
    UserID = userID;
	Name = name;

	salary = 0.0;
	vacationBalance = 0;
	annualBonus = 0;
}

/* getName()
 * returns string name of employee
 */
string Employee::getName()
{
    return Name;
}

/* authenticateEmp()
 * Parameters: string userID
 * Returns true if userID passed in is equal to UserID of employee, 
 * else returns false
 */
bool Employee::authenticateEmp(string userID)
{
	return (UserID == userID);
}

/* setSalary()
 * Prompts user for input salary, changes salary field of employee,
 * and updates salary history accordingly 
 */
void Employee::setSalary()
{
	cout << "Enter new Salary for employee " << Name << " : ";
	double newsalary;
	cin >> newsalary;
	salary = newsalary;
	salaryHistory.push_back(newsalary);
}

/* setVacationBalance()
 * Prompts user for input vacation balance, and changes vacation 
 * balance field of employee
 */
void Employee::setVacationBalance()
{
	cout << "Enter new vacation balance for employee " << Name << " : ";
	int newvacbal;
	cin >> newvacbal;
	vacationBalance = newvacbal;
}

/* setAnnualBonus()
 * Prompts user for input annual bonus, and changes annual
 * bonus field of employee
 */
void Employee::setAnnualBonus()
{
	cout << "Enter new annual bonus for employee " << Name << " : ";
	double annbonus;
	cin >> annbonus;
	annualBonus = annbonus;
}


/* getSalary()
 * Returns salary attribute (double) of employee
 */
double Employee::getSalary()
{
    return salary;
}

/* getSalaryHistory()
 * Returns vector of doubles containing employee's salary history
 */
vector <double> Employee::getSalaryHistory()
{
    return salaryHistory;
}

/* getVacationBalance()
 * Returns vacation balance (int) of employee
 */
int Employee::getVacationBalance()
{
	return vacationBalance;
}

/* getAnnualBonus()
 * Returns annual bonus (double) of employee
 */
double Employee::getAnnualBonus()
{
	return annualBonus;
}

