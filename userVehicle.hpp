#pragma once
#include<iostream>
#include"user.hpp"
using namespace std;

class Vehicle :public User {
public:
	Vehicle(string platenum = "", string model = "", string color = "", string year = "");
	void userAttach(User user); //���û�

	string getPlateNum();
	string getModel();
	string getColor();
	string getYear();

	void setPlateNum(string platenum);
	void setModel(string model);
	void setColor(string color);
	void setYear(string year);
private:
	string PlateNum; //���ƺ�
	string Model; //����
	string Color; //��ɫ
	string Year; //���
};

void Vehicle::userAttach(User user) {
	this->setAccount(user.getAccount());
	this->setName(user.getName());
	this->setPassword(user.getPassword());
	this->setPermission(user.getPermission());
}

Vehicle::Vehicle(string platenum, string model, string color, string year) {
	this->PlateNum = platenum;
	this->Model = model;
	this->Color = color;
	this->Year = year;
}

string Vehicle::getPlateNum() { return this->PlateNum; }
string Vehicle::getModel() { return this->Model; }
string Vehicle::getColor() { return this->Color; }
string Vehicle::getYear() { return this->Year; }

void Vehicle::setPlateNum(string platenum) { this->PlateNum = platenum; }
void Vehicle::setModel(string model) { this->Model = model; }
void Vehicle::setColor(string color) { this->Color = color; }
void Vehicle::setYear(string year) { this->Year = year; }

