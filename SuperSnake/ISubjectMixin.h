#pragma once

class ISubjectMixin
{
	char input;
public:
	ISubjectMixin();
	~ISubjectMixin();

	char get_input_m();
	void set_input_m(char);
};

