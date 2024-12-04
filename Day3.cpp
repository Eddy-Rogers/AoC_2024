//
// Created by Eddy on 12/3/2024.
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include "Functions.h"
#include <regex>

using namespace std;

int mult(string match) {
    int result = 0;
    int num1 = stoi(match.substr(match.find("(") + 1, match.find(",")));
    int num2 = stoi(match.substr(match.find(",") + 1, match.find(")")));
    return num1 * num2;
}

int Process_Day3_File() {
    ifstream inputfile;
    inputfile.open("day3input.txt");

    if (inputfile.fail()) {
        cerr << "Failed to open file";
        exit(1);
    }

    stringstream buffer;
    buffer << inputfile.rdbuf();

    string remaining = buffer.str();

    const regex regex(R"(mul\([0-9]*,[0-9]*\))");

    int ans = 0;

    for (std::smatch sm; regex_search(remaining, sm, regex);)
    {
        ans += mult(sm.str());
        remaining = sm.suffix();
    }

    return ans;
}
