#include "Account.h"
#include "Functions.h"
#include <iostream>
#include <cstring>

#define MAXACCOUNT 100

using namespace std;

int Menu(void) {
	int sel;
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
	cin >> sel;
	cout << endl;

	return sel;
}

Account Open(void) {
	cout << "[���°���]" << endl;
	cout << "����ID : ";
	int id;
	cin >> id;
	cout << "�̸� : ";
	char name[MAXNAME];
	cin >> name;
	cout << "�Աݾ� : ";
	int money;
	cin >> money;
	cout << "�ԱݿϷ�" << endl;
	cout << endl;

	Account newUser;
	newUser.ID = id;
	strcpy_s(newUser.Name, name);
	newUser.Balance = money;

	return newUser;
}

void Deposit(Account * account, int length) {
	cout << "[��    ��]" << endl;
	cout << "����ID : ";
	int id;
	cin >> id;
	cout << "�Աݾ� : ";
	int money;
	cin >> money;
	for (int i = 0; i < length; i++) {
		if (account[i].ID == id) {
			account[i].Balance += money;
			cout << "�ԱݿϷ�" << endl;
			cout << endl;
			break;
		}
	}
}

void Withdraw(Account * account, int length) {
	cout << "[��    ��]" << endl;
	cout << "����ID : ";
	int id;
	cin >> id;
	cout << "��ݾ� : ";
	int money;
	cin >> money;
	for (int i = 0; i < length; i++) {
		if (account[i].ID == id) {
			account[i].Balance -= money;
			cout << "��ݿϷ�" << endl;
			cout << endl;
			break;
		}
	}
}

void AccountInfo(Account * account, int length) {
	for (int i = 0; i < length; i++) {
		cout << "����ID : " << account[i].ID << endl;
		cout << "�̸� : " << account[i].Name << endl;
		cout << "�ܾ� : " << account[i].Balance << endl;
		cout << endl;
	}
}

void Controller(void) {
	Account account[MAXACCOUNT];
	int curAccount = 0;
	int userSel;

	do {
		userSel = Menu();
		switch (userSel) {
		case 1:
			account[curAccount] = Open();
			curAccount++;
			break;
		case 2:
			Deposit(account, curAccount);
			break;
		case 3:
			Withdraw(account, curAccount);
			break;
		case 4:
			AccountInfo(account, curAccount);
			break;
		case 5:
			cout << "[���α׷� ����]" << endl;
			break;
		}
	} while (userSel != 5);
}