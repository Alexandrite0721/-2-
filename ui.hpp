#pragma once
#include<iostream>
#include"userFile.hpp"
#include"vehicleFile.hpp"
using namespace std;

class UI {
private:
	void Start();						    //��ʼ����
	void Login();							//��¼
	void Register();						//ע��
	void Menu(User user);				    //��ͨ�û��˵�
	void AdmiMenu(User user);			    //����Ա�˵�
	void Personal(User user);               //������Ϣ��ѯ
	void Cars(User user);                   //������Ϣ��ѯ
	void Escalate(User user);               //����Ȩ��
	void Modify(User user);                 //������Ϣ��������Ա��
	void ModifyUsername(User user);         //�޸��û���
	void ModifyPassword(User user);         //�޸�����
	void ModifyPersonalVehicle(User user);  //�޸ĸ��˳�����Ϣ
	void AddVehicle(User user);             //���ӳ���
	void DeleteVehicle(User user);          //ɾ������
	void ModifyVehicle(User user);          //�޸ĳ�����Ϣ
public:
	int choice;
	void run(); //��UI����
};

void UI::Start() {
	cout << "******************��������ϵͳ*****************\n" << endl;
	cout << "1.ע���˺�\n" << endl;
	cout << "2.��¼�˺�\n" << endl;
	cout << "0.�˳�\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "******************��������ϵͳ*****************\n" << endl;
	cout << "���������ѡ��: ";
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
			cout << "���벻���Ϲ淶�����������룡\n" << endl;
			this->Start();
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "���벻���Ϲ淶�����������룡\n" << endl;
		this->Start();
	}
}

void UI::Login() {
	string account;
	string password;
	cout << "******************��������ϵͳ��¼*****************\n" << endl;
	cout << "�����������˺������룺\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "******************��������ϵͳ��¼*****************\n" << endl;
	cout << "�˺ţ�";
	cin >> account;
	cout << "���룺";
	cin >> password;
	User user("Ĭ���û���", password, account, 0);
	UserOp userOp(user);
	switch (userOp.userQuery())
	{
	case 1: {
		cout << "��½�ɹ���\n" << endl;
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
		cout << "�������\n" << endl;
		this->Start();
		break;
	}
	case -1: {
		cout << "�û������ڣ�\n" << endl;
		this->Start();
		break;
	}
	}
}

void UI::Register() {
	string account;
	string password1;
	string password2;
	cout << "******************��������ϵͳע��*****************\n" << endl;
	cout << "�����������˺������룺\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "******************��������ϵͳע��*****************\n" << endl;
	cout << "�˺ţ�";
	cin >> account;
	cout << "���룺";
	cin >> password1;
	cout << "�����������룺";
	cin >> password2;
	if (password1 != password2) {
		cout << "���벻һ�£����������롣\n" << endl;
		this->Start();
	}
	else {
		User newUser("Ĭ���û���", password1, account, 0);           //�������û�
		UserOp newUserOp(newUser);
		if (newUserOp.userStore() == 1) {                              //¼���û���Ϣ
			Vehicle vehicle("δ¼��", "δ¼��", "δ¼��", "δ¼��"); //�������û���ʼ������Ϣ
			vehicle.userAttach(newUser);                             //���û�
			VehicleOp vehicleOp(vehicle);
			vehicleOp.vehicleStore();                                //¼�복����Ϣ
		}
		this->Start();
	}
}

void UI::Menu(User user) {
	cout << "****************" << "��ã�" << user.getName() << "****************\n" << endl;
	cout << "1.������Ϣ��ѯ\n" << endl;
	cout << "2.������Ϣ��ѯ\n" << endl;
	cout << "3.��������Ա\n" << endl;
	cout << "0.�˳���¼\n\n\n\n\n\n\n" << endl;
	cout << "\n\n\n\n\n\n\n\n" << endl;
	cout << "*********************�˵�����ͨ�û���*********************\n" << endl;
	cout << "���������ѡ��: ";
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
			cout << "���벻���Ϲ淶�����������룡\n" << endl;
			this->Menu(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "���벻���Ϲ淶�����������룡\n" << endl;
		this->Menu(user);
	}
}

void UI::AdmiMenu(User user) {
	cout << "******************" << "��ã�" << user.getName() << "******************\n" << endl;
	cout << "1.������Ϣ��ѯ\n" << endl;
	cout << "2.������Ϣ��ѯ\n" << endl;
	cout << "3.��������\n" << endl;
	cout << "0.�˳���¼\n\n\n\n\n\n\n" << endl;
	cout << "\n\n\n\n\n\n\n\n" << endl;
	cout << "*********************�˵�������Ա��*********************\n" << endl;
	cout << "���������ѡ��: ";
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
			cout << "���벻���Ϲ淶�����������룡\n" << endl;
			this->Menu(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "���벻���Ϲ淶�����������룡\n" << endl;
		this->Menu(user);
	}
}

void UI::Personal(User user) {
	Vehicle vehicle("δ¼��", "δ¼��", "δ¼��", "δ¼��");
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	cout << "******************" << "��ã�" << user.getName() << "******************\n" << endl;
	cout << "------------------------������Ϣ-----------------------" << endl;
	cout << "�˺ţ�" << vehicleOp.getAccount() << endl;
	cout << "�û�����" << vehicleOp.getName() << endl;
	cout << "----------------------���˳�����Ϣ---------------------" << endl;
	cout << "���ƺţ�" << vehicleOp.getPlateNum() << endl;
	cout << "���ͣ�" << vehicleOp.getModel() << endl;
	cout << "��ɫ��" << vehicleOp.getColor() << endl;
	cout << "��ݣ�" << vehicleOp.getYear() << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "1.�޸��û���" << endl;
	cout << "2.�޸�����" << endl;
	cout << "3.�޸ĸ��˳�����Ϣ" << endl;
	cout << "0.����" << endl;
	cout << "*********************������Ϣ��ѯ*********************\n" << endl;
	cout << "����������ѡ��";
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
			cout << "���벻���Ϲ淶�����������룡\n" << endl;
			this->Personal(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "���벻���Ϲ淶�����������룡\n" << endl;
		this->Personal(user);
	}
}

void UI::Cars(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	cout << "******************" << "��ã�" << user.getName() << "******************\n" << endl;
	cout << "------------------ϵͳ�����г�����Ϣ-------------------" << endl;
	vehicleOp.getList();
	cout << "-------------------------------------------------------" << endl;
	cout << "1.���ƺŲ�ѯ����" << endl;
	cout << "2.���Ͳ�ѯ����" << endl;
	cout << "3.��ݲ�ѯ����" << endl;
	cout << "0.����" << endl;
	cout << "**********************������Ϣ��ѯ**********************\n" << endl;
	cout << "���������ѡ��";
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
			cout << "�����������ѯ�����ĳ��ƺţ�";
			cin >> platenum;
			vehicleOp.keyInformationQueries(platenum, "//", "//", "//");
			this->Cars(user);
			break;
		}
		case 2: {
			string model;
			cout << "�����������ѯ�����ĳ��ͣ�";
			cin >> model;
			vehicleOp.keyInformationQueries("//", model, "//", "//");
			this->Cars(user);
			break;
		}
		case 3: {
			string year;
			cout << "�����������ѯ��������ݣ�";
			cin >> year;
			vehicleOp.keyInformationQueries("//", "//", "//", year);
			this->Cars(user);
			break;
		}
		default:
			choice = -1;
			cout << "���벻���Ϲ淶�����������룡\n" << endl;
			this->Cars(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "���벻���Ϲ淶�����������룡\n" << endl;
		this->Cars(user);
	}
}

void UI::Escalate(User user) {
	UserOp userOp(user);
	string key = "ADMI";
	string inputKey;
	cout << "******************" << "��ã�" << user.getName() << "******************\n" << endl;
	cout << "���������Ա��Կ��" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "**********************�޸��û���**********************\n" << endl;
	cout << "���������Ա��Կ��";
	cin >> inputKey;
	if (inputKey == key) {
		user.setPermission(1);
		userOp.update(user.getName(), user.getAccount(), user.getPassword(), user.getPermission());
		cout << "����Ա�����ɹ���\n" << endl;
		this->AdmiMenu(user);
	}
	else {
		cout << "��Կ�������" << endl;
		this->Menu(user);
	}
}

void UI::Modify(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	cout << "******************" << "��ã�" << user.getName() << "******************\n" << endl;
	cout << "------------------ϵͳ�����г�����Ϣ-------------------" << endl;
	vehicleOp.getList();
	cout << "-------------------------------------------------------" << endl;
	cout << "1.��ӳ���" << endl;
	cout << "2.ɾ������" << endl;
	cout << "3.�޸ĳ�����Ϣ" << endl;
	cout << "0.����" << endl;
	cout << "********************�޸�ϵͳ������Ϣ********************\n" << endl;
	cout << "����������ѡ��";
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
			cout << "���벻���Ϲ淶�����������룡\n" << endl;
			this->AdmiMenu(user);
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore();
		choice = -1;
		cout << "���벻���Ϲ淶�����������룡\n" << endl;
		this->Personal(user);
	}
}

void UI::ModifyUsername(User user) {
	UserOp userOp(user);
	string modifiedUsername;
	cout << "******************" << "��ã�" << user.getName() << "******************\n" << endl;
	cout << "�������޸ĺ���û�����" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "**********************�޸��û���**********************\n" << endl;
	cout << "�������޸ĺ���û�����";
	cin >> modifiedUsername;
	user.setName(modifiedUsername);
	userOp.update(user.getName(), user.getAccount(), user.getPassword(), user.getPermission());
	cout << "�޸ĳɹ���\n" << endl;
	this->Personal(user);
}

void UI::ModifyPassword(User user) {
	UserOp userOp(user);
	string password, modifiedPassword;
	cout << "******************" << "��ã�" << user.getName() << "******************\n" << endl;
	cout << "������ԭ�������޸ĺ�����룺" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "***********************�޸�����***********************\n" << endl;
	cout << "������ԭ���룺";
	cin >> password;
	cout << "�������޸ĺ�����룺";
	cin >> modifiedPassword;
	if (password == user.getPassword()) {
		userOp.update(user.getName(), user.getAccount(), modifiedPassword, user.getPermission());
		cout << "�޸ĳɹ���\n" << endl;
	}
	else
		cout << "ԭ�����������\n" << endl;
	this->Personal(user);
}

void UI::ModifyPersonalVehicle(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	string platenum, model, color, year;
	cout << "******************" << "��ã�" << user.getName() << "******************\n" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "���˳�����Ϣ��" << endl;
	cout << "���ƺţ�" << vehicleOp.getPlateNum() << endl;
	cout << "���ͣ�" << vehicleOp.getModel() << endl;
	cout << "��ɫ��" << vehicleOp.getColor() << endl;
	cout << "��ݣ�" << vehicleOp.getYear() << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "\n\n\n\n\n\n\n\n";
	cout << "**********************�޸ĳ�����Ϣ**********************\n" << endl;
	cout << "��������Ҫ�޸ĵ���Ϣ����Ҫ����������\" \\ \"��:" << endl; // \" \\ \"������"\"��
	cout << "�������޸ĺ�ĳ��ƺţ�";
	cin >> platenum;
	cout << "�������޸ĺ�ĳ��ͣ�";
	cin >> model;
	cout << "�������޸ĺ����ɫ��";
	cin >> color;
	cout << "�������޸ĺ����ݣ�";
	cin >> year;
	vehicleOp.update(platenum, model, color, year);
	cout << "�޸ĳɹ���\n" << endl;
	this->Personal(user);
}

void UI::AddVehicle(User user) {
	Vehicle vehicle;
	vehicle.userAttach(user);
	VehicleOp vehicleOp(vehicle);
	vehicleOp.getVehicle();
	string platenum, model, color, year;
	cout << "�����복�ƺţ�";
	cin >> platenum;
	cout << "�����복�ͣ�";
	cin >> model;
	cout << "��������ɫ��";
	cin >> color;
	cout << "��������ݣ�";
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
	cout << "������ɾ�������ĳ��ƺţ�";
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
	cout << "�������޸ĳ����ĳ��ƺţ�";
	cin >> modifyPlatenum;
	cout << "�����복�ƺţ�";
	cin >> platenum;
	cout << "�����복�ͣ�";
	cin >> model;
	cout << "��������ɫ��";
	cin >> color;
	cout << "��������ݣ�";
	cin >> year;
	vehicleOp.modifyVehicle(modifyPlatenum, platenum, model, color, year);
	this->Modify(user);
}

void UI::run() {
	this->Start();
}

