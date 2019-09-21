#pragma once
#ifndef STEP_H
#define STEP_H

#include <iostream>
#include <string>
#include <vector>
#include "Part.h"
using namespace std;
class Step
{
public:
	Step();
	Step(string stepName_in, string instruct_in, Part &part_in);
	~Step();
	string get_name();
	void display();
	int get_input();
	int get_num_ops();
	void add_op(string option_in, Step * next_in);

	void suggestions(); // this is tricky part - based on relevantPart, FlightData(maybe?). 
private:
	string stepName;
	string instructions;
	Part * relevantPart;
	vector<string> options;
	vector<Step *> nextSteps;
	bool completed; 
	int userChoice;
};

#endif
