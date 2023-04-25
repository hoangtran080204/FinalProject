#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "Playlist.cpp"

using namespace std;

//Method to print out 18 options for genre
void printGenreOption(){
    cout<<"Please choose your preferred genre:"<<endl;
    cout<<"- Movie"<<endl;
    cout<<"- A Capella"<<endl;
    cout<<"- Country"<<endl;
    cout<<"- Dance"<<endl;
    cout<<"- Electronic"<<endl;
    cout<<"- Blues"<<endl;
    cout<<"- Opera"<<endl;
    cout<<"- R&B"<<endl;
    cout<<"- Hip-Hop"<<endl;
    cout<<"- Rap"<<endl;
    cout<<"- Indie"<<endl;
    cout<<"- Classical"<<endl;
    cout<<"- Pop"<<endl;
    cout<<"- Reggae"<<endl;
    cout<<"- Jazz"<<endl;
    cout<<"- Rock"<<endl;
    cout<<"- Soul"<<endl;
    cout<<"- World"<<endl;

}

//Method to print out 4 options for category
void printCategoryOption(){
    cout<<"Please choose the category you want to explore: " <<endl;
    cout<<"- Acousticness"<<endl;
    cout<<"- Danceability"<<endl;
    cout<<"- Popularity"<<endl;
    cout<<"- Energy" <<endl;
}

int main()
{
    Playlist song; // playlist variable
    bool flag = true; // flag to determine whether to stop or continue the program
    string genre, option, numSong, category, exit; // input string for genre, category, number of songs, overrated/underrated option
    int songCount; //number of song convert from input string
    cout<<"Welcome to the PlayList Generator!"<<endl;
    cout<<"Let's discover the most highly-rated and underrated song in different categories from different genres"<<endl;
    while(flag == true){
        printGenreOption(); // print genre
        cin>>genre;
        printCategoryOption(); // print category
        cin>>category;
        cout<<"Would you prefer the most highly-rated(type H) or underrated(type U) song in this category?"<<endl;
        cin>>option;
        cout<<"Please choose the number of songs you want to include in the playlist: "<<endl;
        cin>>numSong;
        songCount= stoi(numSong); // convert number of strong from string to int
        cout<<"Here's the playlist you requested: "<<endl;
        //Load file, sorting and print out the list
        song.loadFile(genre, category); // load the CSV file based on the input genre and category
        song.sortKey(); // call the two sorting algorithms to sort the play list
        song.printPlayList(songCount, option); // print out the playlist based on option for underrated/overrated and number of songs
        song.printTime();
        //Ask for continuation
        cout<<"Hope you enjoy the list. Would you like to make another one(type Yes or No): "<<endl;
        cin>>exit;
        if(exit == "No"){
            flag = false; // terminate the program if user choose No
        }
    }
    cout<<"Thanks for using the PLayList Generator. Hope you discover some fun songs to add to your playlist."<<endl;
    return 0;
}
