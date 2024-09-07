#include "ArrayUtils.cpp"

class Employee
{
  private:
  string name;
  int idNumber;
  public:
  Employee():name(""),idNumber(0){}
  Employee(string a, int b):name(a),idNumber(b){};
  void setName(string n);
  void setIdNumber(int i);
  string getName()const;
  int getIdNumber() const;
  string toString();
};

void Employee::setName(string n)
{
  name = n;
}

void Employee::setIdNumber(int i)
{
  idNumber = i;
}

string Employee::getName()const
{
  return name;
}

int Employee::getIdNumber()const
{
  return idNumber;
}

string Employee::toString()
{
  string a;
  a = getName() + " " + to_string(getIdNumber());
  return a;
}