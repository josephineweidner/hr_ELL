/*
 * Josephine Weidner
 * Manager class definition
 * 
 * Represents a MANAGER with the following fields:
 *    a list of employees, userID and name
 */

#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

using namespace std;

class Manager
{
	public: 
		Manager();
		Manager(string UserID, string name);
		~Manager();

        bool authenticate(string UserID);
        bool hasEmployee(string UserID);

		void addEmployee(string userID, string name);
		void viewEmployee(string Name);
		void updateEmployee(string Name);

	private:
        string userID;
        string Name;

		vector <Employee> employees; 
		int numEmployees;
};

#endif