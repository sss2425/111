#include<iostream>
#include<string>
#include <sstream>
#include"Value.h"
#include<math.h>
using namespace std;

void Value::zf(const string &val){
    if(val.find('-')==0)y=1;
    else y=0;
}
void Value::fz(const string &val){
    int i=(this->y)?1:0;string t;
    if(val.find('.')!=string::npos){int d=val.find('.');
     for(;i<d;i++)t.push_back(val[i]);
     istringstream ss(t);ss>>z;t.clear();i++;
     for(;i<val.size();i++){t.push_back(val[i]);j++;}
     ss.clear();ss.str(t);ss>>x;
    }
    else{
        for(i;i<val.size();i++)t.push_back(val[i]);
        istringstream ss(t);ss>>z;
    }
}
Value::Value(const string &val):j(0),x(0),z(0){
    zf(val);fz(val);cut();
}
Value Value::operator +(Value&a){
    if(this->y!=a.y){Value t=a;t.y=this->y;return *this-t;}Value ret=*this;ret.z+=a.z;
    if(this->x||a.x){
    align(*this,a);
    ret.x=this->x+a.x;ret.j=this->j;
    this->cut();a.cut();
    ret.cut();ret.overflow();
    }
    return ret;
}
void Value::operator +=(Value&a){
*this=*this+a;
}
void Value::overflow(){
    unsigned long long test=this->x;unsigned long long i=0,t1=0,cnt=1;for(;test!=0;test/=10)i++;
    if(i>this->j){
        for(int k=0;k<this->j;k++)cnt*=10;
        t1=this->x%cnt;this->z+=this->x/cnt;this->x=t1;
    }
}
void Value::cut(){
    if(!this->x){this->j=0;return;}
    while(!(this->x%10)){
        this->x/=10;this->j--;
    }
}
int Value::f(Value&a){
  Value t1=*this,t2=a;t1.y=t2.y=0;
 return(t1>t2)?1:0;
}
Value Value::operator-(Value&a){
    if(this->y!=a.y){Value t=a;t.y=(this->y);return *this+t;}
    Value ret;int i=1;long long t1,t2=0;t1=this->z-a.z;
    if((*this).f(a))ret.y=this->y;else ret.y=!this->y;
    if(this->x||a.x){
     align(*this,a);
     t2=this->x-a.x;ret.j=this->j;
     this->cut();jw(&t1,&t2,ret.j);a.cut();
    }ret.z=t1;ret.x=t2;ret.cut();ret.overflow();
    return ret;
}
void jw(long long *p1,long long *p2,int j){
if(*p1<=0&&*p2<=0){
    *p1*=-1;*p2*=-1;return;
}if(*p1>0&&*p2<0){
    int t1=1,t2=*p2*-1;
    for(int k=0;k<j;k++)t1*=10;
    *p1-=1;*p2=t1-t2;return;
}if(*p1<0&&*p2>0){
    *p1*=-1;*p1-=1;int t1=1;
    for(int k=0;k<j;k++)t1*=10;*p2=t1-*p2;
}
}
void Value::operator-=(Value &a){
    *this=*this-a;
}
void Value::align(Value &a,Value &b){
    if(a.j<b.j)while(a.j!=b.j){
      a.j++;a.x*=10;}
    else while(a.j!=b.j){
     b.j++;b.x*=10;}
}
int Value::operator>(Value&a){
    if(this->y<a.y)return true;
    if(this->y>a.y)return false;
    if(this->y==0){
    if(this->z>a.z)return true;
    if(this->z<a.z)return false;
     align(*this,a);
     return(this->x>a.x)?true:false;}
     else{
    if(this->z>a.z)return false;
    if(this->z<a.z)return true;
    align(*this,a);
    return(this->x>a.x)?false:true;
     }
}
int Value::operator<(Value&a){
    return(*this>a)?false:true;
}
int Value::operator==(const Value&a)const{
    Value t1(*this),t2(a);align(t1,t2);
    return (t1.y==t2.y)?(t1.z==t2.z)?(t1.x==t2.x)?true:false:false:false;
}
int Value::operator<=(Value&a){
    return(*this<a||*this==a)?true:false;
}
int Value::operator>=(Value&a){
    return(*this>a||*this==a)?true:false;
}    
Value Value::operator*(Value&a){
Value ret1,ret2;if(a.y)ret1.y=!y;else ret1.y=y;unsigned long long t1,t2;align(*this,a);
ret1.j=j;t1=z*a.z;t2=x*a.z;t2+=z*a.x;ret1.z=t1;ret1.x=t2;this->cut();a.cut();ret2.j=j+a.j;t2=this->x*a.x;ret2.x=t2;
ret2.y=ret1.y;return ret1+ret2;
}
void Value::operator*=(Value&a){
    *this=*this*a;
}
void func(Value &a,Value &b,Value&ret){
 while(a>=b){a-=b;ret.z++;}if(!a.z&&!a.x)return;
  Value c;s:c.z=1;while(ret.j<18&&a*c<b){c.z*=10;ret.j++;}
  a*=c;ret.x*=c.z;if(ret.j==18)a=Value();
    while((a.z||a.x)){
        if(a>=b){a-=b;ret.x++;}else goto s;  
}
}
Value Value::operator/(Value &a){
if(a==Value())throw(0);
Value t1=*this,t2=a;t1.y=t2.y=0;Value ret;func(t1,t2,ret);
ret.overflow();if(a.y)ret.y=!y;else ret.y=y;return ret;
}
void Value::operator/=(Value &a){
   *this=*this/a;
}
string Value::toString(const Value &a){
    string str;if(a.y)str.append("-");
    str.append(to_string(a.z));if(!a.j)return str;str.append(".");
    string t=to_string(a.x);for(int i=t.size();i<a.j;i++)t.insert(0,"0");
    if(a.j==18)t[17]='?';str.append(t);return str;
}