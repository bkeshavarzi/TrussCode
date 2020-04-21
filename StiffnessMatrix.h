#ifndef STIFFNESSMATRIX_H_INCLUDED
#define STIFFNESSMATRIX_H_INCLUDED
#include <iostream>
#include "Node.h"
#include <vector>
#include "Material.h"
#include "Element.h"

using namespace std;
using namespace Eigen;

MatrixXd GlobalStiffnessMatrix(vector <Node>,vector <Element>);
MatrixXd CondensedGlobalStiffnessMatrix(vector <Node>,vector <Element>,MatrixXd);
#endif // STIFFNESSMATRIX_H_INCLUDED
