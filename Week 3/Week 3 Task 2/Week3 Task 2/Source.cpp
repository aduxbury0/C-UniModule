/* Week 3 Task 2 - Creating a recursive linear search over an array of numbers - O(n^2) complexitity  */

#include "stdafx.h"
#include "Source.h"

int main() {

	cout << "Please enter a list of numbers, you can enter as many as you want" << endl << "when you are finished please enter F and press enter" << endl;

	string inputNumber;
	vector<int> numberList;
	int castedInput;
	bool numberInputContinue = true;

	while (numberInputContinue) {

		cin >> inputNumber;
		
		if (inputNumber == "f" | inputNumber == "F") {

			numberInputContinue = false;
			cout << "Ending input" << endl;
		}
		else if(isNumber(inputNumber)) {

			castedInput = stoi(inputNumber);
			numberList.push_back(castedInput);
		}
		else {

			cout << "Please enter a valid number or the f to exit command" << endl;
		}
	}
	
	numberInputContinue = true;

	string stringNumberToFind;
	int numberToFind;
	cout << "Please enter the number you wish to find in the list of numbers" << endl << " This will return True if present or False if not" << endl;
	
	while (numberInputContinue) {
		
		cin >> stringNumberToFind;

		if (isNumber(stringNumberToFind)) {

			numberToFind = stoi(stringNumberToFind);
			numberInputContinue = false;
		}
		else {

			cout << "Plese enter an actual number" << endl;

		}
	}
	
	
	int vectorSize = numberList.size();

	bool finalResult = ListCheck(numberList, numberToFind, 0, vectorSize);

	if (finalResult == 1) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not Found" << endl;
	}

	system("PAUSE");


	return 0;
}

bool ListCheck(vector<int> listOfNumbers, int targetNumber, int currentPoint, int vectorSize) {

	if (currentPoint > (vectorSize-1)) {
		return false;
	}
	
	else if (listOfNumbers[currentPoint] == targetNumber) {
		return true;
	}
	
	else {
		
		bool isIn;
		currentPoint = currentPoint + 1;
		isIn = ListCheck(listOfNumbers, targetNumber, currentPoint, vectorSize);

		return isIn;
	}
}

bool isNumber(string inputtedNumber) {

	if (inputtedNumber[0] == '1' | inputtedNumber[0] == '2' | inputtedNumber[0] == '3' | inputtedNumber[0] == '4' 
		| inputtedNumber[0] == '5' | inputtedNumber[0] == '6' | inputtedNumber[0] == '7' | inputtedNumber[0] == '8' | inputtedNumber[0] == '9') {

		return true;

	}
	
	else {

		return false;
	}
}