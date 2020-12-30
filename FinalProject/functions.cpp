/**
 * @file functions.cpp
 * @brief Where all the functions.h functions are defined to be used properly and called in the compiler
 * @author Colt Magri
 * @assigment Final Project
 * @date 12/31/2020 - Due date extended due to mono sickness incomplete status
*/

#include "functions.h"

using namespace std;

void initCompile(string filePath)
{

    int lineCount = 0;

    ifstream inHISS;
    ofstream outHTML;
    ofstream outCSS;

    vector<int> paramregInt;
    vector<string> paramregString;

    inHISS.open(filePath);

    if (!inHISS) //checks if there was an error opening file, essentially checking if file exists
    {
        cout << "ERROR" << endl;
        inHISS.close();
    }
    else //If there's no error, we continue on to compile
    {
        string htmlFileName;
        string cssFileName;

        string tmpParamString;

        string inString;
        string parseWord;
        int charCount = 0;

        int idHandler = 0;

        while(getline(inHISS, inString)) //Goes through each line and finds the first cell of the lines block to determine what kind it is (example, either a text or image block)
        {
            if(inString[0] == '[')
            {
                charCount = 1;
                parseWord = "";

                while(inString[charCount] != ']' && inString[charCount] != '|')
                {
                    parseWord += inString[charCount];
                    charCount += 1;
                }

            }

            if(lineCount == 0) //Checks to see if it's the first line of the file. First line must be docs block for compiler to function
            {
                if(parseWord == "docs") //Checks to see if it is indeed docs block
                {
                    charCount = 6;
                    htmlFileName = "";
                    while(inString[charCount] != '|')
                    {
                        htmlFileName += inString[charCount];
                        charCount += 1;
                    }
                    //Now the html file name is found

                    charCount += 1;
                    cssFileName = "";
                    while(inString[charCount] != ']')
                    {
                        cssFileName += inString[charCount];
                        charCount += 1;
                    }
                    //Now the css file name is found

                    htmlFileName += ".html";
                    cssFileName += ".css";
                    //Adds important file type to the nams of the files

                    outHTML.open(htmlFileName);
                    outCSS.open(cssFileName);

                    //Here we start by adding some basic document setup info to the html output file
                    outHTML << "<!DOCTYPE html>" << endl;
                    outHTML << "<html>" << endl;
                    outHTML << endl;
                    outHTML << "<head>" << endl;
                    outHTML << "<link rel=\"stylesheet\" href=\"" << cssFileName << "\">" << endl;
                    outHTML << "</head>" << endl;
                    outHTML << "<body" << endl;

                    outHTML.close();
                    outCSS.close();

                    cout << "Initialzation successful, compiling into " << htmlFileName << " and " << cssFileName << endl;
                }
                else
                {
                    cout << "FATAL ERROR: docs block missing from line 0" << endl;
                    cout << "Program aborting..." << endl;
                    abort();
                    //Here, the program will abort if the first line is not a docs block
                    //The docs block must be first because it stores info for what the html and css files must be called for output
                }
                
            }
            else //Here is where we start compiling any blocks that are not docs blocks.
            {
                cout << "Compilling " << parseWord << "block..." << endl;
                paramregInt.clear();
                paramregString.clear();
                //Those two vectors that were just cleared store the paramters for the blocks to then be sent to the blocks compile function

                if(parseWord == "text")
                {

                    charCount = 6;
                    tmpParamString = "";
                    while(inString[charCount] != '|')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregString.push_back(tmpParamString);

                    charCount += 1;
                    tmpParamString = "";
                    while(inString[charCount] != '|')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregString.push_back(tmpParamString);

                    charCount += 1;
                    tmpParamString = "";
                    while(inString[charCount] != '|')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregString.push_back(tmpParamString);

                    charCount += 1;
                    tmpParamString = "";
                    while(inString[charCount] != '|')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregInt.push_back(stoi(tmpParamString));

                    charCount += 1;
                    tmpParamString = "";
                    while(inString[charCount] != ']')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregString.push_back(tmpParamString);

                    //What just happened above was parsing each cell of the block to get parameters
                    //Below is where those vectors and their entries (paramaters) get used as parameters for the text blocks compile function

                    compText(paramregString[0], paramregString[1], paramregString[2], paramregInt[0], paramregString[3], idHandler, htmlFileName, cssFileName);
                    idHandler += 1;
                }
                else if(parseWord == "image") //Same situation here as the text block, just for image blocks
                {
                    charCount = 7;
                    tmpParamString = "";
                    while(inString[charCount] != '|')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregString.push_back(tmpParamString);

                    charCount += 1;
                    tmpParamString = "";
                    while(inString[charCount] != '|')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregString.push_back(tmpParamString);

                    charCount += 1;
                    tmpParamString = "";
                    while(inString[charCount] != '|')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregInt.push_back(stoi(tmpParamString));

                    charCount += 1;
                    tmpParamString = "";
                    while(inString[charCount] != ']')
                    {
                        tmpParamString += inString[charCount];
                        charCount += 1;
                    }
                    paramregInt.push_back(stoi(tmpParamString));

                    compImage(paramregString[0], paramregString[1], paramregInt[0], paramregInt[1], idHandler, htmlFileName, cssFileName);
                    idHandler += 1;
                }
            }
            
            lineCount += 1;
        }
        //Once everything has been parsed and compiled and added, we close off the html file and the HISS file
        outHTML.open(htmlFileName, ios::app);
        outHTML << "</body>" << endl;
        outHTML << "</html>" << endl;
        outHTML.close();

        inHISS.close();

        cout << "Compiler has finished..." << endl;
    }
}

//Here is where text is compiled
void compText(string text, string textColor, string textFont, int fontSize, string textLayout, int id, string htmlFile, string cssFile)
{
    ofstream outHTML;
    ofstream outCSS;

    //Add the html code required for this block
    outHTML.open(htmlFile, ios::app);
    outHTML << "<p id=\"text" << id << "\">" << text << "</p>" << endl;
    outHTML.close();

    //Add the css code required for this block
    outCSS.open(cssFile, ios::app);
    outCSS << "#text" << id << " {" << endl;
    outCSS << "color: " << textColor << ";" << endl;
    outCSS << "font-family: " << textFont << ";" << endl;
    outCSS << "font-size: " << fontSize << "px;" << endl;
    outCSS << "text-align: " << textLayout << ";" << endl;
    outCSS << "}" << endl;
    outCSS << endl;
    outCSS.close();
}

//Here is where images are compiled
void compImage(string imageName, string imageLayout, int imageW, int imageH, int id, string htmlFile, string cssFile)
{
    ofstream outHTML;
    ofstream outCSS;

    //Add necessary html code for images
    outHTML.open(htmlFile, ios::app);
    outHTML << "<img id=\"image" << id << "\" src=\"" << imageName << "\">" << endl;
    outHTML.close();

    //Add the css styling that the image block provided
    outCSS.open(cssFile, ios::app);
    outCSS << "#image" << id << " {" << endl;
    outCSS << "text-align: " << imageLayout << ";" << endl;
    outCSS << "width: " << imageW << "px;" << endl;
    outCSS << "height: " << imageH << "px;" << endl;
    outCSS << "}" << endl;
    outCSS << endl;
    outCSS.close();
}