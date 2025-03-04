//
// Created by oskar on 03/03/2025.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "loader.h"

using namespace std;

vector<string> loadFile(const string& filename) {
  cout << "Loading file: " << filename << endl;
  try
  {
    vector<string> lines;

    fstream file(filename);

    if (file)
    {
      //cout << "DEBUG: File opened successfully" << endl;
    } else
    {
      //cout << "DEBUG: File could not be opened" << endl;
      throw runtime_error("Could not open file!");
    }

    string line;
    while (getline(file, line))
    {
      lines.push_back(line);
    }
    cout << "Loaded " << lines.size() << " lines" << endl;

    file.close();

    if (lines.empty())
    {
      throw runtime_error("File is empty! " + filename);
    }

    return lines;

  } catch ( const exception& e)
  {
    cout << e.what() << endl;
    return {};
  }
}