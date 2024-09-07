#include <iostream>
#include <string>
using namespace std;


class Animal
{
private:
	const static string Noise;
	int AgelnMonths;
public:
	Animal(): AgelnMonths(0){}
	Animal(int a): AgelnMonths(a){}
	Animal& operator = (const Animal &a)
	{
		if(this == &a)
			return *this;
		this->setAgelnMonths(a.agelnMonths());
		return *this;
	}
	string noise() const{return Noise;}
	int repeats() const{return 0;}
	void setAgelnMonths (int a){AgelnMonths = a;}
	virtual int agelnMonths() const{return AgelnMonths;}
	virtual const void print ()
	{
		cout<< agelnMonths() << " ";
		for(int i = 0; i < repeats(); i++)
			cout << Noise << " ";
		cout << endl;
	}
};
const string Animal::Noise = "grunt";




class Cow : public Animal
{
private:
	const static string Noise;
public:
	Cow(): Animal(7){}
	Cow& operator = (const Cow &c)
	{
		if(this == &c)
			return *this;
		Animal a(c.agelnMonths());
		this->Animal::operator = (a);
		this->setAgelnMonths(c.agelnMonths());
		return *this;
	}
	static string noise(){return Noise;}
	int repeats() const{return 2;}
	int agelnMonths() const{return Animal::agelnMonths();}
	const void print ()
	{
		cout<< agelnMonths() << " ";
		for(int i = 0; i < repeats(); i++)
			cout << Noise << " ";
		cout << endl;
	}
};
const string Cow::Noise = "moo";




class Cat : public Animal
{
private:
	const static string Noise;
public:
	Cat(): Animal(4){}
	Cat& operator = (const Cat &c)
	{
		if(this == &c)
			return *this;
		Animal a(c.agelnMonths());
		this->Animal::operator = (a);
		this->setAgelnMonths(c.agelnMonths());
		return *this;
	}
	string noise() const{return Noise;}
	int repeats() const{return 1;}
	int agelnMonths() const{return Animal::agelnMonths();}
	const void print()
	{
		cout<< agelnMonths() << " ";
		for(int i = 0; i < repeats(); i++)
			cout << Noise << " ";
		cout << endl;
	}
};
const string Cat::Noise = "meow";




class Sheep : public Animal
{
private:
	const static string Noise;
public:
	Sheep(): Animal(6){}
	Sheep& operator = (const Sheep &s)
	{
		if(this == &s)
			return *this;
		Animal a(s.agelnMonths());
		this->Animal::operator = (a);
		this->setAgelnMonths(s.agelnMonths());
		return *this;
	}
	string noise() const{return Noise;}
	int repeats() const{return 3;}
	int agelnMonths() const{return Animal::agelnMonths();}
	const void print()
	{
		cout<< agelnMonths() << " ";
		for(int i = 0; i < repeats(); i++)
			cout << Noise << " ";
		cout << endl;
	}
};
const string Sheep::Noise = "baa";




class Mouse : public Animal
{
private:
	const static string Noise;
public:
	Mouse(): Animal(1){}
	Mouse& operator = (const Mouse &m)
	{
		if(this == &m)
			return *this;
		Animal a(m.agelnMonths());
		this->Animal::operator = (a);
		this->setAgelnMonths(m.agelnMonths());
		return *this;
	}
	string noise() const{return Noise;}
	int repeats() const{return 5;}
	int agelnMonths() const{return Animal::agelnMonths();}
	const void print()
	{
		cout<< agelnMonths() << " ";
		for(int i = 0; i < repeats(); i++)
			cout << Noise << " ";
		cout << endl;
	}
};
const string Mouse::Noise = "squeak";







int main()
{
	Animal animal;
	Cow cow;
	Cat cat;
	Sheep sheep;
	Mouse mouse;

	animal.print();
	cow.print();
	cat.print();
	sheep.print();
	mouse.print();
	cout << endl;

	Animal* animals[10];
	animals[0] = new Cow;
	animals[1] = new Mouse;
	animals[2] = new Sheep;
	animals[3] = new Cat;
	animals[4] = new Animal;
	animals[5] = new Cat;
	animals[6] = new Mouse;
	animals[7] = new Sheep;
	animals[8] = new Mouse;
	animals[9] = new Cow;

	for (int i = 0; i < 10; i++)
	{
		animals[i]->print();
	}

	for(int i = 0; i < 10; i++)
	{
		delete animals[i];
	}

	system ("pause");
	return 0;
}