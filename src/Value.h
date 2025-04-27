#include<string>
using namespace std;
class Value{
    public:
    Value(const string &val);
    Value():y(0),z(0),x(0),j(0){
    }
    void zf(const string &val);
    void fz(const string &val);
    Value operator+(Value&a);
    void operator +=(Value&a);
    Value operator-(Value&a);
    void operator -=(Value&a);
    int operator <(Value&a);
    int operator >(Value&a);
    int operator ==(Value&a);
    int operator <=(Value&a);
    int operator >=(Value&a);
    Value operator *(Value&a);
    void operator *=(Value&a);
    Value operator /(Value &a);
    void operator /=(Value &a);
    friend void func(Value &a,Value &b,Value&ret);
    static string toString(const Value &a);
    ~Value(){}
    char y;short j;
    unsigned long long z,x;
    void overflow();
   static void align(Value&a,Value&b);
    void cut();int f(Value &a);
};
void jw(long long*p1,long long *p2,int j);