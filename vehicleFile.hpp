#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"userVehicle.hpp"

class VehicleOp :public Vehicle {
public:
	VehicleOp() {};
	VehicleOp(Vehicle vehicle);
	int vehicleStore(); //车辆信息保存
	void getVehicle(); //绑定车辆信息
	void update(string platenum, string model, string color, string year); //更新车辆信息
	void getList(); //获取全部车辆信息
	void keyInformationQueries(string platenum, string model, string color, string year); //关键信息查询
	void addVehicle(string platenum, string model, string color, string year); //添加车辆
	void deleteVehicle(string platenum); //删除车辆
	void modifyVehicle(string modifyPlatenum, string platenum,
		string model, string color, string year); //根据车牌号修改车辆信息
};

VehicleOp::VehicleOp(Vehicle vehicle) {
	this->setAccount(vehicle.getAccount());
	this->setName(vehicle.getName());
	this->setPassword(vehicle.getPassword());
	this->setPermission(vehicle.getPermission());
	this->setPlateNum(vehicle.getPlateNum());
	this->setModel(vehicle.getModel());
	this->setColor(vehicle.getColor());
	this->setYear(vehicle.getYear());
}

int VehicleOp::vehicleStore() {
	ifstream fin("Vehicle.txt", ios_base::in);
	string curacc, curnum, line;
	fin.seekg(0, ios_base::beg);
	while (!fin.eof()) {
		fin >> curacc >> curnum;
		getline(fin, line);
		if (this->getAccount() == curacc &&
			this->getPlateNum() != "未录入") {
			cout << "车辆信息已被录入！" << endl;
			return -1;
		}
	}
	fin.close();
	ofstream fout("Vehicle.txt", ios_base::app);
	fout << endl;
	fout << this->getAccount() << " "
		<< this->getPlateNum() << " "
		<< this->getModel() << " "
		<< this->getColor() << " "
		<< this->getYear() << " " << endl;
	if (this->getPlateNum() != "未录入")
		cout << "车辆信息录入成功！" << endl;
	fout.close();
	return 1;
}

void VehicleOp::getVehicle() {
	ifstream fin("Vehicle.txt", ios_base::in);
	string curacc, line;
	fin.seekg(0, ios_base::beg);
	while (!fin.eof()) {
		fin >> curacc;
		if (this->getAccount() == curacc) {
			string curnum, curmodel, curcolor, curyear;
			fin >> curnum >> curmodel >> curcolor >> curyear;
			this->setAccount(curacc);
			this->setPlateNum(curnum);
			this->setModel(curmodel);
			this->setColor(curcolor);
			this->setYear(curyear);
			fin.close();
			break;
		}
		else {
			getline(fin, line);
			this->setPlateNum("未录入");
			this->setModel("未录入");
			this->setColor("未录入");
			this->setYear("未录入");
		}
	}
}

void VehicleOp::update(string platenum, string model, string color, string year) {
	ifstream fin("Vehicle.txt", ios::in);
	fin.seekg(0, ios_base::beg);
	string curacc, line;
	string fileContents = "";
	string oriContents[4];
	string curContents[4] = { platenum,model,color,year };
	string flag = "\\";
	while (!fin.eof()) {
		fin >> curacc;
		if (this->getAccount() != curacc) {
			getline(fin, line);
			fileContents += curacc;
			fileContents += line;
			fileContents += "\n";
		}
		else if (this->getAccount() == curacc) {
			for (int i = 0; i < 4; ++i)
				fin >> oriContents[i];
			getline(fin, line);
		}
	}
	ofstream fout("Vehicle.txt", ios_base::out);
	fout.flush();
	fout << fileContents;
	fout << this->getAccount() << " ";
	for (int i = 0; i < 4; ++i) {
		if (curContents[i] != flag)
			fout << curContents[i] << ' ';
		else
			fout << oriContents[i] << ' ';
	}
	fout.close();
}

void VehicleOp::getList() {
	string line;
	ifstream fin("Vehicle.txt", ios::in | ios::ate);
	fin.seekg(0, ios_base::beg);
	string curacc, curnum, curmodel, curcolor, curyear;
	cout << left << setw(15) << "车牌号";
	cout << left << setw(15) << "车型";
	cout << left << setw(15) << "颜色";
	cout << left << setw(15) << "年份" << endl;
	fin >> curacc >> curnum >> curmodel >> curcolor >> curyear;
	while (!fin.eof()) {
		cout << left << setw(15) << curnum;
		cout << left << setw(15) << curmodel;
		cout << left << setw(15) << curcolor;
		cout << left << setw(15) << curyear << endl;
		fin >> curacc >> curnum >> curmodel >> curcolor >> curyear;
	}
	fin.close();
}

void VehicleOp::keyInformationQueries(string platenum, string model, string color, string year) {
	string line;
	ifstream fin("Vehicle.txt", ios::in | ios::ate);
	fin.seekg(0, ios_base::beg);
	string curacc, curnum, curmodel, curcolor, curyear;
	cout << "----------------------------查询结果---------------------------" << endl;
	this->getPermission() ?
		cout << left << setw(15) << "车辆所属用户" : cout << "";
	cout << left << setw(15) << "车牌号";
	cout << left << setw(15) << "车型";
	cout << left << setw(15) << "颜色";
	cout << left << setw(15) << "年份" << endl;
	fin >> curacc >> curnum >> curmodel >> curcolor >> curyear;
	while (!fin.eof()) {
		if (platenum == curnum || model == curmodel || color == curcolor || year == curyear) {
			this->getPermission() ?
				cout << left << setw(15) << curacc : cout << "";
			cout << left << setw(15) << curnum;
			cout << left << setw(15) << curmodel;
			cout << left << setw(15) << curcolor;
			cout << left << setw(15) << curyear << endl;
		}
		fin >> curacc >> curnum >> curmodel >> curcolor >> curyear;
	}
	cout << "\n\n\n" << endl;
	cout << "---------------------------------------------------------------" << endl;
	fin.close();
}

void VehicleOp::addVehicle(string platenum, string model, string color, string year) {
	ofstream fout("Vehicle.txt", ios_base::app);
	fout << endl;
	fout << "无" << " " << platenum << " " << model << " " << color << " " << year << " " << endl;
	cout << "车辆信息录入成功！" << endl;
	fout.close();
}

void VehicleOp::deleteVehicle(string platenum) {
	ifstream fin("Vehicle.txt", ios::in);
	fin.seekg(0, ios_base::beg);
	string curacc, curnum, line;
	string fileContents = "";
	fin >> curacc >> curnum;
	while (!fin.eof()) {
		if (curnum != platenum) {
			getline(fin, line);
			fileContents += curacc;
			fileContents += " ";
			fileContents += curnum;
			fileContents += line;
			fileContents += "\n";
		}
		else if (curnum == platenum)
			getline(fin, line);
		fin >> curacc >> curnum;
	}
	ofstream fout("Vehicle.txt", ios_base::out);
	fout.flush();
	fout << fileContents;
	cout << "删除成功！\n" << endl;
	fout.close();
}

void VehicleOp::modifyVehicle(string modifyPlatenum, string platenum,
	string model, string color, string year) {
	ifstream fin("Vehicle.txt", ios::in);
	fin.seekg(0, ios_base::beg);
	string curacc, curnum, line;
	string modifyAccount;
	string fileContents = "";
	fin >> curacc >> curnum;
	while (!fin.eof()) {
		if (curnum != modifyPlatenum) {
			getline(fin, line);
			fileContents += curacc;
			fileContents += " ";
			fileContents += curnum;
			fileContents += line;
			fileContents += "\n";
		}
		else if (curnum == modifyPlatenum) {
			getline(fin, line);
			modifyAccount = curacc;
		}
		fin >> curacc >> curnum;
	}
	ofstream fout("Vehicle.txt", ios_base::out);
	fout.flush();
	fout << modifyAccount << ' '
		<< platenum << ' '
		<< model << ' '
		<< color << ' '
		<< year << endl;
	fout << fileContents;
	cout << "修改成功！\n" << endl;
	fout.close();
}


