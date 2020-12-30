/**
 * @file functions.h
 * @brief Header file for all the functions that are used in the compiler
 * @author Colt Magri
 * @assigment Final Project
 * @date 12/31/2020 - Due date extended due to mono sickness incomplete status
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>

//initCompile
//Initializes the compiler. It has one parameter, the filepath to the HISS code text file
void initCompile(string filePath);

//compText
//Compiles necessary code when the compiler sees a text block in the HISS text file
//Essentially writes out to the html and css files necessary text to work according to the HISS text file
//Has 8 parameters, which are the actual text to be displayed, the color, font, size, layout on the page, and then it's id number an the html and css file names
void compText(string text, string textColor, string textFont, int fontSize, string textLayout, int id, string htmlFile, string cssFile);

//compImage
//Compiles necessary code when the compiler sees an image block in the HISS text file
//Essentially writes out to the html and css files necessary text to work according to the HISS text file
//Has 7 parameters, which are the name of the image file, its layout on the page, it's width and height, it's id number and the html and css file anmes
void compImage(string imageName, string imageLayout, int imageW, int imageH, int id, string htmlFile, string cssFile);

#endif