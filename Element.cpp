#include "Element.h"

Element::Element()
{
    //ctor
}

Element::Element(int i,vector <Node> obj,double Av,Material mat)
{
    id=i;
    nobj=obj; //Check to see reference type in vector class????
    A=Av;
    E=mat.GetE();
    vector <double> cord1;
    vector <double> cord2;
    cord1=obj[0].getcord();
    cord2=obj[1].getcord();
    double dx=abs(cord1[0]-cord2[0]);
    double dy=abs(cord1[1]-cord2[1]);
    L=sqrt(pow(dx,2)+pow(dy,2));

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
Element::~Element()
{
    //dtor
}
