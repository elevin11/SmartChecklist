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
	~Checklist();
private:
	Step * start;
	Record results;
	vector<Part> partsLookedAt;
	vector<FlightData> flights;
};

