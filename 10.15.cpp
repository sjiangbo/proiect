#include<iostream>
using namespace std;
class a{ 
public:a() {
	cout << "Initialize\n";

}
~a() {
	cout << "Clean up\n";
}
};
a A;

int main()
{
	cout << "Hello,world!" <<'\n'; 
	return 0;
}
