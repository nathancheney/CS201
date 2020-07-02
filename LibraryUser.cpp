#include "LibraryUser.h"

LibraryUser::LibraryUser() {
	newID = 0;
	newNumBooks = 0;
	newArraySize = 0;
}

LibraryUser::LibraryUser(unsigned int ID, string firstName, string lastName, unsigned int numBooks, int arraySize) {
	newFirstName = firstName;
	newLastName = lastName;
	newID = ID;
	newNumBooks = numBooks;
	newArraySize = arraySize;
}

unsigned int LibraryUser::GetID() const {
	return newID;
}

string LibraryUser::GetFirstName() const {
	return newFirstName;
}

string LibraryUser::GetLastName() const {
	return newLastName;
}
unsigned int LibraryUser::CheckoutCount() const {
	return newNumBooks;
}
int LibraryUser::GetNumBooksArraySize() const {
	return newArraySize;
}


//Add pointer for dynamic array of book nums

void LibraryUser::SetID(unsigned int id) {
	newID = id;
}

void LibraryUser::SetFirstName(string fname) {
	newFirstName = fname;
}

void LibraryUser::SetLastName(string lname) {
	newLastName = lname;
}

void LibraryUser::SetCheckoutCount(unsigned int booksOut) {
	newNumBooks = booksOut;
}

/*void LibraryUser::SetBookNumArray(string bookNums) {
}*/


/*
Add:
CheckOut() -> return bool - verifies item is not in array and adds it, if added returns true
CheckIn() -> return bool - verifies item is in array
HasCheckedOut() -> return bool - true if in array
Clear() - removes all data, ID = 0, names = "", array deleted
Destructor - clean up dynamic memory
ReadData() -> return bool
WriteData() -> return bool
*/