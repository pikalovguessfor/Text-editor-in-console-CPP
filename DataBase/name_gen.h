#pragma once

#include "includes.h"
using namespace std;



class subclassName {
		// this is class for generate name of file in SCENARIO UNPATH.

	public:
		long NameProg = 0;
		bool NameNotUsing = false;

		int GetName() {
			// this is function to generate a name of your file.
			// this is need to do your program more unique.
			// thats need for multiple create a some programms
			// you can create more than one txt file. 
			// use function to_string in main page of program, to mutate in string.
			// thats need because function GenName() return LONG type;

			srand(time(0));

			long name;

			do {

				name = (1 + rand() % 100000);

			} while (!__GenNameValid(name));

			return name;
		}

	private:
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
		
		subclassName classgen;
		
		return classgen.GetName();
	}
	