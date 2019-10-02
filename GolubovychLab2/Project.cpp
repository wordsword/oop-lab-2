#include "stdafx.h"
#include "Project.h"
#include "Manager.h"


#include <chrono>
#include <ctime>    



Project::Project(Manager* manager, string customer):allocated_days(0), budget(0) {
	this->customer = customer;
	this->manager = manager;
	this->input();

	manager->projects.push_back(this);
}

Manager* Project::getManager() {
	return this->manager;
}

string Project::getTitle() {
	return this->title;
}

string Project::getStartDate() {
	return this->start_date;
}

void Project::setBudget(double budget) {
	this->budget = budget;
}
double Project::getBudget() {
	return this->budget;
}

string Project::getCustomer() {
	return this->customer;
}

void Project::setAllocatedDays(int allocated_days) {
	this->allocated_days = allocated_days;
}
int Project::getAllocatedDays() {
	return this->allocated_days;
}

string Project::getDeadline() {
	return this->deadline;
}

void Project::input() {
	cout << "Введiть назву проекту: ";
	cin >> this->title;

	time_t t = time(0);
	tm* now = localtime(&t);
	this->start_date = to_string(now->tm_mday) + "." + to_string(now->tm_mon + 1) + "." + to_string(now->tm_year + 1900);
	
	cout << "Введiть зарезервовану кiлькiсть днiв: ";
	cin >> this->allocated_days;

	t += (this->allocated_days * 60 * 60 * 24);
	now = localtime(&t);

	this->deadline = to_string(now->tm_mday) + '.' + to_string(now->tm_mon + 1) + '.' + to_string(now->tm_year + 1900);

	cout << "Введiть опис проекту: ";
	cin >> this->specification;
}

void Project::info() {
	cout << "Проект \"" << this->title << "\": " << endl;
	cout << "\tЗамовник: " << this->customer << endl;
	cout << "\tМенеджер: " << this->manager->getName() << endl;
	cout << "\tБюджет: " << this->budget << endl;
	cout << "\tДата початку: " << this->start_date << endl;
	cout << "\tЗапланована дата кiнця: " << this->deadline << endl;
}

void Project::randomNumbers() {
	srand(time(0));

	int n = 1 + rand() % 15;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = 1 + rand() % 100;
	}
	cout << "Випадковi числа: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}