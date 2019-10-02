#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class Project;
class  Manager
{
private:
	string name;
	string surname;
	string patronimic_name;

	int age;
	double salary;

	void input();

public:
	
	string organization;
	vector<Project*> projects;
	
	Manager();
	
	Manager(string name, string surname, string patronimic_name, int age, double salary);


	string getName();
	string getSurname();
	string getPatronimicName();

	string getFullName();

	int getAge();

	int getSalary();

	void setOrganization(string title);

	Project* startProject();



	void saveToFile() {
		fstream file;

		file.open("manager.txt", ios::out);
		file.write((char*)this, sizeof(Manager));
		file.close();
	}

	static Manager* readFromFile() {
		Manager* manager = new Manager("", "", "", 0, 0);
		fstream file;

		file.open("manager.txt", ios::in);

		file.read((char*)manager, sizeof(Manager));

		return manager;
	}
};
