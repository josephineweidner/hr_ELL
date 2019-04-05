#
# Makefile for Human Resources Application - Ellevation 
#
CXX      = clang++
CXXFLAGS = -Wall -Wextra -Wreturn-type -std=c++11 -g -O2
LDFLAGS  = -g

hr:         HRApp.o Manager.o Employee.o main.o
	        ${CXX} ${LDFLAGS} -o hr HRApp.o Manager.o Employee.o  main.o 

##testEmployee.o: testEmployee.cpp Employee.h
Employee.o:     Employee.cpp Employee.h

##testManager.o:  testManager.cpp Manager.h Employee.h
Manager.o:      Manager.cpp Manager.h 

main.o:         main.cpp HRApp.h
HRApp.o:        HRApp.cpp HRApp.h
