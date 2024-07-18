#pragma once

#include "includes.h"

class Parcer {

public:

	const char arrSymbolsSpec[5] = { '#', '@', '&', '-', '>' };
		
	int ParseFile(char arrSym[2000]) {

		bool operation_stop = false;


		if (true) {

			for (int i = 0; i <= 1999; i++) {
				
				if (arrSym[i] == arrSymbolsSpec[0] or arrSym[i] == arrSymbolsSpec[1] or arrSym[i] == arrSymbolsSpec[2] or arrSym[i] == arrSymbolsSpec[3] or arrSym[i] == arrSymbolsSpec[4]) {

					cout << endl << arrSym[i - 10] << arrSym[ i - 9] << arrSym[i - 8] << arrSym[i - 7] << arrSym[i - 6] << arrSym [i - 5] << arrSym[i - 4] << arrSym[i - 3] << arrSym[i - 2] << arrSym[i - 1] << arrSym[i] << endl;

				}
			}
		}

		return 0;
		
	}

private:

	bool _findSymTxt(char arrSym[2000]) {
		
		for (int i = 0; i <= 1999; i++) {

			if (arrSym[i] == arrSymbolsSpec[i]) {
				return true;
			}

			else {
				return false;
			}

		}

	}

};
