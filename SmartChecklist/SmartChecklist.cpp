// SmartChecklist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>

//#include "Part.h"
#include "Step.h"
using namespace std;

int main()
{
	//create example step
	Part leftFil("Left Filange", 123);
	Part rightFil("Right Filange", 321);
	string ex_name = "Check Left Filange";
	string ex_instruct = "Take out left filange and look at it. What condition is it in?";
	Step example(ex_name, ex_instruct, leftFil);
	
	//next steps for example
	Step * next1 = new Step("Clean Filange", "take out a damp rag and wipe the gunk off it", leftFil);
	Step * next2 = new Step("Replace Filange", "remove filange and put a new one in", leftFil);
	Step * next3 = new Step("Check Right Filange", "Take out right filange and look at it. What condition is it in?", rightFil);
	example.add_op("Filange is dirty", next1);
	example.add_op("Filange is broken", next2);
	example.add_op("Filange in good condition", next3);

	example.do_step();

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
