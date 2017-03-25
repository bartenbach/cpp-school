// TestClass.cpp by Blake Bartenbach
#include <iostream>
#include <vector>
#include "BankClassType.h"
#include <iomanip>

using namespace std;

vector<BankClassType*>* loadAccounts();
BankClassType* getNewAccount();
void mainMenu();
void printSubMenu();
void listAccounts(vector<BankClassType*>*);
void listAccountMenu(vector<BankClassType*>*);
int getSelection(string);
void handleDeposit(BankClassType *);
void handleWithdrawal(BankClassType *);
void accountTypeMenu(string, BankClassType *);
double getAmount(string);
string getAccountNumber();
string getName(string);
char getAccountType();

int main() {
	vector<BankClassType*> *accounts = loadAccounts();
	system("cls");
	cout << "Welcome to the Bank Account Management Program" << endl;
	while (true) {
		cout << "\nAccount List:" << endl;
		listAccounts(accounts);
		mainMenu();
		string selection;
		cin >> selection;
		if (selection == "1") {
			if (accounts->size() >= 5) {
				system("cls");
				cout << "Unable to add account -- Maximum number of accounts reached.\n";
			} else {
				BankClassType* newAccount = getNewAccount();
				accounts->push_back(newAccount);
			}
		} else if (selection == "2") {
			system("cls");
			bool exit = false;
			while (!exit) {
				cout << "Please select an account...\n";
				listAccountMenu(accounts);
				int accountSelection = getSelection("\nSelection: ");
				if (accountSelection > accounts->size() || accountSelection < 1) {
					system("cls");
					continue;
				} else {
					BankClassType* acc = accounts->at(accountSelection -1);
					system("cls");
					while (!exit) {
						printAccountPreview(acc);
						cout << endl;
						printSubMenu();
						int selection = getSelection("Selection: ");
						switch (selection) {
							case 1:
								system("cls");
								cout << endl;
								acc->printAccountInfo();
								break;
							case 2:
								handleDeposit(acc);
								break;
							case 3:
								handleWithdrawal(acc);
								break;
							case 4:
								exit = true;
								system("cls");
								break;
							default:
								system("cls");
								cout << "Invalid option\n\n";
						}
					}
				}
			}
		} else if (selection == "X" || selection == "x") {
			exit(0);
		} else {
			system("cls");
			cout << "Invalid option\n";
		}
	}
}

BankClassType* getNewAccount() {
	system("cls");
	string accountNumber = getAccountNumber();
	char accountType = getAccountType();
	string firstName = getName("first name");
	string lastName = getName("last name");
	double checkingBalance = getAmount("Please enter the checking account balance: ");
	double savingsBalance = getAmount("Please enter the savings account balance: ");
	BankClassType* newAccount = new BankClassType(accountNumber, accountType, firstName, lastName, checkingBalance, savingsBalance);
	system("cls");
	cout << "Account added successfully\n";
	return newAccount;
}

char getAccountType() {
	while (true) {
		cout << "Please enter the account type (P or R): ";
		char accountType;
		cin >> accountType;
		switch (accountType) {
			case 'P':
			case 'R':
				return accountType;
				break;
			default:
				break;
		}
	}
}

string getName(string prompt) {
	cout << "Please enter the " << prompt << " for the account: ";
	string name;
	cin >> name;
	return name;
}

string getAccountNumber() {
	while (true) {
		cout << "Please enter the 6 character alphanumeric account number: ";
		string accountNumber;
		cin >> accountNumber;
		if (accountNumber.length() == 6) {
			// could further validate account number format here
			return accountNumber;
		}
	}
}

void handleDeposit(BankClassType *account) {
	accountTypeMenu("deposit to", account);
	int selection = 0;
	bool invalid = true;
	do {
		selection = getSelection("Selection: ");
		if (selection == 1 || selection == 2) {
			invalid = false;
		}
	} while (invalid);
	double amount = getAmount("Amount: ");
	switch (selection) {
	case 1:
		account->accountDeposit(amount, true);
		system("cls");
		cout << "$" << fixed << setprecision(2) << amount << " deposited into checking.\n\n";
		break;
	case 2:
		account->accountDeposit(amount, false);
		system("cls");
		cout << "$" << fixed << setprecision(2) << amount << " deposited into savings.\n\n";
		break;
	default:
		cout << "Invalid account.  No funds were deposited.\n\n";
		break;
	}
}

void accountTypeMenu(string action, BankClassType *account) {
	system("cls");
	cout << "Please select the account you would like to " << action << "\n\n";
	cout << "    [1] Checking - $" << fixed << setprecision(2) << account->getCheckingBalance() << "\n";
	cout << "    [2] Savings  - $" << fixed << setprecision(2) << account->getSavingsBalance() << "\n\n";
}

void handleWithdrawal(BankClassType *account) {
	accountTypeMenu("withdrawal from", account);
	int selection = 0;
	bool invalid = true;
	do {
		selection = getSelection("Selection: ");
		if (selection == 1 || selection == 2) {
			invalid = false;
		}
	} while (invalid);
	double amount = getAmount("Amount: ");
	switch (selection) {
	    case 1:
		    account->accountWithdrawal(amount, true);
			system("cls");
			cout << "$" << fixed << setprecision(2) << amount << " withdrawn from checking.\n\n";
		    break;
		case 2:
			account->accountWithdrawal(amount, false);
			system("cls");
			cout << "$" << fixed << setprecision(2) << amount << " withdrawn from savings.\n\n";
			break;
		default:
			cout << "Invalid account.  No funds were withdrawn.\n";
			break;
	}
}

int getSelection(string prompt) {
	cout << prompt;
	int selection;
	cin >> selection;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nInvalid entry\n";
		selection = getSelection(prompt);
	}
	return selection;
}

double getAmount(string prompt) {
	cout << prompt;
	double amount;
	cin >> amount;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nInvalid value\n";
		amount = getSelection(prompt);
	}
	return amount;
}

void mainMenu() {
	cout << "Please select from one of the following options...\n\n";
	cout << "[1] Add a new account\n";
	cout << "[2] Use existing account\n";
	cout << "[X] Exit program\n\n";
	cout << "Selection: ";
}

void printSubMenu() {
	cout << "\nPlease select from one of the following options...\n\n";
	cout << "[1] Print Account Info\n";
	cout << "[2] Deposit money into checking or savings\n";
	cout << "[3] Withdraw money from checking or savings\n";
	cout << "[4] Return to main menu\n\n";
}

vector<BankClassType*>* loadAccounts() {
	vector<BankClassType*>* accounts = new vector<BankClassType*>();
	BankClassType* acc1 = new BankClassType("P12345", 'P', "Bill", "Gates", 175253.99, 6875250.23);
	BankClassType* acc2 = new BankClassType("R12346", 'R', "Tommy", "Jones", 845.21, 2700.00);
	BankClassType* acc3 = new BankClassType("P12347", 'P', "Isaac", "Asimov", 300.67, 14750.29);
	accounts->push_back(acc1);
	accounts->push_back(acc2);
	accounts->push_back(acc3);
	return accounts;
}

void listAccounts(vector<BankClassType*>* accounts) {
	cout << endl;
	for (BankClassType* x : *accounts) {
		printAccountPreview(x);
		cout << endl;
	}
	cout << endl;
}

void listAccountMenu(vector<BankClassType*>* accounts) {
	cout << endl;
	int counter = 1;
	for (BankClassType* x : *accounts) {
		cout << "[" << counter << "] ";
		printAccountPreview(x);
		cout << endl;
		counter++;
	}
}