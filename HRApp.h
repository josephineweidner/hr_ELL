/*
 * Josephine Weidner
 * HRApp class definition
 * 
 * Represents a human resources app, where the application 
 * maintains a list of managers, a list of all users & permissions,
 * and has an admin userID to enter the application as an admin user
 * 
 * To compile: make
 * To run: ./hr
 */

#ifndef HRAPP_H
#define HRAPP_H

#include "Manager.h"

using namespace std;

class HRApp
{
	public: 
		HRApp();    
		HRApp(string AdminID); 
		~HRApp();
		void run();

	private:
		string adminID;

		/* ID struct representing each user of the system */
		struct ID {
			string userID;
			string name;
			string role;
		};

		/* keeps track of users of system */
		vector <ID> users;
		void addNewUser(string userID, string name, string role) ;

		/* runs based on userID entered */
		void runAdmin();
		void runManager(string userID);
		void runEmployee(string userID);
		void runHREmployee(string userID);

		/* keeps track of managers and adds users */
		vector <Manager> managers; 
		void addManager();
		void addEmployee();
		int findManager(string userID); //where input is manager's userID

		/* helper functions for permissions */
		string userIDof(string name); // name -> userID
		string nameof(string userID); // userID -> name
		string roleof(string userID); // userID -> role
};

#endif