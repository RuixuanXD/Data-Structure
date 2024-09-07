#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class Entry
{
  int key;
  string data;

  public:
  void random();
  void randomKey();
  void randomData();
  void setKey(const int k){key = k;}
  void setData(const string d){data = d;}
  int getKey() const{return key;}
  string getData() const{return data;}
  string toString();
  bool operator<(const Entry e){return this->key < e.getKey();}
  bool operator>(const Entry e){return this->key > e.getKey();}
  bool operator==(const Entry e){return this->key = e.getKey();}
};

void Entry::randomKey()
{
  int srand = (rand()%100)+0;
  key = srand;
}

void Entry::randomData()
{
  char c;
  string s;
  c = 'a';
  c += (rand()%26)+0;;
  s += c;
  c = 'a';
  c += (rand()%26)+0;;
  s += c;
  c = 'a';
  c += (rand()%26)+0;;
  s += c;
  data = s;
}

void Entry::random()
{
  randomKey();
  randomData();
}

string Entry::toString()
{
  string s = "(";
  s += to_string(key);
  s += ", ";
  s += data;
  s += ")";
  return s;
}
