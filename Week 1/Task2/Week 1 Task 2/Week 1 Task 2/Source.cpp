/* This is the second part of week 1's intermediate and beginner tasks, creating a program that will let the user know if the number they have entered is an armstrong
number with a simple true or false return statement.*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

	string inputnumber = "000"; 
	cout << "Please enter your 3 digit number: " << endl;
	cin >> inputnumber;

	stringstream intInput(inputnumber);
	int inputtedInt;
	intInput >> inputtedInt;

	char firstcubechar = inputnumber[0];
	char secondcubechar = inputnumber[1];
	char thirdcubechar = inputnumber[2];

	int firstcube = firstcubechar - '0';
	int secondcube = secondcubechar - '0';
	int thirdcube = thirdcubechar - '0';

	firstcube = (firstcube * firstcube) * firstcube;
	secondcube = (secondcube * secondcube) * secondcube;
	thirdcube = (thirdcube * thirdcube) * thirdcube;

	if (firstcube + secondcube + thirdcube == inputtedInt) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	system("PAUSE");

	return 0;
	
}

