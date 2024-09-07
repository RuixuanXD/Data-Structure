#include <vector>
#include <iostream>
using namespace std;
template <typename T>
class Heap
{
  vector<T> v;
  void bubbleUp(int i);
  void bubbleDown(int i);
public:
  ~Heap(){}
  T removeMax();
  void insert(T& e);
  int size(){return v.size();}
  bool empty(){return v.empty();}
  void make(T entrise[], int n);
  T& operator[](int i){return v[i];}
};

template <typename T>
void Heap<T>::bubbleUp(int i)
{
  while(i > 0)
  {
    int parentIndex = (i - 1) / 2;
    if(v[i] > v[parentIndex])
    {
      T temp = v[i];
      v[i] = v[parentIndex];
      v[parentIndex] = temp;
      i = parentIndex;
    }
    else
      return;
  }
}

template <typename T>
void Heap<T>::bubbleDown(int i)
{
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int maxIndex = i;
  if(left < v.size() && v[left] > v[maxIndex])
  {
    maxIndex = left;
  }
  if(right < v.size() && v[right] > v[maxIndex])
  {
    maxIndex = right;
  }
  if(maxIndex == i){
    return;
  }
  else
  {
    T temp = v[maxIndex];
    v[maxIndex] = v[i];
    v[i] = temp;
    bubbleDown(maxIndex);
  }
  
}

template <typename T>
T Heap<T>::removeMax()
{
  T result = v[0];
  v[0] = v.back();
  v.pop_back();
  bubbleDown(0);
  return result;
}

template <typename T>
void Heap<T>::insert(T& e)
{
  v.push_back(e);
  bubbleUp(v.size()-1);
}

template <typename T>
void Heap<T>::make(T entrise[], int n)
{
  for(int i = 0; i < n; i++){
    v.push_back(entrise[i]);
  }
  for(int i = n / 2 - 1; i >= 0; i--)
  {
    bubbleDown(i);
  }
}