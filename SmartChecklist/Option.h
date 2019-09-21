#ifndef OPTION_H
#define OPTION_H

#include <string>
#include "Step.h"
using namespace std;
class Step;

#pragma once
class Option
{
public:
	Option();
	Option(string opName_in, Step * next_in, Part * part_in, int condCode_in);
	void update_part();
	void do_next();
	Step * get_next();
	string get_op_name();
	~Option();
private:
	string opName;
	Step * nextStep;
	Part * partToUpdate;
	int conditionCode;
};

#endif

