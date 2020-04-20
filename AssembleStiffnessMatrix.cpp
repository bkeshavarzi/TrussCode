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
}
/*
MatrixXd CondensedGlobalStiffnessMatrix(vector <Node> NV,vector <Element> EV,MatrixXd KG)
{
    int inode,jnode;
    MatrixXd FK;
    vector <Node> NOV;
    vector <bool> res;
    vector <int> id;
    vector<int>::iterator it;
    for (int ielem=0;ielem<EV.size();ielem++)
    {
        NOV=EV[ielem].getnode();
        inode=NOV[0].getid();
        jnode=NOV[1].getid();
        res=NOV[0].getres();
        if (res[0]==true) id.push_back(2*(inode-1));
        if (res[1]==true) id.push_back(2*(inode-1)+1);
        res=NOV[1].getres();
        if (res[0]==true) id.push_back(2*(jnode-1));
        if (res[1]==true) id.push_back(2*(jnode-1)+1);
    }

    sort(id.begin(),id.end(),myfunction);
    it=unique(id.begin(),id.end());
    id.resize(distance(id.begin(), it));
    for (it = id.begin(); it != id.end(); ++it) {
        cout << *it << " ";   //You should check to see they are restrained or not
    }
}
*/
