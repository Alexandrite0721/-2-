#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"user.hpp"

class UserOp :public User {
public:
	UserOp(User user);      //�û��ļ��������캯��
	int userStore();        //�û����ݴ洢����
	int userQuery();        //��ѯ�û�����
	void getUser();         //��ȡ�û���Ϣ����
	void update(string newName, string newAccount, string newPassword, int newPermission);//�����û���Ϣ
};

UserOp::UserOp(User user) {
	this->setAccount(user.getAccount());
	this->setName(user.getName());
	this->setPassword(user.getPassword());
	this->setPermission(user.getPermission());
}

int UserOp::userStore() {
	ifstream fin("User.txt", ios_base::in);
	string curacc, line;
	fin.seekg(0, ios_base::beg);
	while (!fin.eof()) {
		fin >> curacc;
		getline(fin, line);
		if (this->getAccount() == curacc) {
			cout << "�˺��ѱ�ע�ᣬ���������룡" << endl;
			return -1;
		}
	}
	fin.close();
	ofstream fout("User.txt", ios_base::app);
	fout << endl;
	fout << this->getAccount() << " "
		<< this->getPassword() << " "
		<< this->getName() << " "
		<< this->getPermission() << " " << endl;
	cout << "ע��ɹ���" << endl;
	fout.close();
	return 1;
}

int UserOp::userQuery() {
	ifstream fin("User.txt", ios_base::in);
	string curacc, curpasw, line;
	fin.seekg(0, ios_base::beg);
	while (!fin.eof()) {
		fin >> curacc;
		fin >> curpasw;
		getline(fin, line);
		if (this->getAccount() == curacc) {
			if (this->getPassword() == curpasw)
				return 1; //�û�����������ɹ�
			else
				return 0; //�������
		}
	}
	fin.close();
	return -1; //�û�������
}

void UserOp::getUser() {
	ifstream fin("User.txt", ios_base::in);
	string curacc, line;
	fin.seekg(0, ios_base::beg);
	while (!fin.eof()) {
		fin >> curacc;
		if (this->getAccount() == curacc) {
			string curpasw, curname;
			int curperm;
			fin >> curpasw >> curname >> curperm;
			this->setAccount(curacc);
			this->setName(curname);
			this->setPassword(curpasw);
			this->setPermission(curperm);
			fin.close();
			break;
		}
		else
			getline(fin, line);
	}
}

void UserOp::update(string newName, string newAccount, string newPassword, int newPermission) {
	ifstream fin("User.txt", ios::in);
	fin.seekg(0, ios_base::beg);
	string curacc, line;
	string fileContents = "";
	string oriContents[2];
	int oriPermission;
	string curContents[2] = { newPassword,newName };
	int curPermission = newPermission;
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
			for (int i = 0; i < 2; ++i)
				fin >> oriContents[i];
			fin >> oriPermission;
			getline(fin, line);
		}
	}
	ofstream fout("User.txt", ios_base::out);
	fout.flush();
	fout << fileContents;
	fout << this->getAccount() << " ";
	for (int i = 0; i < 3; ++i) {
		if (i < 2) {
			if (curContents[i] != flag)
				fout << curContents[i] << ' ';
			else
				fout << oriContents[i] << ' ';
		}
		else if (i == 2) {
			if (curPermission != 2)
				fout << curPermission << ' ';
			else
				fout << oriPermission << ' ';
		}
	}
	fout.close();
}

