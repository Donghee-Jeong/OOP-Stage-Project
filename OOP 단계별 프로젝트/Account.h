#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#define MAXNAME 100

typedef struct Account {
	int ID;
	char Name[MAXNAME];
	int Balance;
} Account;

#endif