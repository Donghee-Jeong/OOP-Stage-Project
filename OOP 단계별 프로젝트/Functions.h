#pragma once
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include "Account.h"

int Menu(void);	//메뉴보여주기
Account Open(void);	//계좌개설
void Deposit(Account *, int);	//입금
void Withdraw(Account *, int);	//출금
void AccountInfo(Account *, int);	//계좌정보 전체 출력
void Controller(void);	//위 함수 종합

#endif // !__FUNCTIONS_H__
