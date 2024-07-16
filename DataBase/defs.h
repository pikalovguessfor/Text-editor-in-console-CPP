#pragma once
#include "includes.h"
using namespace std;



void Get_Help() { // function to get help with commands
	cout << endl << endl << endl;
	cout << "Commands:" << endl;
	cout << "'/help' go get list of all commands" << endl;
	cout << "'/wrt' to write something in your file" << endl;
	cout << "'/read' to find info for special symbol, and just see what inside the file" << endl;
	cout << "'/brk' to close command line, also setup CLS command to clear console" << endl;
	cout << "'/clo' to close program" << endl;
	cout << "'/cls' to clear the console" << endl;
	cout << endl << endl << endl;
}

void Get_CLS() {  // self-write fuction to get clear console
	 system("cls");

}

void Get_Exit() {// function to abort programm
	exit(0);
}

