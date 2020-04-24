#include "ReadText.h"


vector <Node> ReadNodeFile()
{
  ifstream fid ("Node.txt");
  if (!fid.is_open())
  {
      cout << "Can''t open the Node input file" << endl;
      vector <Node> NodalVector;
  } else {

      int id;
      double xc,yc,fx,fy;
      bool xr,yr;
      Node obj;
      int counter=0;
      vector <Node> NodalVector;
      while (!fid.eof())
      {
          fid >> id >> xc >> yc >> xr >> yr >> fx >> fy;
          obj.setid(id);
          obj.setcord(xc,yc);
          obj.setres(xr,yr);
          obj.setforce(fx,fy);
          NodalVector.push_back(obj);
          counter++;
      }
      fid.close();
      return NodalVector;
  }

}

vector <Element> ReadElementFile(vector <Node> NV)
{
    ifstream fid ("Element.txt");
    if (!fid.is_open())
    {
      cout << "Can''t open the Element input file" << endl;
    } else {
      int id,inode,jnode;
      double A,E;
      vector <Node> temp;
      temp.push_back(NV[0]);
      temp.push_back(NV[1]);
      Element obj;
      vector <Element> ElementVector;
      Material mat;
      //Element(int i,vector <Node> n,double Ae,Material m)
      while (!fid.eof())
      {
         fid >> id >> inode >> jnode >> A;
         temp[0]=NV[inode-1];temp[1]=NV[jnode-1];
         Material mat(2e9);
         Element obj(id,temp,A,mat);
         ElementVector.push_back(obj);
      }
      fid.close();

      return ElementVector;
    }
}

vector <double> ReadForceFile(vector <Node> NV)
{
    ifstream fid ("Node.txt");
    if (!fid.is_open())
  {
      cout << "Can''t open the Node input file" << endl;
      //vector <Node> ForceVector;
  } else {

      int id;
      double xc,yc,fx,fy;
      bool xr,yr;
      Node obj;
      int counter=0;
      vector <double> ForceVector;
      while (!fid.eof())
      {
          fid >> id >> xc >> yc >> xr >> yr >> fx >> fy;
          ForceVector.push_back(fx);
          ForceVector.push_back(fy);
          counter++;
      }
      fid.close();
      return ForceVector;
  }
}

