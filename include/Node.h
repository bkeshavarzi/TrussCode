#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Node
{
    public:

        Node();
        Node(int,double,double,bool,bool);
        vector <double> getcord();
        vector <bool> GetRes(void);
        void setcord(double ,double);
        int getid();
        void setid(int);
        int getcounter(void);
        void setres(bool,bool);
        virtual ~Node();

    protected:

    private:

        double x,y;
        int id;
        bool rx,ry;
        //static int counter;
};

#endif // NODE_H
