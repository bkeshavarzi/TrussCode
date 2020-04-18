#ifndef GLOBALSTIFFNESS_H_INCLUDED
#define GLOBALSTIFFNESS_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include "Node.h"
#include "Element.h"
using namespace std;
using namespace Eigen;

MatrixXd MakeGlobalStiffnessMatrix(vector <Node>,vector <Element>);

#endif // GLOBALSTIFFNESS_H_INCLUDED
