#include "Employee.h"


void testStackUnderflow()
{
  try
  {
    Stack<int> a;
    int b = 1;
    a.push(b);
    a.pop();
    a.pop();
    cout << "did not catch exception";
  }
  catch(EmptyStackException e)
  {
    cout << "caught EmptyStackException";
  }
}

void testStackGrowth()
{
  Stack<int> s;
  for(int i = 1; i < 6; i++)
  {
    s.push(i);
    cout << i << " "; 
  }
  cout << endl << "Capacity is " << s.capacity() << endl;
  for(int i = 6; i < 10; i++)
  {
    s.push(i);
    cout << i << " ";
  }
  cout << endl;
  for(int i = 0; i < 9; i++)
  {
    cout << s.pop() << " ";
  }
  cout << endl << "After pop, the capacity is " << s.capacity();
}

void testReverseIntegers()
{
  int* arr = new int[12];
  for(int i = 0; i < 12; i++)
  {
    arr[i] = i+1;
    cout << arr[i] << " ";
  }
  cout << endl;
  ArrayUtils::reverse<int>(arr, 12);
  for(int i = 0; i < 12; i++)
  {
    cout << arr[i] << " ";
  }

}

void testReverseStrings()
{
  char * c = new char[12];
  char a = 'a';
  for(int i = 0; i < 12; i++)
  {
    c[i] = a;
    a++;
    cout << c[i] << " ";
  }
  cout << endl;
  ArrayUtils::reverse<char>(c,12);
  for(int i = 0; i < 12; i++)
  {
    cout << c[i] << " " ;
  }
}

void testReverseEmployees()
{
  Employee *e = new Employee[12];
  string s = "a";
  for(int i = 0; i < 12; i++)
  {
    e[i].setName(s);
    e[i].setIdNumber(i+1);
    s[0]++;
    cout << e[i].toString() << " ";
  }
  cout << endl;
  ArrayUtils::reverse<Employee>(e, 12);
  for(int i = 0; i < 12; i++)
  {
    cout << e[i].toString() << " ";
  }
}

int main() 
{
  testStackUnderflow();
  cout << endl << endl;
  testStackGrowth();
  cout << endl << endl;
  testReverseIntegers();
  cout << endl << endl;
  testReverseStrings();
  cout << endl << endl;
  testReverseEmployees();
  return 0;
}