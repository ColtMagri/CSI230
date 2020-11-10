/*
Linux/Unix Lab 10.1
11/9/2020
Colt Magri

util.h
This file defines the functions that are later implimented in util.cpp and called in main.cpp
*/

#pragma once

#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

//This function takes in a vector of strings and will return a random element from said vector
string randomElement(vector<string> vect);

//This function takes in a vector of doubles and will return the sum of all doubles
double sum(vector<double> vect);

//This function takes in a vector of doubles and will return the average of all doubles
double average(vector<double> vect);

//This function takes in a vector of doubles and will return the lowest double from the vecotr
double lowest(vector<double> vect);

//This function takes in a string and will convert it to camel case format, returning the modified string
string camelCase(string oldString);