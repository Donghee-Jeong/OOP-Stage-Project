#pragma once
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include "Account.h"

int Menu(void);	//�޴������ֱ�
Account Open(void);	//���°���
void Deposit(Account *, int);	//�Ա�
void Withdraw(Account *, int);	//���
void AccountInfo(Account *, int);	//�������� ��ü ���
void Controller(void);	//�� �Լ� ����

#endif // !__FUNCTIONS_H__
