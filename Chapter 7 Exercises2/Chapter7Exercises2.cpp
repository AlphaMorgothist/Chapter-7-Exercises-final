// Chapter7Exercises2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string stringF();
void ex1();
void ex2();
void ex3();
string askText(string prompt);
int askNumber(string prompt);
void tellStory(string ptrN, string noun, int number, string bodyPart, string verb);

int main()
{
	int choice;
	do {
		enum { point2point = 1, rWriteLib, codeQs };
		cout << "\n\n\t\t\tChapter 7 Exercises\n" << endl;
		cout << "\nPlease select from the following: " << endl;
		cout << "\n1: [Exercises 7.1] Pointer2Pointer" << endl;
		cout << "2: [Exercises 7.2] Mad Lib Rewrite" << endl;
		cout << "3: [Exercises 7.3] Q&A" << endl;
		cout << "4: Quit" << endl;
		cout << "\nSelection: ";
		cin >> choice;
		system("CLS");

		switch (choice) {
		case point2point: {
			ex1();
		}break;
		case rWriteLib: {
			ex2();
		}break;
		case codeQs: {
			ex3();
		}
		}
	} while (choice != 4);
	return 0;
}

string stringF()
{
	string text = "This is a string of text from a function";
	return text;
}

void ex1()
{
	string p = stringF();
	string *ptr = &p;
	cout << *ptr << " dereferenced by a pointer" << endl;
	string &ptr2 = *ptr;
	cin.get();
	cin.ignore();
	cout << ptr2 << " dereferenced by a pointer pointing at a pointer" << endl;
	cin.get();
	cin.ignore();
	cout << "The size of the pointer is: " << ptr2.size() << endl;
	cin.get();
	cin.ignore();
	system("CLS");
}

void ex2() {
	cout << "Welcome to Mad Lib.\n\n";
	cout << "Answer the following questions to help create a new story.\n";

	string name = askText("Please enter a name: ");
	string *ptrN = &name;
	string noun = askText("Please enter a plural noun: ");
	string *ptrNo = &noun;
	int number = askNumber("Please enter a number: ");
	int *ptrAN = &number;
	string bodyPart = askText("Please enter a body part: ");
	string *ptrBP = &bodyPart;
	string verb = askText("Please enter a verb: ");
	string *ptrV = &verb;

	tellStory(*ptrN, *ptrNo, *ptrAN, *ptrBP, *ptrV);

}

void ex3() {
	int a = 10;
	int &b = a;
	int *c = &b;

	cout << &a << endl;
	cout << &b << endl;
	cout << &(*c) << endl;
	cout << "\nAll three addresses are the same.\nThe first line outputs the address of the int 'a'.\nThe second line outputs the address of 'b' which was defined as 'a'";
	cout << "\nThe third line is a pointer to 'c' which was set to the address of 'b', which is the address of 'a'";
	cin.ignore();
}

string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}

void tellStory(string ptrN, string noun, int number, string bodyPart, string verb)
{
	cout << "\nHere's your story:\n";
	cout << "The famous explorer ";
	cout << ptrN;
	cout << " had nearly given up a life-long quest to find\n";
	cout << "The Lost City of ";
	cout << noun;
	cout << " when one day, the ";
	cout << noun;
	cout << " found the explorer.\n";
	cout << "Surrounded by ";
	cout << number;
	cout << " " << noun;
	cout << ", a tear came to ";
	cout << ptrN << "'s ";
	cout << bodyPart << ".\n";
	cout << "After all this time, the quest was finally over. ";
	cout << "And then, the ";
	cout << noun << "\n";
	cout << "promptly devoured ";
	cout << ptrN << ". ";

	cout << "The moral of the story? Be careful what you ";
	cout << verb;
	cout << " for.";
}
