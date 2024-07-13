#include "includes.h"

class ioClass { // special class to manipulate with input-output proccedures
public:

	bool readed = false;
	bool writed =  false;
	
	char arrSymbols[5] = { '#', '@', '&', '-', '>' };

	string text = "";
	
	string Command = "";
	string input = "";

};



int main() {

	while (true) {
		//	
		long name = GetName(); // giving a name to txt file
		string nameEx = to_string(name);
		string FileName = (nameEx +".txt");
		string ArrMan[] = { "/wrt", "/brk", "/clo", "/help", "/read", "/cls" }; // initialization for actions with program


		ioClass FirstL;
		cout << "path: -> main" << endl << endl;
		cout << "'/help' to get commands" << endl << endl;
		cin >> FirstL.Command;


		if (FirstL.Command == ArrMan[0]) {
			Get_CLS();
			while (true) {
				ioClass SecondL;

				ofstream FileWrite;

				FileName = ("Page/" + FileName); // filename for unpath fuction

				string arrWrtCom[] = { "/path", "/unpath", "/brk" };

				cout << "path: -> main -> write in file" << endl << endl;
				cout << "what next? '/path' - to write in file with path, '/unpath' - to write in file wthout path, '/brk' to close this line" << endl;
				cin >> SecondL.Command;

				if (SecondL.Command == arrWrtCom[0]) { // write inside file with path

					ioClass insidePathWrt_;

					string pathP = "Page/"; // first part of path to file
					string pathS;			// second part of path to file
					string pathF = ".txt";  // third part of path to file

					cout << endl << "please write name of your file" << endl;
					cin >> pathS;

					string pathEX = (pathP + pathS + pathF); // setting name of file

					FileWrite.open(pathEX);
					if (FileWrite.is_open()) {

						cout << endl << "enter your text" << endl;
						cin >> insidePathWrt_.text;

						FileWrite << insidePathWrt_.text;

						ifstream checkWrited; // check theres text was writed
						checkWrited.open(pathEX);
						if (checkWrited.is_open()) {

							string text_check;

							checkWrited >> text_check;

							if (text_check != " " or text_check != "") {
								insidePathWrt_.writed = true;
							}
							else {
								cout << endl << "text didnt writed" << endl;
							}

							if (insidePathWrt_.writed == true) {
								cout << endl << endl << "text writed succesfully" << endl << endl;
							}
						}
					}
					else {
						cout << endl << "cant open file" << endl;
					}
				}

				else if (SecondL.Command == arrWrtCom[1]) { //function to write without path
					ioClass insideUnpathWrt;

					ifstream help_me_write;
					
					FileWrite.open(FileName);

					if (FileWrite.is_open()) {

						string text;                       //var text
						char text_rewriter[20000];

						cout << endl << endl;
						cout << "enter your text";
						cout << endl << endl;
						
						cin >> text;
						
						FileWrite << text;

					}
					else {
						cout << endl << endl <<endl;
						cout << "cant open file";
						cout << endl << endl << endl;
					}
				}

				else if (SecondL.Command == arrWrtCom[2]) {
					break;
				}
			}
		}

		else if (FirstL.Command == ArrMan[4]) { // algorithm to function of read and find in file
			Get_CLS();
			ioClass SlineRd;

			ifstream fileToRead;

			string ComArray[] = { "/start", "/find", "/brk" }; // list of command

			while (true) {
				cout << "Path: -> main -> read" << endl << endl;

				cout << "'/start' to simple read file, '/find' to find a symbol in file, '/brk' to exit from this command line" << endl;
				cin >> SlineRd.Command;

				if (SlineRd.Command == ComArray[0]) {
					ioClass insideRead;

					string nameFileF = "Page/";
					string nameFileS;
					string nameFileT = ".txt";

					cout << endl << "enter name of your file." << endl;
					cin >> nameFileS;

					string nameFileE = (nameFileF + nameFileS + nameFileT);

					fileToRead.open(nameFileE);

					if (fileToRead.is_open()) {

						char text[15000];

						cout << endl << "file is open" << endl;
						fileToRead >> text;

						cout << endl << endl << text << endl << endl;
					
					}
					else {
						cout << endl << endl << endl << "file cant be opened" << endl << endl << endl;
					}
				}

				else if (SlineRd.Command == ComArray[1]) { // algorithm to find a symbols in file
					ioClass insideFind;

					string nameFileF = "Page/";
					string nameFileS;
					string nameFileT = ".txt";

					cout << endl << "enter name of your file" << endl;
					cin >> nameFileS;
					
					string nameFileE = (nameFileF + nameFileS + nameFileT);
					
					fileToRead.open(nameFileE);

					if (fileToRead.is_open()) {

						char text[15000];
						long count = 0;

						cout << endl << "file is open" << endl;
						fileToRead >> text;
						
						
						for (int i = 0; i < sizeof(text); i++) { // loop for calculate numbers of specSymbols in array
							if(text[i] ==insideFind.arrSymbols[0]) {
								count++;
							}
							else if (text[i] == insideFind.arrSymbols[1]) {
								count++;
							}
							else if (text[i] == insideFind.arrSymbols[2]) {
								count++;
							}
							else if (text[i] == insideFind.arrSymbols[3]) {
								count++;
							}
							else if (text[i] == insideFind.arrSymbols[4]) {
								count++;
							}

						}

						cout << endl << endl << endl;
						cout << "Numbers of special symbols inside your file is -> " << count;
						cout << endl << endl << endl;


					}
					else {
						cout << endl << endl << endl << "file cant be open" <<  endl;
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
}