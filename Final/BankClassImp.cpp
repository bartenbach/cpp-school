// BankClassImp.cpp by Blake Bartenbach
#include "BankClassType.h"
#include <iomanip>

using namespace std;

BankClassType::BankClassType(string a, char b, string c, string d, double e, double f) {
	this->accountNumber = a;
	this->accountType = b;
	this->firstName = c;
	this->lastName = d;
	this->checkingBalance = e;
	this->savingsBalance = f;
}

void BankClassType::setNewAccountInfo(string a, char b, string c, string d, double e, double f) {
	this->accountNumber = a;
	this->accountType = b;
	this->firstName = c;
	this->lastName = d;
	this->checkingBalance = e;
	this->savingsBalance = f;
}

void printAccountPreview(BankClassType* account) {
	cout << "    Account: " << account->accountNumber;
}

void BankClassType::accountDeposit(double amount, bool isChecking) {
	if (isChecking) {
		this->checkingBalance+=amount;
	} else {
		this->savingsBalance+=amount;
	}
}

void BankClassType::accountWithdrawal(double amount, bool isChecking) {
	if (isChecking) {
		this->checkingBalance-=amount;
	} else {
		this->savingsBalance-=amount;
	}
}

double BankClassType::getCheckingBalance() {
	return this->checkingBalance;
}

double BankClassType::getSavingsBalance() {
	return this->savingsBalance;
}

void BankClassType::printAccountInfo() {
	cout << "    Name: " << lastName << ", " << firstName << endl;
	cout << "    Account Type: " << accountType << endl;
	cout << "    Checking Balance: " << "$" << fixed << setprecision(2) << this->checkingBalance << endl;
	cout << "    Savings Balance:  " << "$" << fixed << setprecision(2) << this->savingsBalance << endl;
}

BankClassType::~BankClassType() {
	cout << "Programmed by Blake Bartenbach" << endl;
	cout << "Goodbye!" << endl;
	system("pause");
}