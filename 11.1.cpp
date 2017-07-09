#include<iostream>
using namespace std;
struct X{
	int i;
	X(int);
	X operator+(int);
}; 
struct Y{
	int i;
	Y(X);
	//Y operator+(X t);
	operator int();
};
extern X operator*(X x,Y y)
{
	return x.i*y.i;
}
extern int f(X);
X x=X(1);
Y y=Y(x);
int i=2;
int main()
{
	cout<<i+10<<'\n'
	<<y+10<<'\n'
	<<x*y<<'\n'
	<<x+y+i<<'\n'
	<<x*x+i<<'\n'
	<<f(7)<<'\n'
	<<f(y)<<'\n'
	<<y+y<<'\n'
	<<106+y<<'\n';
	return 0;
}
