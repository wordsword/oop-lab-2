#include "stdafx.h"
#include "Project.h"
#include "Manager.h"
#include <fstream>


#include <chrono>
#include <ctime>    

void Manager::input() {

	cout << "����i�� �����i���i�: ";
	cin >> this->organization;

	cout << "����i�� i�'�: ";
	cin >> this->name;

	cout << "����i�� ���i�i�: ";
	cin >> this->surname;

	cout << "����i�� ��-�������i: ";
	cin >> this->patronimic_name;

	cout << "����i�� �i�: ";
	cin >> this->age;

	cout << "����i�� �/�: ";
	cin >> this->salary;
}

string Manager::getName() {
	return this->name;
}


string Manager::getSurname() {
	return this->surname;
}


string Manager::getPatronimicName() {
	return this->patronimic_name;
}

string Manager::getFullName() {
	return this->surname + " " + this->name + " " + this->patronimic_name;
}

int Manager::getAge() {
	return this->age;
}

int Manager::getSalary() {
	return this->salary;
}

void Manager::setOrganization(string title) {
	this->organization = title;
}

Project* Manager::startProject() {
	string customer;

	cout << "����i�� i�'� ���������: ";
	cin >> customer;

	Project* project = new Project(this, customer);

	return project;
}

Manager::Manager(string name, string surname, string patronimic_name, int age, double salary) {
	this->name = name;
	this->surname = surname;
	this->patronimic_name = patronimic_name;
	this->age = age;
	this->salary = salary;
}

Manager::Manager():name(""),surname(""),patronimic_name(""),age(0),salary(0) {
	this->input();
}