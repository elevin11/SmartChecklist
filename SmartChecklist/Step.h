#pragma once
#ifndef STEP_H
#define STEP_H

#include <iostream>
#include <string>
#include <vector>
#include "Part.h"
#include "Option.h"
using namespace std;

class Option;

class Step
{
public:
	Step();
	Step(string stepName_in, string instruct_in, Part &part_in);	//construct Step with given name, instructions, and relevant parts being worked on
	~Step();
	string get_name();
	void display();
	int get_input();
	int get_num_ops();
	void add_op(string option_in, Step * next_in, int condCode_in);	//add an option for what do in that step
	void do_step();	//display instructions, offer options, and get user input to selct an option.
	void update_condition(int condition_in);
	void suggestions(); // this is tricky part - based on relevantPart, FlightData(maybe?). 
private:
	string stepName;
	string instructions;
	Part * relevantPart;
	vector<Option *> options;
	bool completed; 
	int userChoice;
};

#endif
