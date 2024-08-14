#pragma once
#include<iostream>
using namespace std;

class User { //用户基类
public:
	User(string Username = "默认用户名", string password = "", string account = "", int permission = 0);
	string getName(); //获取用户名
	string getAccount(); //获取账号
	string getPassword(); //获取密码
	int getPermission(); //获取权限

	void setName(string Name); //设置用户名
	void setAccount(string Account); //设置账号
	void setPassword(string Password); //设置密码
	void setPermission(int Permission); //设置管理员权限
private:
	string username; //用户名
	string password; //密码
	string account; //账号
	int permission;   //管理员权限
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

