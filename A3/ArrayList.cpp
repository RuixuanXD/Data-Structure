#include <iostream>
#include <string>
using namespace std;

class EmptyListException
{
  private:
  string e;
  public:
  EmptyListException(string str):e(str){}
};

class InvalidIteratorException
{
  private:
  string e;
  public:
  InvalidIteratorException(string str):e(str){}
};

template <class T>
class ArrayList
{
  private:

  T* arr;
  int Size;
  int capacity;
  
  public:

  class Iterator
  {
    private:
    T* p;
    public:
    Iterator(T* ptr)
    {
      p = ptr;
    }

    T& operator*()
    {
      return *p;
    }
    Iterator operator++()
    {
      p++;
      return *this;
    }
    Iterator operator--()
    {
      p--;
      return *this;
    }
    bool operator==(const Iterator& i)
    {
      return p == i.p;
    }
    bool operator<(const Iterator &i)
    {
      return p < i.p;
    }
    bool operator>(const Iterator &i)
    {
      return p > i.p;
    }
  };



  ArrayList()
   {
     capacity = 4;
     Size = 0;
     arr = new T[capacity];
   }

   ArrayList(int s)
   {
     Size = s;
     capacity = 2 * s;
     arr = new T[capacity];
   }

	 ~ArrayList(){delete[] arr;}

  T& operator[](int i)
  {
    return arr[i];
  } 

  T& front()
  {
    return arr[0];
  }

  T& back()
  {
    return arr[Size];
  }

  void insertFront(const T& e)
  {
    if(Size == capacity)
    {
      capacity *= 2;
      T *t = new T[capacity];
      for(int i = 0; i < Size; i++)
      {
        t[i] = arr[i];
      }
      delete[] arr;
      arr = t;
    }
    int i = 1;
    T temp1 = e;
    while(i <= Size)
    {
      T temp2 = arr[i];
      arr[i] = temp1;
      temp1 = temp2;
      i++;
    }
    Size++;
  }

  void insertBack(const T& e)
  {
    if(Size == capacity)
    {
      capacity *= 2;
      T *t = new T[capacity];
      for(int i = 0; i < Size; i++)
      {
        t[i] = arr[i];
      }
      delete[] arr;
      arr = t;
    }
    arr[Size] = e;
    Size++;
  }

  void insert(Iterator p, const T& e)
  {
    if(p < begin() || p > end())
    {
      throw InvalidIteratorException("InvalidIteratorException");
    }
    T temp1 = e;
    while(p < end() || p == end())
    {
      T temp2 = *p;
      *p = temp1;
      temp1 = temp2;
      ++p;
    }
    Size++;
  }

  void removeFront()
  {
    if(empty() == true)
    {
      throw EmptyListException("EmptyListException");
    }
    for(int i = 0; i < Size-1; i++)
    {
      arr[i] = arr[i+1];
    }
    Size--;
  }

  void removeBack()
  {
    if(empty() == true)
    {
      throw EmptyListException("EmptyListException");
    }
    Size--;
  }

  void remove(Iterator p)
  {
    if(empty() == true)
    {
      throw EmptyListException("EmptyListException");
    }
    if(p < begin() || p > end())
    {
      throw InvalidIteratorException("InvalidIteratorException");
    }
    while(p < end()  || p == end())
    {
      Iterator temp = p;
      ++temp;
      *p = *temp;
      ++p;
    }
    Size--;
  }

  int size(){return Size;}

  bool empty()
  {
    return Size == 0;
  }

  Iterator begin()
  {
    return Iterator(&arr[0]);
  }

  Iterator end()
  {
    return Iterator(&arr[Size]);
  }
};
