/*Week 2 Task 1B - Creating a function from the provided psuedocode - Alex Duxbury*/


#include "stdafx.h"
#include "Source.h"


int main() {

	vector<int> polynomial1 = { 3,1,9 };
	vector<int> polynomial2 = { 2,1,2,1 };
	int degree1 = polynomial1.size() - 1;
	int degree2 = polynomial2.size() - 1;

	vector<int> resultarray = PolyMulti(degree1, degree2, polynomial1, polynomial2);
	int resultantDegree = (resultarray.size() - 1);
	
	cout << "The resultant multiplication of polynomial : "; // Code from here is just printing out the result in an easy to understand format

	for (int i = 0; i < polynomial1.size(); i++) {

		cout << polynomial1[i] << " " ;

	}

	cout << "with polynomial: ";

	for (int i = 0; i < polynomial2.size(); i++) {

			cout << polynomial2[i] << " ";

	}

	cout << endl << "is: ";


	for (int i = 0; i < resultarray.size(); i++) {

		cout << resultarray[i] << " ";
	}

	cout << "with a degree of: " << resultantDegree << endl;

	system("PAUSE");

	return 0;
}

/* Function for multiplying 2 polunomials together -
   Input: 2 ints and 2 int Vectors, where the first int and first vector are the first polynomial + its degree (m and P1) and the second is the second Polynomial + its degree (n and P2)
   Output: Outputs a vector of ints containing the result of the multiplication called Res
*/

vector<int> PolyMulti(int m, int n, vector<int> P1, vector<int> P2) {

	vector<int> Res(m + n + 1, 0); // Initialising the vector with its size and then what to fill all the space with.

	for (int i = 0; i <= m ; i++) { // set of nested loops to multiply each element within vector P1 with every element within vector P2
		
		for (int j = 0; j <= n; j++) {

			Res[i + j] = Res[i + j] + (P1[i] * P2[j]);

		}
	}

	return Res;
}