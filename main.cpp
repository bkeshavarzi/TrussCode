#include <iostream>
#include <vector>
#include <cmath>
#include "Node.h"
#include "Material.h"
#include "Element.h"
#include "ReadText.h"
#include <algorithm>
#include "StiffnessMatrix.h"

using namespace std;

int main()
{
    vector <Node> NV=ReadNodeFile();
    vector <Element> EV=ReadElementFile(NV);
    vector <double> FV= ReadForceFile(NV);
    MatrixXd KG=GlobalStiffnessMatrix(NV,EV);
    MatrixXd FK=CondensedGlobalStiffnessMatrix(NV,EV,KG);
    MatrixXd F=CondensedForceVector(NV,FV);
}
