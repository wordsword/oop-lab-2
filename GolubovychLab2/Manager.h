#pragma once
#include <string>


class Project;
class  Manager
{
private:
	string name;
	string surname;
	string patronimic_name;

	double salary;


public:
	string getName();
	Project* startProject();

};
