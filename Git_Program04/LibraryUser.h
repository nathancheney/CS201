#pragma once
#include <iostream>
#include <string>

using namespace std;


class LibraryUser
{

public:
	LibraryUser();

	LibraryUser(unsigned int, string, string, unsigned int, int);

	unsigned int GetID() const;
	string GetFirstName() const;
	string GetLastName() const;
	unsigned int CheckoutCount() const;
	int GetNumBooksArraySize() const;
	//string* GetBookNumArray() const;

	void SetID(unsigned int);
	void SetFirstName(string);
	void SetLastName(string);
	void SetCheckoutCount(unsigned int);

private:
	//Add string pointer to manage dynamic array
	unsigned int newID;
	string newFirstName;
	string newLastName;
	unsigned int newNumBooks;
	int newArraySize;
};