#include "ReadText.h"


vector <Node> ReadNodeFile()
{
  ifstream fid ("Node.txt");
  if (!fid.is_open())
  {
      cout << "Can''t open the Node input file" << endl;
      vector <Node> NodalVector;
      return NodalVector;
  } else {

      int id;
      double xc,yc;
      bool xr,yr;
      Node obj;
      int counter=0;
      vector <Node> NodalVector;
      while (!fid.eof())
      {
          fid >> id >> xc >> yc >> xr >> yr;
          obj.setid(id);
          obj.setcord(xc,yc);
          obj.setres(xr,yr);
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
      double A;
      vector <Node> temp;
      temp.push_back(NV[0]);
      temp.push_back(NV[1]);
      Element obj;
      vector <Element> ElementVector;
      while (!fid.eof())
      {
         fid >> id >> inode >> jnode >> A;
         obj.setid(id);
         temp[0]=NV[inode-1];temp[1]=NV[jnode-1];
         obj.setnode(temp);
         obj.setA(A);
         ElementVector.push_back(obj);
      }
      fid.close();

      return ElementVector;
    }
}

