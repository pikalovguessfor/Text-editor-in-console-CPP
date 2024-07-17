#pragma once

#include "includes.h"
using namespace std;


class subclassName {
	// this is class for generate name of file in SCENARIO UNPATH.

public:
	long NameProg;
	bool NameNotUsing = false;

	int GetName() {
		// this is function to generate a name of your file.
		// this is need to do your program more unique.
		// thats need for multiple create a some programms
		// you can create more than one txt file. 
		// use function to_string in main page of program, to mutate in string.
		// thats need because function GenName() return LONG type;

		long name = rand() % 100000;

		return name;
	}


	// bool method to check file with this name is exist;

	bool __GenNameValid(long name) {

		ifstream subCheck;

		string name_string = to_string(name);

		subCheck.open(name_string + ".txt");

		if (subCheck.is_open()) {
			return false;
		}

		else {
			return true;
		}
	}
};


long genNameUn() {
	//Main function theres uses class methods of class "subclass name"

	srand(time(0));

	subclassName Namecl;
	
	long NameFile = Namecl.NameProg;
	long finalName = 0;

	linkgoto:

	Namecl.NameProg = Namecl.GetName();
	
	while (true){
		if (Namecl.__GenNameValid(Namecl.NameProg)) {
			return Namecl.NameProg;

		}
		else {
			goto linkgoto;
		}
	}
}