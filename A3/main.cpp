#include "ArrayList.cpp"

void testArrayListUnderflow()
{
  try
  {
    ArrayList<int> list;
    int a = 1;
    list.insert(list.begin(), a);
    list.removeFront();
    list.removeFront();
    cout << "did not catch the exception" << endl;
  }
  catch (EmptyListException e)
  {
    cout << "catch the exception" << endl;
  }
  try
  {
    ArrayList<int> list;
    int a = 1;
    list.insert(list.begin(), a);
    list.removeBack();
    list.removeBack();
    cout << "did not catch the exception" << endl;
  }
  catch (EmptyListException e)
  {
    cout << "catch the exception" << endl;
  }
  try
  {
    ArrayList<int> list;
    int a = 1;
    list.insert(list.begin(), a);
    list.remove(list.begin());
    list.remove(list.begin());
    cout << "did not catch the exception" << endl;
  }
  catch (EmptyListException e)
  {
    cout << "catch the exception" << endl;
  }
  catch (InvalidIteratorException i)
  {
    cout << "catch the iterator exception" << endl;
  }
}

void testIntegerIterator()
{
  ArrayList<int> list;
  for(int i = 1; i < 7; i++)
  {
    list.insertBack(i);
  }
  for(ArrayList<int>::Iterator iter = list.begin(); !(iter == list.end()); ++iter)
  {
    cout << *iter << " ";
  }
  cout << endl;
}

void testStringIterator()
{
  ArrayList<string> list;
  string a = "a";
  for(int i = 0; i < 3; i++)
  {
    list.insertBack(a);
    a = a + a;
  }
  for(ArrayList<string>::Iterator iter = list.begin(); !(iter == list.end()); ++iter)
  {
    cout << *iter << " ";
  }
  cout << endl;
}



int main() 
{
  testArrayListUnderflow();
  cout << endl;
  testIntegerIterator();
  cout << endl;
  testStringIterator();
  return 0;
}