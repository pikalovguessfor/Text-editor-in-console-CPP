#include "includes.h"
using namespace std;

class ProgramStatus {
	public:
		bool IsOpen;
		bool Writed;
		bool Close;
};

class Actions {
	public:
		string Command;

		// you can use it to manipulate with actions inside the program
};

void Get_Help() { // function to get help with commands
	cout << endl << endl << endl;
	cout << "Welcome to my programm, everything was create just for fun. Thats simply DataBase like program" << endl;
	cout << "'/help' go get list of all commands" << endl;
	cout << "'/wrt' to write something in your file" << endl;
	cout << "/'brk' to close command line, also setup CLS command to clear console" << endl;
	cout << "'/clo' to close program" << endl;
	cout << endl << endl << endl;
}

void Get_CLS() {  // self-write fuction to get clear console
	for (int i = 0; i < 80; i++) {
		cout << endl;
	}
}

void Get_Exit() {// function to abort programm
	exit(0);
}

int main() {
	while (true) {
		while (true) {
			long name = GetName(); // giving a name to txt file
			string nameEx = to_string(name);
			string FileName = (nameEx + ".txt");

			ProgramStatus Stat; // initialise class of prog status
			Stat.IsOpen = false;
			Stat.IsOpen = false;
			Stat.Close = false;

			string ArrMan[] = { "/wrt", "/brk", "/clo", "/help"}; // initialization for actions with program 

			Actions FirstL;
			cout << "'/help' to get commands";
			cin >> FirstL.Command;


			if (FirstL.Command == ArrMan[0]) {
				Get_CLS();
				ofstream FileWrite;

				FileName = ("Page/" + FileName);
				FileWrite.open(FileName);
			}

			else if (FirstL.Command == ArrMan[1]) {
				Get_CLS();
				break;
			}

			else if (FirstL.Command == ArrMan[2]) {
				Get_Exit();
			}

			else if (FirstL.Command == ArrMan[3]) {
				Get_Help();
			}

			else {
				cout << endl << endl << "invalid command" << endl << endl;
			}

		}
	}
	return 0;
}