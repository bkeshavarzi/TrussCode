#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <vector>
#include "Node.h"
#include "Material.h"

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
        virtual ~Element();

    protected:

    private:
        int id;
        vector <Node> nobj;
        double L,A,E;
};

#endif // ELEMENT_H
