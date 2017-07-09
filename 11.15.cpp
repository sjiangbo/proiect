#include<iostream>
class vec4{
	private:
		float a;
		float b;
		float c;
		float d;
	public:
		vec4(float a1,float b1,float c1,float d1): a(a1),b(b1),c(c1),d(d1) { };
		vec4() {};
		vec4 operator+ (float);
		vec4 operator- (float);
		vec4 operator* (float);
		vec4 operator/ (float);
		vec4 operator= (float);
		void operator+= (float);
		void operator-= (float);
		void operator*= (float);
		void operator/= (float);
		void show();
};
vec4 vec4::operator+(float n)
{
	vec4 v;
	v.a=a+n;
	v.b=b+n;
	v.c=c+n;
	v.d=d+n;
	return v;
}
vec4 vec4::operator-(float n)
{
	vec4 v;
	v.a=a-n;
	v.b=b-n;
	v.c=c-n;
	v.d=d-n;
	return v;
}

vec4 vec4::operator*(float n)
{
	vec4 v;
	v.a=a*n;
	v.b=b*n;
	v.c=c*n;
	v.d=d*n;
	return v;
}

vec4 vec4::operator/(float n)
{
	vec4 v;
	v.a=a/n;
	v.b=b/n;
	v.c=c/n;
	v.d=d/n;
	return v;
}

void vec4::operator+=(float n)
{
	a+=n;
	b+=n;
	c+=n;
	d+=n;

}

void vec4::operator-=(float n)
{
	a-=n;
	b-=n;
	c-=n;
	d-=n;

}

void vec4::operator*=(float n)
{
	a*=n;
	b*=n;
	c*=n;
	d*=n;

}

void vec4::operator/=(float n)
{
	a/=n;
	b/=n;
	c/=n;
	d/=n;
}

void vec4::show()
{
	std::cout<<a<<b<<c<<d<<'\n';
}
int main()
{
	vec4 v(1,2,3,4);
	std::cout<<"在原向量的基础上分别进行两次加减乘除：\n" ;
	v=v+1;
	v.show();
	v=v-1;
	v.show();
	v=v*2;
	v.show();
	v=v/2;
	v.show();
	v+=1;
	v.show();
	v-=1;
	v.show();
	v*=2;
	v.show();
	v/=2;
	v.show();
	return 0;
}
