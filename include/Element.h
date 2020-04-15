#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
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
        void SetId(int);
        double GetId();
        vector <Node> GetNode();
        void SetNode(vector <Node>);
        double GetA();
        void SetA(double);
        //int GetCounter();
        virtual ~Element();

    protected:

    private:
        int id;
        vector <Node> nobj;
        double L,A,E;
        MatrixXd Q=MatrixXd::Zero(4,2);
        Matrix2d Lsm=Matrix2d::Zero(2,2);
        MatrixXd Gsm=MatrixXd::Zero(4,4);
};

#endif // ELEMENT_H
