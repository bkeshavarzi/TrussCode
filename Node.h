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
        Node(int,double,double);
        vector <double> getcord();
        void setcord(double ,double);
        int getid();
        void setid(int);
        int getcounter();
        virtual ~Node();

    protected:

    private:

        double x,y;
        int id;
        //static int counter;
};

#endif // NODE_H
