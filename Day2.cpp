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

void Build_Lists_Day2(vector<int> *c1, vector<int> *c2, const string line) {
    string str1 = line.substr(0, line.find(' '));
    string str2 = line.substr(line.find(' ') + 2, line.length());

    int num1 = stoi(str1);
    int num2 = stoi(str2);

    c1->push_back(num1);
    c2->push_back(num2);
}

int Process_Day2_File() {
    ifstream inputfile;
    inputfile.open("input.txt");

    if (inputfile.fail()) {
        cerr << "Failed to open file";
        exit(1);
    }

    vector<int> c1;
    vector<int> c2;

    while (!inputfile.eof()) {
        char line[50];
        inputfile.getline(line, 50);
        Build_Lists_Day2(&c1, &c2, string(line));
    }

    map<int, int> c2frequencymap;

    // Build map of numbers to times found using c2
    int ptr = 0;
    while (ptr < c2.size()) {
        if (c2frequencymap.find(c2[ptr]) == c2frequencymap.end()) {
            c2frequencymap[c2[ptr]] = 1;
        } else {
            c2frequencymap[c2[ptr]]++;
        }
        ptr++;
    }

    ptr = 0;
    int ans = 0;

    // Use map, multiply number with frequency found in map
    while (ptr < c1.size()) {
        ans += c1[ptr] * c2frequencymap[c1[ptr]];
        ptr++;
    }

    return ans;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
