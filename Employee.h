/*
 * Josephine Weidner
 * Employee class definition
 * 
 * Represents an EMPLOYEE with the following fields:
 *    salary, salary history, vacation balance, annual bonus
 *    userID and name (for authentication and identification purposes)
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <string>

using namespace std;

class Employee
{
	public: 
		Employee();
		Employee(string userID, string name);
		~Employee();

		bool authenticateEmp(string userID);

		string getName();

		void setSalary();
		void setVacationBalance();
		void setAnnualBonus();

		double getSalary();
		vector <double> getSalaryHistory();
		int getVacationBalance();
		double getAnnualBonus();


	private:
		string UserID;
		string Name;

		double salary;
		vector <double> salaryHistory;
		int vacationBalance;
		double annualBonus;
};

#endif