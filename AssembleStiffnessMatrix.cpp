#include "StiffnessMatrix.h"

bool myfunction (int i,int j) { return (i>j); }

MatrixXd GlobalStiffnessMatrix(vector <Node> NV,vector <Element> EV)
{
    int inode,jnode; //This store node's id for each element
    MatrixXd EK,KG;
    KG=MatrixXd::Zero(2*NV.size(),2*NV.size());
    vector <Node> NOV;
    int dof[4];
    for (int ielem=0;ielem<EV.size();ielem++)
    {
        EK=EV[ielem].GlobalS();
        NOV=EV[ielem].getnode();
        inode=NOV[0].getid();
        jnode=NOV[1].getid();
        dof[0]=2*(inode-1);dof[1]=2*(inode-1)+1,dof[2]=2*(jnode-1);dof[3]=2*(jnode-1)+1;
        for (int idof=0;idof<4;idof++)
        {
            for (int jdof=0;jdof<4;jdof++)
            {
                KG(dof[idof],dof[jdof])=KG(dof[idof],dof[jdof])+EK(idof,jdof);
            }
        }
    }

    return KG;
}

MatrixXd CondensedGlobalStiffnessMatrix(vector <Node> NV,vector <Element> EV,MatrixXd KG)
{
    int inode,jnode;
    vector <Node> NOV;
    vector <bool> res;
    vector <int> resdof;
    vector <int> freedof;
    for (int inode=0;inode<NV.size();inode++)
    {
        res=NV[inode].getres();
        if (res[1]==false) freedof.push_back(2*(NV[inode].getid()-1)+1);
        if (res[0]==false) freedof.push_back(2*(NV[inode].getid()-1));
    }
    int icounter=0,jcounter=0;
    MatrixXd FK=MatrixXd::Zero(freedof.size(),freedof.size());
    for (int idof=0;idof<freedof.size();idof++)
    {
        for (int jdof=0;jdof<freedof.size();jdof++)
        {
            FK(icounter,jcounter)=KG(freedof[idof],freedof[jdof]);
            jcounter++;
        }
        icounter++;
        jcounter=0;
    }
    return FK;
}

MatrixXd CondensedForceVector(vector <Node> NV,vector <double> FG)
{
    vector <bool> res;
    vector <int> freedof;
    for (int inode=0;inode<NV.size();inode++)
    {
        res=NV[inode].getres();
        if (res[1]==false) freedof.push_back(2*(NV[inode].getid()-1)+1);
        if (res[0]==false) freedof.push_back(2*(NV[inode].getid()-1));
    }
    MatrixXd F=MatrixXd::Zero(freedof.size(),1);
    int icounter=0,jcounter=0;
    for (int jdof=0;jdof<freedof.size();jdof++)
    {
        F(jdof)=FG[freedof[jdof]];
    }
    return F;
}
