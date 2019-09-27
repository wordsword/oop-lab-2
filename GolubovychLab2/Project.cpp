#include "stdafx.h"
#include "Project.h"
#include "Manager.h"


#include <chrono>
#include <ctime>    


Project::Project(Manager* manager, string customer) {
	this->customer = customer;
	this->manager = manager;
	this->input();
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
	cout << "����i�� ����� �������: ";
	cin >> this->title;

	time_t t = time(0);
	tm* now = localtime(&t);
	this->start_date = now->tm_mday + '.' + (now->tm_mon + 1) + '.' + (now->tm_year + 1900);
	
	cout << "����i�� ������������� �i���i��� ��i�: ";
	cin >> this->allocated_days;

	t += this->allocated_days * 60 * 60 * 24;
	now = localtime(&t);

	this->deadline = now->tm_mday + '.' + (now->tm_mon + 1) + '.' + (now->tm_year + 1900);

	cout << "����i�� ���� �������: ";
	cin >> this->specification;
}

void Project::info() {
	cout << "������ \"" << this->title << "\": " << endl;
	cout << "\t��������: " << this->customer << endl;
	cout << "\t����������: " << this->executer << endl;
	cout << "\t��������: " << this->manager->getName() << endl;
	cout << "\t������: " << this->budget << endl;
	cout << "\t���� �������: " << this->start_date << endl;
	cout << "\t����������� ���� ����: " << this->deadline << endl;
}