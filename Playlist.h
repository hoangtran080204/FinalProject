//
// Created by Hoang Tran on 4/21/2023.
//
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Sorting.h"
using namespace std;


class Playlist
{
private :
    unordered_map<int, vector<string>> playList;
    vector<int> sortedLevel;
    long long shellSortTime;
    long long quickSortTime;
public:
    int convertToInt(const string& str);
    void loadFile(string genre, string category);
    void sortKey();
    void printPlayList(int songCount, string sortedOption);
    string processString(const string input);
    void printTime();
};


