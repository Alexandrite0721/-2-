#include<iostream>

using namespace std;

class UI {
private:
	void Start();    //��ʼ����
	void Login();
	void Register();
	void Menu();
public:
	int choice;
	void run();
};

void UI::Start() {
	cout << "************ͼ�����ϵͳ��¼*************\n" << endl;
	cout << "1.ע���˺�\n" << endl;
	cout << "2.��¼�˺�\n" << endl;
	cout << "3.�˳�\n\n\n\n\n" << endl;
	cout << "************ͼ�����ϵͳ��¼*************\n" << endl;
	cout << "���������ѡ��: ";
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
		cout << "���벻���Ϲ淶�����������룡" << endl;
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