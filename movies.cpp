//movies cpp file with methods and construtor to set values 
#include <string>
#include "movies.h"

using namespace std;

movies::movies(string tit, string dir, int yea, int dur, int rat) {
	digitalMedia::title = tit;
	director = dir;
	digitalMedia::year = yea;
	duration = dur;
	rating = rat;
	digitalMedia::type = "movie";
}

string movies::getDirector() {
  return director;
}

int movies::getRating() {
  return rating;
}

int movies::getDuration() {
  return duration;
}
