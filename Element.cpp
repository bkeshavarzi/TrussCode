#include "Element.h"
#include <iostream>
using namespace std;

Element::Element()
{
    //ctor
}
Element::Element(int i,vector <Node> n,double Ae,Material m)
{
  setid(i);
  setnode(n);
  setA(Ae);
  E=m.GetE();

  vector <double> cord1;
  vector <double> cord2;
  cord1=n[0].getcord();
  cord2=n[1].getcord();
  double dx=abs(cord1[0]-cord2[0]);
  double dy=abs(cord1[1]-cord2[1]);
  L=sqrt(pow(dx,2)+pow(dy,2));
  MakeQ();
  LocalS();
}

void Element :: MakeQ()
{
  vector <double> cord1=obj[0].getcord();
  vector <double> cord2=obj[1].getcord();
  double dx=abs(cord1[0]-cord2[0]);
  double dy=abs(cord1[1]-cord2[1]);
  double teta=atan(dy/dx);
  Q(0,0)=cos(teta);
  Q(1,0)=sin(teta);
  Q(2,1)=cos(teta);
  Q(3,1)=sin(teta);
}
void Element ::LocalS()
{
    double term=A*E/L;
    Lsm(0,0)=term;
    Lsm(0,1)=-1*term;
    Lsm(1,0)=-1*term;
    Lsm(1,1)=term;
}
MatrixXd Element::GlobalS()
{

    cout << Q <<endl;
    Gsm=Q*Lsm*Q.transpose();
    return Gsm;
}
void Element::setid(int i)
{
    id=i;
}
int Element::getid()
{
    return id;
}
vector <Node> Element::getnode()
{
    return obj;
}
void Element::setnode(vector <Node> v)
{
    obj=v;
}
double Element:: getA()
{
    return A;
}
void Element::setA(double ar)
{
    A=ar;
}
/*
vector <bool> Element::getres()
{
    vector <bool> ret,temp;
    temp=obj[0].getresn();
    ret.push_back(temp[0]);
    ret.push_back(temp[1]);
    temp=obj[1].getresn();
    ret.push_back(temp[0]);
    ret.push_back(temp[1]);
    return ret;
}
*/
Element::~Element()
{
    //dtor
}
