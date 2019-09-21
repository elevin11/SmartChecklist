#include "pch.h"
#include "Step.h"


Step::Step()
{
}

Step::Step(string stepName_in, string instruct_in, Part &part_in)
{
	stepName = stepName_in;
	instructions = instruct_in;
	relevantPart = &part_in;
}


Step::~Step()
{
}

string Step::get_name()
{
	return stepName;
}

void Step::display()
{
	cout << "STEP: " << stepName << endl;
	cout << "INSTRUCTIONS: " << instructions << endl;
	for (unsigned int i = 0; i < options.size(); ++i)
	{
		cout << i << ". " << options[i] << endl;
	}
}

int Step::get_input()
{
	int choice = 0;
	cin >> choice;
	return choice;
}

int Step::get_num_ops()
{
	return options.size();
}

void Step::add_op(string option_in, Step * next_in)
{
	options.push_back(option_in);
	nextSteps.push_back(next_in);
}

void Step::do_step()
{
	display();

	int userInput = 0;
	while (true)
	{
		userInput = get_input();
		if (userInput >= 0 && userInput < get_num_ops())
		{
			nextSteps[userInput]->do_step();
		}
		else
		{
			cout << "Please select one of the given options" << endl;
		}
	}
}

