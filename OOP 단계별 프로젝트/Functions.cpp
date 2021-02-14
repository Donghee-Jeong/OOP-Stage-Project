#include "Account.h"
#include "Functions.h"
#include <iostream>
#include <cstring>

#define MAXACCOUNT 100

using namespace std;

int Menu(void) {
	int sel;
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
	cin >> sel;
	cout << endl;

	return sel;
}

Account Open(void) {
	cout << "[계좌개설]" << endl;
	cout << "계좌ID : ";
	int id;
	cin >> id;
	cout << "이름 : ";
	char name[MAXNAME];
	cin >> name;
	cout << "입금액 : ";
	int money;
	cin >> money;
	cout << "입금완료" << endl;
	cout << endl;

	Account newUser;
	newUser.ID = id;
	strcpy_s(newUser.Name, name);
	newUser.Balance = money;

	return newUser;
}

void Deposit(Account * account, int length) {
	cout << "[입    금]" << endl;
	cout << "계좌ID : ";
	int id;
	cin >> id;
	cout << "입금액 : ";
	int money;
	cin >> money;
	for (int i = 0; i < length; i++) {
		if (account[i].ID == id) {
			account[i].Balance += money;
			cout << "입금완료" << endl;
			cout << endl;
			break;
		}
	}
}

void Withdraw(Account * account, int length) {
	cout << "[출    금]" << endl;
	cout << "계좌ID : ";
	int id;
	cin >> id;
	cout << "출금액 : ";
	int money;
	cin >> money;
	for (int i = 0; i < length; i++) {
		if (account[i].ID == id) {
			account[i].Balance -= money;
			cout << "출금완료" << endl;
			cout << endl;
			break;
		}
	}
}

void AccountInfo(Account * account, int length) {
	for (int i = 0; i < length; i++) {
		cout << "계좌ID : " << account[i].ID << endl;
		cout << "이름 : " << account[i].Name << endl;
		cout << "잔액 : " << account[i].Balance << endl;
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
			cout << "[프로그램 종료]" << endl;
			break;
		}
	} while (userSel != 5);
}