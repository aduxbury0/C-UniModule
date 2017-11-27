/*

Task 1: Write a method that combines two strings, by taking one character from the first string, then one from
the second string and so on. Once one string has no characters left it should carry on with the other
string.

*/

#include <iostream>
#include <string>

using namespace std;

int main() {

	string word1 = "";
	string word2 = "";
	string wordHolding = "";
	int length1 = 0;
	int length2 = 0;
	string newWord = "";


	cout << "Please input the first string: ";
	cin >> word1;
	cout << endl << "Please input the second string: ";
	cin >> word2;

	//sets the word length variables

	length1 = word1.length();
	length2 = word2.length();

	//Sets word2 to be the longest string from the 2 inputted

	if (length1 > length2) {
		wordHolding = word2;
		word2 = word1;
		word1 = wordHolding;
		wordHolding.clear();
		length1 = word1.length();
		length2 = word2.length();
	}

	//For loop to adds alternate letters up to the end of the shortest string

	for (int n = 0; n<length1; n++) {

		newWord = newWord + word1[n] + word2[n];

	}

	//For loop that adds the remaining letters from the largest string

	for (int n = 0 + length1; n < length2; n++) {

		newWord = newWord + word2[n];

	}

	cout << endl << newWord << endl << endl;

	system("pause");

	return 0;
}