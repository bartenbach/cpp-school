// BankClassType.h by Blake Bartenbach
#pragma once
#include <string>
#include <iostream>

using namespace std;

class BankClassType {
	private:
		string accountNumber;
		char accountType;
		string firstName;
		string lastName;
		double checkingBalance;
		double savingsBalance;
	public:
		BankClassType(string, char, string, string, double, double);
		~BankClassType();
		void setNewAccountInfo(string, char, string, string, double, double);
		friend void printAccountPreview(BankClassType*);
		void printAccountInfo();
		void accountDeposit(double, bool);
		void accountWithdrawal(double, bool);
		double getCheckingBalance();
		double getSavingsBalance();
};