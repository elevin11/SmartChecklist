#include "pch.h"
#include "Part.h"


Part::Part()
{
}

Part::Part(string partName_in, int partID_in, vector<string> conditions_in)
{
	partName = partName_in;
	partID = partID_in;
	possibleConditions = conditions_in;
}

void Part::set_condition(int cond_in)
{
	currentCondition = cond_in;
}

string Part::get_condition()
{
	return possibleConditions[currentCondition];
}

string Part::get_part_name()
{
	return partName;
}

int Part::get_part_id()
{
	return partID;
}


Part::~Part()
{
}
