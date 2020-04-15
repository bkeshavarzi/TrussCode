#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <cmath>
#include <vector>
#include "Node.h"
#include "Material.h"
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;


class Element
{
    public:
        Element();
        Element(int,vector <Node>,double,Material);
        void setid(int);
        int getid();
        vector <Node> getnode();
        void setnode(vector <Node>);
        double getA();
        void setA(double);
        void MakeQ();
        void LocalS();
        MatrixXd GlobalS();
        ~Element();

    protected:

    private:
        int id;
        vector <Node> obj;
        double L,A,E;
        MatrixXd Q=MatrixXd::Zero(4,2);
        Matrix2d Lsm=Matrix2d::Zero(2,2);
        MatrixXd Gsm=MatrixXd::Zero(4,4);
};

#endif // ELEMENT_H
