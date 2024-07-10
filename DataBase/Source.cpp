#include "includes.h"

struct ioClass { // special class to manipulate with input-output proccedures

	bool readed;
	bool writed;
	
	char arrSymbols[5] = { '#', '@', '&', '-', '>' };
	string text = "";
	
	string Command;
	string input;
	

};

int main() {

	while (true) {
		//	
		long name = GetName(); // giving a name to txt file
		string nameEx = to_string(name);
		string FileName = (nameEx + ".txt");
		string ArrMan[] = { "/wrt", "/brk", "/clo", "/help", "/read", "/cls" }; // initialization for actions with program


		ioClass FirstL;
		cout << "path: -> main" << endl << endl;
		cout << "'/help' to get commands" << endl << endl;
		cin >> FirstL.Command;


		if (FirstL.Command == ArrMan[0]) {
			Get_CLS();
			ofstream FileWrite;
			ioClass SecondL;

			FileName = ("Page/" + FileName);

			string arrWrtCom[] = { "/path", "/unpath", "/brk"};

				cout << "path: -> main -> write in file" << endl << endl;
				cout << "what next? '/path' - to write in file with path, '/unpath' - to write in file wthout path" << endl;
				cin >> SecondL.Command;
				
				if (SecondL.Command == arrWrtCom[0]){
					string pathP = "Page/";
					string pathS;
					string pathF = "/txt";
				
				
				}

				else if (SecondL.Command == arrWrtCom[1]) {
					try {
						FileWrite.open(FileName); // try to open file

						if (FileWrite.is_open()) { // check to open file
							while (true){

								cout << "path: -> main -> write in file -> unpath" << endl << endl;
								cout << "What do next? '/start' to enter text, '/brk' to leave command line" << endl;

								cin >> SecondL.Command;

								bool writedIN = false;

								if (SecondL.Command == "/start") { // start input in file

									cout << endl << endl << "enter your text" << endl;

									cin >> SecondL.input;
									FileWrite << SecondL.input;
									cout << endl << endl << endl;

									if (SecondL.input != "") {
										writedIN = true;
									}
									if (writedIN == true) {
										cout << endl << endl << "text writed succesfully" << endl << endl;
									}
									else {
										cout << endl << "text is empty" << endl;
									}
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
			}

		else if (FirstL.Command == ArrMan[4]) { // algorithm to function of read and find in file
			Get_CLS();
			ioClass SlineRd;

			string pathP = "Page/";
			string pathS;
			string pathF;

			ifstream fileToRead;

			string ComArray[] = { "/start", "/find", "/brk" }; // list of command

			while (true) {
				cout << "Path: -> main -> read" << endl << endl;

				cout << "'/start' to simple read file, '/find' to find a symbol in file, '/brk' to exit from this command line" << endl;
				cin >> SlineRd.Command;

				if (SlineRd.Command == ComArray[0]) {
					cout << endl << "---------------------------------------------------------------------------------------------" << endl;

					cout << "enter name of your file." << endl;
					cin >> pathS;

					pathF = (pathP + pathS + ".txt");

					fileToRead.open(pathF);

					try {
						bool readed = false;
						if (fileToRead.is_open()) {

							string txt;

							fileToRead >> txt;
							cout << endl << txt << endl;

							if (txt == "") {
								cout << endl << endl << "Text not found" << endl << endl;
							}
							if (txt != "") {
								readed = true;
							}
							if (readed == true) {
								fileToRead.close();
							}
						}
						else {
							cout << endl << endl << "file didnt found" << endl << endl;
						}
					}
					catch (const std::exception&) {
						cout << endl << endl << endl << "file didnt found" << endl << endl << endl;
					}
				}

				else if (SlineRd.Command == ComArray[1]) { // algorithm to find a symbols in file
					cout << endl << "---------------------------------------------------------------------------------------------" << endl;

					try {

						char text[10000]; //initializing array of text. max size of text is (10000) symbols
						bool loopOperator = false; // operator for main loop.

						cout << endl << endl << "enter name of your file" << endl << endl;
						cin >> pathS;

						pathF = (pathP + pathS + ".txt");
						if (pathS != "") {

							fileToRead.open(pathF);

							if (fileToRead.is_open()) {
								cout << endl << "file - open" << endl;

								while (loopOperator == false) { // 

									fileToRead >> text; //input file in array of text
									long numbersSym = 0;

									for (int i = 0; i < 10000; i++) {
										if (text[i] == '(' or text[i] == ')' or text[i] == '-' or text[i] == '$') {

											numbersSym = (numbersSym + 1);
										}
									}
									if (numbersSym > 0) {
										cout << endl << numbersSym << " " << "-" << " " << "numbers of special symbols in text" << endl << endl;
									}
									else if (numbersSym == 0) {
										cout << endl << numbersSym << " " << "-" << " " << "numbers of special symbols in text" << endl << endl;
									}

									loopOperator = true;
								}
							}
							else { // I NEED MORE CHECK
								cout << endl << endl << "file cant be opened" << endl << endl;
							}

						}
						else { // I NEED MORE CHECK
							cout << endl << endl << "invalid name of file" << endl << endl;
						}

					}
					catch (const std::exception&) {

					}

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

		else if (FirstL.Command == ArrMan[5]) {
			Get_CLS();
		}

		else {
			cout << endl << endl << "invalid command" << endl << endl;
		}
	}
	return 0;
