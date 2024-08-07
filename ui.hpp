#include<iostream>

using namespace std;

class UI {
private:
	void Start();    //开始界面
	void Login();
	void Register();
	void Menu();
public:
	int choice;
	void run();
};

void UI::Start() {
	cout << "************图书管理系统登录*************\n" << endl;
	cout << "1.注册账号\n" << endl;
	cout << "2.登录账号\n" << endl;
	cout << "3.退出\n\n\n\n\n" << endl;
	cout << "************图书管理系统登录*************\n" << endl;
	cout << "请输入你的选择: ";
	cin >> choice;
	if (cin.good())
		switch (choice) {
		case 1:
			Login();
		case 2:
			Register();
		case 3:
			break;
		}
	else {
		cout << "输入不符合规范，请重新输入！" << endl;
		cin.clear();
		this->Start();
	}
}

void UI::run() {
	this->Start();
}

void UI::Login() {

}

void UI::Register() {

}