#pragma once
#include<iostream>
#include"userFile.hpp"
#include"vehicleFile.hpp"
using namespace std;

class UI {
private:
	void Start();						    //开始界面
	void Login();							//登录
	void Register();						//注册
	void Menu(User user);				    //普通用户菜单
	void AdmiMenu(User user);			    //管理员菜单
	void Personal(User user);               //个人信息查询
	void Cars(User user);                   //车辆信息查询
	void Escalate(User user);               //升级权限
	void Modify(User user);                 //车辆信息管理（管理员）
	void ModifyUsername(User user);         //修改用户名
	void ModifyPassword(User user);         //修改密码
	void ModifyPersonalVehicle(User user);  //修改个人车辆信息
	void AddVehicle(User user);             //增加车辆
	void DeleteVehicle(User user);          //删除车辆
	void ModifyVehicle(User user);          //修改车辆信息
public:
	int choice;
	void run(); //打开UI界面
};

void UI::Start() {
	cout << "******************车辆管理系统*****************\n" << endl;
	cout << "1.注册账号\n" << endl;
	cout << "2.登录账号\n" << endl;
	cout << "0.退出\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "******************车辆管理系统*****************\n" << endl;
	cout << "请输入你的选择: ";
	cin >> choice;
	if (cin.good()) {
		switch (choice) {
		case 1:
			this->Register();
			break;
		case 2:
			this->Login();
			break;
		case 0:
			exit(0);
			break;
		default:
			choice = -1;
			cout << "输入不符合规范，请重新输入！\n" << endl;
			this->Start();
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "输入不符合规范，请重新输入！\n" << endl;
		this->Start();
	}
}

void UI::Login() {
	string account;
	string password;
	cout << "******************车辆管理系统登录*****************\n" << endl;
	cout << "请输入您的账号与密码：\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "******************车辆管理系统登录*****************\n" << endl;
	cout << "账号：";
	cin >> account;
	cout << "密码：";
	cin >> password;
	User user("默认用户名", password, account, 0);
	UserOp userOp(user);
	switch (userOp.userQuery())
	{
	case 1: {
		cout << "登陆成功！\n" << endl;
		userOp.getUser();
		if (userOp.getPermission() == 0) {
			this->Menu(userOp);
			break;
		}
		else if (userOp.getPermission() == 1) {
			this->AdmiMenu(userOp);
			break;
		}
	}
	case 0: {
		cout << "密码错误！\n" << endl;
		this->Start();
		break;
	}
	case -1: {
		cout << "用户不存在！\n" << endl;
		this->Start();
		break;
	}
	}
}

void UI::Register() {
	string account;
	string password1;
	string password2;
	cout << "******************车辆管理系统注册*****************\n" << endl;
	cout << "请输入您的账号与密码：\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "******************车辆管理系统注册*****************\n" << endl;
	cout << "账号：";
	cin >> account;
	cout << "密码：";
	cin >> password1;
	cout << "重新输入密码：";
	cin >> password2;
	if (password1 != password2) {
		cout << "密码不一致！请重新输入。\n" << endl;
		this->Start();
	}
	else {
		User newUser("默认用户名", password1, account, 0);           //建立新用户
		UserOp newUserOp(newUser);
		if (newUserOp.userStore() == 1) {                              //录入用户信息
			Vehicle vehicle("未录入", "未录入", "未录入", "未录入"); //建立新用户初始车辆信息
			vehicle.userAttach(newUser);                             //绑定用户
			VehicleOp vehicleOp(vehicle);
			vehicleOp.vehicleStore();                                //录入车辆信息
		}
		this->Start();
	}
}

void UI::Menu(User user) {
	cout << "****************" << "你好，" << user.getName() << "****************\n" << endl;
	cout << "1.个人信息查询\n" << endl;
	cout << "2.车辆信息查询\n" << endl;
	cout << "3.升级管理员\n" << endl;
	cout << "0.退出登录\n\n\n\n\n\n\n" << endl;
	cout << "\n\n\n\n\n\n\n\n" << endl;
	cout << "*********************菜单（普通用户）*********************\n" << endl;
	cout << "请输入你的选择: ";
	cin >> choice;
	if (cin.good()) {
		switch (choice)
		{
		case 1:
			this->Personal(user);
			break;
		case 2:
			this->Cars(user);
			break;
		case 3:
			this->Escalate(user);
			break;
		case 0:
			this->Start();
			break;
		default:
			choice = -1;
			cout << "输入不符合规范，请重新输入！\n" << endl;
			this->Menu(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "输入不符合规范，请重新输入！\n" << endl;
		this->Menu(user);
	}
}

void UI::AdmiMenu(User user) {
	cout << "******************" << "你好，" << user.getName() << "******************\n" << endl;
	cout << "1.个人信息查询\n" << endl;
	cout << "2.车辆信息查询\n" << endl;
	cout << "3.车辆管理\n" << endl;
	cout << "0.退出登录\n\n\n\n\n\n\n" << endl;
	cout << "\n\n\n\n\n\n\n\n" << endl;
	cout << "*********************菜单（管理员）*********************\n" << endl;
	cout << "请输入你的选择: ";
	cin >> choice;
	if (cin.good()) {
		switch (choice)
		{
		case 1:
			this->Personal(user);
			break;
		case 2:
			this->Cars(user);
			break;
		case 3:
			this->Modify(user);
			break;
		case 0:
			this->Start();
			break;
		default:
			choice = -1;
			cout << "输入不符合规范，请重新输入！\n" << endl;
			this->Menu(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "输入不符合规范，请重新输入！\n" << endl;
		this->Menu(user);
	}
}

void UI::Personal(User user) {
	Vehicle vehicle("未录入", "未录入", "未录入", "未录入");
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	cout << "******************" << "你好，" << user.getName() << "******************\n" << endl;
	cout << "------------------------个人信息-----------------------" << endl;
	cout << "账号：" << vehicleOp.getAccount() << endl;
	cout << "用户名：" << vehicleOp.getName() << endl;
	cout << "----------------------个人车辆信息---------------------" << endl;
	cout << "车牌号：" << vehicleOp.getPlateNum() << endl;
	cout << "车型：" << vehicleOp.getModel() << endl;
	cout << "颜色：" << vehicleOp.getColor() << endl;
	cout << "年份：" << vehicleOp.getYear() << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "1.修改用户名" << endl;
	cout << "2.修改密码" << endl;
	cout << "3.修改个人车辆信息" << endl;
	cout << "0.返回" << endl;
	cout << "*********************个人信息查询*********************\n" << endl;
	cout << "请输入您的选择：";
	cin >> choice;
	if (cin.good()) {
		switch (choice)
		{
		case 0:
			if (user.getPermission() == 0)
				this->Menu(user);
			else
				this->AdmiMenu(user);
			break;
		case 1:
			this->ModifyUsername(user);
			break;
		case 2:
			this->ModifyPassword(user);
			break;
		case 3:
			this->ModifyPersonalVehicle(user);
			break;
		default:
			choice = -1;
			cout << "输入不符合规范，请重新输入！\n" << endl;
			this->Personal(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "输入不符合规范，请重新输入！\n" << endl;
		this->Personal(user);
	}
}

void UI::Cars(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	cout << "******************" << "你好，" << user.getName() << "******************\n" << endl;
	cout << "------------------系统内所有车辆信息-------------------" << endl;
	vehicleOp.getList();
	cout << "-------------------------------------------------------" << endl;
	cout << "1.车牌号查询车辆" << endl;
	cout << "2.车型查询车辆" << endl;
	cout << "3.年份查询车辆" << endl;
	cout << "0.返回" << endl;
	cout << "**********************车辆信息查询**********************\n" << endl;
	cout << "请输入你的选择：";
	cin >> choice;
	if (cin.good()) {
		switch (choice)
		{
		case 0:
			if (user.getPermission() == 0)
				this->Menu(user);
			else
				this->AdmiMenu(user);
			break;
		case 1: {
			string platenum;
			cout << "请输入您想查询车辆的车牌号：";
			cin >> platenum;
			vehicleOp.keyInformationQueries(platenum, "//", "//", "//");
			this->Cars(user);
			break;
		}
		case 2: {
			string model;
			cout << "请输入您想查询车辆的车型：";
			cin >> model;
			vehicleOp.keyInformationQueries("//", model, "//", "//");
			this->Cars(user);
			break;
		}
		case 3: {
			string year;
			cout << "请输入您想查询车辆的年份：";
			cin >> year;
			vehicleOp.keyInformationQueries("//", "//", "//", year);
			this->Cars(user);
			break;
		}
		default:
			choice = -1;
			cout << "输入不符合规范，请重新输入！\n" << endl;
			this->Cars(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "输入不符合规范，请重新输入！\n" << endl;
		this->Cars(user);
	}
}

void UI::Escalate(User user) {
	UserOp userOp(user);
	string key = "ADMI";
	string inputKey;
	cout << "******************" << "你好，" << user.getName() << "******************\n" << endl;
	cout << "请输入管理员秘钥：" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "**********************修改用户名**********************\n" << endl;
	cout << "请输入管理员秘钥：";
	cin >> inputKey;
	if (inputKey == key) {
		user.setPermission(1);
		userOp.update(user.getName(), user.getAccount(), user.getPassword(), user.getPermission());
		cout << "管理员升级成功！\n" << endl;
		this->AdmiMenu(user);
	}
	else {
		cout << "秘钥输入错误！" << endl;
		this->Menu(user);
	}
}

void UI::Modify(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	cout << "******************" << "你好，" << user.getName() << "******************\n" << endl;
	cout << "------------------系统内所有车辆信息-------------------" << endl;
	vehicleOp.getList();
	cout << "-------------------------------------------------------" << endl;
	cout << "1.添加车辆" << endl;
	cout << "2.删除车辆" << endl;
	cout << "3.修改车辆信息" << endl;
	cout << "0.返回" << endl;
	cout << "********************修改系统车辆信息********************\n" << endl;
	cout << "请输入您的选择：";
	cin >> choice;
	if (cin.good()) {
		switch (choice)
		{
		case 0:
			this->AdmiMenu(user);
			break;
		case 1:
			this->AddVehicle(user);
			break;
		case 2:
			this->DeleteVehicle(user);
			break;
		case 3:
			this->ModifyVehicle(user);
			break;
		default:
			choice = -1;
			cout << "输入不符合规范，请重新输入！\n" << endl;
			this->AdmiMenu(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "输入不符合规范，请重新输入！\n" << endl;
		this->Personal(user);
	}
}

void UI::ModifyUsername(User user) {
	UserOp userOp(user);
	string modifiedUsername;
	cout << "******************" << "你好，" << user.getName() << "******************\n" << endl;
	cout << "请输入修改后的用户名：" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "**********************修改用户名**********************\n" << endl;
	cout << "请输入修改后的用户名：";
	cin >> modifiedUsername;
	user.setName(modifiedUsername);
	userOp.update(user.getName(), user.getAccount(), user.getPassword(), user.getPermission());
	cout << "修改成功！\n" << endl;
	this->Personal(user);
}

void UI::ModifyPassword(User user) {
	UserOp userOp(user);
	string password, modifiedPassword;
	cout << "******************" << "你好，" << user.getName() << "******************\n" << endl;
	cout << "请输入原密码与修改后的密码：" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "***********************修改密码***********************\n" << endl;
	cout << "请输入原密码：";
	cin >> password;
	cout << "请输入修改后的密码：";
	cin >> modifiedPassword;
	if (password == user.getPassword()) {
		userOp.update(user.getName(), user.getAccount(), modifiedPassword, user.getPermission());
		cout << "修改成功！\n" << endl;
	}
	else
		cout << "原密码输入错误！\n" << endl;
	this->Personal(user);
}

void UI::ModifyPersonalVehicle(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	string platenum, model, color, year;
	cout << "******************" << "你好，" << user.getName() << "******************\n" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "个人车辆信息：" << endl;
	cout << "车牌号：" << vehicleOp.getPlateNum() << endl;
	cout << "车型：" << vehicleOp.getModel() << endl;
	cout << "颜色：" << vehicleOp.getColor() << endl;
	cout << "年份：" << vehicleOp.getYear() << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "\n\n\n\n\n\n\n\n";
	cout << "**********************修改车辆信息**********************\n" << endl;
	cout << "请输入您要修改的信息（若要跳过请输入\" \\ \"）:" << endl; // \" \\ \"即代表“"\"”
	cout << "请输入修改后的车牌号：";
	cin >> platenum;
	cout << "请输入修改后的车型：";
	cin >> model;
	cout << "请输入修改后的颜色：";
	cin >> color;
	cout << "请输入修改后的年份：";
	cin >> year;
	vehicleOp.update(platenum, model, color, year);
	cout << "修改成功！\n" << endl;
	this->Personal(user);
}

void UI::AddVehicle(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	string platenum, model, color, year;
	cout << "请输入车牌号：";
	cin >> platenum;
	cout << "请输入车型：";
	cin >> model;
	cout << "请输入颜色：";
	cin >> color;
	cout << "请输入年份：";
	cin >> year;
	vehicleOp.addVehicle(platenum, model, color, year);
	this->Modify(user);
}

void UI::DeleteVehicle(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	string platenum;
	cout << "请输入删除车辆的车牌号：";
	cin >> platenum;
	vehicleOp.deleteVehicle(platenum);
	this->Modify(user);
}

void UI::ModifyVehicle(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	string modifyPlatenum;
	string platenum, model, color, year;
	cout << "请输入修改车辆的车牌号：";
	cin >> modifyPlatenum;
	cout << "请输入车牌号：";
	cin >> platenum;
	cout << "请输入车型：";
	cin >> model;
	cout << "请输入颜色：";
	cin >> color;
	cout << "请输入年份：";
	cin >> year;
	vehicleOp.modifyVehicle(modifyPlatenum, platenum, model, color, year);
	this->Modify(user);
}

void UI::run() {
	this->Start();
}

