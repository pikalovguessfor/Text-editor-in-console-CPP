#include "includes.h"
using namespace std;

class Actions {
	public:
		string Command;
		string input;

		// you can use it to manipulate with actions inside the program
};

void Get_Help() { // function to get help with commands
	cout << endl << endl << endl;
	cout << "Welcome to my programm, everything was create just for fun. Thats simply DataBase like program" << endl;
	cout << "'/help' go get list of all commands" << endl;
	cout << "'/wrt' to write something in your file" << endl;
	cout << "'/find' to find info for special symbol, and just see what inside the file" << endl;
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
		Get_CLS();

		while (true) {
			//
			long name = GetName(); // giving a name to txt file
			string nameEx = to_string(name);
			string FileName = (nameEx + ".txt");
			//
			string ArrMan[] = { "/wrt", "/brk", "/clo", "/help", "/find"}; // initialization for actions with program 
			//
			Actions FirstL;
			cout << "path: -> main" << endl << endl;
			cout << "'/help' to get commands";
			cin >> FirstL.Command;


			if (FirstL.Command == ArrMan[0]) {
				Get_CLS();
				ofstream FileWrite;

				FileName = ("Page/" + FileName);

				try {
					FileWrite.open(FileName); // try to open file
					
					if (FileWrite.is_open()) { // check to open file
						while (true)
						{
							Get_CLS();

							cout << "path: -> main -> write in file" << endl << endl;
							cout << "What do next? '/start' to enter text, '/brk' to leave command line" << endl;
							
							Actions SecondL;
							cin >> SecondL.Command;
							if (SecondL.Command == "/start") { // start input in file
								cout << endl << endl << "enter your text" << endl;


								cin >> SecondL.input;
								
								FileWrite << SecondL.input;

								cout << endl << endl << endl;
							}
							else if (SecondL.Command == ArrMan[1]) {
								FileWrite.close();
								Get_CLS();
								break;
							}
							else {
								cout << endl << "invalid command" << endl;
							}

						}
					}
					else {
						cout << endl << endl;
						cout << "cant open file...";
						cout << endl << endl;
					}
				}
				catch (const char) {
					cout << endl << endl;
					cout << "something went wrong";
					cout << endl;
				}
			}

			else if (FirstL.Command == ArrMan[4]) { // algorithm to function of read and find in file
				Get_CLS();
				Actions SlineRd;

				string pathP = "Page/";
				string pathS;
				string pathF;

				ifstream fileToRead;
				
				string ComArray[] = { "/start", "/find", "/brk" }; // list of command
				
				while (true) {
					cout << "Path: -> main -> find" << endl << endl;
					cout << "'/start' to simple read file, '/find' to find a symbol in file, '/brk' to exit from this command line" << endl;
					cin >> SlineRd.Command;
					cout << "enter name of your file." << endl;
					cin >> pathS;

					string pathF = (pathP + pathS + ".txt");
					
					if (SlineRd.Command == ComArray[0]) {
						fileToRead.open(pathF);

						try {
							if (fileToRead.is_open()) {
								string txt;
								
								fileToRead >> txt;
								cout << endl << txt << endl;

								if (txt == "") {
									cout << endl << endl << "Text not found" << endl << endl;
								}
							}
						}
						catch (const std::exception&) {
							cout << endl << endl << endl << "file didnt found" << endl << endl << endl;
						}
					}
					else if (SlineRd.Command == ComArray[1]) {

					}
					else if (SlineRd.Command == ComArray[2]) {
						break;
					}
					else {
						cout << endl << endl << "invalid command" << endl << endl;
					}
				}
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