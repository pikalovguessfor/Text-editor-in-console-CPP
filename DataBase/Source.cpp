#include "includes.h"


//----------------------------------------------------------Classes to subwork with text--------------------------------------------------------------\\

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
	char SymArr[2000];
	
	int TextFSym(string text) {
		
		if (FsymBool(text)) {
			cout << endl << "Text is empty" << endl;
		}
		else {
			cout << "";
		}

		return 0;

	}

private:

	bool FsymBool(string text) {
		
		for (int i = 0; i != 1; i++) {
			if (text[i] == '\n' or text[i] == '\0') {

				return true;

			}
			else {
				return false;
			}
		}
	}
};
//----------------------------------------------------------------------------------------------------------------------------------\\


int main() {
	
	while (true) {

		string ArrMan[] = { "/wrt", "/brk", "/clo", "/help", "/rd", "/cls" }; // initialization for actions with program
		ioClass FirstL;

		cout << "path: -> main" << endl << endl;
		cout << "'/help' to get commands" << endl << endl;

		cin >> FirstL.Command;
		FirstL.ChSlash();



		//----------------------------------------------------------WRT function--------------------------------------------------------------\\

		if (FirstL.Command == ArrMan[0]) {
			Get_CLS();

			while (true) {

				ioClass SecondL;

				ofstream FileWrite;

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


						cout << endl << "enter your text" << endl;
						cin.get();
						getline(cin, TextPath.Text);

						TextPath.TextFSym(TextPath.Text);

						FileWrite << TextPath.Text;

						FileWrite.close();
					}
					else {
						cout << endl << "cant open file" << endl;
					}
				}

				else if (SecondL.Command == arrWrtCom[1]) { //function to write without path
					subclassName nameGener;

					// algorith imagined in "name_gen.h"	
					long nameFileUn = genNameUn();			// giving a name to txt file
					string nameEx = to_string(nameFileUn);
					nameEx = nameEx + "_un";

					string FileName = (nameEx + ".txt");
					FileName = ("Page/" + FileName);       // filename for unpath fuction
					cout << endl << FileName << "<- name of file" << endl;
					//

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

						TextUnpath.TextFSym(TextUnpath.Text);
						
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


		//----------------------------------------------------------READ function--------------------------------------------------------------\\

		else if (FirstL.Command == ArrMan[4]) {					// algorithm to function of read and find in file
			Get_CLS();
			ioClass SlineRd;

			ifstream fileToRead;

			string ComArray[] = { "/start", "/find", "/brk" };	// list of command

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

						for (int i = 0; i < 1999; i++) {
							fileToRead.get(TextINSRead.SymArr[i]);
						}
						cout << endl << endl << TextINSRead.SymArr << endl << endl;

						
						fileToRead.close();
					}
					else {
						cout << endl << endl << endl << "file cant be opened" << endl << endl << endl;
					}
				}

				else if (SlineRd.Command == ComArray[1]) {			// algorithm to find a special symbols in file
					ioClass insideFind;
					TextWork TextInsideFind;
					Parcer ParceSpec;

					string nameFileF = "Page/";
					string nameFileS;
					string nameFileT = ".txt";

					cout << endl << "enter name of your file" << endl;
					cin >> nameFileS;
					
					string nameFileE = (nameFileF + nameFileS + nameFileT);
					
					fileToRead.open(nameFileE);

					if (fileToRead.is_open()) {

						TextInsideFind.Text;

						cout << endl << "file is open" << endl;
						for (int i = 0; i <= 1999; i++) {
							fileToRead.get(TextInsideFind.SymArr[i]);
						}
						
						ParceSpec.ParseFile(TextInsideFind.SymArr);
						
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

		//----------------------------------------------------------SUB functions--------------------------------------------------------------\\

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