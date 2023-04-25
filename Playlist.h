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

//Playlist class to process the dataset, sorting the songs and print out the requested playlist
class Playlist
{
private :
    unordered_map<int, vector<string>> playList; // unordered_map to store the songs in the user's requested genre
    vector<int> sortedLevel; //vector to store the key of the unordered_map after sorting
    long long shellSortTime; // runtime for Shell Sort
    long long quickSortTime; // runtime for Quick Sort
public:
    int convertToInt(const string& str); //clean up numerical data from the CSV file
    void loadFile(string genre, string category); // store the song from the CSV file based on the genre, category
    void sortKey(); //sort the keys of the song stored in the map
    void printPlayList(int songCount, string sortedOption); // function to print the requested playlist
    string processString(const string input); // clean up string data from the CSV file
    void printTime(); //print the run time for two sorting algorithms
};


