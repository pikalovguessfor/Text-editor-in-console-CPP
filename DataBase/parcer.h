//----------------------------------------------------------PARSER Class--------------------------------------------------------------\\

#pragma once

#include "includes.h"

const int ARRHalfCount = 2000;

namespace parcer {

	const char arrSymbolsSpec[5] = { '#', '@', '&', '-', '>' };

	void ParseFile(char arrSym[2000]) {

		bool start_pars = true;


		if (start_pars) {

			for (int i = 0; i <= ARRHalfCount; i++) {

				if (arrSym[i] == arrSymbolsSpec[0] or arrSym[i] == arrSymbolsSpec[1] or arrSym[i] == arrSymbolsSpec[2] or arrSym[i] == arrSymbolsSpec[3] or arrSym[i] == arrSymbolsSpec[4]) {

					short SubSymCont = - 10;

					char subArr[10];

					for (int j = 0; j < 10; j++) {
						
						char Symbol = arrSym[i + (SubSymCont)];
						subArr[j] = Symbol;
						SubSymCont++;

						cout << subArr[j];

					}

				}
			}
		}
		else {
			cout << endl << endl << "Something went wrong with a parcer" << endl << endl;
		}

		return;
	}


}