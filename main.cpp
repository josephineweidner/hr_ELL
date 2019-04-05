/*
 * Josephine Weidner
 * main.cpp - driver for the HRApp program
 */

#include <iostream>
#include <string.h>

#include "HRApp.h"

using namespace std;

int main()
{
	HRApp myApp("admin");

	myApp.run();

   return 0;
}