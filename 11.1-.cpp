#include<iostream>
using namespace std;
struct X{
	int i;
	X(){ };
	X(int n):i(n){cout<<"X(int):"<<endl;};
	X operator+(int);
}; 

struct Y{
	int i;
	Y() { };
	Y(X x):i(x.i){ cout<<"Y(X x):"<<endl;};
	Y operator+(X);
	operator int();
};

X X::operator+(int n)
{   
	cout<<"X::operator+(int):"<<endl;
	X x;
	x.i=i+n;
	return x;
}


Y Y::operator+(X x){
	cout<<"Y::operator+(X):"<<endl;
	Y r;
	r.i=i+x.i;
	return r;
}

Y::operator int(){
		cout<<"Y::int()"<<endl;
	return i;
	};
	
extern X operator*(X x,Y y){
	cout<<" X operator*(X x,Y y):"<<endl;
	X r;
	r.i=x.i*y.i;
	return r;
}	

extern int f(X x){
	cout<<"f(X):"<<endl;
	return x.i;
} 
int main(){
	X x=1;
	Y y=x;
	int I=2;
	cout<<"I+10="<<I+10<<endl;
	cout<<'\n'; 
	cout<<"无法计算：y+10"<<endl;
	cout<<'\n'; 
	cout<<"无法计算：y+y*10:"<<endl;
	cout<<'\n'; 
	cout<<"x+y+I="<<(x+y+I).i<<endl;
	cout<<'\n'; 
	cout<<"x*x+I="<<(x*x+I).i<<endl;
	cout<<'\n'; 
	cout<<"f(7)="<<f(7)<<endl;
	cout<<'\n'; 
	cout<<"can not convert f(y)"<<endl;//两个用户定义转换顺序 
	cout<<'\n'; 
	cout<<"y+y="<<y+y<<endl;//内部运算 
	cout<<'\n'; 
	cout<<"106+y="<<106+y<<endl;
}

