//digital media header file with members 
#ifndef digitalMedia_H
#define digitalMedia_H

#include <string>

using namespace std;

class digitalMedia {
 public: 
  digitalMedia();
  digitalMedia(string tit, int yea);
  string title;
  int year;
  string type;
};

#endif
