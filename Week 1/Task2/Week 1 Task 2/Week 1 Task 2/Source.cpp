
#include "stdafx.h"
#include "Source.h"

int main() {

	bool loopContinue = true;
	string inputnumber = "000";

	while (loopContinue) {

		cout << "Please enter your 3 digit number: " << endl;
		cin >> inputnumber;
	
		if (inputnumber.size() == 3) { // makes sure the inputted string is 3 chars long

			loopContinue = false;

		}
	}


	isArmstrong(inputnumber);


	system("PAUSE");

	return 0;
	
}

/* Function to determine if an inputted string is an armstrong number or not
input: takes 1 numerical string
output: True if it is an armstrong number or False if not*/

bool isArmstrong(string inputNumber) {
	
	stringstream intInput(inputNumber); 
	int inputtedInt; 
	intInput >> inputtedInt; // inserting the string number into an int using a string stream, can also be done with stoi

	char firstcubechar = inputNumber[0]; //creating the 3 numbers to cube from the input
	char secondcubechar = inputNumber[1];
	char thirdcubechar = inputNumber[2];

	int firstcube = firstcubechar - '0'; // minus '0' unix number from a char to get an integer compatible value
	int secondcube = secondcubechar - '0';
	int thirdcube = thirdcubechar - '0';


	firstcube = (firstcube * firstcube) * firstcube; //cubing 3 numbers created earlier
	secondcube = (secondcube * secondcube) * secondcube;
	thirdcube = (thirdcube * thirdcube) * thirdcube;

	if (firstcube + secondcube + thirdcube == inputtedInt) { //comparison with original input
		cout << "True" << endl;
		return true;
	}
	else {
		cout << "False" << endl;
		return false;
	}



}
