#include <iostream>
#include <string>

using namespace std;
class A {
public:
	A();
	A(int, int);
	~A() { cout << "A destructor called" << endl; }
	void setA(int, int);
	void getA(int&, int&);
	void printA();
private:
	int a;
	int b;
};

class B {
public:
	B();
	B(int, int, int);
	~B() { cout << "B destructor called" << endl; }
	void setB(int, int, int);
	void getB(int&, int&, int&);
	void printB();
private:
	int x;
	int y;
	int z;
};

class C {
public:
	C(int a = 0, int b = 0, int x = 1, int y = 1, int z = 1, string name = "Hello Class");
	void setCData(int a, int b, int x, int y, int z, string name);
	void printCData();
	~C() { cout << "C destructor called" << endl; }
private:
	string Cname;
	A Ca;
	B Cb;

};
int main() {
	C c(1, 4, 2, 5, 0, "Hello Class");
	return 0;
}
A::A() {
	a = 0;
	b = 0;
	cout << "A constructor called" << endl;
}
A::A(int a = 0, int b = 0) {
	cout << "A constructor called" << endl;
}
void A::setA(int a_, int b_) {
	a = a_;
	b = b_;
}
void A::getA(int& a_, int& b_) {
	a_ = a;
	b_ = b;
}
void A::printA() {
	cout << a << ";" << b << endl;
}
B::B() {
	x = 1;
	y = 2;
	z = 3;
	cout << "B constructor called" << endl;
}
B::B(int x = 0, int y = 0, int z = 0) {
	cout << "B constructor called" << endl;
}
void B::setB(int x_, int y_,int z_) {
	x = x_;
	y = y_;
	z = z_;
}
void B::getB(int& x_, int& y_, int& z_) {
	x_ = x;
	y_ = y;
	z_ = z;
}
void B::printB() {
	cout << x << "-" << y <<";"<<z<< endl;
}
C::C(int a, int b, int x, int y, int z, string name)
	:Cb(x, y, z), Ca(a, b)
{
	Cname = name;
	cout << "C constructor called" << endl;
}
void C::setCData(int a, int b, int x, int y, int z, string name)
{
	Ca.setA(a, b);
	Cb.setB(x, y, z);
	Cname = name;
}
void C::printCData()
{
	cout << Cname << " occurs ";
	Ca.printA();
	cout << " at ";
	Cb.printB();
	cout << endl;
}
