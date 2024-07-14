#define _CRT_SECURE_NO_WARNINGS

#include "includes.h"
#include "defs.h"


class ioClass { // special class to manipulate with input-output proccedures
public:
	
	const char arrSymbols[5] = { '#', '@', '&', '-', '>' };

	string text = "";
	
	string Command = "";
	string input = "";
	


	void ChSlash() { //check '/' symbol in command
		
		if (Command[0] != '/') {
			cout << endl << endl << "commands must begin from '/' symbol";
		}

	}

};

class TextWork {
public:

	string Text; //class to work with text in "find" function
	
	
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
		FirstL.ChSlash();


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
				SecondL.ChSlash(); // check correct of 'command'

				if (SecondL.Command == arrWrtCom[0]) { // write inside file with path

					ioClass insidePathWrt_;
					TextWork TextPath;

					string pathP = "Page/"; // first part of path to file
					string pathS;			// second part of path to file
					string pathF = ".txt";  // third part of path to file

					cout << endl << "please write name of your file" << endl;
					cin >> pathS;

					string pathEX = (pathP + pathS + pathF); // setting name of file

					FileWrite.open(pathEX);
					if (FileWrite.is_open()) {

						char symbol = ' ';

						cout << endl << "enter your text" << endl;
						cin.get();
						getline(cin, TextPath.Text);
						
						FileWrite << TextPath.Text;

						FileWrite.close();
					}
					else {
						cout << endl << "cant open file" << endl;
					}
				}

				else if (SecondL.Command == arrWrtCom[1]) { //function to write without path
					ioClass insideUnpathWrt;
					TextWork TextUnpath;
					
					FileWrite.open(FileName);

					if (FileWrite.is_open()) {

						TextUnpath.Text;                   //var text

						cout << endl << endl;
						cout << "enter your text";
						cout << endl << endl;
						
						cin.get();
						getline(cin, TextUnpath.Text);
						
						FileWrite << TextUnpath.Text;


						FileWrite.close();
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
				SlineRd.ChSlash();

				if (SlineRd.Command == ComArray[0]) {
					ioClass insideRead;

					TextWork TextINSRead;

					string nameFileF = "Page/";
					string nameFileS;
					string nameFileT = ".txt";

					cout << endl << "enter name of your file." << endl;
					cin >> nameFileS;

					string nameFileE = (nameFileF + nameFileS + nameFileT);

					fileToRead.open(nameFileE);

					if (fileToRead.is_open()) {

						TextINSRead.Text;

						cout << endl << "file is open" << endl;

						fileToRead >> TextINSRead.Text;

						cout << endl << endl << TextINSRead.Text << endl << endl;

						
						fileToRead.close();
					}
					else {
						cout << endl << endl << endl << "file cant be opened" << endl << endl << endl;
					}
				}

				else if (SlineRd.Command == ComArray[1]) { // algorithm to find a symbols in file
					ioClass insideFind;
					TextWork TextInsideFind;

					string nameFileF = "Page/";
					string nameFileS;
					string nameFileT = ".txt";

					cout << endl << "enter name of your file" << endl;
					cin >> nameFileS;
					
					string nameFileE = (nameFileF + nameFileS + nameFileT);
					
					fileToRead.open(nameFileE);

					if (fileToRead.is_open()) {

						TextInsideFind.Text;
						long count = 0;

						cout << endl << "file is open" << endl;
						fileToRead >> TextInsideFind.Text;
						
						
						for (int i = 0; i < sizeof(TextInsideFind.Text); i++) { // loop for calculate numbers of specSymbols in array
							if(TextInsideFind.Text[i] == insideFind.arrSymbols[0]) {
								count++;

								cout << TextInsideFind.Text[i - 5] << TextInsideFind.Text[i - 4] << TextInsideFind.Text[i - 3] << TextInsideFind.Text[i - 2] << TextInsideFind.Text[i - 1] << TextInsideFind.Text[i];
							}
							else if (TextInsideFind.Text[i] == insideFind.arrSymbols[1]) {
								count++;

								cout << TextInsideFind.Text[i - 5] << TextInsideFind.Text[i - 4] << TextInsideFind.Text[i - 3] << TextInsideFind.Text[i - 2] << TextInsideFind.Text[i - 1] << TextInsideFind.Text[i];
							}
							else if (TextInsideFind.Text[i] == insideFind.arrSymbols[2]) {
								count++;

								cout << TextInsideFind.Text[i - 5] << TextInsideFind.Text[i - 4] << TextInsideFind.Text[i - 3] << TextInsideFind.Text[i - 2] << TextInsideFind.Text[i - 1] << TextInsideFind.Text[i];
							}
							else if (TextInsideFind.Text[i] == insideFind.arrSymbols[3]) {
								count++;

								cout << TextInsideFind.Text[i - 5] << TextInsideFind.Text[i - 4] << TextInsideFind.Text[i - 3] << TextInsideFind.Text[i - 2] << TextInsideFind.Text[i - 1] << TextInsideFind.Text[i];
							}
							else if (TextInsideFind.Text[i] == insideFind.arrSymbols[4]) {
								count++;

								cout << TextInsideFind.Text[i - 5] << TextInsideFind.Text[i - 4] << TextInsideFind.Text[i - 3] << TextInsideFind.Text[i - 2] << TextInsideFind.Text[i - 1] << TextInsideFind.Text[i];
							}

						}

						cout << endl << endl << endl;
						cout << "Numbers of special symbols inside your file is -> " << count;
						cout << endl << endl << endl;


						fileToRead.close();
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