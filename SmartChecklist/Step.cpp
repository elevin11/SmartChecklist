#include "pch.h"
#include "Step.h"


Step::Step()
{
	completed = false;
}

Step::Step(string stepName_in, string instruct_in, Part &part_in)
{
	stepName = stepName_in;
	instructions = instruct_in;
	relevantPart = &part_in;
	completed = false;
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
		cout << i << ". " << options[i]->get_op_name() << endl;
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

void Step::add_op(string option_in, Step * next_in, int condCode_in)
{
	Option * newOp = new Option(option_in, next_in, relevantPart, condCode_in); 
	options.push_back(newOp);
}

void Step::do_step()
{
	display();
	int userInput;
	cin >> userInput;
	while (userInput < 0 || userInput > get_num_ops())
	{
		cout << "Please select one of the given options" << endl;
		cin >> userInput;
	}
	options[userInput]->update_part();
	if (options[userInput]->get_next() != nullptr)
	{
		options[userInput]->do_next();
	}
	


}

void Step::update_condition(int condition_in)
{
	relevantPart->set_condition(condition_in);
}

