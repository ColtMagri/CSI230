/**
 * @file logger.h
 * @brief Lab 10.2 Code
 * handles the declaration of all logging functionality
 * @author Colt Magri
 * @credit Bilbo Baggins
 * @assigment Lab 10.2
 * @date 11/12/2020
*/

#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;

/**
 * @brief creates a discrete syslog message
 * @date 11/12/2020
 * @return returns a boolean indicating the message was written ok
 * @param msg string containing syslog message
 * @param logFile ofstream reference, validation of this file is expected
*/

bool log(string msg, string programName, ofstream& logFile);
#endif