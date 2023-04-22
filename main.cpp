#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "Playlist.cpp"

using namespace std;

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
void printCategoryOption(){
    cout<<"Please choose the category you want to explore: " <<endl;
    cout<<"- Popularity"<<endl;
    cout<<"- Acousticness"<<endl;
    cout<<"- Danceability"<<endl;
    cout<<"- Energy" <<endl;
}

int main()
{
    // Open the CSV file
    Playlist song;
    bool flag = true;
    string genre, option, numSong, category, exit;
    int songCount;
    cout<<"Welcome to the PlayList Maker!"<<endl;
    cout<<"Let's discover the most highly-rated and underrated song in different categories from different genres"<<endl;
    while(flag == true){
        printGenreOption();
        cin>>genre;
        printCategoryOption();
        cin>>category;
        cout<<"Would you prefer the most highly-rated(type H) or underrated(type U) song in this category?"<<endl;
        cin>>option;
        cout<<"Please choose the number of songs you want to include in the playlist: "<<endl;
        cin>>numSong;
        songCount= stoi(numSong);
        cout<<"Here's the playlist you requested: "<<endl;
        //Load file, sorting and print out the list
        song.loadFile(genre, category);
        song.sortKey();
        song.printPlayList(songCount, option);
        song.printTime();
        //Ask for continuation
        cout<<"Hope you enjoy the list. Would you like to make another one(type Yes or No): "<<endl;
        cin>>exit;
        if(exit == "No"){
            flag = false;
        }
    }
    cout<<"Thanks for using the PLayList Maker. Hope you discover some fun songs to add to your playlist."<<endl;
    return 0;
}
