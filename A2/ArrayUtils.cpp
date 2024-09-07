#include "Stack.cpp"

class ArrayUtils
{
  public:
  template <class T>
	static T* reverse(T* a, int s)
  {
  if(s == 0)
    return a;
  Stack<T> temp;
  for(int i = 0; i < s; i++)
  {
    temp.push(a[i]);
  }
  for(int i = 0; i < s; i++)
  {
    a[i] = temp.pop();
  }
  return a;
  }
};