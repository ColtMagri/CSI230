/*
Linux/Unix Lab 10.1
11/9/2020
Colt Magri

main.cpp
This file is the driver for the program. It creates the two vectors and the string to be used
with the functions defined in util.h and implimented in util.cpp
*/

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

int main()
{
	string camelString = "This Should Be Camel Cased"; //Creating a string to be modified to camelcase format later

	vector<string> vectString; //Initializing a vector with five string values
	vectString.push_back("String One");
	vectString.push_back("String Two");
	vectString.push_back("String Three");
	vectString.push_back("String Four");
	vectString.push_back("String Five");

	vector<double> vectDouble; //Initializing a vector with five double values
	vectDouble.push_back(1.1);
	vectDouble.push_back(2.2);
	vectDouble.push_back(3.3);
	vectDouble.push_back(4.4);
	vectDouble.push_back(5.5);

	cout << "Running Random Element: " << randomElement(vectString) << endl; //Runs the randomElement function with string vector

	cout << "Running Sum: " << sum(vectDouble) << endl; //Runs the sum function with double vector

	cout << "Running Average: " << average(vectDouble) << endl; //Runs the average function with double vector

	cout << "Running Lowest: " << lowest(vectDouble) << endl; //Runs the lowest function with double vector

	cout << "Running Camel Case: " << camelCase(camelString) << endl; //Runs the camelCase function with the string initialized before

	cin.get(); //Waits for user input before closing program. Mostly so I can screenshot results :)
	return 0; //Once input is given, exit program with 0 (closes program)
}