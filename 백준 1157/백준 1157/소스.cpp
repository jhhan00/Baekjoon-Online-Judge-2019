#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alphabet[26] = { 0, };
int character[26];

int main() {
	string word;
	char c;
	cin >> word;
	int len = word.length();
	for (int i = 0; i < len; i++) {
		c = word[i];
		if (c >= 97 && c <= 122)
			c -= 32;
		alphabet[c - 65]++;
	}/*
	int a;
	for (a = 0; a < 26; a++)
		character[a] = alphabet[a];
	sort(character, character + 26);
	if (character[25] == character[24]) {
		cout << "?" << endl;
		return 0;
	}
	else {
		a = 0;
		while (a < 26) {
			if (alphabet[a] == character[25])
				break;
			a++;
		}
		cout << char(a+65) << endl;
	}*/
	int i, max; i = max = 0;
	int isMax = 0;
	while (i < 26) {
		if (alphabet[i] > alphabet[max]) {
			max = i;
			isMax = 0;
		}
		else if (alphabet[i] == alphabet[max] && i != max) 
			isMax = 1;		
		i++;
	}
	if (isMax)
		cout << "?" << endl;
	else
		cout << char(max+65) << endl;
}