#include "Heap.h"
#include "Entry.h"

Entry* heapsort1(Entry* e, int n)
{
  Heap<Entry> h;
  for(int i = 0; i < n; i++)
  {
    h.insert(e[i]);
  }
  for(int i = 0; i < n; i++)
  {
    e[i] = h.removeMax();
  }
  for(int i = 0; i < n/2; i++)
  {
    Entry temp = e[n-i-1];
    e[n-i-1] = e[i];
    e[i] = temp;
  }
  return e;
}

Entry* heapsort2(Entry* e, int n)
{
  Heap<Entry> h;
  h.make(e, n);
  for(int i = 0; i < n; i++)
  {
    e[i] = h.removeMax();
  }
  return e;
}

int main() 
{
  srand(time(0));
  Entry *e1 = new Entry[15];
  for(int i = 0; i < 15; i++)
  {
    e1[i].random();
  }
  for(int i = 0; i < 15; i++)
  {
    cout << e1[i].toString() << " ";
  }
  cout << endl << endl;   
  heapsort1(e1, 15);
  for(int i = 0; i < 15; i++)
  {
    cout << e1[i].toString() << " ";
  }
  cout << endl << endl;


  for(int i = 0; i < 15; i++)
  {
    e1[i].random();
  }
  for(int i = 0; i < 15; i++)
  {
    cout << e1[i].toString() << " ";
  }
  cout << endl << endl;  
  heapsort2(e1, 15);
  for(int i = 0; i < 15; i++)
  {
    cout << e1[i].toString() << " ";
  }
  cout << endl << endl;


  Entry *e2 = new Entry[31];
  for(int i = 0; i < 31; i++)
  {
    e2[i].random();
  }
  for(int i = 0; i < 31; i++)
  {
    cout << e2[i].toString() << " ";
  }
  cout << endl << endl;   
  heapsort1(e2, 31);
  for(int i = 0; i < 31; i++)
  {
    cout << e2[i].toString() << " ";
  }
  cout << endl << endl;


  for(int i = 0; i < 31; i++)
  {
    e2[i].random();
  }
  for(int i = 0; i < 31; i++)
  {
    cout << e2[i].toString() << " ";
  }
  cout << endl << endl;   
  heapsort1(e2, 31);
  for(int i = 0; i < 31; i++)
  {
    cout << e2[i].toString() << " ";
  }
  cout << endl << endl;



  cout << 1 << endl;
  return 0;
}