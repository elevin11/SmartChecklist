#pragma once
#ifndef PART_H
#define PART_H
#include <string>
#include <vector>
using namespace std;

class Part
{
public:
	Part();
	Part(string partName_in, int partID_in, vector<string> conditions_in);
	void set_condition(int cond_in);
	string get_condition();
	string get_part_name();
	int get_part_id();
	~Part();
private:
	string partName;
	int partID;
	vector<string> possibleConditions;
	int currentCondition;
};



#endif
