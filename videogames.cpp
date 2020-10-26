//videogames cpp file with methods and construtor to set values 
#include "videogames.h"

using namespace std;

videogames::videogames(string tit, string pub, int yea, int rat) {
	digitalMedia::title = tit;
	publisher = pub;
	digitalMedia::year = yea;
	rating = rat;
	digitalMedia::type = "videogames";
}

string videogames::getPublisher() {
  return publisher;
}

int videogames::getRating() {
  return rating;
}
