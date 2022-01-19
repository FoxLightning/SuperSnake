#pragma once

class ControlledObject
{
	char input;
public:
	ControlledObject();
	~ControlledObject();

	char get_input_m();
	void set_input_m(char);
};

