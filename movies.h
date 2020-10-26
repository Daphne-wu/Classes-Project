//movie header file with members child class extends digitalMedia class

#ifndef movies_H
#define movies_H

#include <string>
#include "digitalMedia.h"

using namespace std;

class movies: public digitalMedia {
 public:
  movies(string tit, string dir, int yea, int dur, int rat);
  string getDirector();
  int getRating();
  int getDuration();
private:
  string director;
  int duration;
  int rating;
};

#endif
