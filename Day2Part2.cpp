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

using namespace std;

int Get_Number_2(string line) {
    return stoi(line.substr(0, line.find(" ")));
}

string pop_2(string line) {
    // Check if this is the last number in the line
    if(line.find(" ") == std::string::npos) return "";
    else return line.substr(line.find(" ") + 1);
}

bool Determine_Safe_2(string line) {
    bool safe = true;

    int previous = Get_Number_2(line);
    line = pop_2(line);
    int current = Get_Number_2(line);
    line = pop_2(line);

    const bool increasing = current > previous;

    if(previous == current) safe = false;

    if(increasing) {
        if(current - previous > 3) {
            safe = false;
        }
    }
    else
    {
        if(current - previous < -3) {
            safe = false;
        }
    }

    while(line.size() > 0) {
        previous = current;
        current = Get_Number_2(line);
        line = pop_2(line);

        if(previous == current) {
            safe = false;
        }

        if(increasing) {
            if(current - previous > 3 || current - previous < 0) {
                safe = false;
            }
        }
        else {
            if(current - previous < -3 || current - previous > 0) {
                safe = false;
            }
        }
    }

    return safe;
}

int Process_Day2Part2_File() {
    ifstream inputfile;
    inputfile.open("day2input.txt");

    if (inputfile.fail()) {
        cerr << "Failed to open file";
        exit(1);
    }

    int ans = 0;

    while (!inputfile.eof()) {
        char line[50];
        inputfile.getline(line, 50);
        ans += Determine_Safe_2(string(line)) ? 1 : 0;
    }

    return ans;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
