/* Week 4 - Task 2 - Use a binary search to implement a guessing game to guess a number the user is thinking of between 1 and 20,000*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void numberGame(vector<int> inputArray);

int main() {

	// create the vector and fill it with numbers 0-20,000
	vector<int> searchVector;
	for (int i = 0; i <= 20000; i++) {
		searchVector.push_back(i);
	}

	cout << "This game will attempt to guess a number you think of between 1 and 20,000" << endl;

	//starts the game
	numberGame(searchVector);

	return 0;
}

/* This function takes a single int vector as input and will search through it with a binary search until the correct number is found*/
void numberGame(vector<int> inputArray) {

	string higherOrLower;
	auto vectorMiddle = inputArray.begin();
	advance(vectorMiddle, (inputArray.size() / 2));
	bool loopContinue = true;

	cout << "Is the number you're thinking of this: " << *vectorMiddle << endl;
	
	// while loop contains the componants of the binary search, kept in a while loop so anything that isnt the correct input will prompt the user to enter a correct input until they do so
	while (loopContinue) {

		cout << "Please enter 'h' if your number is higher, 'l' if you number is lower, or 'y' if it is correct" << endl;
		cin >> higherOrLower;

		//creates a new vector with the top half of the old vector in it using iterators pointing the the middle and end of the old vector
		if (higherOrLower == "h" | higherOrLower == "H") {

			vector<int> newVector(vectorMiddle, inputArray.end());
			numberGame(newVector);
			loopContinue = false;

		}
		//creates a new vector with the bottom half of the old vector in it using iterators pointing the the start and middle of the old vector
		else if (higherOrLower == "l" | higherOrLower == "L") {

			vector<int> newVector(inputArray.begin(), vectorMiddle);
			numberGame(newVector);
			loopContinue = false;

		}
		//will display a correct guess message and exit the game
		else if (higherOrLower == "y" | higherOrLower == "Y") {

			cout << "Horay, I guessed your number!" << endl;
			loopContinue = false;
			
			//remember to remove, non-complient with non-windows systems
			system("PAUSE");
		}
	}
}