/* CS 201RSummer 2020
Nathan Cheney ncxn8@umkc.edu
Lab 03 - Bank account tracker
Tracks bank account deposits/withdraws and calculates loan values. */

#include <iostream>
#include <string>
#include <iomanip>
#include "checkingmodule.h"
using namespace std;

void deposit(double& account, double amount);
char mainMenu();
double GetValue(string);
double GetValue(string inputString, double upperLimit);
double GetInterestRate(int creditScore);
void withdraw(double& account, double withdrawAmount);
int GetLoanMonths();
int GetCreditRating();
double CalculateLoanAmount(double principle, double interestRate, int months);
void OutputAccount(double amount);

int main() {
	/*PRE:None.
	POST: Calculates account balance and loan amounts based on user input values.
	RETURNS: Updates parameters with respective daily values.
	EXCEPTIONS, OTHER INFO: None. */
	cout << fixed << setprecision(2);
	double account = 0.0;
	double inputWithdraw;
	char selection;
	do
	{
		selection = mainMenu();
		if (selection == 'D') {
			double deposit_amount = GetValue("How much would you like to deposit: ");
			deposit(account, deposit_amount);
			OutputAccount(account);
		}
		else if (selection == 'W') {
			cout << "Enter amount to withdraw: ";
			cin >> inputWithdraw;
			while (inputWithdraw > account) {
				cout << "Cannot withdraw more the account value" << endl;
				cout << "Enter amount to withdraw: ";
				cin >> inputWithdraw;
			}
			withdraw(account, inputWithdraw);
			OutputAccount(account);
		}
		else if (selection == 'L') {
			int creditRating = GetCreditRating();
			double interestRate = GetInterestRate(creditRating);
			int months = GetLoanMonths();
			double loanAmount = GetValue("How much do you want to borrow? ");
			
			cout << "Interest Rate: " << interestRate << endl;
			cout << "Principal: " << loanAmount << endl;
			cout << "Months: " << months << endl;
			cout << "Total loan amount: " << CalculateLoanAmount(loanAmount, interestRate, months) << endl;
		}

	} while (selection != 'Q');
	
	cout << account << endl;
	cout << selection << endl;
	return 0;
}


