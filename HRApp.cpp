/*
 * Josephine Weidner
 * HRApp class implementation
 * 
 * Represents a human resources app, where the application 
 * maintains a list of managers, a list of all users & permissions,
 * and has an admin userID to enter the application as an admin user
 * 
 * To compile: make
 * To run: ./hr
 */


#include "Manager.h"
#include "HRApp.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

/* Default constructor 
 * sets adminID to default: "admin"
 */
HRApp::HRApp()
{
	adminID = "admin";
}

/* Parameterized constructor 
 * sets adminID to string passed in as argument
 */
HRApp::HRApp(string AdminID)
{
	adminID = AdminID;
}

/* Destructor 
 */
HRApp::~HRApp()
{
	//nothing to be done
}

/* run()
 * Prompts for userID input, begins program, driver function
 */
void HRApp::run()
{
	string ID;
	cout << "------------------------------------------------------------ " << endl; 
	cout << endl << endl; 
	cout << "------------------------------------------------------------ " << endl; 
	cout << "WELCOME TO HR APP. Enter q to quit. Please enter your UserID: "; 
	cin >> ID;

	if (ID == adminID) {
		cout << "Welcome admin" << endl;
		runAdmin();
	} else if (roleof(ID) == "MANAGER") {
		runManager(ID);
	} else if (roleof(ID) == "EMPLOYEE") {
		runEmployee(ID);
	} else if (roleof(ID) == "HR_EMPLOYEE") {
		runHREmployee(ID);
	} else if (ID == "q") {
		return;
	} else {
		cout << "Incorrect UserID entered. Please try again." << endl;
		run();
	}
}

/* runAdmin()
 * Parameters: none
 * Allows admin to add users
 */
void HRApp::runAdmin()
{ 
	string option;

	cout << "Enter 1 to add new manager" << endl 
	     << "      2 to add new employee" << endl;

	cin >> option;

	if (option == "1") {
		addManager();
	} else if (option == "2") {
		addEmployee();
	}

	cout << "Enter q to quit" << endl 
	     << "      c to continue" << endl
	     << "      l to logout" << endl;

	cin >> option;

	if (option == "q") {
		return;
	} else if (option == "c") {
		runAdmin();
	} else if (option == "l") {
		run();
	}
}

/* runManager(string userID)
 * Parameters: string userID
 * Allows manager to edit and view their employees
 */
void HRApp::runManager(string userID)
{
	string option, empname;

	cout << "Enter 1 to view employee" << endl 
	     << "      2 to update employee" << endl;

	cin >> option;

	//notes on findManager()
	// - userID already confirmed to exist, will not return -1
	// - findManager() based on manager's userID, which ensures that manager 
	//   will only be able to view their own employees' information
	if (option == "1") {
		cout << "Enter employee's name: " << endl;
		cin >> empname;
		managers.at(findManager(userID)).viewEmployee(empname);
	} else if (option == "2") {	
		cout << "Enter employee's name: " << endl;
		cin >> empname;
		managers.at(findManager(userID)).updateEmployee(empname);
	}

	cout << "Enter q to quit" << endl 
	     << "      c to continue" << endl
	     << "      l to logout" << endl;

	cin >> option;

	if (option == "q") {
		return;
	} else if (option == "c") {
		runManager(userID);
	} else if (option == "l") {
		run();
	}
}

/* runEmployee(string userID)
 * Parameters: string userID 
 * Allows employee to view their information
 */
void HRApp::runEmployee(string userID)
{
	//get Name of employee with given userID
	string name = nameof(userID);
	bool found = false;

	//determine who is employee's manager
	unsigned long int i;
	for (i = 0; i < managers.size(); i++) {
		if (managers.at(i).hasEmployee(userID)) {
			managers.at(i).viewEmployee(name);
			found = true;
		}
	}

	// sanity check (employee should be in the system before this fct called)
	if (found == false) {
		cout << "Employee is not in the system" << endl;
	}

	string option;
	cout << "Enter q to quit" << endl 
	     << "      c to continue" << endl
	     << "      l to logout" << endl;

	cin >> option;

	if (option == "q") {
		return;
	} else if (option == "c") {
		runEmployee(userID);
	} else if (option == "l") {
		run();
	}
}

void HRApp::runHREmployee(string userID)
{
	string option;
	cout << "Enter 1 to view my information" << endl 
	     << "      2 to view other employees' information" << endl;

	cin >> option;

	string empname_toview;
	string empuserID_toview;

	bool access_ok = true;

	if (option == "1") { //viewing own information
		empname_toview = nameof(userID);
		empuserID_toview = userID;
	} else if (option == "2") {
        cout << "Enter employee's name: " << endl;
		cin >> empname_toview;
		empuserID_toview = userIDof(empname_toview);

		if (roleof(empuserID_toview) != "EMPLOYEE") {
			access_ok = false;
		}
	}

	bool found = false;
	unsigned long int i;
	if (access_ok == true) {
		for (i = 0; i < managers.size(); i++) {
				if (managers.at(i).hasEmployee(empuserID_toview))
					managers.at(i).viewEmployee(empname_toview);
					found = true;
	 	    }
	}

	if (found == false)
	 		cout << "Sorry, unable to access " << empname_toview << "'s information." << endl;

	cout << "Enter q to quit" << endl 
	     << "      c to continue" << endl
	     << "      l to logout" << endl;

	cin >> option;

	if (option == "q") {
		return;
	} else if (option == "c") {
		runHREmployee(userID);
	} else if (option == "l") {
		run();
	}
}

/* findManager(string userID)
 * Parameters: string userID of manager
 * Returns index into managers vector for manager
 * with given userID
 */
int HRApp::findManager(string userID)
{
	unsigned long int i;
    for (i = 0; i < managers.size(); i++) {
    	if (managers.at(i).authenticate(userID))
    		return i;
    }
    return -1; 
}

/* addManager()
 * Parameters: none
 * Prompts user for input userID and name for new manager
 * Adds new manager & new user of system
 */
void HRApp::addManager() 
{
	string userID, name;
	cout << "Enter UserID for new manager in this system: " << endl;
	cin >> userID;
	cout << "Enter name for new manager in this system: " << endl;
	cin >> name;

	Manager newManager(userID, name);
	managers.push_back(newManager);

	addNewUser(userID, name, "MANAGER");
}

/* addEmployee()
 * Parameters: none
 * Prompts user for input userID and name for new employee,
 * as well as new employee's manager
 * Adds new employee & new user of system
 */
void HRApp::addEmployee() 
{  
	string managername, userID, name;
	cout << "Enter new employee's manager: " << endl;
	cin >> managername;
	string managerID = userIDof(managername);

	if (roleof(managerID) != "MANAGER") {
		cout << "Sorry, manager with name " << managername << "does not exist" << endl;
		return;
	}

	string isHRopt;
	cout << "Enter 1 if employee is part of HR Dept, else enter 2 " << endl;
	cin >> isHRopt;

	bool isHR = (isHRopt == "1");

	cout << "Enter UserID for new employee in this system: " << endl;
	cin >> userID;

	cout << "Enter name for new employee in this system: " << endl;
	cin >> name;

	managers.at(findManager(managerID)).addEmployee(userID, name);

	if (isHR) 
		addNewUser(userID, name, "HR_EMPLOYEE");
	else addNewUser(userID, name, "EMPLOYEE");
}

/* addNewUser(string userID, string name, string role)
 * Parameters: string userID, string name, string role
 * Adds new user to list of users maintained by HRApp
 */
void HRApp::addNewUser(string userID, string name, string role) 
{
	ID newUser;
	newUser.userID = userID;
	newUser.name = name;
	newUser.role = role;

	users.push_back(newUser);
}

/* userIDof(string name)
 * Parameters: string name
 * Returns: string userID
 * Returns string userID associated with the name passed in
 * in list of users, or "NOT_FOUND" if name not present
 * in list of users
 */
string HRApp::userIDof(string name)
{
	unsigned long int i;
	for (i = 0; i < users.size(); i++) {
		if (users.at(i).name == name)  {
			return users.at(i).userID;
		}
	}
	return "NOT_FOUND";
}

/* nameof(string userID)
 * Parameters: string userID
 * Returns: string name
 * Returns string name associated with the userID passed in
 * in list of users, or "NOT_FOUND" if userID not present
 * in list of users
 */
string HRApp::nameof(string userID)
{
	unsigned long int i;
	for (i = 0; i < users.size(); i++) {
		if (users.at(i).userID == userID)  {
			return users.at(i).name;
		}
	}
	return "NOT_FOUND";
}

/* roleof(string userID)
 * Parameters: string role
 * Returns: string userID
 * Returns string role associated with the userID passed in
 * in list of users, or "NOT_FOUND" if userID not present
 * in list of users
 */
string HRApp::roleof(string userID)
{
	unsigned long int i;
	for (i = 0; i < users.size(); i++) {
		if (users.at(i).userID == userID)  {
			return users.at(i).role;
		}
	}
	return "NOT_FOUND";
}
