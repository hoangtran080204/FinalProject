//
// Created by Hoang Tran on 4/21/2023.
//

#include "Playlist.h"



int Playlist::convertToInt(const string &str)
{
    try {
        return stoi(str);
    }
    catch (const invalid_argument& e) {
        // If stoi throws an invalid_argument exception,
        // return -1 to indicate that the conversion failed
        return -1;
    }
}

string Playlist::processString(const string input)
{
    string output = input;
    // remove all quotation marks
    output.erase(std::remove(output.begin(), output.end(), '\"'), output.end());

    // check if there is an extra open bracket in the string and append closing bracket for it

    int open_count = std::count(output.begin(), output.end(), '(');
    int closing_count = std::count(output.begin(), output.end(), ')');
    if (open_count == 1 && closing_count == 0) {
        // append a closing bracket at the end of the string
        output += ')';
    }


    return output;
}



void Playlist::loadFile(string genre, string category)
{
    playList.clear();
    std::ifstream file("SpotifyFeatures.csv");
    // Read the CSV file row by row and split each row into columns
    std::string line;
    std::getline(file, line); // skip the first line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }
        if(columns[0] == genre){

            // Add the fourth column as key and second as value
            int level;
            if(category == "Popularity"){
                level = convertToInt(columns[4]);
            }else if(category == "Acousticness"){
                level = convertToInt(columns[5]);
            }else if(category == "Danceability"){
                level = convertToInt(columns[6]);
            }else if(category == "Energy"){
                level = convertToInt(columns[8]);
            }
            string song = processString(columns[2]);
            if(level != -1){
                if(playList.find(level) == playList.end()){
                    vector<string> element;
                    element.push_back(song);
                    playList[level] = element;
                }else{
                    playList[level].push_back(song);
                }
            }

        }

    }

}

void Playlist::sortKey()
{
    sortedLevel.clear();

    vector<int> keys; // used for shellSort
    for(const auto pair: playList){
        keys.push_back(pair.first);
    }
    vector<int> temporaryKeys;
    temporaryKeys = keys; // used for quicksort

    auto start = chrono::high_resolution_clock::now();
    quickSort(temporaryKeys, 0, temporaryKeys.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    this->quickSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // runtime for ShellSort

    start = chrono::high_resolution_clock::now();
    shellSort(keys);
    end = chrono::high_resolution_clock::now();
    this->shellSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // runtime for QuickSort

    this->sortedLevel = keys; // can set the final sortedKeys to either shellSort or quickSort
}

void Playlist::printPlayList(int songCount, string sortedOption)
{
    int count = 1;
    if(sortedOption == "U"){
        for(int level: sortedLevel){
            for(string song: playList[level])
            {
                if (count > songCount) {
                    break; // exit the inner loop
                }
                cout << count << ". " << song << endl;
                count++;
            }
            if (count > songCount) {
                break; // exit the outer loop
            }
        }
    }else{
        for(auto it = sortedLevel.rbegin(); it != sortedLevel.rend(); ++it){
            for(string song: playList[*it])
            {
                if (count > songCount) {
                    break; // exit the inner loop
                }
                cout << count << ". " << song << endl;
                count++;
            }
            if (count > songCount) {
                break; // exit the outer loop
            }
        }
    }



}

void Playlist::printTime()
{
    cout<< " " << endl;
    cout<<"Sorting time for Shell Sort: " << this->shellSortTime <<" nanoseconds" << endl;
    cout<<" "<<endl;
    cout<<"Sorting time for Quick Sort: " << this->quickSortTime <<" nanoseconds" <<endl;
    cout<<" " <<endl;
    double difference;
    if(shellSortTime > quickSortTime){
        difference = (double) shellSortTime - quickSortTime;
        cout<<"For your specific request, Quick Sort is faster by " <<difference << " nanoseconds"<<endl;
        cout<<" "<<endl;
    }else if(quickSortTime>shellSortTime){
        difference = (double) quickSortTime - shellSortTime;
        cout<<"For your specific request, Shell Sort is faster by " <<difference << " nanoseconds"<<endl;
        cout<<" "<<endl;
    }else{
        cout<<"For your specific request, both sorting algorithm perform by exactly the same time"<<endl;
        cout<<" "<<endl;
    }
}



