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

			string ArrMan[] = { "/wrt", "/brk", "/clo"}; // initialization for actions with program 

			Actions FirstL;
			cin >> FirstL.Command;

			if (FirstL.Command == ArrMan[0]) {

			}
			else if (FirstL.Command == ArrMan[1]) {

			}
			else if (FirstL.Command == ArrMan[2]) {

			}

			if (Stat.Writed == true) {
				break;
			}
		}
	}
}