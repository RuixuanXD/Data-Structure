#include "SkipList.h"

int main() 
{
  srand(time(0));

  SkipList x;
  
  x.put(12, "asw");
  x.put(15, "efs");
  x.put(32, "gjn");
  x.put(56, "tht");
  x.put(23, "dsc");
  x.put(62, "axz");
  x.put(42, "qsw");
  x.put(12, "bnb");

  x.print();
  try
  {
    x.erase(32);
  }
  catch(Exception)
  {
    cout << "Did not find the key" << endl;
  }
  cout << endl;
  x.print();

  try
  {
    cout << x.find(56).toString() << endl;
    cout << x.find(32).toString() << endl;
  }
  catch(Exception)
  {
    cout << "Did not find the key" << endl;
  }
  try
  {
    cout << x.find(32).toString() << endl;
  }
  catch(Exception)
  {
    cout << "Did not find the key" << endl;
  }

  try
  {
    cout << x.greaterEntry(15).toString() << endl;
  }
  catch(Exception)
  {
    cout << "the entry with the lowest key that is greater than k is infinity" << endl;
  }
  try
  {
    cout << x.lessEntry(15).toString() << endl;
  }
  catch(Exception)
  {
    cout << "the entry with the greatest key that is less than k is minus infinity" << endl;
  }


  SkipList y;
  for(int i = 0; i < 40; i++)
  {
    Entry e;
    e.random();
    y.put(e.getKey(), e.getData());
  }
  y.print();





  return 0;
}