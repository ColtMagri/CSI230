/**
 * @file earth_utils.h
 * @brief Lab 10.2 Code
 * handles parsing a lat/long csv file and conversion of that file to kml format
 * @author Colt Magri
 * @credit Bilbo Baggins
 * @assigment Lab 10.2
 * @date 11/12/2020
*/

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * @brief process a country capital csv file
 * @date 11/12/2020
 * @return returns the number of records processed
 * @param inFile ifsteram to an operand and validated csv file
 * @param kmlFileName string containing the name of the kml file you wish to produce
 * @param logFile ofstream reference, validataion of thsi file is expected
*/
int processCSV(ifstream& inFile, string kmlFileName);

/**
 * @brief writes to a kml file a new placemark with passed in info
 * @date 11/12/2020
 * @return returns nothing
 * @param kmlFile the ofstream that is use to output
 * @param name the name of the placemakr
 * @param latitude latitude coordinates
 * @param longitude longitude coordinates
*/
void writePlacemark(ofstream& kmlFile, string name, string latitude, string longitude);

#endif