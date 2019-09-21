// SmartChecklist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>

#include "Checklist.h"
//#include "Part.h"
#include "Step.h"
using namespace std;

int main()
{
	//define example parts
	vector<string> ex_cond;
	ex_cond.push_back("GOOD"); //conditionCode = 0
	ex_cond.push_back("DIRTY"); //conditionCode = 1
	ex_cond.push_back("BROKEN"); //conditionCode = 2
	Part leftFil("Left Filange", 123, ex_cond);
	Part rightFil("Right Filange", 321, ex_cond);
	
	//define example steps
	Step * checkLeft = new Step("Check Left Filange", "Take out left filange and look at it. What condition is it in?", leftFil);
	Step * cleanFil = new Step("Clean Filange", "Get a damp rag and wipe the gunk off it", leftFil);
	Step * replaceFil = new Step("Replace Filange", "Remove filange and put a new one in", leftFil);
	Step * checkRight = new Step("Check Right Filange", "Take out right filange and look at it. What condition is it in?", rightFil);

	checkLeft->add_op("Filange in good condition", checkRight, 0);
	checkLeft->add_op("Filange is dirty", cleanFil, 1);
	checkLeft->add_op("Filange is broken", replaceFil, 2);

	cleanFil->add_op("Filange cleaned", nullptr, 0);
	cleanFil->add_op("No action taken", nullptr, 1);

	replaceFil->add_op("Filange replaced", nullptr, 0);
	replaceFil->add_op("No action taken", nullptr, 2);

	checkRight->add_op("Filange in good condition", nullptr, 0);
	checkRight->add_op("Filange is dirty", nullptr, 1);
	checkRight->add_op("Filange is broken", nullptr, 2);

	//define example checklist
	Checklist check(checkLeft);
	check.add_part(&leftFil);
	check.add_part(&rightFil);

	check.begin();
	check.show_conditions();


}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
