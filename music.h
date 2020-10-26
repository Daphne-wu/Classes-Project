//music header file with members child class extends digitalMedia class

#ifndef music_H
#define music_H

#include <string>
#include "digitalMedia.h"
using namespace std;

class music: public digitalMedia {
 public:
  music(string tit, string pub, string art, int yea, int dur);
  string getPublisher();
  string getArtist();
  int getDuration();
private:
  string publisher;
  string artist;
  int duration;
};


#endif
