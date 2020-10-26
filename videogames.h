//videogame header file with members child class extends digitalMedia class
#ifndef videogames_H
#define videogames_H

#include <string>
#include "digitalMedia.h"

using namespace std;

class videogames: public digitalMedia {
 public:
  videogames(string tit, string pub, int yea, int rat);
  string getPublisher();
  int getRating();
private:
  string publisher;
  int rating;
};

#endif
