#include <iostream>
#include <string>
#include <vector>
#include "FlightData.h"
#include "Part.h"
#include "Record.h"
#include "Step.h"
using namespace std;

#pragma once
class Checklist
{
public:
	Checklist();
	Checklist(Step * start_in);
	~Checklist();
	void begin();
	void show_conditions();
	
	
	void add_part(Part * part_in);
private:
	Step * start;
	Record results;
	vector<Part *> partsLookedAt;
//	vector<FlightData> flights;
};

