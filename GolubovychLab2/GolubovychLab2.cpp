// GolubovychLab2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Manager.h"
#include "Project.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Manager staticMananger;
	Manager* dynamicManager = new Manager(
		"Iван",
		"Iванов",
		"Iванович",
		30,
		8000
	);

	staticMananger.startProject();
	staticMananger.saveToFile();

	Manager* managerFromFile = Manager::readFromFile();


	int project_count = managerFromFile->projects.size();

	cout << managerFromFile->getFullName() << ": " << project_count << " проектiв" << endl;

	Project* firstProject = managerFromFile->projects[0];


	firstProject->info();
	firstProject->randomNumbers();

	system("pause");

    return 0;
}

