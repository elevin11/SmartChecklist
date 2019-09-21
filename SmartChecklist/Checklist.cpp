#include "pch.h"
#include "Checklist.h"


Checklist::Checklist()
{
}

Checklist::Checklist(Step * start_in)
{
	start = start_in;
}


Checklist::~Checklist()
{
}

void Checklist::begin()
{
	start->do_step();
}

void Checklist::show_conditions()
{
	for (unsigned int i = 0; i < partsLookedAt.size(); ++i)
	{
		cout << "PART: " << partsLookedAt[i]->get_part_name() << endl << "ID #: "<< partsLookedAt[i]->get_part_id() << endl << "CONDITION: " << partsLookedAt[i]->get_condition() << endl << endl;
	}
}

void Checklist::add_part(Part * part_in)
{
	partsLookedAt.push_back(part_in);
}
