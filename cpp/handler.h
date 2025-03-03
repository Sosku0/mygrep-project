//
// Created by oskar on 03/03/2025.
//

#ifndef HANDLER_H
#define HANDLER_H
#include <string>
#include <vector>


void Search (std::string searchString, std::vector<std::string> linesToSearchFrom, std::vector<bool> &optionalSettings);
int ScanLine(std::string line, std::string searchString);

#endif //HANDLER_H
