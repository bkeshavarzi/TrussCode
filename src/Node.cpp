#include "Node.h"
static int counter=0;

Node::Node()
{
    setcord(0.0,0.0);
    setid(0);
    setres(true,true);
}
Node::Node(int i, double x,double y,bool xr,bool yr)
{
    setcord(x,y);
    setid(i);
    setres(xr,yr);
    counter++;
}
vector <double> Node::getcord()
{
    vector <double> temp;
    temp.push_back(x);
    temp.push_back(y);
    return temp;
}
int Node::getid()
{
    return id;
}
void Node::setcord(double xc,double yc)
{
    x=xc;
    y=yc;
}
void Node::setid(int i)
{
    id=i;
}
int Node::getcounter()
{
    return counter;
}
void Node::setres(bool xr,bool yr)
{
    rx=xr;
    ry=yr;
}
vector <bool> Node::GetRes()
{
   vector <bool> res;
   res.push_back(rx);
   res.push_back(ry);
   return res;
}
Node::~Node()
{
    //dtor
}
