#include <iostream>
#include <string>
#include <vector>
#include "digitalMedia.h"
#include "music.h"
#include "movies.h"
#include "videogames.h"




using namespace std;
//main pointer vector with parent class
vector <digitalMedia*> vect;

//function prototypes
void addMovie(vector<digitalMedia*> &vect);
void addMusic(vector<digitalMedia*> &vect);
void addVideogame(vector<digitalMedia*> &vect);
vector<digitalMedia*>::iterator search(vector<digitalMedia*> &vect, string searchType);
vector<digitalMedia*>::iterator deleteM(vector<digitalMedia*> &vect, string searchType);

//main function
int main() 
{
	//initialize variables
	string input;
	string mediaType;
	string answer;
	bool running = true;
	bool keepadding = true;
	//when the program is running do the following
	while (running == true) {
		//ask user what they want to do
		cout << "What would you like to do?" << endl;
		cout << "Type ADD to add each kind of media, including the information in each field." << endl;
		cout << "Type SEARCH to search media." << endl;
		cout << "Type DELETE to delete an item" << endl;
		cout << "Type QUIT to quit" << endl;

		cin >> input;
		//while the input isn't correct keep asking fo input
		while (input != "ADD" && input != "SEARCH" && input != "DELETE" && input != "QUIT" ) {
				cout << "Invalid input of " << input << ", please try again." << endl;
				cin >> input;
		}
		//if the user wants to add do the following depending on the mediatype
		if (input == "ADD" || input == "Add" || input == "add") {
			keepadding = true;
			while (keepadding == true) {
				cout << "What would you like to add? Type: movie, music, videogame." << endl;
				cin >> mediaType;
				if (mediaType == "movie") {
					addMovie(vect);
				}
				else if (mediaType == "music") {
					addMusic(vect);
				}
				else if (mediaType == "videogame") {
					addVideogame(vect);
				}
				cout << "Would you like to add another digital media type? Yes or no." << endl;
				cin >> answer;
				while (keepadding == true) {
					if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "y" || answer == "Y") {
						keepadding = true;
						break;
					}
					else if (answer == "no" || answer == "No" || answer == "NO" || answer == "n" || answer == "N") {
						keepadding = false;
					}
					else {
						cout << "Please input either yes or no:" << endl;
						cin >> answer;
						keepadding = true;
					}
				}
			}
		}
				//if the user wants to search do the following depending on the mediatype
		else if (input == "SEARCH" || input == "Search" || input == "search") {
			string searchType;
			cout << "How would you like to search? By: Title or year." << endl;
			cin >> searchType;
			search(vect, searchType);
		}
		//if the user wants to delete do the following depending on the mediatype
		else if (input == "DELETE" || input == "Delete" || input == "delete") {
			string searchType;
			cout << "How would you like to delete? By: title or year." << endl;
			cin >> searchType;
			vector<digitalMedia*>::iterator itr = deleteM(vect, searchType);

		}
		//quit the program
		else if (input == "QUIT" || input == "Quit" || input == "quit") {
			cout << "Bye bye!" << endl;
			running = false; 
		}
	}
	return 0;
}

//funciton to add a movie
void addMovie(vector<digitalMedia*> &vect){
	string title;
	string director;
	int duration;
	int rating;
	int year;
	cout << "Enter the movie title: " << endl;
	cin >> title;
	cout << "Enter movie director: " << endl;
	cin >> director;
	cout << "Enter movie year: " << endl;
	cin >> year;
	cout << "Enter movie duration: " << endl;
	cin >> duration;
	cout << "Enter movie rating: " << endl;
	cin >> rating;
	movies* movie = new movies(title, director, year, duration, rating);
	vect.push_back(movie);
	return;
}
//funciton to add a music
void addMusic(vector<digitalMedia*> &vect) {
	string title;
	string artist;
	string publisher;
	int year;
	int duration;
	cout << "Enter music title: " << endl;
	cin >> title;
	cout << "Enter music artist: " << endl;
	cin >> artist;
	cout << "Enter music publisher: " << endl;
	cin >> publisher;
	cout << "Enter music year: " << endl;
	cin >> year;
	cout << "Enter music duration: " << endl;
	cin >> duration;
	music* mus = new music(title, publisher, artist, year, duration);
	vect.push_back(mus);
	return;
}
//funciton to add a videogame
void addVideogame(vector<digitalMedia*> &vect) {
	string title;
	string publisher;
	int year;
	int rating;
	cout << "Enter game title: " << endl;
	cin >> title;
	cout << "Enter game publisher: " << endl;
	cin >> publisher;
	cout << "Enter game year: " << endl;
	cin >> year;
	cout << "Enter movie rating: " << endl;
	cin >> rating;
	videogames* videogame = new videogames(title, publisher, year, rating);
	vect.push_back(videogame);
	return;
}

//fucntion to search a media type depending on title and year it will print out valye
vector<digitalMedia*>::iterator search(vector<digitalMedia*> &vect, string searchType) {
	string tit;
	vector<digitalMedia*>::iterator it;
	bool found = false;
	if (searchType == "Title" || searchType == "title") {
		cout << "Enter the title:" << endl;
		cin >> tit;
		for(it = vect.begin() ; it != vect.end() ; ++it) {
			if (tit == (*it)->title) {
				found = true;
				if ((*it)->type == "movie") {
					cout << "Movie:\n";
					cout << "title: " << (*it)->title << " ";
					cout << "director: " << static_cast<movies*>(*it)->getDirector() << " ";
					cout << "year: " << (*it)->year << " ";
					cout << "duration: " << static_cast<movies*>(*it)->getDuration() << " ";
					cout << "rating: " << static_cast<movies*>(*it)->getRating() << endl;
				}
				else if ((*it)->type == "music") {
					cout << "Music:\n";
					cout << "title: " << (*it)->title << " ";
					cout << "artist: " << static_cast<music*>(*it)->getArtist() << " ";
					cout << "year: " << (*it)->year << " ";
					cout << "duration: " << static_cast<music*>(*it)->getDuration() << " ";
					cout << "publisher: " << static_cast<music*>(*it)->getPublisher() << endl;
				}
				else if ((*it)->type == "videogames") {
					cout << "Videogame:\n";
					cout << "title: " << (*it)->title << " ";
					cout << "publisher: " << static_cast<videogames*>(*it)->getPublisher() << " ";
					cout << "year: " << (*it)->year << " ";
					cout << "rating: " << static_cast<videogames*>(*it)->getRating() << " " << endl;
				}
			}
		}
	}

	else if (searchType == "year" || searchType == "Year") {
		int yea; 
		cout << "Enter the year:" << endl;
		cin >> yea;
		for(it = vect.begin(); it != vect.end(); ++it) {
			if (yea == (*it)->year) {
				found = true;
				if ((*it)->type == "movie") {
					cout << "Movie:\n";
					cout << "title: " << (*it)->title << " ";
					cout << "director: " << static_cast<movies*>(*it)->getDirector() << " ";
					cout << "year: " << (*it)->year << " ";
					cout << "duration: " << static_cast<movies*>(*it)->getDuration() << " ";
					cout << "rating: " << static_cast<movies*>(*it)->getRating() << endl;
				}
				else if ((*it)->type == "music") {
					cout << "Music:\n";
					cout << "title: " << (*it)->title << " ";
					cout << "artist: " << static_cast<music*>(*it)->getArtist() << " ";
					cout << "year: " << (*it)->year << " ";
					cout << "duration: " << static_cast<music*>(*it)->getDuration() << " ";
					cout << "publisher: " << static_cast<music*>(*it)->getPublisher() << endl;
				}
				else if ((*it)->type == "videogames") {
					cout << "Videogame:\n";
					cout << "title: " << (*it)->title << " ";
					cout << "publisher: " << static_cast<videogames*>(*it)->getPublisher() << " ";
					cout << "year: " << (*it)->year << " ";
					cout << "rating: " << static_cast<videogames*>(*it)->getRating() << " " << endl;
				}
			}
		}
	}
	if (found == false) {
		cout << "Could not find any matching title/year." << endl;
	}
	return it;
}

//funciton to delete media type depending on year/title
vector<digitalMedia*>::iterator deleteM(vector<digitalMedia*> &vect, string searchType) {
	string tit;
	vector<digitalMedia*>::iterator it;
	bool found = false;
	if (searchType == "Title" || searchType == "title") {
		cout << "Enter the title:" << endl;
		cin >> tit;
		for(it = vect.begin() ; it != vect.end() ; ++it) {
			if (tit == (*it)->title) {
				found = true;
				cout << (*it)->type << " title: " << (*it)->title << endl;
				delete *it;
				vect.erase(it);
				it--;
			}
		}
	}

	else if (searchType == "year" || searchType == "Year") {
		int yea; 
		cout << "Enter the year:" << endl;
		cin >> yea;
		for(it = vect.begin(); it != vect.end(); ++it) {
			if (yea == (*it)->year) {
				found = true;
				cout << (*it)->type << " Year: " << (*it)->year << endl;
				delete *it;
				vect.erase(it);
				it--;
			}
		}
	}
	if (found == false) {
		cout << "The title/year does not exist and could not be deleted." << endl;
	}
	return it;
}


