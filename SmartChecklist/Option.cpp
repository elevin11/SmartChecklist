#include "pch.h"
#include "Option.h"


Option::Option()
{
}

Option::Option(string opName_in, Step * next_in, Part * part_in, int condCode_in)
{
	opName = opName_in;
	nextStep = next_in;
	partToUpdate = part_in;
	conditionCode = condCode_in;
}

void Option::update_part()
{
	partToUpdate->set_condition(conditionCode);
}

void Option::do_next()
{
	nextStep->do_step();
}

Step * Option::get_next()
{
	return nextStep;
}

string Option::get_op_name()
{
	return opName;
}


Option::~Option()
{
}
