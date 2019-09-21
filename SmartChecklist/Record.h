#pragma once
#include<string>
#include<vector>
#include "Part.h"
#include "Step.h"
using namespace std;

class Record
{
public:
	Record();
	~Record();
private:
	vector<Part *> partsRecorded;
	vector<Step *> stepsRecorded;
};

