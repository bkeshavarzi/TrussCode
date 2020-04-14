#include "Element.h"
#include <iostream>
using namespace std;
using namespace Eigen;

static int counter=0;

Element::Element()
{
   id=0;
   Node obj1,obj2;
   A=0.002;

}

Element::Element(int i,vector <Node> obj,double Av,Material mat)
{
    id=i;
    nobj=obj; //Check to see reference type in vector class????
    A=Av;
    E=mat.GetE();
    counter++;
    vector <double> cord1;
    vector <double> cord2;
    cord1=obj[0].getcord();
    cord2=obj[1].getcord();
    double dx=abs(cord1[0]-cord2[0]);
    double dy=abs(cord1[1]-cord2[1]);
    L=sqrt(pow(dx,2)+pow(dy,2));
    double teta=atan(dy/dx); //in radian
    Lsm(0,0)=A*E/L;Lsm(0,1)=-1*A*E/L;Lsm(1,0)=-1*A*E/L;Lsm(1,1)=A*E/L;
    Q(0,0)=cos(teta);Q(1,0)=cos(teta);Q(2,1)=cos(teta);Q(3,1)=sin(teta);
    Gsm=Q*Lsm*Q.transpose();
}
void Element::SetId(int i)
{
    id=i;
}
double Element:: GetId()
{
    return id;
}
vector <Node> Element:: GetNode()
{
    return nobj;
}
void Element::SetNode(vector <Node> obj)
{
    nobj.push_back(obj[0]);
    nobj.push_back(obj[1]);
}
double Element:: GetA()
{
    return A;
}
void Element::SetA(double Av)
{
    A=Av;
}
int Element::GetCounter()
{
    return counter;
}
Element::~Element()
{
    //dtor
}
