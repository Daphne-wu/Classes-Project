//music cpp file with methods and construtor to set values 
#include "music.h"

using namespace std;

music::music(string tit, string pub, string art, int yea, int dur) {
	digitalMedia::title = tit;
	publisher = pub;
	artist = art;
	digitalMedia::year = yea;
	duration = dur;
	digitalMedia::type = "music";
}

string music::getPublisher() {
  return publisher;
}

string music::getArtist() {
  return artist;
}

int music::getDuration() {
  return duration;
}
