#include "GlobalStiffness.h"

MatrixXd MakeGlobalStiffnessMatrix(vector <Node> NV,vector <Element> EV)
{
    int d[4];
    vector <Node> ElementNodal;
    MatrixXd KG=MatrixXd::Zero(2*NV.size(),2*NV.size());
    MatrixXd KL=MatrixXd::Zero(4,4);
    for (int elementno=0; elementno <EV.size(); elementno ++)
    {
        ElementNodal=EV[elementno].getnode();
        d[0]=2*(ElementNodal[0].getid()-1);
        d[1]=2*(ElementNodal[0].getid()-1)+1;
        d[2]=2*(ElementNodal[1].getid()-1);
        d[3]=2*(ElementNodal[1].getid()-1)+1;
        for (int ildof=0; ildof <4 ;ildof++)
        {
           for (int jldof=0; jldof <4 ;jldof++)
           {
               KG(d[ildof],d[jldof])=KG(d[ildof],d[jldof])+KL(ildof,jldof);
           }
        }
    }

    return KG;
}
