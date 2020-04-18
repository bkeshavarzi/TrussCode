#include "ReadText.h"


vector <Node> ReadNodeFile()
{
  ifstream fid ("Node.txt");
  if (!fid.is_open())
  {
      cout << "Can''t open the Node input file" << endl;

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
          cout <<static_cast <bool> (xr) <<static_cast <bool> (yr) <<endl;
          obj.setid(id);
          obj.setcord(xc,yc);
          //obj.setres(xr,yr);
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
      double A, E;
      vector <Node> temp;
      temp.push_back(NV[0]);
      temp.push_back(NV[1]);
      vector <Element> ElementVector;
      while (!fid.eof())
      {
         fid >> id >> inode >> jnode >> A >> E;
         Material mat(E);
         temp[0]=NV[inode-1];temp[1]=NV[jnode-1];
         Element obj(id,temp,A,mat);
         ElementVector.push_back(obj);
      }
      fid.close();

      return ElementVector;
    }
}

