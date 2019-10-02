#pragma once
#include <string>
#include <iostream>

using namespace std;

class Manager;
class Project
{
private:
	string title;
	string start_date;
	double budget;
	string customer;
	int allocated_days;
	string deadline;

	Manager *manager;

public:
	string specification;

	Project(Manager* manager, string customer);

	string getTitle();

	string getStartDate();

	string getDeadline();

	void setBudget(double budget);
	double getBudget();

	string getCustomer();

	void setAllocatedDays(int allocated_days);
	int getAllocatedDays();

	Manager* getManager();

	void input();
	void info();


	static void randomNumbers();
};

