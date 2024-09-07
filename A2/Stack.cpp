#include <iostream>
#include <string>
using namespace std;

class EmptyStackException
{
  private:
  string e;
  public:
  EmptyStackException():e("EmptyStackException."){}
  EmptyStackException(string str):e(str){}
  void throwException()
  {
    throw EmptyStackException("EmptyStackException.");
  }
};

template <class T>
class Stack
{
private:
  T* arr;
  int Size;
  int Capacity;
public:
	 Stack()
   {
     Capacity = 4;
     Size = 0;
     arr = new T[Capacity];
   }
   Stack(int s)
   {
     Size = s;
     Capacity = 2 * s;
     arr = new T[Capacity];
   }
	 ~Stack()
   {
     delete[] arr;
   }
	 T& pop();
	 void push(T&);
	 bool empty();
	 int size();
	 int capacity();
};

template <class T>
T& Stack<T>::pop()
 {
    if(empty() == true)
    {
      EmptyStackException e;
      e.throwException();
    }
    T& temp = arr[Size-1];
    Size -= 1;
    return temp;
 }

template <class T>
void Stack<T>::push(T& a)
 {
   if(Size == capacity())
   {
     Capacity *= 2;
     T *t = new T[Capacity];
     for(int i = 0; i < Size; i++)
     {
       t[i] = arr[i];
     }
     delete[] arr;
     arr = t;
   }
   arr[Size] = a;
   Size++;
 }

template <class T>
bool Stack<T>::empty()
{
  if (Size == 0)
    return true;
  else
    return false;
}

template <class T>
int Stack<T>::size()
{
  return Size;
}

template <class T>
int Stack<T>::capacity()
{
  return Capacity;
}