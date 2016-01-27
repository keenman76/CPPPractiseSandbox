// 2016-01-15-Basic1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const string kFilename = "c:\\temp\\one.txt";

void fizzbuzz(int n = 60) {
	for (int i = 0; i < n; i++) {
		if ((i % 5) == 0 && (i % 3) == 0)
			cout << i << ": fizzbuzz\n";
		else if ((i % 5) == 0)
			cout << i << ": fizz\n";
		else if ((i % 3) == 0)
			cout << i << ": buzz\n";			
	}

	return;
}

void printSingleLineName(HANDLE hConsole, int msSleep, int colour, int y) {
	SetConsoleTextAttribute(hConsole, colour);
	cout << std::string(y, ' ') << "Keenan\n";
	Sleep(msSleep);		
}

void printName(int n = 15, int msSleep = 100)
{
	HANDLE  hConsole;
	int colour = 0;
	int colourInc = 255 / n;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < k; i++) {
			printSingleLineName(hConsole, msSleep, colour, i);
			colour += colourInc;
		}
		for (int i = 0; i < k; i++) {
			printSingleLineName(hConsole, msSleep, colour, k - i);
			colour += colourInc;
		}
	}
}

void writeFibonacciToFile(int n = 50, string filename = kFilename)
{
	if (filename == "")
		filename = kFilename;

	fstream file(filename);

	int prev = 1;
	int curr = 1;

	if (n > 0)
		file << prev << "\n";

	if (n > 1)
		file << curr << "\n";

	for (int i = 0; i < n - 2; i++) {
		int temp = prev;
		prev = curr;
		curr = curr + temp;
		file << curr << "\n";
	}
	file.close();
}

void outputFileToConsole(string filename = kFilename) {
	if (filename == "")
		filename = kFilename;

	string line;
	fstream file(filename);	
	if (file.is_open()) 
	{
		while (getline(file, line)) 
		{
			cout << line << endl;
		}
	}
	file.close();
}

// A function which, given a char array and two ints, will return a string * which holds the section between the two ints.Return the null pointer if it’s not possible.
string *substr(char arr[], int start, int stop) {
	if (stop < start + 1 || start < 0 || stop < 0)
		return NULL;
	
	string *substr = new string;
	for (int i = start; i < stop; i++) {
		if (!arr[i])
			return NULL;
		*substr += arr[i];
	}

	return substr;
}

int longestGap(int input) {
	int maxCurrGap = 0;
	int currGap = 0;
	bool isInGap = false;
	int currDigit = 0;

	// find first 1
	while (input > 0 && input % 2 == 0)
		input /= 2;

	// iterate through each number of input finding gaps
	while (input > 0) {
		currDigit = input % 2;
		if (currDigit == 1) {
			if (currGap > maxCurrGap) maxCurrGap = currGap;
			currGap = 0;
		}
		else { // currDigit == 0
			currGap++;
		}
		input /= 2;
	}

	return maxCurrGap;
}

string convertIntToBoolString(int i) {
	string output;
	while (i > 0) {
		output = (i % 2 ? '1' : '0') + output;
		i /= 2;
	}
	return output;
}

int main(int argc, int* argv)
{
	// fizzbuzz(-3);	
	// printName();
	// writeFibonacciToFile(10);
	// outputFileToConsole("");
	// cout << *substr("Keenan was here", 0, 6) << endl;
	// cout << *substr("Keenan was here", 7, 10) << endl;
	
	int i = 513;
	cout << "Enter a number:";
	cin >> i;
	cout << "bool:" << convertIntToBoolString(i) << endl;
	cout << "longest gap of " << i << ": " << longestGap(i) << endl;
    return 0;
}
