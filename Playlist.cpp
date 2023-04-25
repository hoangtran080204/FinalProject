//
// Created by Hoang Tran on 4/21/2023.
//

#include "Playlist.h"


//Helper method to check if the numerical value from the CSV column can be converted
int Playlist::convertToInt(const string &str)
{
    try {
        return stoi(str); // convert string to int using stoi
    }
    catch (const invalid_argument& e) {
        // If stoi throws an invalid_argument exception,
        // return -1 to indicate that the conversion failed
        return -1;
    }
}
//Helper method to clean up the string variable of the song name from the CSV file.
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


//Method to read the CSV file and store the appropriate songs in the map based on the requested genre and category
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
        //Only add the song that fit the user's requested genre to the unordered_map
        if(columns[0] == genre){

            // Add the category column as key and the song name column as value in a vector of string
            int level;
            if(category == "Popularity"){
                level = convertToInt(columns[4]); //popularity case
            }else if(category == "Acousticness"){
                level = convertToInt(columns[5]); //acousticness case
            }else if(category == "Danceability"){
                level = convertToInt(columns[6]); //danceability case
            }else if(category == "Energy"){
                level = convertToInt(columns[8]); //energy case
            }
            string song = processString(columns[2]);
            if(level != -1){
                if(playList.find(level) == playList.end()){
                    vector<string> element;
                    element.push_back(song); //add song to the vector
                    playList[level] = element; // add vector to map
                }else{
                    playList[level].push_back(song);
                }
            }

        }

    }

}
//Method to sort the song based on the key value of the category and calculate sorting time for both algorithm
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
    quickSort(temporaryKeys, 0, temporaryKeys.size() - 1); //call quicksort to sort the category
    auto end = chrono::high_resolution_clock::now();
    this->quickSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // runtime for ShellSort

    start = chrono::high_resolution_clock::now();
    shellSort(keys); // call shellsort to sort the category
    end = chrono::high_resolution_clock::now();
    this->shellSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // runtime for QuickSort

    this->sortedLevel = keys; // can set the final sortedKeys to either shellSort or quickSort
}
//Method to print either the most underrated or highly rated song based on the requested number of song
void Playlist::printPlayList(int songCount, string sortedOption)
{
    int count = 1; //variable to keep track of number of song

    if(sortedOption == "U"){
        //Underrated case
        for(int level: sortedLevel){
            for(string song: playList[level])
            {
                if (count > songCount) {
                    break; // exit the inner loop when count reach the number of song
                }
                cout << count << ". " << song << endl; //print out the song sequentially since the underrated song is at the beginning of the vector
                count++;
            }
            if (count > songCount) {
                break; // exit the outer loop when count reach the number of song
            }
        }
    }else{
        //Loop from the back of the sorted vector to get the overrated song
        for(auto it = sortedLevel.rbegin(); it != sortedLevel.rend(); ++it){
            for(string song: playList[*it])
            {
                if (count > songCount) {
                    break; // exit the inner loop when count reach the number of song
                }
                cout << count << ". " << song << endl;
                count++;
            }
            if (count > songCount) {
                break; // // exit the outer loop when count reach the number of song
            }
        }
    }



}
//Method to print out the runtime and comparison of both sorting algorithms
void Playlist::printTime()
{
    cout<< " " << endl;
    cout<<"Sorting time for Shell Sort: " << this->shellSortTime <<" nanoseconds" << endl; //shell sort time
    cout<<" "<<endl;
    cout<<"Sorting time for Quick Sort: " << this->quickSortTime <<" nanoseconds" <<endl; //quick sort time
    cout<<" " <<endl;
    double difference; //variable for comparison
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



