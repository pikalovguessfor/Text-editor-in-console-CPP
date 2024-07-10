#pragma once
#include "includes.h"
using namespace std;

int GetName() {  
	// this is function to generate a name of your file.
	// this is need to do your program more unique.
	// you can create more than one txt file. 
	// use function to_string in main page of program, to mutate in string.
	// thats need because function GenName() return INT type;

	long long *timeSr = 0;

	srand(time(timeSr));

	long Fi = 0;
	long Se = 0;
	long Th = 0;
	long Fo = 0;
	long Fv = 0;

	long Grab[] = {111 , 222, 333, 444, 555};

	int Fi_op = rand() % 20;
	int Se_op = rand() % 20;
	int Th_op = rand() % 20;
	int Fo_op = rand() % 20;
	int FV_op = rand() % 20;

	if (Fi_op < 10) {
		Fi = Grab[0];
	}
	else if (Fi_op > 10) {
		Fi = Grab[1];
	}
	else if (Fi_op == 10) {
		Fi = Grab[2];
	}

	if (Se_op < 10) {
		Se = Grab[3];
	}
	else if (Se_op > 10) {
		Se = Grab[4];
	}
	else if (Se_op == 10) {
		Se = Grab[0];
	}

	if (Th_op < 10) {
		Th = Grab[2];
	}
	else if (Th_op > 10) {
		Th = Grab[3];
	}
	else if (Th_op == 10) {
		Th = Grab[0];
	}

	if (Fo_op < 10) {
		Fo = Grab[4];
	}
	else if (Fo_op > 10) {
		Fo = Grab[2];
	}
	else if (Fo_op == 10) {
		Fo = Grab[0];
	}

	if (Fi_op < 10) {
		Fi = Grab[4];
	}
	else if (Fi_op > 10) {
		Fi = Grab[1];
	}
	else if (Fi_op == 10) {
		Fi = Grab[2];
	}
	
	
	long Name = (Fi + Se + Th + Fo + Fv + (rand() % 1000));

	return Name;
}
void Get_Help() { // function to get help with commands
	cout << endl << endl << endl;
	cout << "Commands:" << endl;
	cout << "'/help' go get list of all commands" << endl;
	cout << "'/wrt' to write something in your file" << endl;
	cout << "'/read' to find info for special symbol, and just see what inside the file" << endl;
	cout << "/'brk' to close command line, also setup CLS command to clear console" << endl;
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
