/* Week 3 Task 1 - Program that prints words mirrored from a single sentence input, the complexity being O(1^n) as the function calls only a single copy of itself for every iteration */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string Mirroring(string& word, int count);

int main() {

	string wordListInput;
	string wordCount;

	// Getting the sentence and the number of words within it
	cout << "Please enter your list of words seperated by single spaces: " << endl;
	getline(cin, wordListInput);
	
	cout << endl << "Please enter the number of words in the sentence: " << endl;
	getline(cin, wordCount);

	//Creating Stringstream using the inputted sentence
	stringstream stringStream1(wordListInput);
	string word;
	vector<string> newList; // This is the vector that will be used to store the reversed words


	// Using the getline function with stringstream to get every word individually using the ' ' as a delimiter to indicate the end of the line
	while (getline(stringStream1, word, ' ')) { 
		word = Mirroring(word, 0);
		newList.push_back(word);

	}

	// Range based for loop, will iterate through every item in the vector and output the reversed words
	for (auto i : newList) {

		cout << i << ' ';

	}

	cout << endl;

	system("PAUSE");

	return 0;
}


/* This function is for mirroring an input word
   Input: string word - the word that needs to be mirrored
	      int count - This is a counter of how many times the word has gone through the recursive process, it is used to determine which set of 2 letters in the word need swapping in this recursive step
   
   Output: Returns the word with its letters swapped if the function determines that it has been fully mirrored, else it will recursively call itself again until that case is reached.

   Base Case: startpoint and endpoint become equal or if startpoint > endpoint 
*/

string Mirroring(string& word, int count) {

	//determines which 2 letters need swapping by adding the count to the start point of the word and subtracting it from the end point
	int startPoint = 0 + count;
	int endPoint = (word.length() - count) - 1;

	string newWord = word;
	char charstore;
	
	// Where the 2 letters in the word get swapped
	if (startPoint < endPoint) {


		charstore = newWord[startPoint];
		newWord[startPoint] = newWord[endPoint];
		newWord[endPoint] = charstore;

		count++;

		// Calls itself to check to see if the word has been completely mirrored, if yes it will return the word and if not it will repeat the process with the next letters
		newWord = Mirroring(newWord, count);
		
		return newWord;


	}

	else {
		return word;
	}

	
}