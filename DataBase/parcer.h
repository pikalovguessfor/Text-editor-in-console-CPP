//----------------------------------------------------------PARSER Class--------------------------------------------------------------\\

#pragma once

#include "includes.h"

namespace parcer {

	const char arrSymbolsSpec[5] = { '#', '@', '&', '-', '>' };

	void ParseFile(char arrSym[2000]) {

		bool start_pars = true;


		if (start_pars) {

			if (_isThisDataForm(arrSym)) {
				cout << endl << endl << "Correct 'data_find' format" << endl << endl;
			}
			else if (!_isThisDataForm(arrSym)) {
				cout << endl << endl << "data format recommend to begin from special symbol" << endl << endl;
			}

			for (int i = 0; i <= 1999; i++) {

				if (arrSym[i] == arrSymbolsSpec[0] or arrSym[i] == arrSymbolsSpec[1] or arrSym[i] == arrSymbolsSpec[2] or arrSym[i] == arrSymbolsSpec[3] or arrSym[i] == arrSymbolsSpec[4]) {

					cout << endl << arrSym[i - 10] << arrSym[i - 9] << arrSym[i - 8] << arrSym[i - 7] << arrSym[i - 6] << arrSym[i - 5] << arrSym[i - 4] << arrSym[i - 3] << arrSym[i - 2] << arrSym[i - 1] << arrSym[i] << endl;

				}
			}
		}
		else {
			cout << endl << endl << "Something went wrong with a parcer" << endl << endl;
		}

		return;
	}



	// method to see 'is this correct'

	bool _isThisDataForm(char arrSym[2000]) {

		for (int i = 0; i <= 5; i++) {

			if (arrSym[0] == arrSymbolsSpec[i]) {


				return true;
			}

		}

		return false;
	}

}