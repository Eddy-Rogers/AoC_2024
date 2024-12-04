//
// Created by Eddy on 12/3/2024.
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#include "Functions.h"
using namespace std;

bool comp(int a, int b) {
    return a >= b;
}

void BuildLists(vector<int>* c1, vector<int>* c2, const string line) {
    // Take each line, split into two numbers
    string str1 = line.substr(0,line.find(' '));
    string str2 = line.substr(line.find(' ') + 2, line.length());

    // Use stoi function to turn into int, push onto vector
    int num1 = stoi(str1);
    int num2 = stoi(str2);

    c1->push_back(num1);
    c2->push_back(num2);
}

int Process_Day1_File() {
    ifstream inputfile;
    inputfile.open("input.txt");

    if(inputfile.fail()) {
        cerr << "Failed to open file";
        exit(1);
    }

    vector<int> c1;
    vector<int> c2;

    while (!inputfile.eof()) {
        char line[50];
        inputfile.getline(line, 50);
        BuildLists(&c1, &c2, string(line));
    }

    sort(c1.begin(), c1.end(), comp);
    sort(c2.begin(), c2.end(), comp);

    int ptr = 0;
    int ans = 0;
    while(ptr < c1.size()) {
        ans += abs(c1[ptr] - c2[ptr]);
        ptr++;
    }

    return ans;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.

