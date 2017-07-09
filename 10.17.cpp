#include<iostream>
using namespace std;
static int c=1;
class A
{
	private:
		static int &a;
	public:
		void f1();
				
};
class B
{
	private:
		static int &b;
	public:
		void f2();	
};
	int &A::a=c;
	int &B::b=c;
void A::f1()
{
	cout<<a<<'\n';
}
void B::f2()
{
	cout<<b;	
}
int main()
{
	A m;
	B n;
	m.f1();
	n.f2();
	return 0;
}
