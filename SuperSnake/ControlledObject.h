#pragma once

class ControlledObject

{
	/*
	* This is a mixin whose purpose is to add a method
	* to receive input from the console 
	*/
	char input;
public:
	ControlledObject();
	~ControlledObject();

	char get_input_console();
	void set_input_console(char);
};

