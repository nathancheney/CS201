#pragma once
#include <iostream>
#include <string>
using namespace std;

void deposit(double& account, double amount) {
	account = account + amount;
}

char mainMenu() {
	/*PRE:None.
	POST: Requests user inputted character then checks characters validity.
	RETURNS: Character to main function to direct program to the appropriate function.
	EXCEPTIONS, OTHER INFO: None. */

	char userInput = 'z';
	bool loopCheck = true;
	cout << "Enter (D)eposit, (W)ithdrawal, (L)oan, or (Q)uit >>> ";
	cin >> userInput;
	userInput = toupper(userInput);
	while (loopCheck == true) {
		if ((userInput != 'D') && (userInput != 'W') && (userInput != 'L') && (userInput != 'Q')) {
			cout << userInput << " is not a valid entry." << endl;
			cout << "Enter D, W, L, or Q >>> ";
			cin >> userInput;
			userInput = toupper(userInput);			
		}
		else {
			loopCheck = false;
		}
	}
	return userInput;
}

double GetValue(string inputString) {
	/*PRE:inputString.
	POST: Outputs input string to give direction to user to correctly input integer.
	RETURNS: userInput as a double.
	EXCEPTIONS, OTHER INFO: None. */
	double userInput;
	do
	{
		cout << inputString;
		cin >> userInput;
	} while (userInput <= 0);
	return userInput;
}

double GetValue(string inputString, double upperLimit) {
	/*PRE:inputString, upperLimit
	POST: Overloads GetValue with upperLimit value. Outputs input string to give
	direction to user to correctly input integer and checks if input is less than
	upperLimit value.
	RETURNS: userInput as a double.
	EXCEPTIONS, OTHER INFO: None. */
	double userInput;
	do
	{
		cout << inputString;
		cin >> userInput;
		if (userInput <= 0 || userInput >= upperLimit) {
			cout << "Amount must be greater than zero and less than " << upperLimit;
		}
	} while (userInput <= 0 || userInput >= upperLimit);
	return userInput;
}

double GetInterestRate(int creditScore) {
	/*PRE:creditScore
	POST: Checks range of creditScore.
	RETURNS: Interest rate based on creditScore.
	EXCEPTIONS, OTHER INFO: None. */
	if (creditScore <= 500) {
		return 0.05;
	}
	else if (creditScore <= 700) {
		return 0.03;
	}
	else {
		return 0.01;
	}
}

void withdraw(double& account, double withdrawAmount) {
	account -= withdrawAmount;
}

int GetLoanMonths() {
	/*PRE: None
	POST: Checks if user input is in array of valid integers.
	RETURNS: User input as months.
	EXCEPTIONS, OTHER INFO: None. */
	const int monthArrayLength = 4;
	int monthArray[monthArrayLength] = {12, 24, 36, 60};
	int months;
	int i;
	bool validEntry = true;
	do
	{
		cout << "Enter number of months (12, 24, 36, 60) >>> ";
		cin >> months;
		for (i = 0; i < monthArrayLength; ++i) {
			if (months == monthArray[i]) {
				validEntry = false;
			}
		}
	} while (validEntry);
	return months;
}

int GetCreditRating() {
	/*PRE: None
	POST: Checks range of user inputted creditScore. Outputs error message if input
	is out of range.
	RETURNS: creditRating.
	EXCEPTIONS, OTHER INFO: None. */
	int creditRating;

	do
	{
		cout << "Enter credit rating" << endl;
		cin >> creditRating;
		if (creditRating < 300 || creditRating > 850) {
			cout << "Rating must be between 300 and 850" << endl;
		}
	} while (creditRating < 300 || creditRating > 850);
	return creditRating;
}

double CalculateLoanAmount(double principle, double interestRate, int months) {
	/*PRE: principle, interestRate, months
	POST: Calculates loan value.
	RETURNS: Loan value.
	EXCEPTIONS, OTHER INFO: None. */
	return pow((principle * (1 + (interestRate / 12))), (months / 12));
}

void OutputAccount(double amount) {
	/*PRE: amount
	POST: Outputs account balance.
	RETURNS: None.
	EXCEPTIONS, OTHER INFO: None. */
	cout << "Account balance: " << amount << endl;
}
