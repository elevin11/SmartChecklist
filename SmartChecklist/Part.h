#pragma once
#ifndef PART_H
#define PART_H
#include <string>
using namespace std;

class Part
{
public:
	Part();
	Part(string partName_in, int partID_in);
	~Part();
private:
	string partName;
	int partID;
};

#endif
