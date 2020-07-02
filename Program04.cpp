#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "LibraryUser.h"

using std::stringstream;
using namespace std;

void main() {
	string tempFirst, tempLast, tempBookNum, tempLine;
	unsigned int tempID, tempBooksOut;
	string filename = "students.txt";
	stringstream tempSS;
	
	const int numStudents = 120;
	string* studentArray;
	studentArray = new string[numStudents];		//Add loop to increase array size if needed

	LibraryUser studentObject[numStudents];

	string tempArray[25];

	int i;
	int k = 0;


	ifstream fin(filename);
	if (fin.fail()) {
		cerr << "ERROR: File not found" << endl;
		exit(1);
	}
	while (getline(fin, tempLine)) {
		const int numBookNums = 12;
		string* BookNumArray;
		BookNumArray = new string[numBookNums];
		i = 0;
		tempSS << tempLine;
		tempSS >> tempID >> tempFirst >> tempLast >> tempBooksOut;	//Deconstructed values from getline string, use to build object
		while (tempSS >> tempBookNum) {
			//if (i = numBookNums) {
				//numBookNums *= 2;
			BookNumArray[i] = tempBookNum;
			++i;
		}
		/* Print variables from file lines
		int j;
		cout << "ID: " << tempID << " " << "First Name: " << tempFirst << " " << "Last Name: " << tempLast << " " << endl;
		cout << "Book Numbers: " << endl;
		for (j = 0; j < numBookNums; ++j) {
			cout << BookNumArray[j] << endl;
		}*/
		tempSS.clear();
		delete[] BookNumArray;

		//*********************Build Object*********************
		studentObject[k].SetID(tempID);
		studentObject[k].SetFirstName(tempFirst);
		studentObject[k].SetLastName(tempLast);
		studentObject[k].SetCheckoutCount(tempBooksOut);
		++k;
	}
	fin.close();
	for (i = 0; i < numStudents; ++i) {
		cout << studentObject[i].GetID() << " " << studentObject[i].GetFirstName() << " " << studentObject[i].GetLastName() << " " << studentObject[i].CheckoutCount() << endl;
	}
}