#include <iostream>
#include <cstring>

using namespace std;
using std::istream;
using std::ostream;

class String {
    struct Srep;
    Srep *rep;
public:
    class Cref;
    class Range {};

    String( );
    String(const char*);
    String(const String&);
    String& operator=(const char*);
    String& operator=(const String&);
    ~String( );

    void check(int i) const;
    char read(int i) const;
    void write(int i, char c);
    Cref operator[](int i);
    char operator[](int i) const;
    int size() const;

    String& operator+=(const String&);
    String& operator+=(const char*);

    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
    friend bool operator==(const String& x, const char* s);
    friend bool operator==(const String& x, const String& y);
    friend bool operator!=(const String& x, const char* s);
    friend bool operator!=(const String& x, const String& y);

 //   String operator+(const String&, const String&);
 //   String operator+(const String&, const char*);

};

struct String::Srep {
    char* s;
    int sz;
    int n;

    Srep(int nsz, const char* p)
    {
        n = 1;
        sz = nsz;
        s = new char[sz+1];
        strcpy(s,p);
    }

    ~Srep() {delete[] s;}

    Srep* get_own_copy()
    {
        if (n==1) return this;
        n--;
        return new Srep(sz,s);
    }

    void assign(int nsz, const char* p)
    {
        if (sz != nsz){
            delete[] s;
            sz = nsz;
            s = new char[sz+1];
        }
        strcpy(s,p);
    }
public:
    Srep(const Srep&);
    Srep& operator=(const Srep&);
};

class String::Cref{
friend class String;
    String& s;
    int i;
    Cref(String& ss, int ii) : s(ss),i(ii) {}
public:
    operator char() const { return s.read(i); }
    void operator=(char c) { s.write(i, c); }
};

String::String()
{
    rep = new Srep(0,"");
}

String::String(const char* s)
{
    rep = new Srep(strlen(s),s);
}

String::String(const String& x)
{
    x.rep->n++;
    rep = x.rep;
}

String::~String()
{
    if(--rep->n == 0) delete rep;
}

String& String::operator=(const String& x)
{
    x.rep->n++;
    if (--rep->n==0) delete rep;
    rep = x.rep;
    return *this;
}

String& String::operator=(const char*s)
{
    if(rep->n==1)
        rep->assign(strlen(s),s);
    else{
        rep->n--;
        rep = new Srep(strlen(s),s);
    }
    return *this;
}

void String::check(int i) const { if(i<0) throw Range();}
char String::read(int i) const { return rep->s[i]; }
void String::write(int i,char c) { rep=rep->get_own_copy(); rep->s[i]=c; }
String::Cref String::operator[](int i) { check(i); return Cref(*this,i); }
char String::operator[](int i) const { check(i); return rep->s[i]; }
int String::size() const { return rep->sz; }

String& String::operator+=(const String& x)
{
    return *this += x.rep->s;
}

String& String::operator+=(const char* x)
{
    int sz = rep->sz+strlen(x);
    char* s = new char[sz+1];
    strcpy(s, rep->s);
    strcat(s, x);
    rep->assign(sz, s);
    delete s;
    return *this;
}

ostream& operator<<(ostream& o, const String& x)
{
    o << x.rep->s;
    return o;
}

const int INPUT_BUF = 255;
istream& operator>>(istream& i, String& x)
{

    char* s = new char[INPUT_BUF+1];
    int n = 0;
    int sz = INPUT_BUF;
    char ch;

    while(i && i.get(ch) && !isspace(ch))
    {
        s[n++] = ch;
        if(n > sz)
        {
            s[n]=0;
            char* s2 = new char[sz * 2 + 1];
            strcpy(s2,s);
            delete s;
            s = s2;
            sz *= 2;
        }
    }
    s[n]=0;

    x = String(s);
    delete s;
    return i;
}

bool operator==(const String& x, const char* s) { return strcmp(x.rep->s, s)==0; }
bool operator==(const String& x, const String& y) { return strcmp(x.rep->s, y.rep->s)==0; }
bool operator!=(const String& x, const char* s) { return strcmp(x.rep->s, s)!=0; }
bool operator!=(const String& x, const String& y) { return strcmp(x.rep->s, y.rep->s)!=0; }

String operator+(const String& x, const String& y)
{
    String s(x);
    s += y;
    return s;
}

String operator+(const String& x, const char* y)
{
    String s(x);
    s += y;
    return s;
}

String f(String a, String b)
{
    a[2] = 'x';
    char c = b[3];
    cout << "in f: " << a << ' ' << b << ' ' << c << '\n';
    return b;
}

int main()
{
    String x,y;
    cout << "Please enter two string\n";
    cin >> x >> y;
    cout << "input: " << x << ' ' << y << '\n';
    String z=x;
    y = f(x,y);
    if (x!=z) cout << "x corrupted!\n";
    x[0] = '!';
    if (x==z) cout << "write failed!\n";
    cout << "exit: " << x << ' ' << y << ' ' << z << '\n';
	cout<<x+y<<'\n';
	cout<<x+"123";
    return 0;
}

