#include<iostream>
#include <unordered_map>
#include<vector>
#include<algorithm>
#include "assert.h"
using namespace std;

string convert(string s, int numRows) {
	if (numRows < 2)
		return s;

	string converted = "";
	int step = numRows + numRows - 2;

	for (size_t j = 0; j < s.size(); j += step)
	{
		converted += s[j];
	}
	
	for (size_t i = 1; i < step - 1; i++)
	{
		for (size_t j = i; j < s.size(); j += numRows)
		{
			converted += s[j];
		}
	}

	for (size_t j = numRows - 1; j < s.size(); j += step)
	{
		converted += s[j];
	}

	return converted;
}

int main() {
	cout << convert("PAYPALISHIRING", 1) << endl;
	cout << convert("PAYPALISHIRING", 2) << endl;
	cout << convert("PAYPALISHIRING", 3) << endl;
	cout << convert("PAYPALISHIRING", 4) << endl;
	cout << convert("PAYPALISHIRING", 5) << endl;
	
	assert(convert("PAYPALISHIRING", 1) == "PAYPALISHIRING");
	assert(convert("PAYPALISHIRING", 2) == "PYAIHRNAPLSIIG");
	assert(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
	assert(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
	assert(convert("PAYPALISHIRING", 5) == "PHASIYIRPLIGAN");
}