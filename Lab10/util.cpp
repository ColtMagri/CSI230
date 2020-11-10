/*
Linux/Unix Lab 10.1
11/9/2020
Colt Magri

util.cpp
This file impliments the functions defined in util.h that are then called in main.cpp
*/

#include "util.h"
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

string randomElement(vector<string> vect)
{
	unsigned int theSeed = (unsigned int)time(NULL); //Initializes the integer variable theSeed with the use of time
	srand(theSeed); //Randomizes using the seed created before

	int low = 0; //Sets an amount for the lowest number the randomizer can pick
	int high = 4; // Sets an amount for the highest number the randomizer can pick
	int range = (high - low) + 1; //Creates a range from the low and high variables

	return(vect[(rand() % range) + low]); //Returns the random element from the vector
}

double sum(vector<double> vect)
{
	double result = 0; //Sets a value for the final result to 0

	for (int i = 0; i < vect.size(); i++) { //Will repeat for every element in the vector
		result += vect[i]; //Adds each element to result
	}

	return result; //Returns the final result
}

double average(vector<double> vect)
{
	double result = 0; //Sets a value for the final result to 0

	for (int i = 0; i < vect.size(); i++) { //Will repeat for every element in the vector
		result += vect[i]; //Adds each element to result
	}

	result = result / vect.size(); //Result is divided by the number of elements in the vector, creating average

	return result; //Returns the final result
}

double lowest(vector<double> vect)
{
	double smallest = vect[0]; //Creates a double variable set to the first element of the vector as a starting point for comparison

	for (int i = 0; i < vect.size(); i++) { //Will repeat for every element in the vector
		if (vect[i] < smallest) //Checks to see if teh current element being compared is smaller than the so far smallest found element
		{
			smallest = vect[i]; //If it is, it sets smallest to the newly found smallest element. If not, keeps looping
		}
	}

	return smallest; //Returns the smallest element from the vector
}

string camelCase(string oldString)
{
	bool lowOrUp = 0; //Essentially a boolean switch to flip between upper and lower case to create camel case format
	char temp; //A temp variable to store the char being modified in the loop

	oldString.erase(remove(oldString.begin(), oldString.end(), ' '), oldString.end()); //Uses the erase and remove functions built into strings to remove all spaces from the string

	for (int i = 0; i < oldString.length(); i++) { //Will repeat for the length of the string (ie for every character)

		if (lowOrUp == 0) //If lowOrUp is 0, set the current char to lower case
		{
			temp = tolower(oldString[i]); //Set the temp char to the current char in the loop from the string after being changed to lowercase from tolower
			oldString[i] = temp; //Set the current char in the loop from the string to the modified char
			lowOrUp = 1; //Set lowOrUp to now convert to uppercase for next passthrough in the loop
		}
		else //If lowOrUp is 1, set the current char to upper case
		{
			temp = toupper(oldString[i]); //Set the temp char to the current char in the loop from the string after being changed to uppercase from toupper
			oldString[i] = temp; //Set the current char in the loop from the string to the modified char
			lowOrUp = 0; //Set lowOrUp to now convert to uppercase for next passthrough in the loop
		}
	}

	return oldString; //Return the modified string
}
