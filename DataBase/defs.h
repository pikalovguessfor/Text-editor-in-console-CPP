#pragma once
#include "includes.h"

string GenName(string Name) {
	srand(time(0));

	string Fi = " ";
	string Se = " ";
	string Th = " ";
	string Fo = " ";
	string Fv = " ";

	string Grab[] = { "abc" , "bcd", "yui", "iop", "qwe" };

	int Fi_op = rand() % 20;
	int Se_op = rand() % 20;
	int Th_op = rand() % 20;
	int Fo_op = rand() % 20;
	int FV_op = rand() % 20;

	if (Fi_op < 10) {
		Fi = Grab[0];
	}
	else if (Fi_op > 10) {
		Fi = Grab[1];
	}
	else if (Fi_op == 10) {
		Fi = Grab[2];
	}

	if (Se_op < 10) {
		Se = Grab[3];
	}
	else if (Se_op > 10) {
		Se = Grab[4];
	}
	else if (Se_op == 10) {
		Se = Grab[0];
	}

	Name = (Fi + Se + Th + Fo + Fv);

	return Name;
}