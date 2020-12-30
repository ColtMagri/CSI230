/**
 * @file main.cpp
 * @brief The driver for the program, calls functions for the compiler
 * @author Colt Magri
 * @credit https://theboostcpplibraries.com/boost.program_options#ex.program_options_01
 * @assigment Final Project
 * @date 12/31/2020 - Due date extended due to mono sickness incomplete status
*/

#include <boost/program_options.hpp>
#include <boost/date_time.hpp>
#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

using namespace boost::program_options;
using namespace boost::gregorian;

int main(int argc, const char *argv[])
{
  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help", "Lists the help menu. For code documentation, use the docs command")
      ("docs", "Lists out documentation on the language")
      ("compile", value<string>()->default_value("NULLNOFILENAMEGIVEN") ,"Compiles a file into an html and css file. Pass in the name of the file to be compiled. Using quation marks allows for spaces in file names");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      cout << desc << endl;
    else if (vm.count("docs"))
      cout << "For documentation, see hiss_docs.txt" << endl;
    else if (vm.count("compile"))
      initCompile(vm["compile"].as<string>());
      
  }
  catch (const error &ex)
  {
    cerr << ex.what() << '\n';
  }
}