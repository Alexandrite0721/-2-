#pragma once
#include<iostream>
using namespace std;

class User { //�û�����
public:
	User(string Username = "Ĭ���û���", string password = "", string account = "", int permission = 0);
	string getName(); //��ȡ�û���
	string getAccount(); //��ȡ�˺�
	string getPassword(); //��ȡ����
	int getPermission(); //��ȡȨ��

	void setName(string Name); //�����û���
	void setAccount(string Account); //�����˺�
	void setPassword(string Password); //��������
	void setPermission(int Permission); //���ù���ԱȨ��
private:
	string username; //�û���
	string password; //����
	string account; //�˺�
	int permission;   //����ԱȨ��
};

User::User(string Username, string Password, string Account, int Permission) {
	User::username = Username;
	User::password = Password;
	User::account = Account;
	User::permission = 0;
}
string User::getName() { return this->username; }
string User::getAccount() { return this->account; }
string User::getPassword() { return this->password; }
int User::getPermission() { return this->permission; }

void User::setName(string Name) { this->username = Name; }
void User::setAccount(string Account) { this->account = Account; }
void User::setPassword(string Password) { this->password = Password; }
void User::setPermission(int Permission) { this->permission = Permission; }

